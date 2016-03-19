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

DLL(ISteamMatchmaking*) BS_SteamMatchmaking() {
	return SteamMatchmaking();
}


// game server favorites storage
// saves basic details about a multiplayer game server locally

// returns the number of favorites servers the user has stored
DLL(int32_t) BS_ISteamMatchmaking_GetFavoriteGameCount(ISteamMatchmaking* pThis) {
	return pThis->GetFavoriteGameCount();
}

// returns the details of the game server
// iGame is of range [0,GetFavoriteGameCount())
// *pnIP, *pnConnPort are filled in the with IP:port of the game server
// *punFlags specify whether the game server was stored as an explicit favorite or in the history of connections
// *pRTime32LastPlayedOnServer is filled in the with the Unix time the favorite was added
DLL(int32_t) BS_ISteamMatchmaking_GetFavoriteGame(ISteamMatchmaking* pThis, int32_t iGame,
	AppId_t *pnAppID, uint32_t *pnIP, uint16_t *pnConnPort, uint16_t *pnQueryPort,
	uint32_t *punFlags, uint32_t *pRTime32LastPlayedOnServer) {
	return pThis->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
}

// adds the game server to the local list; updates the time played of the server if it already exists in the list
DLL(int) BS_ISteamMatchmaking_AddFavoriteGame(ISteamMatchmaking* pThis, AppId_t nAppID,	uint32 nIP, uint16 nConnPort,
	uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) {
	return pThis->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
}

// removes the game server from the local storage; returns true if one was removed
DLL(bool) BS_ISteamMatchmaking_RemoveFavoriteGame(ISteamMatchmaking* pThis, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags) {
	return pThis->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
}

///////
// Game lobby functions

// Get a list of relevant lobbies
// this is an asynchronous request
// results will be returned by LobbyMatchList_t callback & call result, with the number of lobbies found
// this will never return lobbies that are full
// to add more filter, the filter calls below need to be call before each and every RequestLobbyList() call
// use the CCallResult<> object in steam_api.h to match the SteamAPICall_t call result to a function in an object, e.g.
/*
class CMyLobbyListManager
{
CCallResult<CMyLobbyListManager, LobbyMatchList_t> m_CallResultLobbyMatchList;
void FindLobbies()
{
// SteamMatchmaking()->AddRequestLobbyListFilter*() functions would be called here, before RequestLobbyList()
SteamAPICall_t hSteamAPICall = SteamMatchmaking()->RequestLobbyList();
m_CallResultLobbyMatchList.Set( hSteamAPICall, this, &CMyLobbyListManager::OnLobbyMatchList );
}

void OnLobbyMatchList( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
{
// lobby list has be retrieved from Steam back-end, use results
}
}
*/
// 
//CALL_RESULT(LobbyMatchList_t)
DLL(SteamAPICall_t) BS_ISteamMatchmaking_RequestLobbyList(ISteamMatchmaking* pThis) {
	return pThis->RequestLobbyList();
}
// filters for lobbies
// this needs to be called before RequestLobbyList() to take effect
// these are cleared on each call to RequestLobbyList()
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListStringFilter(ISteamMatchmaking* pThis, const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType) {
	pThis->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
}
// numerical comparison
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(ISteamMatchmaking* pThis, const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType) {
	pThis->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}
// returns results closest to the specified value. Multiple near filters can be added, with early filters taking precedence
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(ISteamMatchmaking* pThis, const char *pchKeyToMatch, int nValueToBeCloseTo) {
	pThis->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}
// returns only lobbies with the specified number of slots available
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(ISteamMatchmaking* pThis, int nSlotsAvailable) {
	pThis->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}
// sets the distance for which we should search for lobbies (based on users IP address to location map on the Steam backed)
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(ISteamMatchmaking* pThis, ELobbyDistanceFilter eLobbyDistanceFilter) {
	pThis->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}
// sets how many results to return, the lower the count the faster it is to download the lobby results & details to the client
DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(ISteamMatchmaking* pThis, int cMaxResults) {
	pThis->AddRequestLobbyListResultCountFilter(cMaxResults);
}

DLL(void) BS_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	pThis->AddRequestLobbyListCompatibleMembersFilter(*steamIDLobby);
}

// returns the CSteamID* of a lobby, as retrieved by a RequestLobbyList call
// should only be called after a LobbyMatchList_t callback is received
// iLobby is of the range [0, LobbyMatchList_t::m_nLobbiesMatching)
// the returned CSteamID*::IsValid() will be false if iLobby is out of range
DLL(CSteamID*) BS_ISteamMatchmaking_GetLobbyByIndex(ISteamMatchmaking* pThis, int iLobby) {
	return &(pThis->GetLobbyByIndex(iLobby));
}

// Create a lobby on the Steam servers.
// If private, then the lobby will not be returned by any RequestLobbyList() call; the CSteamID*
// of the lobby will need to be communicated via game channels or via InviteUserToLobby()
// this is an asynchronous request
// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this point
// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
//CALL_RESULT(LobbyCreated_t)
DLL(SteamAPICall_t) BS_ISteamMatchmaking_CreateLobby(ISteamMatchmaking* pThis, ELobbyType eLobbyType, int cMaxMembers) {
	return pThis->CreateLobby(eLobbyType, cMaxMembers);
}

// Joins an existing lobby
// this is an asynchronous request
// results will be returned by LobbyEnter_t callback & call result, check m_EChatRoomEnterResponse to see if was successful
// lobby metadata is available to use immediately on this call completing
//CALL_RESULT(LobbyEnter_t)
DLL(SteamAPICall_t) BS_ISteamMatchmaking_JoinLobby(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->JoinLobby(*steamIDLobby);
}

// Leave a lobby; this will take effect immediately on the client side
// other users in the lobby will be notified by a LobbyChatUpdate_t callback
DLL(void) BS_ISteamMatchmaking_LeaveLobby(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->LeaveLobby(*steamIDLobby);
}

// Invite another user to the lobby
// the target user will receive a LobbyInvite_t callback
// will return true if the invite is successfully sent, whether or not the target responds
// returns false if the local user is not connected to the Steam servers
// if the other user clicks the join link, a GameLobbyJoinRequested_t will be posted if the user is in-game,
// or if the game isn't running yet the game will be launched with the parameter +connect_lobby <64-bit lobby id>
DLL(bool) BS_ISteamMatchmaking_InviteUserToLobby(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, CSteamID* steamIDInvitee) {
	return pThis->InviteUserToLobby(*steamIDLobby, *steamIDInvitee);
}

// Lobby iteration, for viewing details of users in a lobby
// only accessible if the lobby user is a member of the specified lobby
// persona information for other lobby members (name, avatar, etc.) will be asynchronously received
// and accessible via ISteamFriends interface

// returns the number of users in the specified lobby
DLL(int) BS_ISteamMatchmaking_GetNumLobbyMembers(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->GetNumLobbyMembers(*steamIDLobby);
}
// returns the CSteamID* of a user in the lobby
// iMember is of range [0,GetNumLobbyMembers())
// note that the current user must be in a lobby to retrieve CSteamID*s of other users in that lobby
DLL(CSteamID*) BS_ISteamMatchmaking_GetLobbyMemberByIndex(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, int iMember) {
	return &(pThis->GetLobbyMemberByIndex(*steamIDLobby, iMember));
}

// Get data associated with this lobby
// takes a simple key, and returns the string associated with it
// "" will be returned if no value is set, or if steamIDLobby is invalid
DLL(const char*) BS_ISteamMatchmaking_GetLobbyData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, const char *pchKey) {
	return pThis->GetLobbyData(*steamIDLobby, pchKey);
}
// Sets a key/value pair in the lobby metadata
// each user in the lobby will be broadcast this new value, and any new users joining will receive any existing data
// this can be used to set lobby names, map, etc.
// to reset a key, just set it to ""
// other users in the lobby will receive notification of the lobby data change via a LobbyDataUpdate_t callback
DLL(bool) BS_ISteamMatchmaking_SetLobbyData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, const char *pchKey, const char *pchValue) {
	return pThis->SetLobbyData(*steamIDLobby, pchKey, pchValue);
}

// returns the number of metadata keys set on the specified lobby
DLL(int) BS_ISteamMatchmaking_GetLobbyDataCount(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->GetLobbyDataCount(*steamIDLobby);
}

// returns a lobby metadata key/values pair by index, of range [0, GetLobbyDataCount())
DLL(bool) BS_ISteamMatchmaking_GetLobbyDataByIndex(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize) {
	return pThis->GetLobbyDataByIndex(*steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
}

// removes a metadata key from the lobby
DLL(bool) BS_ISteamMatchmaking_DeleteLobbyData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, const char *pchKey) {
	return pThis->DeleteLobbyData(*steamIDLobby, pchKey);
}

// Gets per-user metadata for someone in this lobby
DLL(const char*) BS_ISteamMatchmaking_GetLobbyMemberData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, CSteamID* steamIDUser, const char *pchKey) {
	return pThis->GetLobbyMemberData(*steamIDLobby, *steamIDUser, pchKey);
}
// Sets per-user metadata (for the local user implicitly)
DLL(void) BS_ISteamMatchmaking_SetLobbyMemberData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, const char *pchKey, const char *pchValue) {
	pThis->SetLobbyMemberData(*steamIDLobby, pchKey, pchValue);
}

// Broadcasts a chat message to the all the users in the lobby
// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
// returns true if the message is successfully sent
// pvMsgBody can be binary or text data, up to 4k
// if pvMsgBody is text, cubMsgBody should be strlen( text ) + 1, to include the null terminator
DLL(bool) BS_ISteamMatchmaking_SendLobbyChatMsg(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, const void *pvMsgBody, int cubMsgBody) {
	return pThis->SendLobbyChatMsg(*steamIDLobby, pvMsgBody, cubMsgBody);
}
// Get a chat message as specified in a LobbyChatMsg_t callback
// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
// *pSteamIDUser is filled in with the CSteamID* of the member
// *pvData is filled in with the message itself
// return value is the number of bytes written into the buffer
DLL(int) BS_ISteamMatchmaking_GetLobbyChatEntry(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, int iChatID, OUT_STRUCT() CSteamID* *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType) {
	return pThis->GetLobbyChatEntry(*steamIDLobby, iChatID, *pSteamIDUser, pvData, cubData, peChatEntryType);
}

// Refreshes metadata for a lobby you're not necessarily in right now
// you never do this for lobbies you're a member of, only if your
// this will send down all the metadata associated with a lobby
// this is an asynchronous call
// returns false if the local user is not connected to the Steam servers
// results will be returned by a LobbyDataUpdate_t callback
// if the specified lobby doesn't exist, LobbyDataUpdate_t::m_bSuccess will be set to false
DLL(bool) BS_ISteamMatchmaking_RequestLobbyData(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->RequestLobbyData(*steamIDLobby);
}

// sets the game server associated with the lobby
// usually at this point, the users will join the specified game server
// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
DLL(void) BS_ISteamMatchmaking_SetLobbyGameServer(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID* steamIDGameServer) {
	pThis->SetLobbyGameServer(*steamIDLobby, unGameServerIP, unGameServerPort, *steamIDGameServer);
}

// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
DLL(bool) BS_ISteamMatchmaking_GetLobbyGameServer(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, OUT_STRUCT() CSteamID* *psteamIDGameServer) {
	return pThis->GetLobbyGameServer(*steamIDLobby, punGameServerIP, punGameServerPort, *psteamIDGameServer);
}

// set the limit on the # of users who can join the lobby
DLL(bool) BS_ISteamMatchmaking_SetLobbyMemberLimit(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, int cMaxMembers) {
	return pThis->SetLobbyMemberLimit(*steamIDLobby, cMaxMembers);
}

// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
DLL(int) BS_ISteamMatchmaking_GetLobbyMemberLimit(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return pThis->GetLobbyMemberLimit(*steamIDLobby);
}

// updates which type of lobby it is
// only lobbies that are k_ELobbyTypePublic or k_ELobbyTypeInvisible, and are set to joinable, will be returned by RequestLobbyList() calls
DLL(bool) BS_ISteamMatchmaking_SetLobbyType(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, ELobbyType eLobbyType) {
	return pThis->SetLobbyType(*steamIDLobby, eLobbyType);
}

// sets whether or not a lobby is joinable - defaults to true for a new lobby
// if set to false, no user can join, even if they are a friend or have been invited
DLL(bool) BS_ISteamMatchmaking_SetLobbyJoinable(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, bool bLobbyJoinable) {
	return pThis->SetLobbyJoinable(*steamIDLobby, bLobbyJoinable);
}

// returns the current lobby owner
// you must be a member of the lobby to access this
// there always one lobby owner - if the current owner leaves, another user will become the owner
// it is possible (bur rare) to join a lobby just as the owner is leaving, thus entering a lobby with self as the owner
DLL(CSteamID*) BS_ISteamMatchmaking_GetLobbyOwner(ISteamMatchmaking* pThis, CSteamID* steamIDLobby) {
	return &(pThis->GetLobbyOwner(*steamIDLobby));
}

// changes who the lobby owner is
// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
// after completion, the local user will no longer be the owner
DLL(bool) BS_ISteamMatchmaking_SetLobbyOwner(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, CSteamID* steamIDNewOwner) {
	return pThis->SetLobbyOwner(*steamIDLobby, *steamIDNewOwner);
}

// link two lobbies for the purposes of checking player compatibility
// you must be the lobby owner of both lobbies
DLL(bool) BS_ISteamMatchmaking_SetLinkedLobby(ISteamMatchmaking* pThis, CSteamID* steamIDLobby, CSteamID* steamIDLobbyDependent) {
	return pThis->SetLinkedLobby(*steamIDLobby, *steamIDLobbyDependent);
}