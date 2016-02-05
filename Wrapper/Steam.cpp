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
	return SteamAPI_Init();
}
#pragma comment(linker, "/EXPORT:BS_Steam_Init=_BS_Steam_Init@0")

DLL_FUNCTION(void) BS_Steam_Shutdown() {
	SteamAPI_Shutdown();
}
#pragma comment(linker, "/EXPORT:BS_Steam_Shutdown=_BS_Steam_Shutdown@0")

DLL_FUNCTION(uint32_t) BS_Steam_IsSteamRunning() {
	return SteamAPI_IsSteamRunning();
}
#pragma comment(linker, "/EXPORT:BS_Steam_IsSteamRunning=_BS_Steam_IsSteamRunning@0")

DLL_FUNCTION(uint32_t) BS_Steam_RestartAppIfNecessary(uint32_t unOwnAppID) {
	return SteamAPI_RestartAppIfNecessary(unOwnAppID);
}
#pragma comment(linker, "/EXPORT:BS_Steam_RestartAppIfNecessary=_BS_Steam_RestartAppIfNecessary@4")

DLL_FUNCTION(void) BS_Steam_SetMiniDumpComment(const char* pchMsg) {
	SteamAPI_SetMiniDumpComment(pchMsg);
}
#pragma comment(linker, "/EXPORT:BS_Steam_SetMiniDumpComment=_BS_Steam_SetMiniDumpComment@4")

DLL_FUNCTION(void) BS_Steam_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID) {
	SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}
#pragma comment(linker, "/EXPORT:BS_Steam_WriteMiniDump=_BS_Steam_WriteMiniDump@12")

// -- Callbacks
DLL_FUNCTION(void) BS_Steam_RunCallbacks() {
	SteamAPI_RunCallbacks();
}
#pragma comment(linker, "/EXPORT:BS_Steam_RunCallbacks=_BS_Steam_RunCallbacks@0")

DLL_FUNCTION(void) BS_Steam_RegisterCallback(class CCallbackBase *pCallback, uint32_t iCallback) {
	SteamAPI_RegisterCallback(pCallback, iCallback);
}
#pragma comment(linker, "/EXPORT:BS_Steam_RegisterCallback=_BS_Steam_RegisterCallback@8")

DLL_FUNCTION(void) BS_Steam_UnregisterCallback(class CCallbackBase *pCallback) {
	SteamAPI_UnregisterCallback(pCallback);
}
#pragma comment(linker, "/EXPORT:BS_Steam_UnregisterCallback=_BS_Steam_UnregisterCallback@4")

DLL_FUNCTION(void) BS_Steam_RegisterCallResult(class CCallbackBase *pCallback, uint64_t* phAPICall) {
	SteamAPI_RegisterCallResult(pCallback, *phAPICall);
}
#pragma comment(linker, "/EXPORT:BS_Steam_RegisterCallResult=_BS_Steam_RegisterCallResult@8")

DLL_FUNCTION(void) BS_Steam_UnregisterCallResult(class CCallbackBase *pCallback, uint64_t* phAPICall) {
	SteamAPI_UnregisterCallResult(pCallback, *phAPICall);
}
#pragma comment(linker, "/EXPORT:BS_Steam_UnregisterCallResult=_BS_Steam_UnregisterCallResult@8")
