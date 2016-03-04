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

DLL_FUNCTION(ISteamMatchmakingServers*) BS_MatchmakingServers() {
	return SteamMatchmakingServers();
}

DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestInternetServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppkvFilter, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	return SteamMatchmakingServers()->RequestInternetServerList(iApp, ppkvFilter, nFilters, pRequestServersResponse);
}
/*DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestLANServerList(AppId_t iApp, const char** ppchFilters, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {
	//return SteamMatchmakingServers()->RequestLANServerList(iApp);
}
DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestFriendsServerList(AppId_t iApp, const char** ppchFilters, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {

}
DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestFavoritesServerList(AppId_t iApp, const char** ppchFilters, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {

}
DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestHistoryServerList(AppId_t iApp, const char** ppchFilters, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {

}
DLL_FUNCTION(HServerListRequest) BS_MathmakingServers_RequestSpectatorServerList(AppId_t iApp, const char** ppchFilters, uint32_t nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse) {

}*/

//
//
//// Releases the asynchronous request object and cancels any pending query on it if there's a pending query in progress.
//// RefreshComplete callback is not posted when request is released.
//virtual void ReleaseRequest( HServerListRequest hServerListRequest ) = 0;
//
//// Get details on a given server in the list, you can get the valid range of index
//// values by calling GetServerCount().  You will also receive index values in 
//// ISteamMatchmakingServerListResponse::ServerResponded() callbacks
//virtual gameserveritem_t *GetServerDetails( HServerListRequest hRequest, int iServer ) = 0; 
//
//// Cancel an request which is operation on the given list type.  You should call this to cancel
//// any in-progress requests before destructing a callback object that may have been passed 
//// to one of the above list request calls.  Not doing so may result in a crash when a callback
//// occurs on the destructed object.
//// Canceling a query does not release the allocated request handle.
//// The request handle must be released using ReleaseRequest( hRequest )
//virtual void CancelQuery( HServerListRequest hRequest ) = 0; 
//
//// Ping every server in your list again but don't update the list of servers
//// Query callback installed when the server list was requested will be used
//// again to post notifications and RefreshComplete, so the callback must remain
//// valid until another RefreshComplete is called on it or the request
//// is released with ReleaseRequest( hRequest )
//virtual void RefreshQuery( HServerListRequest hRequest ) = 0; 
//
//// Returns true if the list is currently refreshing its server list
//virtual bool IsRefreshing( HServerListRequest hRequest ) = 0; 
//
//// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
//virtual int GetServerCount( HServerListRequest hRequest ) = 0; 
//
//// Refresh a single server inside of a query (rather than all the servers )
//virtual void RefreshServer( HServerListRequest hRequest, int iServer ) = 0; 
//
//
////-----------------------------------------------------------------------------
//// Queries to individual servers directly via IP/Port
////-----------------------------------------------------------------------------
//
//// Request updated ping time and other details from a single server
//virtual HServerQuery PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse ) = 0; 
//
//// Request the list of players currently playing on a server
//virtual HServerQuery PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse ) = 0;
//
//// Request the list of rules that the server is running (See ISteamGameServer::SetKeyValue() to set the rules server side)
//virtual HServerQuery ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse ) = 0; 
//
//// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
//// any in-progress requests before destructing a callback object that may have been passed 
//// to one of the above calls to avoid crashing when callbacks occur.
//virtual void CancelServerQuery( HServerQuery hServerQuery ) = 0; 