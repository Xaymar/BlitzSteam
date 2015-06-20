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

DLL_EXPORT HSteamPipe DLL_CALL BlitzSteamClient_CreateSteamPipe(ISteamClient* lpSteamClient) {
	return lpSteamClient->CreateSteamPipe();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_CreateSteamPipe=_BlitzSteamClient_CreateSteamPipe@4")

DLL_EXPORT bool DLL_CALL BlitzSteamClient_ReleaseSteamPipe(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->BReleaseSteamPipe(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ReleaseSteamPipe=_BlitzSteamClient_ReleaseSteamPipe@8")

DLL_EXPORT HSteamUser DLL_CALL BlitzSteamClient_ConnectToGlobalUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->ConnectToGlobalUser(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ConnectToGlobalUser=_BlitzSteamClient_ConnectToGlobalUser@8")

DLL_EXPORT void DLL_CALL BlitzSteamClient_SetLocalIPBinding(ISteamClient* lpSteamClient, uint32_t unIP, uint16 usPort) {
	return lpSteamClient->SetLocalIPBinding(unIP, usPort);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_SetLocalIPBinding=_BlitzSteamClient_SetLocalIPBinding@12")

DLL_EXPORT HSteamUser DLL_CALL BlitzSteamClient_CreateLocalUser(ISteamClient* lpSteamClient, HSteamPipe* phSteamPipe, EAccountType eAccountType) {
	return lpSteamClient->CreateLocalUser(phSteamPipe, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_CreateLocalUser=_BlitzSteamClient_CreateLocalUser@12")

DLL_EXPORT void DLL_CALL BlitzSteamClient_ReleaseUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	return lpSteamClient->ReleaseUser(hSteamPipe, hSteamUser);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ReleaseUser=_BlitzSteamClient_ReleaseUser@12")

DLL_EXPORT void DLL_CALL BlitzSteamClient_RunFrame(ISteamClient* lpSteamClient) {
	lpSteamClient->RunFrame();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_RunFrame=_BlitzSteamClient_RunFrame@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamClient_GetIPCCallCount(ISteamClient* lpSteamClient) {
	return lpSteamClient->GetIPCCallCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetIPCCallCount=_BlitzSteamClient_GetIPCCallCount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamClient_ShutdownIfAllPipesClosed(ISteamClient* lpSteamClient) {
	return lpSteamClient->BShutdownIfAllPipesClosed();
}

// Interfaces
DLL_EXPORT ISteamAppList* DLL_CALL BlitzSteamClient_GetSteamAppList(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamAppList=_BlitzSteamClient_GetSteamAppList@16")

DLL_EXPORT ISteamApps* DLL_CALL BlitzSteamClient_GetSteamApps(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamApps=_BlitzSteamClient_GetSteamApps@16")

DLL_EXPORT ISteamController* DLL_CALL BlitzSteamClient_GetSteamController(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamController=_BlitzSteamClient_GetSteamController@16")

DLL_EXPORT ISteamFriends* DLL_CALL BlitzSteamClient_GetSteamFriends(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamFriends=_BlitzSteamClient_GetSteamFriends@16")

DLL_EXPORT ISteamGameServer* DLL_CALL BlitzSteamClient_GetSteamGameServer(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamGameServer=_BlitzSteamClient_GetSteamGameServer@16")

DLL_EXPORT ISteamGameServerStats* DLL_CALL BlitzSteamClient_GetSteamGameServerStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamGameServerStats=_BlitzSteamClient_GetSteamGameServerStats@16")

DLL_EXPORT ISteamHTMLSurface* DLL_CALL BlitzSteamClient_GetSteamHTMLSurface(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamHTMLSurface=_BlitzSteamClient_GetSteamHTMLSurface@16")

DLL_EXPORT ISteamHTTP* DLL_CALL BlitzSteamClient_GetSteamHTTP(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamHTTP=_BlitzSteamClient_GetSteamHTTP@16")

DLL_EXPORT ISteamInventory* DLL_CALL BlitzSteamClient_GetSteamInventory(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamInventory=_BlitzSteamClient_GetSteamInventory@16")

DLL_EXPORT ISteamMatchmaking* DLL_CALL BlitzSteamClient_GetSteamMatchmaking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMatchmaking=_BlitzSteamClient_GetSteamMatchmaking@16")

DLL_EXPORT ISteamMatchmakingServers* DLL_CALL BlitzSteamClient_GetSteamMatchmakingServers(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMatchmakingServers=_BlitzSteamClient_GetSteamMatchmakingServers@16")

DLL_EXPORT ISteamMusic* DLL_CALL BlitzSteamClient_GetSteamMusic(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMusic=_BlitzSteamClient_GetSteamMusic@16")

DLL_EXPORT ISteamMusicRemote* DLL_CALL BlitzSteamClient_GetSteamMusicRemote(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMusicRemote=_BlitzSteamClient_GetSteamMusicRemote@16")

DLL_EXPORT ISteamNetworking* DLL_CALL BlitzSteamClient_GetSteamNetworking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamNetworking=_BlitzSteamClient_GetSteamNetworking@16")

DLL_EXPORT ISteamRemoteStorage* DLL_CALL BlitzSteamClient_GetSteamRemoteStorage(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamRemoteStorage=_BlitzSteamClient_GetSteamRemoteStorage@16")

DLL_EXPORT ISteamScreenshots* DLL_CALL BlitzSteamClient_GetSteamScreenshots(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamScreenshots=_BlitzSteamClient_GetSteamScreenshots@16")

DLL_EXPORT ISteamUGC* DLL_CALL BlitzSteamClient_GetSteamUGC(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUGC=_BlitzSteamClient_GetSteamUGC@16")

DLL_EXPORT ISteamUnifiedMessages* DLL_CALL BlitzSteamClient_GetSteamUnifiedMessages(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUnifiedMessages(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUnifiedMessages=_BlitzSteamClient_GetSteamUnifiedMessages@16")

DLL_EXPORT ISteamUser* DLL_CALL BlitzSteamClient_GetSteamUser(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUser=_BlitzSteamClient_GetSteamUser@16")

DLL_EXPORT ISteamUserStats* DLL_CALL BlitzSteamClient_GetSteamUserStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUserStats=_BlitzSteamClient_GetSteamUserStats@16")

DLL_EXPORT ISteamUtils* DLL_CALL BlitzSteamClient_GetSteamUtils(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUtils(hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUtils=_BlitzSteamClient_GetSteamUtils@12")

DLL_EXPORT ISteamVideo* DLL_CALL BlitzSteamClient_GetSteamVideo(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamVideo=_BlitzSteamClient_GetSteamVideo@16")

// Callbacks & Hooks
DLL_EXPORT void DLL_CALL BlitzSteamClient_SetWarningMessageHook(ISteamClient* lpSteamClient, SteamAPIWarningMessageHook_t fpfunction) {
	lpSteamClient->SetWarningMessageHook(fpfunction);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_SetWarningMessageHook=_BlitzSteamClient_SetWarningMessageHook@8")

DLL_EXPORT void DLL_CALL BlitzSteamClient_Set_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CPostAPIResultInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_Set_SteamAPI_CPostAPIResultInProcess=_BlitzSteamClient_Set_SteamAPI_CPostAPIResultInProcess@8")

DLL_EXPORT void DLL_CALL BlitzSteamClient_Remove_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Remove_SteamAPI_CPostAPIResultInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_Remove_SteamAPI_CPostAPIResultInProcess=_BlitzSteamClient_Remove_SteamAPI_CPostAPIResultInProcess@8")

DLL_EXPORT void DLL_CALL BlitzSteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(ISteamClient* lpSteamClient, SteamAPI_CheckCallbackRegistered_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CCheckCallbackRegisteredInProcess(fpFunction);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess=_BlitzSteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess@8")
