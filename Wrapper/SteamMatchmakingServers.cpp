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

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
//-----------------------------------------------------------------------------
DLL(ISteamMatchmakingServers*) BS_SteamMatchmakingServers() {
	return SteamMatchmakingServers();
}

// Request a new list of servers of a particular type.  These calls each correspond to one of the EMatchMakingType values.
// Each call allocates a new asynchronous request object.
// Request object must be released by calling ReleaseRequest( hServerListRequest )
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestInternetServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestLANServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestLANServerList(iApp, pRequestServersResponse);
}
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestFriendsServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestFavoritesServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestHistoryServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
DLL(HServerListRequest) BS_ISteamMatchmakingServers_RequestSpectatorServerList(ISteamMatchmakingServers* pThis, AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return pThis->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

// Releases the asynchronous request object and cancels any pending query on it if there's a pending query in progress.
// RefreshComplete callback is not posted when request is released.
DLL(void) BS_ISteamMatchmakingServers_ReleaseRequest(ISteamMatchmakingServers* pThis, HServerListRequest hServerListRequest) {
	pThis->ReleaseRequest(hServerListRequest);
}

/* the filter operation codes that go in the key part of MatchMakingKeyValuePair_t should be one of these:

"map"
- Server passes the filter if the server is playing the specified map.
"gamedataand"
- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains all of the
specified strings.  The value field is a comma-delimited list of strings to match.
"gamedataor"
- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) contains at least one of the
specified strings.  The value field is a comma-delimited list of strings to match.
"gamedatanor"
- Server passes the filter if the server's game data (ISteamGameServer::SetGameData) does not contain any
of the specified strings.  The value field is a comma-delimited list of strings to check.
"gametagsand"
- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) contains all
of the specified strings.  The value field is a comma-delimited list of strings to check.
"gametagsnor"
- Server passes the filter if the server's game tags (ISteamGameServer::SetGameTags) does not contain any
of the specified strings.  The value field is a comma-delimited list of strings to check.
"and" (x1 && x2 && ... && xn)
"or" (x1 || x2 || ... || xn)
"nand" !(x1 && x2 && ... && xn)
"nor" !(x1 || x2 || ... || xn)
- Performs Boolean operation on the following filters.  The operand to this filter specifies
the "size" of the Boolean inputs to the operation, in Key/value pairs.  (The keyvalue
pairs must immediately follow, i.e. this is a prefix logical operator notation.)
In the simplest case where Boolean expressions are not nested, this is simply
the number of operands.

For example, to match servers on a particular map or with a particular tag, would would
use these filters.

( server.map == "cp_dustbowl" || server.gametags.contains("payload") )
"or", "2"
"map", "cp_dustbowl"
"gametagsand", "payload"

If logical inputs are nested, then the operand specifies the size of the entire
"length" of its operands, not the number of immediate children.

( server.map == "cp_dustbowl" || ( server.gametags.contains("payload") && !server.gametags.contains("payloadrace") ) )
"or", "4"
"map", "cp_dustbowl"
"and", "2"
"gametagsand", "payload"
"gametagsnor", "payloadrace"

Unary NOT can be achieved using either "nand" or "nor" with a single operand.

"addr"
- Server passes the filter if the server's query address matches the specified IP or IP:port.
"gameaddr"
- Server passes the filter if the server's game address matches the specified IP or IP:port.

The following filter operations ignore the "value" part of MatchMakingKeyValuePair_t

"dedicated"
- Server passes the filter if it passed true to SetDedicatedServer.
"secure"
- Server passes the filter if the server is VAC-enabled.
"notfull"
- Server passes the filter if the player count is less than the reported max player count.
"hasplayers"
- Server passes the filter if the player count is greater than zero.
"noplayers"
- Server passes the filter if it doesn't have any players.
"linux"
- Server passes the filter if it's a linux server
*/

// Get details on a given server in the list, you can get the valid range of index
// values by calling GetServerCount().  You will also receive index values in 
// ISteamMatchmakingServerListResponse::ServerResponded() callbacks
DLL(gameserveritem_t*) BS_ISteamMatchmakingServers_GetServerDetails(ISteamMatchmakingServers* pThis, HServerListRequest hRequest, int iServer) {
	return pThis->GetServerDetails(hRequest, iServer);
}

// Cancel an request which is operation on the given list type.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above list request calls.  Not doing so may result in a crash when a callback
// occurs on the destructed object.
// Canceling a query does not release the allocated request handle.
// The request handle must be released using ReleaseRequest( hRequest )
DLL(void) BS_ISteamMatchmakingServers_CancelQuery(ISteamMatchmakingServers* pThis, HServerListRequest hRequest) {
	pThis->CancelQuery(hRequest);
}

// Ping every server in your list again but don't update the list of servers
// Query callback installed when the server list was requested will be used
// again to post notifications and RefreshComplete, so the callback must remain
// valid until another RefreshComplete is called on it or the request
// is released with ReleaseRequest( hRequest )
DLL(void) BS_ISteamMatchmakingServers_RefreshQuery(ISteamMatchmakingServers* pThis, HServerListRequest hRequest) {
	pThis->RefreshQuery(hRequest);
}

// Returns true if the list is currently refreshing its server list
DLL(bool) BS_ISteamMatchmakingServers_IsRefreshing(ISteamMatchmakingServers* pThis, HServerListRequest hRequest) {
	return pThis->IsRefreshing(hRequest);
}

// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
DLL(int) BS_ISteamMatchmakingServers_GetServerCount(ISteamMatchmakingServers* pThis, HServerListRequest hRequest) {
	return pThis->GetServerCount(hRequest);
}

// Refresh a single server inside of a query (rather than all the servers )
DLL(void) BS_ISteamMatchmakingServers_RefreshServer(ISteamMatchmakingServers* pThis, HServerListRequest hRequest, int iServer) {
	pThis->RefreshServer(hRequest, iServer);
}


//-----------------------------------------------------------------------------
// Queries to individual servers directly via IP/Port
//-----------------------------------------------------------------------------

// Request updated ping time and other details from a single server
DLL(HServerQuery) BS_ISteamMatchmakingServers_PingServer(ISteamMatchmakingServers* pThis, uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse) {
	return pThis->PingServer(unIP, usPort, pRequestServersResponse);
}

// Request the list of players currently playing on a server
DLL(HServerQuery) BS_ISteamMatchmakingServers_PlayerDetails(ISteamMatchmakingServers* pThis, uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse) {
	return pThis->PlayerDetails(unIP, usPort, pRequestServersResponse);
}

// Request the list of rules that the server is running (See ISteamGameServer::SetKeyValue() to set the rules server side)
DLL(HServerQuery) BS_ISteamMatchmakingServers_ServerRules(ISteamMatchmakingServers* pThis, uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse) {
	return pThis->ServerRules(unIP, usPort, pRequestServersResponse);
}

// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
// any in-progress requests before destructing a callback object that may have been passed 
// to one of the above calls to avoid crashing when callbacks occur.
DLL(void) BS_ISteamMatchmakingServers_CancelServerQuery(ISteamMatchmakingServers* pThis, HServerQuery hServerQuery) {
	pThis->CancelServerQuery(hServerQuery);
}