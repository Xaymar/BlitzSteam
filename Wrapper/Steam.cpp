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

DLL_EXPORT uint32_t DLL_CALL BS_Init() {
	return SteamAPI_Init();
}
#pragma comment(linker, "/EXPORT:BS_Init=_BS_Init@0")

DLL_EXPORT void DLL_CALL BS_Shutdown() {
	SteamAPI_Shutdown();
}
#pragma comment(linker, "/EXPORT:BS_Shutdown=_BS_Shutdown@0")

DLL_EXPORT uint32_t DLL_CALL BS_IsSteamRunning() {
	return SteamAPI_IsSteamRunning();
}
#pragma comment(linker, "/EXPORT:BS_IsSteamRunning=_BS_IsSteamRunning@0")

DLL_EXPORT uint32_t DLL_CALL BS_RestartAppIfNecessary(uint32 unOwnAppID) {
	return SteamAPI_RestartAppIfNecessary(unOwnAppID);
}
#pragma comment(linker, "/EXPORT:BS_RestartAppIfNecessary=_BS_RestartAppIfNecessary@4")

DLL_EXPORT void DLL_CALL BS_SetMiniDumpComment(const char* pchMsg) {
	SteamAPI_SetMiniDumpComment(pchMsg);
}
#pragma comment(linker, "/EXPORT:BS_SetMiniDumpComment=_BS_SetMiniDumpComment@4")

DLL_EXPORT void DLL_CALL BS_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID) {
	SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}
#pragma comment(linker, "/EXPORT:BS_WriteMiniDump=_BS_WriteMiniDump@12")

// Interface Pointers, configured by SteamAPI_Init().
DLL_EXPORT ISteamClient* DLL_CALL BS_Client() {
	return SteamClient();
}
#pragma comment(linker, "/EXPORT:BS_Client=_BS_Client@0")

DLL_EXPORT ISteamUser* DLL_CALL BS_User() {
	return SteamUser();
}
#pragma comment(linker, "/EXPORT:BS_User=_BS_User@0")

DLL_EXPORT ISteamFriends* DLL_CALL BS_Friends() {
	return SteamFriends();
}
#pragma comment(linker, "/EXPORT:BS_Friends=_BS_Friends@0")

DLL_EXPORT ISteamUtils* DLL_CALL BS_Utils() {
	return SteamUtils();
}
#pragma comment(linker, "/EXPORT:BS_Utils=_BS_Utils@0")

DLL_EXPORT ISteamMatchmaking* DLL_CALL BS_Matchmaking() {
	return SteamMatchmaking();
}
#pragma comment(linker, "/EXPORT:BS_Matchmaking=_BS_Matchmaking@0")

DLL_EXPORT ISteamUserStats* DLL_CALL BS_UserStats() {
	return SteamUserStats();
}
#pragma comment(linker, "/EXPORT:BS_UserStats=_BS_UserStats@0")

DLL_EXPORT ISteamApps* DLL_CALL BS_Apps() {
	return SteamApps();
}
#pragma comment(linker, "/EXPORT:BS_Apps=_BS_Apps@0")

DLL_EXPORT ISteamNetworking* DLL_CALL BS_Networking() {
	return SteamNetworking();
}
#pragma comment(linker, "/EXPORT:BS_Networking=_BS_Networking@0")

DLL_EXPORT ISteamMatchmakingServers* DLL_CALL BS_MatchmakingServers() {
	return SteamMatchmakingServers();
}
#pragma comment(linker, "/EXPORT:BS_MatchmakingServers=_BS_MatchmakingServers@0")

DLL_EXPORT ISteamRemoteStorage* DLL_CALL BS_RemoteStorage() {
	return SteamRemoteStorage();
}
#pragma comment(linker, "/EXPORT:BS_RemoteStorage=_BS_RemoteStorage@0")

DLL_EXPORT ISteamScreenshots* DLL_CALL BS_Screenshots() {
	return SteamScreenshots();
}
#pragma comment(linker, "/EXPORT:BS_Screenshots=_BS_Screenshots@0")

DLL_EXPORT ISteamHTTP* DLL_CALL BS_HTTP() {
	return SteamHTTP();
}
#pragma comment(linker, "/EXPORT:BS_HTTP=_BS_HTTP@0")

DLL_EXPORT ISteamUnifiedMessages* DLL_CALL BS_UnifiedMessages() {
	return SteamUnifiedMessages();
}
#pragma comment(linker, "/EXPORT:BS_UnifiedMessages=_BS_UnifiedMessages@0")

DLL_EXPORT ISteamController* DLL_CALL BS_Controller() {
	return SteamController();
}
#pragma comment(linker, "/EXPORT:BS_Controller=_BS_Controller@0")

DLL_EXPORT ISteamUGC* DLL_CALL BS_UGC() {
	return SteamUGC();
}
#pragma comment(linker, "/EXPORT:BS_UGC=_BS_UGC@0")

DLL_EXPORT ISteamAppList* DLL_CALL BS_AppList() {
	return SteamAppList();
}
#pragma comment(linker, "/EXPORT:BS_AppList=_BS_AppList@0")

DLL_EXPORT ISteamMusic* DLL_CALL BS_Music() {
	return SteamMusic();
}
#pragma comment(linker, "/EXPORT:BS_Music=_BS_Music@0")

DLL_EXPORT ISteamMusicRemote* DLL_CALL BS_MusicRemote() {
	return SteamMusicRemote();
}
#pragma comment(linker, "/EXPORT:BS_MusicRemote=_BS_MusicRemote@0")

DLL_EXPORT ISteamHTMLSurface* DLL_CALL BS_HTMLSurface() {
	return SteamHTMLSurface();
}
#pragma comment(linker, "/EXPORT:BS_HTMLSurface=_BS_HTMLSurface@0")

DLL_EXPORT ISteamInventory* DLL_CALL BS_Inventory() {
	return SteamInventory();
}
#pragma comment(linker, "/EXPORT:BS_Inventory=_BS_Inventory@0")

DLL_EXPORT ISteamVideo* DLL_CALL BS_Video() {
	return SteamVideo();
}
#pragma comment(linker, "/EXPORT:BS_Video=_BS_Video@0")

// Callbacks & Hooks
DLL_EXPORT void DLL_CALL BS_RunCallbacks() {
	SteamAPI_RunCallbacks();
}
#pragma comment(linker, "/EXPORT:BS_RunCallbacks=_BS_RunCallbacks@0")

DLL_EXPORT void DLL_CALL BS_RegisterCallback(class CCallbackBase *pCallback, int iCallback) {
	SteamAPI_RegisterCallback(pCallback, iCallback);
}
#pragma comment(linker, "/EXPORT:BS_RegisterCallback=_BS_RegisterCallback@8")

DLL_EXPORT void DLL_CALL BS_UnregisterCallback(class CCallbackBase *pCallback) {
	SteamAPI_UnregisterCallback(pCallback);
}
#pragma comment(linker, "/EXPORT:BS_UnregisterCallback=_BS_UnregisterCallback@4")

DLL_EXPORT void DLL_CALL BS_RegisterCallResult(class CCallbackBase *pCallback, uint32_t hAPICall_L, uint32_t hAPICall_R) {
	SteamAPI_RegisterCallResult(pCallback, ((uint64_t)hAPICall_L << 32) + (uint64_t)hAPICall_R);
}
#pragma comment(linker, "/EXPORT:BS_RegisterCallResult=_BS_RegisterCallResult@12")

DLL_EXPORT void DLL_CALL BS_UnregisterCallResult(class CCallbackBase *pCallback, uint32_t hAPICall_L, uint32_t hAPICall_R) {
	SteamAPI_UnregisterCallResult(pCallback, ((uint64_t)hAPICall_L << 32) + (uint64_t)hAPICall_R);
}
#pragma comment(linker, "/EXPORT:BS_UnregisterCallResult=_BS_UnregisterCallResult@12")
