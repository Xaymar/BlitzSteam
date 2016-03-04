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

DLL_FUNCTION(ISteamClient*) BS_SteamClient() {
	return SteamClient();
}

DLL_FUNCTION(HSteamPipe) BS_ISteamClient_CreateSteamPipe(ISteamClient* lpSteamClient) {
	return lpSteamClient->CreateSteamPipe();
}

DLL_FUNCTION(int32_t) BS_ISteamClient_ReleaseSteamPipe(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->BReleaseSteamPipe(hSteamPipe);
}

DLL_FUNCTION(HSteamUser) BS_ISteamClient_ConnectToGlobalUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->ConnectToGlobalUser(hSteamPipe);
}

DLL_FUNCTION(void) BS_ISteamClient_SetLocalIPBinding(ISteamClient* lpSteamClient, uint32_t unIP, uint16 usPort) {
	return lpSteamClient->SetLocalIPBinding(unIP, usPort);
}

DLL_FUNCTION(HSteamUser) BS_ISteamClient_CreateLocalUser(ISteamClient* lpSteamClient, HSteamPipe* phSteamPipe, EAccountType eAccountType) {
	return lpSteamClient->CreateLocalUser(phSteamPipe, eAccountType);
}

DLL_FUNCTION(void) BS_ISteamClient_ReleaseUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	return lpSteamClient->ReleaseUser(hSteamPipe, hSteamUser);
}

DLL_FUNCTION(int32_t) BS_ISteamClient_GetIPCCallCount(ISteamClient* lpSteamClient) {
	return lpSteamClient->GetIPCCallCount();
}

DLL_FUNCTION(int32_t) BS_ISteamClient_ShutdownIfAllPipesClosed(ISteamClient* lpSteamClient) {
	return lpSteamClient->BShutdownIfAllPipesClosed();
}

// Interfaces
DLL_FUNCTION(ISteamAppList*) BS_ISteamClient_GetSteamAppList(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamApps*) BS_ISteamClient_GetSteamApps(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamController*) BS_ISteamClient_GetSteamController(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamFriends*) BS_ISteamClient_GetSteamFriends(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamGameServer*) BS_ISteamClient_GetSteamGameServer(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamGameServerStats*) BS_ISteamClient_GetSteamGameServerStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamHTMLSurface*) BS_ISteamClient_GetSteamHTMLSurface(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamHTTP*) BS_ISteamClient_GetSteamHTTP(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamInventory*) BS_ISteamClient_GetSteamInventory(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamMatchmaking*) BS_ISteamClient_GetSteamMatchmaking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamMatchmakingServers*) BS_ISteamClient_GetSteamMatchmakingServers(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamMusic*) BS_ISteamClient_GetSteamMusic(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamMusicRemote*) BS_ISteamClient_GetSteamMusicRemote(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamNetworking*) BS_ISteamClient_GetSteamNetworking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamRemoteStorage*) BS_ISteamClient_GetSteamRemoteStorage(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamScreenshots*) BS_ISteamClient_GetSteamScreenshots(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamUGC*) BS_ISteamClient_GetSteamUGC(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamUnifiedMessages*) BS_ISteamClient_GetSteamUnifiedMessages(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUnifiedMessages(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamUser*) BS_ISteamClient_GetSteamUser(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamUserStats*) BS_ISteamClient_GetSteamUserStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamUtils*) BS_ISteamClient_GetSteamUtils(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUtils(hSteamPipe, pchVersion);
}

DLL_FUNCTION(ISteamVideo*) BS_ISteamClient_GetSteamVideo(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
}

// Callbacks & Hooks
DLL_FUNCTION(void) BS_ISteamClient_SetWarningMessageHook(ISteamClient* lpSteamClient, SteamAPIWarningMessageHook_t fpfunction) {
	lpSteamClient->SetWarningMessageHook(fpfunction);
}
