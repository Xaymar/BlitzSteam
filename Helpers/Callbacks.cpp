//	BS_ - Steam wrapper for Blitz.
//	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as
//	published by the Free Software Foundation, either version 3 of the 
//	License, or (at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "dllmain.h"
#include "Helpers/BlitzPointer.h"
#include <time.h>

// Callbacks
class BS_Callback : CCallbackBase {
	public:
	uint32_t blitzFunctionPointer;

	virtual void Run(void *pvParam) {
		BP_CallFunction4((uint32_t)blitzFunctionPointer, (uint32_t)pvParam, 0, 0, 0);
	}

	virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) {
		BP_CallFunction4((uint32_t)blitzFunctionPointer, (uint32_t)pvParam, bIOFailure, (uint32_t)(hSteamAPICall & 0xFFFFFFFF), (uint32_t)(hSteamAPICall >> 32));
	}

	virtual int GetCallbackSizeBytes() {
		return sizeof(BS_Callback);
	}
};

DLL_EXPORT void* DLL_CALL BS_Helper_CreateCallback(uint32_t fpFunctionPointer) {
	BS_Callback* lpBSCallback = new BS_Callback();
	lpBSCallback->blitzFunctionPointer = fpFunctionPointer;
	return lpBSCallback;
}
#pragma comment(linker, "/EXPORT:BS_Helper_CreateCallback=_BS_Helper_CreateCallback@4")

DLL_EXPORT void DLL_CALL BS_Helper_DestroyCallback(uint32_t lpCallback) {
	BS_Callback* lpBSCallback = (BS_Callback*)lpCallback;
	if (lpBSCallback != nullptr) {
		delete lpBSCallback;
	}
}
#pragma comment(linker, "/EXPORT:BS_Helper_DestroyCallback=_BS_Helper_DestroyCallback@4")

DLL_EXPORT const char* DLL_CALL BS_Helper_FormatUnixTime(uint32_t unTime, const char* pchFormat) {
	char* output = new char[strlen(pchFormat) * 4];
	time_t t = unTime;
	struct tm *tm = localtime(&t);
	strftime(output, sizeof(output), pchFormat, tm);
	delete tm;
	return output;
}
#pragma comment(linker, "/EXPORT:BS_Helper_FormatUnixTime=_BS_Helper_FormatUnixTime@8")
