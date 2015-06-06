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

DLL_EXPORT uint32_t BlitzSteam_Init() {
	return SteamAPI_Init();
}
#pragma comment(linker, "/EXPORT:BlitzSteam_Init=_BlitzSteam_Init@0")

DLL_EXPORT void BlitzSteam_Shutdown() {
	SteamAPI_Shutdown();
}
#pragma comment(linker, "/EXPORT:BlitzSteam_Shutdown=_BlitzSteam_Shutdown@0")

DLL_EXPORT uint32_t BlitzSteam_IsSteamRunning() {
	return SteamAPI_IsSteamRunning();
}
#pragma comment(linker, "/EXPORT:BlitzSteam_IsSteamRunning=_BlitzSteam_IsSteamRunning@0")

DLL_EXPORT uint32_t BlitzSteam_RestartAppIfNecessary(uint32 unOwnAppID) {
	return SteamAPI_RestartAppIfNecessary(unOwnAppID);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_RestartAppIfNecessary=_BlitzSteam_RestartAppIfNecessary@4")

DLL_EXPORT void BlitzSteam_SetMiniDumpComment(const char* pchMsg) {
	SteamAPI_SetMiniDumpComment(pchMsg);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_SetMiniDumpComment=_BlitzSteam_SetMiniDumpComment@4")

DLL_EXPORT void BlitzSteam_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID) {
	SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_WriteMiniDump=_BlitzSteam_WriteMiniDump@12")

// Interface Pointers, configured by SteamAPI_Init().
DLL_EXPORT ISteamClient* BlitzSteamClient() {
	return SteamClient();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient=_BlitzSteamClient@0")

DLL_EXPORT ISteamUser* BlitzSteamUser() {
	return SteamUser();
}
#pragma comment(linker, "/EXPORT:BlitzSteamUser=_BlitzSteamUser@0")

DLL_EXPORT ISteamFriends* BlitzSteamFriends() {
	return SteamFriends();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends=_BlitzSteamFriends@0")

DLL_EXPORT ISteamUtils* BlitzSteamUtils() {
	return SteamUtils();
}
#pragma comment(linker, "/EXPORT:BlitzSteamUtils=_BlitzSteamUtils@0")

DLL_EXPORT ISteamMatchmaking* BlitzSteamMatchmaking() {
	return SteamMatchmaking();
}
#pragma comment(linker, "/EXPORT:BlitzSteamMatchmaking=_BlitzSteamMatchmaking@0")

DLL_EXPORT ISteamUserStats* BlitzSteamUserStats() {
	return SteamUserStats();
}
#pragma comment(linker, "/EXPORT:BlitzSteamUserStats=_BlitzSteamUserStats@0")

DLL_EXPORT ISteamApps* BlitzSteamApps() {
	return SteamApps();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps=_BlitzSteamApps@0")

DLL_EXPORT ISteamNetworking* BlitzSteamNetworking() {
	return SteamNetworking();
}
#pragma comment(linker, "/EXPORT:BlitzSteamNetworking=_BlitzSteamNetworking@0")

DLL_EXPORT ISteamMatchmakingServers* BlitzSteamMatchmakingServers() {
	return SteamMatchmakingServers();
}
#pragma comment(linker, "/EXPORT:BlitzSteamMatchmakingServers=_BlitzSteamMatchmakingServers@0")

DLL_EXPORT ISteamRemoteStorage* BlitzSteamRemoteStorage() {
	return SteamRemoteStorage();
}
#pragma comment(linker, "/EXPORT:BlitzSteamRemoteStorage=_BlitzSteamRemoteStorage@0")

DLL_EXPORT ISteamScreenshots* BlitzSteamScreenshots() {
	return SteamScreenshots();
}
#pragma comment(linker, "/EXPORT:BlitzSteamScreenshots=_BlitzSteamScreenshots@0")

DLL_EXPORT ISteamHTTP* BlitzSteamHTTP() {
	return SteamHTTP();
}
#pragma comment(linker, "/EXPORT:BlitzSteamHTTP=_BlitzSteamHTTP@0")

DLL_EXPORT ISteamUnifiedMessages* BlitzSteamUnifiedMessages() {
	return SteamUnifiedMessages();
}
#pragma comment(linker, "/EXPORT:BlitzSteamUnifiedMessages=_BlitzSteamUnifiedMessages@0")

DLL_EXPORT ISteamController* BlitzSteamController() {
	return SteamController();
}
#pragma comment(linker, "/EXPORT:BlitzSteamController=_BlitzSteamController@0")

DLL_EXPORT ISteamUGC* BlitzSteamUGC() {
	return SteamUGC();
}
#pragma comment(linker, "/EXPORT:BlitzSteamUGC=_BlitzSteamUGC@0")

DLL_EXPORT ISteamAppList* BlitzSteamAppList() {
	return SteamAppList();
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList=_BlitzSteamAppList@0")

DLL_EXPORT ISteamMusic* BlitzSteamMusic() {
	return SteamMusic();
}
#pragma comment(linker, "/EXPORT:BlitzSteamMusic=_BlitzSteamMusic@0")

DLL_EXPORT ISteamMusicRemote* BlitzSteamMusicRemote() {
	return SteamMusicRemote();
}
#pragma comment(linker, "/EXPORT:BlitzSteamMusicRemote=_BlitzSteamMusicRemote@0")

DLL_EXPORT ISteamHTMLSurface* BlitzSteamHTMLSurface() {
	return SteamHTMLSurface();
}
#pragma comment(linker, "/EXPORT:BlitzSteamHTMLSurface=_BlitzSteamHTMLSurface@0")

DLL_EXPORT ISteamInventory* BlitzSteamInventory() {
	return SteamInventory();
}
#pragma comment(linker, "/EXPORT:BlitzSteamInventory=_BlitzSteamInventory@0")

DLL_EXPORT ISteamVideo* BlitzSteamVideo() {
	return SteamVideo();
}
#pragma comment(linker, "/EXPORT:BlitzSteamVideo=_BlitzSteamVideo@0")

// Callbacks & Hooks
DLL_EXPORT void BlitzSteam_RunCallbacks() {
	SteamAPI_RunCallbacks();
}
#pragma comment(linker, "/EXPORT:BlitzSteam_RunCallbacks=_BlitzSteam_RunCallbacks@0")

DLL_EXPORT void BlitzSteam_RegisterCallback(class CCallbackBase *pCallback, int iCallback) {
	SteamAPI_RegisterCallback(pCallback, iCallback);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_RegisterCallback=_BlitzSteam_RegisterCallback@8")

DLL_EXPORT void BlitzSteam_UnregisterCallback(class CCallbackBase *pCallback) {
	SteamAPI_UnregisterCallback(pCallback);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_UnregisterCallback=_BlitzSteam_UnregisterCallback@4")

DLL_EXPORT void BlitzSteam_RegisterCallResult(class CCallbackBase *pCallback, uint32_t hAPICall_L, uint32_t hAPICall_R) {
	SteamAPI_RegisterCallResult(pCallback, ((uint64_t)hAPICall_L << 32) + (uint64_t)hAPICall_R);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_RegisterCallResult=_BlitzSteam_RegisterCallResult@12")

DLL_EXPORT void BlitzSteam_UnregisterCallResult(class CCallbackBase *pCallback, uint32_t hAPICall_L, uint32_t hAPICall_R) {
	SteamAPI_UnregisterCallResult(pCallback, ((uint64_t)hAPICall_L << 32) + (uint64_t)hAPICall_R);
}
#pragma comment(linker, "/EXPORT:BlitzSteam_UnregisterCallResult=_BlitzSteam_UnregisterCallResult@12")