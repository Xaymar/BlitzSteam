//	BlitzSteam - Steam wrapper for Blitz
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

#include "Callbacks.h"

// Callbacks
void BS_Callback::Run(void *pvParam) {
	BP_CallFunction3(bbRunFunction, reinterpret_cast<uint32_t>(pvParam), 0, 0);
}

void BS_Callback::Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) {
	BP_CallFunction3(bbRunFunction, reinterpret_cast<uint32_t>(pvParam), (uint32_t)bIOFailure, reinterpret_cast<uint32_t>(&hSteamAPICall));
}

int BS_Callback::GetCallbackSizeBytes() {
	return sizeof(BS_Callback);
}

// DLL-Callables
DLL_FUNCTION(BS_Callback*) BS_Callback_Create(uint32_t fpFunctionPointer) {
	BS_Callback* lpCallback = new BS_Callback();
	lpCallback->bbRunFunction = (void*)fpFunctionPointer;
	return lpCallback;
}
#pragma comment(linker, "/EXPORT:BS_Callback_Create=_BS_Callback_Create@4")

DLL_FUNCTION(void) BS_Callback_Destroy(BS_Callback* lpCallback) {
	if (lpCallback != nullptr) {
		delete lpCallback;
	}
}
#pragma comment(linker, "/EXPORT:BS_Callback_Destroy=_BS_Callback_Destroy@4")