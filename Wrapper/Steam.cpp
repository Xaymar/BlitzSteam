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

#include "BlitzSteam.h"

DLL_FUNCTION(uint32_t) BS_Steam_Init() {
#pragma comment(linker, "/EXPORT:BS_Steam_Init=_BS_Steam_Init@0")
	return SteamAPI_Init();
}

DLL_FUNCTION(void) BS_Steam_Shutdown() {
#pragma comment(linker, "/EXPORT:BS_Steam_Shutdown=_BS_Steam_Shutdown@0")
	SteamAPI_Shutdown();
}

DLL_FUNCTION(uint32_t) BS_Steam_IsSteamRunning() {
#pragma comment(linker, "/EXPORT:BS_Steam_IsSteamRunning=_BS_Steam_IsSteamRunning@0")
	return SteamAPI_IsSteamRunning();
}

DLL_FUNCTION(uint32_t) BS_Steam_RestartAppIfNecessary(uint32_t unOwnAppID) {
#pragma comment(linker, "/EXPORT:BS_Steam_RestartAppIfNecessary=_BS_Steam_RestartAppIfNecessary@4")
	return SteamAPI_RestartAppIfNecessary(unOwnAppID);
}

DLL_FUNCTION(void) BS_Steam_SetMiniDumpComment(const char* pchMsg) {
#pragma comment(linker, "/EXPORT:BS_Steam_SetMiniDumpComment=_BS_Steam_SetMiniDumpComment@4")
	SteamAPI_SetMiniDumpComment(pchMsg);
}

DLL_FUNCTION(void) BS_Steam_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID) {
#pragma comment(linker, "/EXPORT:BS_Steam_WriteMiniDump=_BS_Steam_WriteMiniDump@12")
	SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}

// -- Callbacks
DLL_FUNCTION(void) BS_Steam_RunCallbacks() {
#pragma comment(linker, "/EXPORT:BS_Steam_RunCallbacks=_BS_Steam_RunCallbacks@0")
	SteamAPI_RunCallbacks();
}

DLL_FUNCTION(void) BS_Steam_RegisterCallback(class CCallbackBase *pCallback, uint32_t iCallback) {
#pragma comment(linker, "/EXPORT:BS_Steam_RegisterCallback=_BS_Steam_RegisterCallback@8")
	SteamAPI_RegisterCallback(pCallback, iCallback);
}

DLL_FUNCTION(void) BS_Steam_UnregisterCallback(class CCallbackBase *pCallback) {
#pragma comment(linker, "/EXPORT:BS_Steam_UnregisterCallback=_BS_Steam_UnregisterCallback@4")
	SteamAPI_UnregisterCallback(pCallback);
}

DLL_FUNCTION(void) BS_Steam_RegisterCallResult(class CCallbackBase *pCallback, uint64_t* phAPICall) {
#pragma comment(linker, "/EXPORT:BS_Steam_RegisterCallResult=_BS_Steam_RegisterCallResult@8")
	SteamAPI_RegisterCallResult(pCallback, *phAPICall);
}

DLL_FUNCTION(void) BS_Steam_UnregisterCallResult(class CCallbackBase *pCallback, uint64_t* phAPICall) {
#pragma comment(linker, "/EXPORT:BS_Steam_UnregisterCallResult=_BS_Steam_UnregisterCallResult@8")
	SteamAPI_UnregisterCallResult(pCallback, *phAPICall);
}
