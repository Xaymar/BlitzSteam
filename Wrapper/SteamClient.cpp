#include "dllmain.h"

DLL_EXPORT HSteamPipe BlitzSteamClient_CreateSteamPipe(ISteamClient* lpSteamClient) {
	return lpSteamClient->CreateSteamPipe();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_CreateSteamPipe=_BlitzSteamClient_CreateSteamPipe@4")

DLL_EXPORT bool BlitzSteamClient_ReleaseSteamPipe(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->BReleaseSteamPipe(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ReleaseSteamPipe=_BlitzSteamClient_ReleaseSteamPipe@8")

DLL_EXPORT HSteamUser BlitzSteamClient_ConnectToGlobalUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe) {
	return lpSteamClient->ConnectToGlobalUser(hSteamPipe);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ConnectToGlobalUser=_BlitzSteamClient_ConnectToGlobalUser@8")

DLL_EXPORT void BlitzSteamClient_SetLocalIPBinding(ISteamClient* lpSteamClient, uint32_t unIP, uint16 usPort) {
	return lpSteamClient->SetLocalIPBinding(unIP, usPort);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_SetLocalIPBinding=_BlitzSteamClient_SetLocalIPBinding@12")

DLL_EXPORT HSteamUser BlitzSteamClient_CreateLocalUser(ISteamClient* lpSteamClient, HSteamPipe* phSteamPipe, EAccountType eAccountType) {
	return lpSteamClient->CreateLocalUser(phSteamPipe, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_CreateLocalUser=_BlitzSteamClient_CreateLocalUser@12")

DLL_EXPORT void BlitzSteamClient_ReleaseUser(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, HSteamUser hSteamUser) {
	return lpSteamClient->ReleaseUser(hSteamPipe, hSteamUser);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_ReleaseUser=_BlitzSteamClient_ReleaseUser@12")

DLL_EXPORT void BlitzSteamClient_RunFrame(ISteamClient* lpSteamClient) {
	lpSteamClient->RunFrame();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_RunFrame=_BlitzSteamClient_RunFrame@4")

DLL_EXPORT uint32_t BlitzSteamClient_GetIPCCallCount(ISteamClient* lpSteamClient) {
	return lpSteamClient->GetIPCCallCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetIPCCallCount=_BlitzSteamClient_GetIPCCallCount@4")

DLL_EXPORT uint32_t BlitzSteamClient_ShutdownIfAllPipesClosed(ISteamClient* lpSteamClient) {
	return lpSteamClient->BShutdownIfAllPipesClosed();
}

// Interfaces
DLL_EXPORT ISteamUser* BlitzSteamClient_GetSteamUser(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUser=_BlitzSteamClient_GetSteamUser@16")

DLL_EXPORT ISteamGameServer* BlitzSteamClient_GetSteamGameServer(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamGameServer=_BlitzSteamClient_GetSteamGameServer@16")

DLL_EXPORT ISteamFriends* BlitzSteamClient_GetSteamFriends(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamFriends=_BlitzSteamClient_GetSteamFriends@16")

DLL_EXPORT ISteamUtils* BlitzSteamClient_GetSteamUtils(ISteamClient* lpSteamClient, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUtils(hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUtils=_BlitzSteamClient_GetSteamUtils@12")

DLL_EXPORT ISteamMatchmaking* BlitzSteamClient_GetSteamMatchmaking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMatchmaking=_BlitzSteamClient_GetSteamMatchmaking@16")

DLL_EXPORT ISteamMatchmakingServers* BlitzSteamClient_GetSteamMatchmakingServers(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMatchmakingServers=_BlitzSteamClient_GetSteamMatchmakingServers@16")

DLL_EXPORT ISteamUserStats* BlitzSteamClient_GetSteamUserStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUserStats=_BlitzSteamClient_GetSteamUserStats@16")

DLL_EXPORT ISteamGameServerStats* BlitzSteamClient_GetSteamGameServerStats(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamGameServerStats=_BlitzSteamClient_GetSteamGameServerStats@16")

DLL_EXPORT ISteamApps* BlitzSteamClient_GetSteamApps(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamApps=_BlitzSteamClient_GetSteamApps@16")

DLL_EXPORT ISteamNetworking* BlitzSteamClient_GetSteamNetworking(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamNetworking=_BlitzSteamClient_GetSteamNetworking@16")

DLL_EXPORT ISteamRemoteStorage* BlitzSteamClient_GetSteamRemoteStorage(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamRemoteStorage=_BlitzSteamClient_GetSteamRemoteStorage@16")

DLL_EXPORT ISteamScreenshots* BlitzSteamClient_GetSteamScreenshots(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamScreenshots(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamScreenshots=_BlitzSteamClient_GetSteamScreenshots@16")

DLL_EXPORT ISteamHTTP* BlitzSteamClient_GetSteamHTTP(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTTP(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamHTTP=_BlitzSteamClient_GetSteamHTTP@16")

DLL_EXPORT ISteamUnifiedMessages* BlitzSteamClient_GetSteamUnifiedMessages(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUnifiedMessages(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUnifiedMessages=_BlitzSteamClient_GetSteamUnifiedMessages@16")

DLL_EXPORT ISteamController* BlitzSteamClient_GetSteamController(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamController=_BlitzSteamClient_GetSteamController@16")

DLL_EXPORT ISteamUGC* BlitzSteamClient_GetSteamUGC(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamUGC=_BlitzSteamClient_GetSteamUGC@16")

DLL_EXPORT ISteamAppList* BlitzSteamClient_GetSteamAppList(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamAppList=_BlitzSteamClient_GetSteamAppList@16")

DLL_EXPORT ISteamMusic* BlitzSteamClient_GetSteamMusic(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusic(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMusic=_BlitzSteamClient_GetSteamMusic@16")

DLL_EXPORT ISteamMusicRemote* BlitzSteamClient_GetSteamMusicRemote(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamMusicRemote(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamMusicRemote=_BlitzSteamClient_GetSteamMusicRemote@16")

DLL_EXPORT ISteamHTMLSurface* BlitzSteamClient_GetSteamHTMLSurface(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamHTMLSurface(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamHTMLSurface=_BlitzSteamClient_GetSteamHTMLSurface@16")

DLL_EXPORT ISteamInventory* BlitzSteamClient_GetSteamInventory(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamInventory(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamInventory=_BlitzSteamClient_GetSteamInventory@16")

DLL_EXPORT ISteamVideo* BlitzSteamClient_GetSteamVideo(ISteamClient* lpSteamClient, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion) {
	return lpSteamClient->GetISteamVideo(hSteamUser, hSteamPipe, pchVersion);
}
#pragma comment(linker, "/EXPORT:BlitzSteamClient_GetSteamVideo=_BlitzSteamClient_GetSteamVideo@16")


// Callbacks & Hooks
DLL_EXPORT void BlitzSteamClient_SetWarningMessageHook(ISteamClient* lpSteamClient, SteamAPIWarningMessageHook_t pfunction) {
	lpSteamClient->SetWarningMessageHook(pfunction);
}

DLL_EXPORT void BlitzSteamClient_Set_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CPostAPIResultInProcess(fpFunction);
}

DLL_EXPORT void BlitzSteamClient_Remove_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Remove_SteamAPI_CPostAPIResultInProcess(fpFunction);
}

DLL_EXPORT void BlitzSteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(ISteamClient* lpSteamClient, SteamAPI_CheckCallbackRegistered_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CCheckCallbackRegisteredInProcess(fpFunction);
}