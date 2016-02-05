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

DLL_FUNCTION(ISteamGameServer*) BS_GameServer() {
#pragma comment(linker, "/EXPORT:BS_GameServer=_BS_GameServer@0")
	return SteamGameServer();
}

DLL_FUNCTION(uint32_t) BS_GameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, EServerMode eServerMode, const char *pchVersionString) {
#pragma comment(linker, "/EXPORT:BS_GameServer_Init=_BS_GameServer_Init@24")
	return SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
}

DLL_FUNCTION(void) BS_GameServer_Shutdown() {
#pragma comment(linker, "/EXPORT:BS_GameServer_Shutdown=_BS_GameServer_Shutdown@0")
	SteamGameServer_Shutdown();
}

DLL_FUNCTION(void) BS_GameServer_RunCallbacks() {
#pragma comment(linker, "/EXPORT:BS_GameServer_RunCallbacks=_BS_GameServer_RunCallbacks@0")
	SteamGameServer_RunCallbacks();
}

DLL_FUNCTION(HSteamPipe) BS_GameServer_GetHSteamPipe() {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetHSteamPipe=_BS_GameServer_GetHSteamPipe@0")
	return SteamGameServer_GetHSteamPipe();
}

DLL_FUNCTION(uint32_t) BS_GameServer_IsSecureC() {
#pragma comment(linker, "/EXPORT:BS_GameServer_IsSecureC=_BS_GameServer_IsSecureC@0")
	return SteamGameServer_BSecure();
}

DLL_FUNCTION(CSteamID*) BS_GameServer_GetSteamIDC() {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetSteamIDC=_BS_GameServer_GetSteamIDC@0")
	return new CSteamID(SteamGameServer_GetSteamID());
}

// ISteamGameServer Stuff
DLL_FUNCTION(uint32_t) BS_GameServer_InitGameServer(ISteamGameServer* pSteamGameServer, uint32_t unIP, uint16_t usGamePort, uint16_t usQueryPort, uint32_t unFlags, AppId_t nGameAppId, const char *pchVersionString) {
#pragma comment(linker, "/EXPORT:BS_GameServer_InitGameServer=_BS_GameServer_InitGameServer@28")
	return pSteamGameServer->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
}

DLL_FUNCTION(void) BS_GameServer_SetProduct(ISteamGameServer* pSteamGameServer, const char *pszProduct) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetProduct=_BS_GameServer_SetProduct@8")
	pSteamGameServer->SetProduct(pszProduct);
}

DLL_FUNCTION(void) BS_GameServer_SetGameDescription(ISteamGameServer* pSteamGameServer, const char *pszGameDescription) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetGameDescription=_BS_GameServer_SetGameDescription@8")
	pSteamGameServer->SetGameDescription(pszGameDescription);
}

DLL_FUNCTION(void) BS_GameServer_SetModDir(ISteamGameServer* pSteamGameServer, const char *pszModDir) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetModDir=_BS_GameServer_SetModDir@8")
	pSteamGameServer->SetModDir(pszModDir);
}

DLL_FUNCTION(void) BS_GameServer_SetDedicatedServer(ISteamGameServer* pSteamGameServer, uint32_t bDedicated) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetDedicatedServer=_BS_GameServer_SetDedicatedServer@8")
	pSteamGameServer->SetDedicatedServer(!!bDedicated);
}

DLL_FUNCTION(void) BS_GameServer_LogOn(ISteamGameServer* pSteamGameServer, const char *pszToken) {
#pragma comment(linker, "/EXPORT:BS_GameServer_LogOn=_BS_GameServer_LogOn@8")
	pSteamGameServer->LogOn(pszToken);
}

DLL_FUNCTION(void) BS_GameServer_LogOnAnonymous(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_LogOnAnonymous=_BS_GameServer_LogOnAnonymous@4")
	pSteamGameServer->LogOnAnonymous();
}

DLL_FUNCTION(void) BS_GameServer_LogOff(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_LogOff=_BS_GameServer_LogOff@4")
	pSteamGameServer->LogOff();
}

DLL_FUNCTION(uint32_t) BS_GameServer_IsLoggedOn(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_IsLoggedOn=_BS_GameServer_IsLoggedOn@4")
	return pSteamGameServer->BLoggedOn();
}

DLL_FUNCTION(uint32_t) BS_GameServer_IsSecure(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_IsSecure=_BS_GameServer_IsSecure@4")
	return pSteamGameServer->BSecure();
}

DLL_FUNCTION(CSteamID*) BS_GameServer_GetSteamID(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetSteamID=_BS_GameServer_GetSteamID@4")
	return new CSteamID(pSteamGameServer->GetSteamID());
}

DLL_FUNCTION(uint32_t) BS_GameServer_WasRestartRequested(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_WasRestartRequested=_BS_GameServer_WasRestartRequested@4")
	return pSteamGameServer->WasRestartRequested();
}

DLL_FUNCTION(void) BS_GameServer_SetMaxPlayerCount(ISteamGameServer* pSteamGameServer, int32_t cPlayersMax) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetMaxPlayerCount=_BS_GameServer_SetMaxPlayerCount@8")
	pSteamGameServer->SetMaxPlayerCount(cPlayersMax);
}

DLL_FUNCTION(void) BS_GameServer_SetBotPlayerCount(ISteamGameServer* pSteamGameServer, int32_t cBotplayers) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetBotPlayerCount=_BS_GameServer_SetBotPlayerCount@8")
	pSteamGameServer->SetBotPlayerCount(cBotplayers);
}

DLL_FUNCTION(void) BS_GameServer_SetServerName(ISteamGameServer* pSteamGameServer, const char *pszServerName) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetServerName=_BS_GameServer_SetServerName@8")
	pSteamGameServer->SetServerName(pszServerName);
}

DLL_FUNCTION(void) BS_GameServer_SetMapName(ISteamGameServer* pSteamGameServer, const char *pszMapName) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetMapName=_BS_GameServer_SetMapName@8")
	pSteamGameServer->SetMapName(pszMapName);
}

DLL_FUNCTION(void) BS_GameServer_SetPasswordProtected(ISteamGameServer* pSteamGameServer, uint32_t bPasswordProtected) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetPasswordProtected=_BS_GameServer_SetPasswordProtected@8")
	pSteamGameServer->SetPasswordProtected(!!bPasswordProtected);
}

DLL_FUNCTION(void) BS_GameServer_SetSpectatorPort(ISteamGameServer* pSteamGameServer, uint16_t unSpectatorPort) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetSpectatorPort=_BS_GameServer_SetSpectatorPort@8")
	pSteamGameServer->SetSpectatorPort(unSpectatorPort);
}

DLL_FUNCTION(void) BS_GameServer_SetSpectatorServerName(ISteamGameServer* pSteamGameServer, const char *pszSpectatorServerName) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetSpectatorServerName=_BS_GameServer_SetSpectatorServerName@8")
	pSteamGameServer->SetSpectatorServerName(pszSpectatorServerName);
}

DLL_FUNCTION(void) BS_GameServer_ClearAllKeyValues(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_ClearAllKeyValues=_BS_GameServer_ClearAllKeyValues@4")
	pSteamGameServer->ClearAllKeyValues();
}

DLL_FUNCTION(void) BS_GameServer_SetKeyValue(ISteamGameServer* pSteamGameServer, const char *pKey, const char *pValue) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetKeyValue=_BS_GameServer_SetKeyValue@12")
	pSteamGameServer->SetKeyValue(pKey, pValue);
}

DLL_FUNCTION(void) BS_GameServer_SetGameTags(ISteamGameServer* pSteamGameServer, const char *pchGameTags) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetGameTags=_BS_GameServer_SetGameTags@8")
	pSteamGameServer->SetGameTags(pchGameTags);
}

DLL_FUNCTION(void) BS_GameServer_SetGameData(ISteamGameServer* pSteamGameServer, const char *pchGameData) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetGameData=_BS_GameServer_SetGameData@8")
	pSteamGameServer->SetGameData(pchGameData);
}

DLL_FUNCTION(void) BS_GameServer_SetRegion(ISteamGameServer* pSteamGameServer, const char *pszRegion) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetRegion=_BS_GameServer_SetRegion@8")
	pSteamGameServer->SetRegion(pszRegion);
}

DLL_FUNCTION(uint32_t) BS_GameServer_SendUserConnectAndAuthenticate(ISteamGameServer* pSteamGameServer, uint32_t unIPClient, const void *pvAuthBlob, uint32_t cubAuthBlobSize, CSteamID *pSteamIDUser) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SendUserConnectAndAuthenticate=_BS_GameServer_SendUserConnectAndAuthenticate@20")
	return pSteamGameServer->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
}

DLL_FUNCTION(CSteamID*) BS_GameServer_CreateUnauthenticatedUserConnection(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_CreateUnauthenticatedUserConnection=_BS_GameServer_CreateUnauthenticatedUserConnection@4")
	return new CSteamID(pSteamGameServer->CreateUnauthenticatedUserConnection());
}

DLL_FUNCTION(void) BS_GameServer_SendUserDisconnect(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SendUserDisconnect=_BS_GameServer_SendUserDisconnect@8")
	pSteamGameServer->SendUserDisconnect(*pSteamIDUser);
}

DLL_FUNCTION(uint32_t) BS_GameServer_UpdateUserData(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser, const char *pchPlayerName, uint32_t uScore) {
#pragma comment(linker, "/EXPORT:BS_GameServer_UpdateUserData=_BS_GameServer_UpdateUserData@16")
	return pSteamGameServer->BUpdateUserData(*pSteamIDUser, pchPlayerName, uScore);
}

DLL_FUNCTION(HAuthTicket) BS_GameServer_GetAuthSessionTicket(ISteamGameServer* pSteamGameServer, void *pTicket, int32_t cbMaxTicket, uint32_t *pcbTicket) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetAuthSessionTicket=_BS_GameServer_GetAuthSessionTicket@16")
	return pSteamGameServer->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

DLL_FUNCTION(EBeginAuthSessionResult) BS_GameServer_BeginAuthSession(ISteamGameServer* pSteamGameServer, const void *pAuthTicket, int32_t cbAuthTicket, CSteamID* pSteamID) {
#pragma comment(linker, "/EXPORT:BS_GameServer_BeginAuthSession=_BS_GameServer_BeginAuthSession@16")
	return pSteamGameServer->BeginAuthSession(pAuthTicket, cbAuthTicket, *pSteamID);
}

DLL_FUNCTION(void) BS_GameServer_EndAuthSession(ISteamGameServer* pSteamGameServer, CSteamID* pSteamID) {
#pragma comment(linker, "/EXPORT:BS_GameServer_EndAuthSession=_BS_GameServer_EndAuthSession@8")
	pSteamGameServer->EndAuthSession(*pSteamID);
}

DLL_FUNCTION(void) BS_GameServer_CancelAuthTicket(ISteamGameServer* pSteamGameServer, HAuthTicket hAuthTicket) {
#pragma comment(linker, "/EXPORT:BS_GameServer_CancelAuthTicket=_BS_GameServer_CancelAuthTicket@8")
	pSteamGameServer->CancelAuthTicket(hAuthTicket);
}

DLL_FUNCTION(EUserHasLicenseForAppResult) BS_GameServer_UserHasLicenseForApp(ISteamGameServer* pSteamGameServer, CSteamID* pSteamID, AppId_t appID) {
#pragma comment(linker, "/EXPORT:BS_GameServer_UserHasLicenseForApp=_BS_GameServer_UserHasLicenseForApp@12")
	return pSteamGameServer->UserHasLicenseForApp(*pSteamID, appID);
}

DLL_FUNCTION(uint32_t) BS_GameServer_RequestUserGroupStatus(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser, CSteamID* pSteamIDGroup) {
#pragma comment(linker, "/EXPORT:BS_GameServer_RequestUserGroupStatus=_BS_GameServer_RequestUserGroupStatus@12")
	return pSteamGameServer->RequestUserGroupStatus(*pSteamIDUser, *pSteamIDGroup);
}

DLL_FUNCTION(void) BS_GameServer_GetGameplayStats(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetGameplayStats=_BS_GameServer_GetGameplayStats@4")
	pSteamGameServer->GetGameplayStats();
}

DLL_FUNCTION(SteamAPICall_t*) BS_GameServer_GetServerReputation(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetServerReputation=_BS_GameServer_GetServerReputation@4")
	return new uint64_t(pSteamGameServer->GetServerReputation());
}

DLL_FUNCTION(uint32_t) BS_GameServer_GetPublicIP(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetPublicIP=_BS_GameServer_GetPublicIP@4")
	return pSteamGameServer->GetPublicIP();
}

DLL_FUNCTION(uint32_t) BS_GameServer_HandleIncomingPacket(ISteamGameServer* pSteamGameServer, const void *pData, int32_t cbData, uint32_t srcIP, uint16_t srcPort) {
#pragma comment(linker, "/EXPORT:BS_GameServer_HandleIncomingPacket=_BS_GameServer_HandleIncomingPacket@20")
	return pSteamGameServer->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
}

DLL_FUNCTION(uint32_t) BS_GameServer_GetNextOutgoingPacket(ISteamGameServer* pSteamGameServer, void *pOut, int32_t cbMaxOut, uint32_t *pNetAdr, uint16_t *pPort) {
#pragma comment(linker, "/EXPORT:BS_GameServer_GetNextOutgoingPacket=_BS_GameServer_GetNextOutgoingPacket@20")
	return pSteamGameServer->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
}

DLL_FUNCTION(void) BS_GameServer_EnableHeartbeats(ISteamGameServer* pSteamGameServer, uint32_t bActive) {
#pragma comment(linker, "/EXPORT:BS_GameServer_EnableHeartbeats=_BS_GameServer_EnableHeartbeats@8")
	pSteamGameServer->EnableHeartbeats(!!bActive);
}

DLL_FUNCTION(void) BS_GameServer_SetHeartbeatInterval(ISteamGameServer* pSteamGameServer, int32_t iHeartbeatInterval) {
#pragma comment(linker, "/EXPORT:BS_GameServer_SetHeartbeatInterval=_BS_GameServer_SetHeartbeatInterval@8")
	pSteamGameServer->SetHeartbeatInterval(iHeartbeatInterval);
}

DLL_FUNCTION(void) BS_GameServer_ForceHeartbeat(ISteamGameServer* pSteamGameServer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_ForceHeartbeat=_BS_GameServer_ForceHeartbeat@4")
	pSteamGameServer->ForceHeartbeat();
}

DLL_FUNCTION(SteamAPICall_t*) BS_GameServer_AssociateWithClan(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDClan) {
#pragma comment(linker, "/EXPORT:BS_GameServer_AssociateWithClan=_BS_GameServer_AssociateWithClan@8")
	return new uint64_t(pSteamGameServer->AssociateWithClan(*pSteamIDClan));
}

DLL_FUNCTION(SteamAPICall_t*) BS_GameServer_ComputeNewPlayerCompatibility(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDNewPlayer) {
#pragma comment(linker, "/EXPORT:BS_GameServer_ComputeNewPlayerCompatibility=_BS_GameServer_ComputeNewPlayerCompatibility@8")
	return new uint64_t(pSteamGameServer->ComputeNewPlayerCompatibility(*pSteamIDNewPlayer));
}