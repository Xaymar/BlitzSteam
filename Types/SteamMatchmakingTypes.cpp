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

#include "SteamMatchmakingTypes.h"

//////////////////////////////////////////////////////////////////////////
BlitzISteamMatchmakingServerListResponse::BlitzISteamMatchmakingServerListResponse(void* pData, BP_BlitzFunction3_t pServerResponded,
	BP_BlitzFunction3_t pServerFailedToRespond, BP_BlitzFunction3_t pRefreshComplete)
	: m_pData(pData), m_pServerResponded(pServerResponded), m_pServerFailedToRespond(pServerFailedToRespond), m_pRefreshComplete(pRefreshComplete) {}

void BlitzISteamMatchmakingServerListResponse::ServerResponded(HServerListRequest hRequest, int iServer) {
	if (this->m_pServerResponded != nullptr)
		BP_CallFunction3(m_pServerResponded, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(hRequest), iServer);
}

void BlitzISteamMatchmakingServerListResponse::ServerFailedToRespond(HServerListRequest hRequest, int iServer) {
	if (this->m_pServerFailedToRespond != nullptr)
		BP_CallFunction3(m_pServerFailedToRespond, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(hRequest), iServer);
}

void BlitzISteamMatchmakingServerListResponse::RefreshComplete(HServerListRequest hRequest, EMatchMakingServerResponse response) {
	if (this->m_pRefreshComplete != nullptr)
		BP_CallFunction3(m_pRefreshComplete, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(hRequest), static_cast<int32_t>(response));
}

DLL(BlitzISteamMatchmakingServerListResponse*) BS_ISteamMatchmakingServerListResponse_New(void* pData, BP_BlitzFunction3_t pServerResponded, BP_BlitzFunction3_t pServerFailedToRespond, BP_BlitzFunction3_t pRefreshComplete) {
	return new BlitzISteamMatchmakingServerListResponse(pData, pServerResponded, pServerFailedToRespond, pRefreshComplete);
}

DLL(void) BS_ISteamMatchmakingServerListResponse_Destroy(BlitzISteamMatchmakingServerListResponse* pThis) {
	delete pThis;
}

//////////////////////////////////////////////////////////////////////////
BlitzISteamMatchmakingPingResponse::BlitzISteamMatchmakingPingResponse(void* pData, BP_BlitzFunction2_t pServerResponded, BP_BlitzFunction1_t pServerFailedToRespond)
	: m_pData(pData), m_pServerResponded(pServerResponded), m_pServerFailedToRespond(pServerFailedToRespond) {}

void BlitzISteamMatchmakingPingResponse::ServerResponded(gameserveritem_t &server) {
	if (this->m_pServerResponded != nullptr)
		BP_CallFunction2(m_pServerResponded, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(&server));
}

void BlitzISteamMatchmakingPingResponse::ServerFailedToRespond() {
	if (this->m_pServerFailedToRespond != nullptr)
		BP_CallFunction1(m_pServerFailedToRespond, reinterpret_cast<int32_t>(m_pData));
}

DLL(BlitzISteamMatchmakingPingResponse*) BS_ISteamMatchmakingPingResponse_New(void* pData, BP_BlitzFunction2_t pServerResponded, BP_BlitzFunction1_t pServerFailedToRespond) {
	return new BlitzISteamMatchmakingPingResponse(pData, pServerResponded, pServerFailedToRespond);
}

DLL(void) BS_ISteamMatchmakingPingResponse_Destroy(BlitzISteamMatchmakingPingResponse* pThis) {
	delete pThis;
}

//////////////////////////////////////////////////////////////////////////
BlitzISteamMatchmakingPlayersResponse::BlitzISteamMatchmakingPlayersResponse(void* pData, BP_BlitzFunction4_t pAddPlayerToList, BP_BlitzFunction1_t pPlayersFailedToRespond, BP_BlitzFunction1_t pPlayersRefreshComplete)
	: m_pData(pData), m_pAddPlayerToList(pAddPlayerToList), m_pPlayersFailedToRespond(pPlayersFailedToRespond), m_pPlayersRefreshComplete(pPlayersRefreshComplete) {}

void BlitzISteamMatchmakingPlayersResponse::AddPlayerToList(const char *pchName, int nScore, float flTimePlayed) {
	if (m_pAddPlayerToList != nullptr)
		BP_CallFunction4(m_pAddPlayerToList, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(pchName), nScore, *reinterpret_cast<int32_t*>(&flTimePlayed));
}

void BlitzISteamMatchmakingPlayersResponse::PlayersFailedToRespond() {
	if (m_pPlayersFailedToRespond != nullptr)
		BP_CallFunction1(m_pPlayersFailedToRespond, reinterpret_cast<int32_t>(m_pData));
}

void BlitzISteamMatchmakingPlayersResponse::PlayersRefreshComplete() {
	if (m_pPlayersRefreshComplete != nullptr)
		BP_CallFunction1(m_pPlayersRefreshComplete, reinterpret_cast<int32_t>(m_pData));
}

DLL(BlitzISteamMatchmakingPlayersResponse*) BS_ISteamMatchmakingPlayersResponse_New(void* pData, BP_BlitzFunction4_t pAddPlayerToList, BP_BlitzFunction1_t pPlayersFailedToRespond, BP_BlitzFunction1_t pPlayersRefreshComplete) {
	return new BlitzISteamMatchmakingPlayersResponse(pData, pAddPlayerToList, pPlayersFailedToRespond, pPlayersRefreshComplete);
}

DLL(void) BS_ISteamMatchmakingPlayersResponse_Destroy(BlitzISteamMatchmakingPlayersResponse* pThis) {
	delete pThis;
}

//////////////////////////////////////////////////////////////////////////
BlitzISteamMatchmakingRulesResponse::BlitzISteamMatchmakingRulesResponse(void* pData, BP_BlitzFunction3_t pRulesResponded, BP_BlitzFunction1_t pRulesFailedToRespond, BP_BlitzFunction1_t pRulesRefreshComplete)
	: m_pData(pData), m_pRulesResponded(pRulesResponded), m_pRulesFailedToRespond(pRulesFailedToRespond), m_pRulesRefreshComplete(pRulesRefreshComplete) {}

void BlitzISteamMatchmakingRulesResponse::RulesResponded(const char *pchRule, const char *pchValue) {
	if (this->m_pRulesResponded != nullptr)
		BP_CallFunction3(m_pRulesResponded, reinterpret_cast<int32_t>(m_pData), reinterpret_cast<int32_t>(pchRule), reinterpret_cast<int32_t>(pchValue));
}

void BlitzISteamMatchmakingRulesResponse::RulesFailedToRespond() {
	if (this->m_pRulesFailedToRespond != nullptr)
		BP_CallFunction1(m_pRulesFailedToRespond, reinterpret_cast<int32_t>(m_pData));
}

void BlitzISteamMatchmakingRulesResponse::RulesRefreshComplete() {
	if (this->m_pRulesRefreshComplete != nullptr)
		BP_CallFunction1(m_pRulesRefreshComplete, reinterpret_cast<int32_t>(m_pData));
}

DLL(BlitzISteamMatchmakingRulesResponse*) BS_ISteamMatchmakingRulesResponse_New(void* pData, BP_BlitzFunction3_t pRulesResponded, BP_BlitzFunction1_t pRulesFailedToRespond, BP_BlitzFunction1_t pRulesRefreshComplete) {
	return new BlitzISteamMatchmakingRulesResponse(pData, pRulesResponded, pRulesFailedToRespond, pRulesRefreshComplete);
}

DLL(void) BS_ISteamMatchmakingRulesResponse_Destroy(BlitzISteamMatchmakingRulesResponse* pThis) {
	delete pThis;
}

//////////////////////////////////////////////////////////////////////////
char* BS_TGameServerItem_CharBuffer = new char[128];

DLL(const char*) BS_TGameServerItem_GetName(gameserveritem_t* pThis) {
	strcpy(BS_TGameServerItem_CharBuffer, pThis->GetName());
	return BS_TGameServerItem_CharBuffer;
}

DLL(void) BS_TGameServerItem_SetName(gameserveritem_t* pThis, const char* cName) {
	pThis->SetName(cName);
}

///< IP/Query Port/Connection Port for this server
DLL(servernetadr_t*) BS_TGameServerItem_NetAdr(gameserveritem_t* pThis) {
	return &(pThis->m_NetAdr);
}

///< current ping time in milliseconds
DLL(int) BS_TGameServerItem_Ping(gameserveritem_t* pThis) {
	return pThis->m_nPing;
}

///< server has responded successfully in the past
DLL(bool) BS_TGameServerItem_HadSuccessfulResponse(gameserveritem_t* pThis) {
	return pThis->m_bHadSuccessfulResponse;
}

///< server is marked as not responding and should no longer be refreshed
DLL(bool) BS_TGameServerItem_DoNotRefresh(gameserveritem_t* pThis) {
	return pThis->m_bDoNotRefresh;
}

///< current game directory
DLL(const char*) BS_TGameServerItem_GameDir(gameserveritem_t* pThis) {
	strcpy(BS_TGameServerItem_CharBuffer, pThis->m_szGameDir);
	return BS_TGameServerItem_CharBuffer;
}

///< current map
DLL(const char*) BS_TGameServerItem_Map(gameserveritem_t* pThis) {
	strcpy(BS_TGameServerItem_CharBuffer, pThis->m_szMap);
	return BS_TGameServerItem_CharBuffer;
}

///< game description
DLL(const char*) BS_TGameServerItem_GameDescription(gameserveritem_t* pThis) {
	strcpy(BS_TGameServerItem_CharBuffer, pThis->m_szGameDescription);
	return BS_TGameServerItem_CharBuffer;
}

///< Steam App ID of this server
DLL(uint32_t) BS_TGameServerItem_AppId(gameserveritem_t* pThis) {
	return pThis->m_nAppID;
}

///< total number of players currently on the server.  INCLUDES BOTS!!
DLL(uint32_t) BS_TGameServerItem_Players(gameserveritem_t* pThis) {
	return pThis->m_nPlayers;
}

///< Maximum players that can join this server
DLL(uint32_t) BS_TGameServerItem_MaxPlayers(gameserveritem_t* pThis) {
	return pThis->m_nMaxPlayers;
}

///< Number of bots (i.e simulated players) on this server
DLL(uint32_t) BS_TGameServerItem_BotPlayers(gameserveritem_t* pThis) {
	return pThis->m_nBotPlayers;
}

///< true if this server needs a password to join
DLL(bool) BS_TGameServerItem_Password(gameserveritem_t* pThis) {
	return pThis->m_bPassword;
}

///< Is this server protected by VAC
DLL(bool) BS_TGameServerItem_Secure(gameserveritem_t* pThis) {
	return pThis->m_bSecure;
}

///< time (in unix time) when this server was last played on (for favorite/history servers)
DLL(uint32_t) BS_TGameServerItem_TimeLastPlayed(gameserveritem_t* pThis) {
	return pThis->m_ulTimeLastPlayed;
}

///< server version as reported to Steam
DLL(uint32_t) BS_TGameServerItem_ServerVersion(gameserveritem_t* pThis) {
	return pThis->m_nServerVersion;
}

/// the tags this server exposes
DLL(const char*) BS_TGameServerItem_GameTags(gameserveritem_t* pThis) {
	strcpy(BS_TGameServerItem_CharBuffer, pThis->m_szGameTags);
	return BS_TGameServerItem_CharBuffer;
}

/// steamID of the game server - invalid if it's doesn't have one (old server, or not connected to Steam)
DLL(CSteamID*) BS_TGameServerItem_SteamID(gameserveritem_t* pThis) {
	return &(pThis->m_steamID);
}

//////////////////////////////////////////////////////////////////////////
char* BS_TServerNetAdr_CharBuffer = new char[128];

DLL(void) BS_TServerNetAdr_Set(servernetadr_t* pThis, servernetadr_t* pThat) {
	*pThis = *pThat;
}

DLL(void) BS_TServerNetAdr_Init(servernetadr_t* pThis, uint32_t iIP, uint16_t iQueryPort, uint16_t iConnectionPort) {
	pThis->Init(iIP, iQueryPort, iConnectionPort);
}

DLL(uint16_t) BS_TServerNetAdr_GetQueryPort(servernetadr_t* pThis) {
	return pThis->GetQueryPort();
}

DLL(void) BS_TServerNetAdr_SetQueryPort(servernetadr_t* pThis, uint16_t iPort) {
	pThis->SetQueryPort(iPort);
}

DLL(uint16_t) BS_TServerNetAdr_GetConnectionPort(servernetadr_t* pThis) {
	return pThis->GetConnectionPort();
}

DLL(void) BS_TServerNetAdr_SetConnectionPort(servernetadr_t* pThis, uint16_t iPort) {
	pThis->SetConnectionPort(iPort);
}

DLL(uint32_t) BS_TServerNetAdr_GetIP(servernetadr_t* pThis) {
	return pThis->GetIP();
}

DLL(void) BS_TServerNetAdr_SetIP(servernetadr_t* pThis, uint32_t iIP) {
	pThis->SetIP(iIP);
}

DLL(const char*) BS_TServerNetAdr_GetConnectionAddressString(servernetadr_t* pThis) {
	strcpy(BS_TServerNetAdr_CharBuffer, pThis->GetConnectionAddressString());
	return BS_TServerNetAdr_CharBuffer;
}

DLL(const char*) BS_TServerNetAdr_GetQueryAddressString(servernetadr_t* pThis) {
	strcpy(BS_TServerNetAdr_CharBuffer, pThis->GetQueryAddressString());
	return BS_TServerNetAdr_CharBuffer;
}

DLL(uint32_t) BS_TServerNetAdr_Compare(servernetadr_t* pThis, servernetadr_t* pThat) {
	return (pThis < pThat ? -1 : (pThis > pThat ? 1 : 0));
}