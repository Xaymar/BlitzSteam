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

// Initialize ISteamGameServer interface object, and set server properties which may not be changed.
//
// After calling this function, you should set any additional server parameters, and then
// call ISteamGameServer::LogOnAnonymous() or ISteamGameServer::LogOn()
//
// - usSteamPort is the local port used to communicate with the steam servers.
// - usGamePort is the port that clients will connect to for gameplay.
// - usQueryPort is the port that will manage server browser related duties and info
//		pings from clients.  If you pass MASTERSERVERUPDATERPORT_USEGAMESOCKETSHARE for usQueryPort, then it
//		will use "GameSocketShare" mode, which means that the game is responsible for sending and receiving
//		UDP packets for the master  server updater. See references to GameSocketShare in isteamgameserver.h.
// - The version string is usually in the form x.x.x.x, and is used by the master server to detect when the
//		server is out of date.  (Only servers with the latest version will be listed.)
DLL(uint32_t) BS_SteamGameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, EServerMode eServerMode, const char *pchVersionString) {
	return SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
}

DLL(void) BS_SteamGameServer_Shutdown() {
	SteamGameServer_Shutdown();
}

DLL(void) BS_SteamGameServer_RunCallbacks() {
	SteamGameServer_RunCallbacks();
}

DLL(uint32_t) BS_SteamGameServer_IsSecure() {
	return SteamGameServer_BSecure();
}

DLL(CSteamID*) BS_SteamGameServer_GetSteamID() {
	return new CSteamID(SteamGameServer_GetSteamID());
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steamclient.dll private wrapper functions
//
//	The following functions are part of abstracting API access to the steamclient.dll, but should only be used in very specific cases
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
DLL(HSteamPipe) BS_SteamGameServer_GetHSteamPipe() {
	return SteamGameServer_GetHSteamPipe();
}

// ISteamGameServer Stuff
//-----------------------------------------------------------------------------
// Purpose: Functions for authenticating users via Steam to play on a game server
//-----------------------------------------------------------------------------
DLL(ISteamGameServer*) BS_SteamGameServer() {
	return SteamGameServer();
}

//
// Basic server data.  These properties, if set, must be set before before calling LogOn.  They
// may not be changed after logged in.
//

/// This is called by SteamGameServer_Init, and you will usually not need to call it directly
DLL(uint32_t) BS_ISteamGameServer_InitGameServer(ISteamGameServer* pSteamGameServer, uint32_t unIP, uint16_t usGamePort, uint16_t usQueryPort, uint32_t unFlags, AppId_t nGameAppId, const char *pchVersionString) {
	return pSteamGameServer->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
}

/// Game product identifier.  This is currently used by the master server for version checking purposes.
/// It's a required field, but will eventually will go away, and the AppID will be used for this purpose.
DLL(void) BS_ISteamGameServer_SetProduct(ISteamGameServer* pSteamGameServer, const char *pszProduct) {
	pSteamGameServer->SetProduct(pszProduct);
}

/// Description of the game.  This is a required field and is displayed in the steam server browser....for now.
/// This is a required field, but it will go away eventually, as the data should be determined from the AppID.
DLL(void) BS_ISteamGameServer_SetGameDescription(ISteamGameServer* pSteamGameServer, const char *pszGameDescription) {
	pSteamGameServer->SetGameDescription(pszGameDescription);
}

/// If your game is a "mod," pass the string that identifies it.  The default is an empty string, meaning
/// this application is the original game, not a mod.
///
/// @see k_cbMaxGameServerGameDir
DLL(void) BS_ISteamGameServer_SetModDir(ISteamGameServer* pSteamGameServer, const char *pszModDir) {
	pSteamGameServer->SetModDir(pszModDir);
}

/// Is this is a dedicated server?  The default value is false.
DLL(void) BS_ISteamGameServer_SetDedicatedServer(ISteamGameServer* pSteamGameServer, uint32_t bDedicated) {
	pSteamGameServer->SetDedicatedServer(!!bDedicated);
}

//
// Login
//

/// Begin process to login to a persistent game server account
///
/// You need to register for callbacks to determine the result of this operation.
/// @see SteamServersConnected_t
/// @see SteamServerConnectFailure_t
/// @see SteamServersDisconnected_t
DLL(void) BS_ISteamGameServer_LogOn(ISteamGameServer* pSteamGameServer, const char *pszToken) {
	pSteamGameServer->LogOn(pszToken);
}

/// Login to a generic, anonymous account.
///
/// Note: in previous versions of the SDK, this was automatically called within SteamGameServer_Init,
/// but this is no longer the case.
DLL(void) BS_ISteamGameServer_LogOnAnonymous(ISteamGameServer* pSteamGameServer) {
	pSteamGameServer->LogOnAnonymous();
}

/// Begin process of logging game server out of steam
DLL(void) BS_ISteamGameServer_LogOff(ISteamGameServer* pSteamGameServer) {
	pSteamGameServer->LogOff();
}

// status functions
DLL(uint32_t) BS_ISteamGameServer_IsLoggedOn(ISteamGameServer* pSteamGameServer) {
	return pSteamGameServer->BLoggedOn();
}

DLL(uint32_t) BS_ISteamGameServer_IsSecure(ISteamGameServer* pSteamGameServer) {
	return pSteamGameServer->BSecure();
}

DLL(CSteamID*) BS_ISteamGameServer_GetSteamID(ISteamGameServer* pSteamGameServer) {
	return new CSteamID(pSteamGameServer->GetSteamID());
}

/// Returns true if the master server has requested a restart.
/// Only returns true once per request.
DLL(uint32_t) BS_ISteamGameServer_WasRestartRequested(ISteamGameServer* pSteamGameServer) {
	return pSteamGameServer->WasRestartRequested();
}

//
// Server state.  These properties may be changed at any time.
//

/// Max player count that will be reported to server browser and client queries
DLL(void) BS_ISteamGameServer_SetMaxPlayerCount(ISteamGameServer* pSteamGameServer, int32_t cPlayersMax) {
	pSteamGameServer->SetMaxPlayerCount(cPlayersMax);
}

/// Number of bots.  Default value is zero
DLL(void) BS_ISteamGameServer_SetBotPlayerCount(ISteamGameServer* pSteamGameServer, int32_t cBotplayers) {
	pSteamGameServer->SetBotPlayerCount(cBotplayers);
}

/// Set the name of server as it will appear in the server browser
///
/// @see k_cbMaxGameServerName
DLL(void) BS_ISteamGameServer_SetServerName(ISteamGameServer* pSteamGameServer, const char *pszServerName) {
	pSteamGameServer->SetServerName(pszServerName);
}

/// Set name of map to report in the server browser
///
/// @see k_cbMaxGameServerName
DLL(void) BS_ISteamGameServer_SetMapName(ISteamGameServer* pSteamGameServer, const char *pszMapName) {
	pSteamGameServer->SetMapName(pszMapName);
}

/// Let people know if your server will require a password
DLL(void) BS_ISteamGameServer_SetPasswordProtected(ISteamGameServer* pSteamGameServer, uint32_t bPasswordProtected) {
	pSteamGameServer->SetPasswordProtected(!!bPasswordProtected);
}

/// Spectator server.  The default value is zero, meaning the service
/// is not used.
DLL(void) BS_ISteamGameServer_SetSpectatorPort(ISteamGameServer* pSteamGameServer, uint16_t unSpectatorPort) {
	pSteamGameServer->SetSpectatorPort(unSpectatorPort);
}

/// Name of the spectator server.  (Only used if spectator port is nonzero.)
///
/// @see k_cbMaxGameServerMapName
DLL(void) BS_ISteamGameServer_SetSpectatorServerName(ISteamGameServer* pSteamGameServer, const char *pszSpectatorServerName) {
	pSteamGameServer->SetSpectatorServerName(pszSpectatorServerName);
}

/// Call this to clear the whole list of key/values that are sent in rules queries.
DLL(void) BS_ISteamGameServer_ClearAllKeyValues(ISteamGameServer* pSteamGameServer) {
	pSteamGameServer->ClearAllKeyValues();
}

/// Call this to add/update a key/value pair.
DLL(void) BS_ISteamGameServer_SetKeyValue(ISteamGameServer* pSteamGameServer, const char *pKey, const char *pValue) {
	pSteamGameServer->SetKeyValue(pKey, pValue);
}

/// Sets a string defining the "gametags" for this server, this is optional, but if it is set
/// it allows users to filter in the matchmaking/server-browser interfaces based on the value
///
/// @see k_cbMaxGameServerTags
DLL(void) BS_ISteamGameServer_SetGameTags(ISteamGameServer* pSteamGameServer, const char *pchGameTags) {
	pSteamGameServer->SetGameTags(pchGameTags);
}

/// Sets a string defining the "gamedata" for this server, this is optional, but if it is set
/// it allows users to filter in the matchmaking/server-browser interfaces based on the value
/// don't set this unless it actually changes, its only uploaded to the master once (when
/// acknowledged)
///
/// @see k_cbMaxGameServerGameData
DLL(void) BS_ISteamGameServer_SetGameData(ISteamGameServer* pSteamGameServer, const char *pchGameData) {
	pSteamGameServer->SetGameData(pchGameData);
}

/// Region identifier.  This is an optional field, the default value is empty, meaning the "world" region
DLL(void) BS_ISteamGameServer_SetRegion(ISteamGameServer* pSteamGameServer, const char *pszRegion) {
	pSteamGameServer->SetRegion(pszRegion);
}

//
// Player list management / authentication
//

// Handles receiving a new connection from a Steam user.  This call will ask the Steam
// servers to validate the users identity, app ownership, and VAC status.  If the Steam servers 
// are off-line, then it will validate the cached ticket itself which will validate app ownership 
// and identity.  The AuthBlob here should be acquired on the game client using SteamUser()->InitiateGameConnection()
// and must then be sent up to the game server for authentication.
//
// Return Value: returns true if the users ticket passes basic checks. pSteamIDUser will contain the Steam ID of this user. pSteamIDUser must NOT be NULL
// If the call succeeds then you should expect a GSClientApprove_t or GSClientDeny_t callback which will tell you whether authentication
// for the user has succeeded or failed (the steamid in the callback will match the one returned by this call)
DLL(uint32_t) BS_ISteamGameServer_SendUserConnectAndAuthenticate(ISteamGameServer* pSteamGameServer, uint32_t unIPClient, const void *pvAuthBlob, uint32_t cubAuthBlobSize, CSteamID *pSteamIDUser) {
	return pSteamGameServer->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
}

// Creates a fake user (ie, a bot) which will be listed as playing on the server, but skips validation.  
// 
// Return Value: Returns a SteamID for the user to be tracked with, you should call HandleUserDisconnect()
// when this user leaves the server just like you would for a real user.
DLL(CSteamID*) BS_ISteamGameServer_CreateUnauthenticatedUserConnection(ISteamGameServer* pSteamGameServer) {
	return new CSteamID(pSteamGameServer->CreateUnauthenticatedUserConnection());
}

// Should be called whenever a user leaves our game server, this lets Steam internally
// track which users are currently on which servers for the purposes of preventing a single
// account being logged into multiple servers, showing who is currently on a server, etc.
DLL(void) BS_ISteamGameServer_SendUserDisconnect(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser) {
	pSteamGameServer->SendUserDisconnect(*pSteamIDUser);
}

// Update the data to be displayed in the server browser and matchmaking interfaces for a user
// currently connected to the server.  For regular users you must call this after you receive a
// GSUserValidationSuccess callback.
// 
// Return Value: true if successful, false if failure (ie, steamIDUser wasn't for an active player)
DLL(uint32_t) BS_ISteamGameServer_UpdateUserData(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser, const char *pchPlayerName, uint32_t uScore) {
	return pSteamGameServer->BUpdateUserData(*pSteamIDUser, pchPlayerName, uScore);
}

// New auth system APIs - do not mix with the old auth system APIs.
// ----------------------------------------------------------------

// Retrieve ticket to be sent to the entity who wishes to authenticate you ( using BeginAuthSession API ). 
// pcbTicket retrieves the length of the actual ticket.
DLL(HAuthTicket) BS_ISteamGameServer_GetAuthSessionTicket(ISteamGameServer* pSteamGameServer, void *pTicket, int32_t cbMaxTicket, uint32_t *pcbTicket) {
	return pSteamGameServer->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}

// Authenticate ticket ( from GetAuthSessionTicket ) from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
DLL(EBeginAuthSessionResult) BS_ISteamGameServer_BeginAuthSession(ISteamGameServer* pSteamGameServer, const void *pAuthTicket, int32_t cbAuthTicket, CSteamID* pSteamID) {
	return pSteamGameServer->BeginAuthSession(pAuthTicket, cbAuthTicket, *pSteamID);
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
DLL(void) BS_ISteamGameServer_EndAuthSession(ISteamGameServer* pSteamGameServer, CSteamID* pSteamID) {
	pSteamGameServer->EndAuthSession(*pSteamID);
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
DLL(void) BS_ISteamGameServer_CancelAuthTicket(ISteamGameServer* pSteamGameServer, HAuthTicket hAuthTicket) {
	pSteamGameServer->CancelAuthTicket(hAuthTicket);
}

// After receiving a user's authentication data, and passing it to SendUserConnectAndAuthenticate, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
DLL(EUserHasLicenseForAppResult) BS_ISteamGameServer_UserHasLicenseForApp(ISteamGameServer* pSteamGameServer, CSteamID* pSteamID, AppId_t appID) {
	return pSteamGameServer->UserHasLicenseForApp(*pSteamID, appID);
}

// Ask if a user in in the specified group, results returns async by GSUserGroupStatus_t
// returns false if we're not connected to the steam servers and thus cannot ask
DLL(uint32_t) BS_ISteamGameServer_RequestUserGroupStatus(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDUser, CSteamID* pSteamIDGroup) {
	return pSteamGameServer->RequestUserGroupStatus(*pSteamIDUser, *pSteamIDGroup);
}

// Returns the public IP of the server according to Steam, useful when the server is 
// behind NAT and you want to advertise its IP in a lobby for other clients to directly
// connect to
DLL(uint32_t) BS_ISteamGameServer_GetPublicIP(ISteamGameServer* pSteamGameServer) {
	return pSteamGameServer->GetPublicIP();
}

// These are in GameSocketShare mode, where instead of ISteamGameServer creating its own
// socket to talk to the master server on, it lets the game use its socket to forward messages
// back and forth. This prevents us from requiring server ops to open up yet another port
// in their firewalls.
//
// the IP address and port should be in host order, i.e 127.0.0.1 == 0x7f000001

// These are used when you've elected to multiplex the game server's UDP socket
// rather than having the master server updater use its own sockets.
// 
// Source games use this to simplify the job of the server admins, so they 
// don't have to open up more ports on their firewalls.

// Call this when a packet that starts with 0xFFFFFFFF comes in. That means
// it's for us.
DLL(uint32_t) BS_ISteamGameServer_HandleIncomingPacket(ISteamGameServer* pSteamGameServer, const void *pData, int32_t cbData, uint32_t srcIP, uint16_t srcPort) {
	return pSteamGameServer->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
}

// AFTER calling HandleIncomingPacket for any packets that came in that frame, call this.
// This gets a packet that the master server updater needs to send out on UDP.
// It returns the length of the packet it wants to send, or 0 if there are no more packets to send.
// Call this each frame until it returns 0.
DLL(uint32_t) BS_ISteamGameServer_GetNextOutgoingPacket(ISteamGameServer* pSteamGameServer, void *pOut, int32_t cbMaxOut, uint32_t *pNetAdr, uint16_t *pPort) {
	return pSteamGameServer->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
}

//
// Control heartbeats / advertisement with master server
//

// Call this as often as you like to tell the master server updater whether or not
// you want it to be active (default: off).
DLL(void) BS_ISteamGameServer_EnableHeartbeats(ISteamGameServer* pSteamGameServer, uint32_t bActive) {
	pSteamGameServer->EnableHeartbeats(!!bActive);
}

// You usually don't need to modify this.
// Pass -1 to use the default value for iHeartbeatInterval.
// Some mods change this.
DLL(void) BS_ISteamGameServer_SetHeartbeatInterval(ISteamGameServer* pSteamGameServer, int32_t iHeartbeatInterval) {
	pSteamGameServer->SetHeartbeatInterval(iHeartbeatInterval);
}

// Force a heartbeat to steam at the next opportunity
DLL(void) BS_ISteamGameServer_ForceHeartbeat(ISteamGameServer* pSteamGameServer) {
	pSteamGameServer->ForceHeartbeat();
}

// associate this game server with this clan for the purposes of computing player compat
DLL(SteamAPICall_t*) BS_ISteamGameServer_AssociateWithClan(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDClan) {
	return new SteamAPICall_t(pSteamGameServer->AssociateWithClan(*pSteamIDClan));
}

// ask if any of the current players dont want to play with this new player - or vice versa
DLL(SteamAPICall_t*) BS_ISteamGameServer_ComputeNewPlayerCompatibility(ISteamGameServer* pSteamGameServer, CSteamID* pSteamIDNewPlayer) {
	return new SteamAPICall_t(pSteamGameServer->ComputeNewPlayerCompatibility(*pSteamIDNewPlayer));
}