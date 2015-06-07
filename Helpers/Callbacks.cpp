//	BlitzSteam - Steam wrapper for Blitz.
//	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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
#include "Libraries/BlitzPointer.h"
#include <time.h>

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

DLL_EXPORT void* BlitzSteamHelper_CreateCallback(uint32_t fpFunctionPointer) {
	BlitzSteamCallback* lpBSCallback = new BlitzSteamCallback();
	lpBSCallback->blitzFunctionPointer = fpFunctionPointer;
	return lpBSCallback;
}
#pragma comment(linker, "/EXPORT:BlitzSteamHelper_CreateCallback=_BlitzSteamHelper_CreateCallback@4")

DLL_EXPORT void BlitzSteamHelper_DestroyCallback(uint32_t lpCallback) {
	BlitzSteamCallback* lpBSCallback = (BlitzSteamCallback*)lpCallback;
	if (lpBSCallback != nullptr) {
		delete lpBSCallback;
	}
}
#pragma comment(linker, "/EXPORT:BlitzSteamHelper_DestroyCallback=_BlitzSteamHelper_DestroyCallback@4")

DLL_EXPORT const char* BlitzSteamHelper_FormatUnixTime(uint32_t unTime, const char* pchFormat) {
	char* output = new char[strlen(pchFormat) * 4];
	time_t t = unTime;
	struct tm *tm = localtime(&t);
	strftime(output, sizeof(output), pchFormat, tm);
	delete tm;
	return output;
}
#pragma comment(linker, "/EXPORT:BlitzSteamHelper_FormatUnixTime=_BlitzSteamHelper_FormatUnixTime@8")
