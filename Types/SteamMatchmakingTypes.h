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

#pragma once
#include "BlitzSteamInternal.h"
#include "../Helpers/BlitzPointer.h"

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after a server list refresh
// or an individual server update.
//
// Since you get these callbacks after requesting full list refreshes you will
// usually implement this interface inside an object like CServerBrowser.  If that
// object is getting destructed you should use ISteamMatchMakingServers()->CancelQuery()
// to cancel any in-progress queries so you don't get a callback into the destructed
// object and crash.
//-----------------------------------------------------------------------------
class BlitzISteamMatchmakingServerListResponse : public ISteamMatchmakingServerListResponse {
private:
	void* m_pData;

	BP_BlitzFunction3_t m_pServerResponded;
	BP_BlitzFunction3_t m_pServerFailedToRespond;
	BP_BlitzFunction3_t m_pRefreshComplete;
public:
	BlitzISteamMatchmakingServerListResponse(void* pData, BP_BlitzFunction3_t pServerResponded, BP_BlitzFunction3_t pServerFailedToRespond, BP_BlitzFunction3_t pRefreshComplete);

	// Server has responded ok with updated data
	virtual void ServerResponded(HServerListRequest hRequest, int iServer) override;
	// Server has failed to respond
	virtual void ServerFailedToRespond(HServerListRequest hRequest, int iServer) override;
	// A list refresh you had initiated is now 100% completed
	virtual void RefreshComplete(HServerListRequest hRequest, EMatchMakingServerResponse response) override;
};

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after pinging an individual server 
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->PingServer() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
class BlitzISteamMatchmakingPingResponse : public ISteamMatchmakingPingResponse {
private:
	void* m_pData;

	BP_BlitzFunction2_t m_pServerResponded;
	BP_BlitzFunction1_t m_pServerFailedToRespond;
public:
	BlitzISteamMatchmakingPingResponse(void* pData, BP_BlitzFunction2_t pServerResponded, BP_BlitzFunction1_t pServerFailedToRespond);

	// Server has responded successfully and has updated data
	virtual void ServerResponded(gameserveritem_t &server) override;
	// Server failed to respond to the ping request
	virtual void ServerFailedToRespond() override;
};

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting details on
// who is playing on a particular server.
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->PlayerDetails() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
class BlitzISteamMatchmakingPlayersResponse : public ISteamMatchmakingPlayersResponse {
private:
	void* m_pData;

	BP_BlitzFunction4_t m_pAddPlayerToList;
	BP_BlitzFunction1_t m_pPlayersFailedToRespond;
	BP_BlitzFunction1_t m_pPlayersRefreshComplete;

public:
	BlitzISteamMatchmakingPlayersResponse(void* pData, BP_BlitzFunction4_t pAddPlayerToList, BP_BlitzFunction1_t pPlayersFailedToRespond, BP_BlitzFunction1_t pPlayersRefreshComplete);

	// Got data on a new player on the server -- you'll get this callback once per player
	// on the server which you have requested player data on.
	virtual void AddPlayerToList(const char *pchName, int nScore, float flTimePlayed) override;
	// The server failed to respond to the request for player details
	virtual void PlayersFailedToRespond() override;
	// The server has finished responding to the player details request 
	// (ie, you won't get anymore AddPlayerToList callbacks)
	virtual void PlayersRefreshComplete() override;
};

//-----------------------------------------------------------------------------
// Purpose: Callback interface for receiving responses after requesting rules
// details on a particular server.
//
// These callbacks all occur in response to querying an individual server
// via the ISteamMatchmakingServers()->ServerRules() call below.  If you are 
// destructing an object that implements this interface then you should call 
// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
// which is in progress.  Failure to cancel in progress queries when destructing
// a callback handler may result in a crash when a callback later occurs.
//-----------------------------------------------------------------------------
class BlitzISteamMatchmakingRulesResponse : public ISteamMatchmakingRulesResponse {
private:
	void* m_pData;

	BP_BlitzFunction3_t m_pRulesResponded;
	BP_BlitzFunction1_t m_pRulesFailedToRespond, m_pRulesRefreshComplete;

public:
	BlitzISteamMatchmakingRulesResponse(void* pData, BP_BlitzFunction3_t pRulesResponded, BP_BlitzFunction1_t pRulesFailedToRespond, BP_BlitzFunction1_t pRulesRefreshComplete);

	// Got data on a rule on the server -- you'll get one of these per rule defined on
	// the server you are querying
	virtual void RulesResponded(const char *pchRule, const char *pchValue) override;

	// The server failed to respond to the request for rule details
	virtual void RulesFailedToRespond() override;

	// The server has finished responding to the rule details request 
	// (ie, you won't get anymore RulesResponded callbacks)
	virtual void RulesRefreshComplete() override;
};