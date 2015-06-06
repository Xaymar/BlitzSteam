#include "dllmain.h"
#include "Libraries/BlitzPointer.h"

// Callbacks
class BlitzSteamCallback : CCallbackBase {
	public:
	uint32_t blitzFunctionPointer;

	virtual void Run(void *pvParam) {
		BlitzPointer_CallFunction4((uint32_t)blitzFunctionPointer, (uint32_t)pvParam, 0, 0, 0);
	}

	virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) {
		BlitzPointer_CallFunction4((uint32_t)blitzFunctionPointer, (uint32_t)pvParam, bIOFailure, (uint32_t)(hSteamAPICall & 0xFFFFFFFF), (uint32_t)(hSteamAPICall >> 32));
	}

	virtual int GetCallbackSizeBytes() {
		return sizeof(BlitzSteamCallback);
	}
};

DLL_EXPORT void* BlitzSteam_CreateCallback(uint32_t fpFunctionPointer) {
	BlitzSteamCallback* lpBSCallback = new BlitzSteamCallback();
	lpBSCallback->blitzFunctionPointer = fpFunctionPointer;
	return lpBSCallback;
}
#pragma comment(linker, "/EXPORT:BlitzSteam_CreateCallback=_BlitzSteam_CreateCallback@4")

DLL_EXPORT void BlitzSteam_DestroyCallback(uint32_t lpCallback) {
	BlitzSteamCallback* lpBSCallback = (BlitzSteamCallback*)lpCallback;
	if (lpBSCallback != nullptr) {
		delete lpBSCallback;
	}
}
#pragma comment(linker, "/EXPORT:BlitzSteam_DestroyCallback=_BlitzSteam_DestroyCallback@4")