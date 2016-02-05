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

DLL_FUNCTION(ISteamClient*) BS_Client() {
	return SteamClient();
}
#pragma comment(linker, "/EXPORT:BS_Client=_BS_Client@0")

DLL_FUNCTION(HSteamPipe) BS_Client_CreateSteamPipe(ISteamClient* lpSteamClient) {
	return lpSteamClient->CreateSteamPipe();
}
#pragma comment(linker, "/EXPORT:BS_Client_CreateSteamPipe=_BS_Client_CreateSteamPipe@4")

DLL_FUNCTION(uint32_t) BS_Client_ReleaseSteamPipe(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->BReleaseSteamPipe(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BS_Client_ReleaseSteamPipe=_BS_Client_ReleaseSteamPipe@8")

DLL_FUNCTION(HSteamUser) BS_Client_ConnectToGlobalUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->ConnectToGlobalUser(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BS_Client_ConnectToGlobalUser=_BS_Client_ConnectToGlobalUser@8")

DLL_FUNCTION(void) BS_Client_SetLocalIPBinding(ISteamClient* lpSteamClient, uint32_t unIP, uint16 usPort) {
	return lpSteamClient->SetLocalIPBinding(unIP, usPort);
}
#pragma comment(linker, "/EXPORT:BS_Client_SetLocalIPBinding=_BS_Client_SetLocalIPBinding@12")

DLL_FUNCTION(HSteamUser) BS_Client_CreateLocalUser(ISteamClient* lpSteamClient, HSteamPipe* phSteamPipe, EAccountType eAccountType) {
	return lpSteamClient->CreateLocalUser(phSteamPipe, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_Client_CreateLocalUser=_BS_Client_CreateLocalUser@12")

DLL_FUNCTION(void) BS_Client_ReleaseUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	return lpSteamClient->ReleaseUser(hSteamPipe, hSteamUser);
}
#pragma comment(linker, "/EXPORT:BS_Client_ReleaseUser=_BS_Client_ReleaseUser@12")

DLL_FUNCTION(void) BS_Client_RunFrame(ISteamClient* lpSteamClient) {
	lpSteamClient->RunFrame();
}
#pragma comment(linker, "/EXPORT:BS_Client_RunFrame=_BS_Client_RunFrame@4")

DLL_FUNCTION(uint32_t) BS_Client_GetIPCCallCount(ISteamClient* lpSteamClient) {
	return lpSteamClient->GetIPCCallCount();
}
#pragma comment(linker, "/EXPORT:BS_Client_GetIPCCallCount=_BS_Client_GetIPCCallCount@4")

DLL_FUNCTION(uint32_t) BS_Client_ShutdownIfAllPipesClosed(ISteamClient* lpSteamClient) {
	return lpSteamClient->BShutdownIfAllPipesClosed();
}

// Interfaces
DLL_FUNCTION(ISteamAppList*) BS_Client_GetSteamAppList(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamAppList=_BS_Client_GetSteamAppList@16")

DLL_FUNCTION(ISteamApps*) BS_Client_GetSteamApps(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamApps=_BS_Client_GetSteamApps@16")

DLL_FUNCTION(ISteamController*) BS_Client_GetSteamController(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamController=_BS_Client_GetSteamController@16")

DLL_FUNCTION(ISteamFriends*) BS_Client_GetSteamFriends(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamFriends=_BS_Client_GetSteamFriends@16")

DLL_FUNCTION(ISteamGameServer*) BS_Client_GetSteamGameServer(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamGameServer=_BS_Client_GetSteamGameServer@16")

DLL_FUNCTION(ISteamGameServerStats*) BS_Client_GetSteamGameServerStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamGameServerStats=_BS_Client_GetSteamGameServerStats@16")

DLL_FUNCTION(ISteamHTMLSurface*) BS_Client_GetSteamHTMLSurface(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamHTMLSurface=_BS_Client_GetSteamHTMLSurface@16")

DLL_FUNCTION(ISteamHTTP*) BS_Client_GetSteamHTTP(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamHTTP=_BS_Client_GetSteamHTTP@16")

DLL_FUNCTION(ISteamInventory*) BS_Client_GetSteamInventory(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamInventory=_BS_Client_GetSteamInventory@16")

DLL_FUNCTION(ISteamMatchmaking*) BS_Client_GetSteamMatchmaking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamMatchmaking=_BS_Client_GetSteamMatchmaking@16")

DLL_FUNCTION(ISteamMatchmakingServers*) BS_Client_GetSteamMatchmakingServers(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamMatchmakingServers=_BS_Client_GetSteamMatchmakingServers@16")

DLL_FUNCTION(ISteamMusic*) BS_Client_GetSteamMusic(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamMusic=_BS_Client_GetSteamMusic@16")

DLL_FUNCTION(ISteamMusicRemote*) BS_Client_GetSteamMusicRemote(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamMusicRemote=_BS_Client_GetSteamMusicRemote@16")

DLL_FUNCTION(ISteamNetworking*) BS_Client_GetSteamNetworking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamNetworking=_BS_Client_GetSteamNetworking@16")

DLL_FUNCTION(ISteamRemoteStorage*) BS_Client_GetSteamRemoteStorage(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamRemoteStorage=_BS_Client_GetSteamRemoteStorage@16")

DLL_FUNCTION(ISteamScreenshots*) BS_Client_GetSteamScreenshots(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamScreenshots=_BS_Client_GetSteamScreenshots@16")

DLL_FUNCTION(ISteamUGC*) BS_Client_GetSteamUGC(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamUGC=_BS_Client_GetSteamUGC@16")

DLL_FUNCTION(ISteamUnifiedMessages*) BS_Client_GetSteamUnifiedMessages(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUnifiedMessages(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamUnifiedMessages=_BS_Client_GetSteamUnifiedMessages@16")

DLL_FUNCTION(ISteamUser*) BS_Client_GetSteamUser(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamUser=_BS_Client_GetSteamUser@16")

DLL_FUNCTION(ISteamUserStats*) BS_Client_GetSteamUserStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamUserStats=_BS_Client_GetSteamUserStats@16")

DLL_FUNCTION(ISteamUtils*) BS_Client_GetSteamUtils(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUtils(hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamUtils=_BS_Client_GetSteamUtils@12")

DLL_FUNCTION(ISteamVideo*) BS_Client_GetSteamVideo(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BS_Client_GetSteamVideo=_BS_Client_GetSteamVideo@16")

// Callbacks & Hooks
DLL_FUNCTION(void) BS_Client_SetWarningMessageHook(ISteamClient* lpSteamClient, SteamAPIWarningMessageHook_t fpfunction) {
	lpSteamClient->SetWarningMessageHook(fpfunction);
}
#pragma comment(linker, "/EXPORT:BS_Client_SetWarningMessageHook=_BS_Client_SetWarningMessageHook@8")

DLL_FUNCTION(void) BS_Client_Set_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CPostAPIResultInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BS_Client_Set_SteamAPI_CPostAPIResultInProcess=_BS_Client_Set_SteamAPI_CPostAPIResultInProcess@8")

DLL_FUNCTION(void) BS_Client_Remove_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Remove_SteamAPI_CPostAPIResultInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BS_Client_Remove_SteamAPI_CPostAPIResultInProcess=_BS_Client_Remove_SteamAPI_CPostAPIResultInProcess@8")

DLL_FUNCTION(void) BS_Client_Set_SteamAPI_CCheckCallbackRegisteredInProcess(ISteamClient* lpSteamClient, SteamAPI_CheckCallbackRegistered_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CCheckCallbackRegisteredInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BS_Client_Set_SteamAPI_CCheckCallbackRegisteredInProcess=_BS_Client_Set_SteamAPI_CCheckCallbackRegisteredInProcess@8")
