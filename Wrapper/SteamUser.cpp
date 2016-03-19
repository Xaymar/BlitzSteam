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
// Purpose: Functions for accessing and manipulating a steam account
//			associated with one client instance
//-----------------------------------------------------------------------------
DLL(ISteamUser*) BS_SteamUser() {
	return SteamUser();
}

// returns the HSteamUser this interface represents
// this is only used internally by the API, and by a few select interfaces that support multi-user
DLL(HSteamUser) BS_ISteamUser_GetHSteamUser( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetHSteamUser( );
}

// returns true if the Steam client current has a live connection to the Steam servers. 
// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
// The Steam client will automatically be trying to recreate the connection as often as possible.
DLL(uint32_t) BS_ISteamUser_IsLoggedOn( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BLoggedOn( );
}

// returns the CSteamID of the account currently logged into the Steam client
// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
DLL(CSteamID*) BS_ISteamUser_GetSteamID( ISteamUser* lpSteamUser ) {
	return &(lpSteamUser->GetSteamID( ));
}

// Multiplayer Authentication functions

// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
//
// Parameters:
// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
// CGameID gameID - the ID of the current game. For games without mods, this is just CGameID( <appID> )
// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
//
// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
DLL(uint32_t) BS_ISteamUser_InitiateGameConnection( ISteamUser* lpSteamUser, void* pAuthBlob, uint32_t cbMaxAuthBlob, CSteamID* SteamIDGameServer, uint32_t unIPServer, uint16_t usPortServer, uint32_t bSecure ) {
	return lpSteamUser->InitiateGameConnection( pAuthBlob, cbMaxAuthBlob, *SteamIDGameServer, unIPServer, usPortServer, bSecure != 0 );
}

// notify of disconnect
// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
DLL(void) BS_ISteamUser_TerminateGameConnection( ISteamUser* lpSteamUser, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->TerminateGameConnection( unIPServer, usPortServer );
}

// Legacy functions

// used by only a few games to track usage events
DLL(void) BS_ISteamUser_TrackAppUsageEvent( ISteamUser* lpSteamUser, CGameID* gameId, uint32_t eAppUsageEvent, const char* pchExtraInfo ) {
	lpSteamUser->TrackAppUsageEvent( *gameId, eAppUsageEvent, pchExtraInfo );
}

// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
DLL(uint32_t) BS_ISteamUser_GetUserDataFolder( ISteamUser* lpSteamUser, char* pchBuffer, uint32_t cubBuffer ) {
	return lpSteamUser->GetUserDataFolder( pchBuffer, cubBuffer );
}

// Starts voice recording. Once started, use GetVoice() to get the data
DLL(void) BS_ISteamUser_StartVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StartVoiceRecording( );
}

// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
// a little bit after this function is called. GetVoice() should continue to be called until it returns
// k_eVoiceResultNotRecording
DLL(void) BS_ISteamUser_StopVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StopVoiceRecording( );
}

// Determine the amount of captured audio data that is available in bytes.
// This provides both the compressed and uncompressed data. Please note that the uncompressed
// data is not the raw feed from the microphone: data may only be available if audible 
// levels of speech are detected.
// nUncompressedVoiceDesiredSampleRate is necessary to know the number of bytes to return in pcbUncompressed - can be set to 0 if you don't need uncompressed (the usual case)
// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nUncompressedVoiceDesiredSampleRate
DLL(EVoiceResult) BS_ISteamUser_GetAvailableVoice( ISteamUser* lpSteamUser, uint32_t* pcbCompressed, uint32_t* pcbUncompressed, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetAvailableVoice( pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate );
}

// Gets the latest voice data from the microphone. Compressed data is an arbitrary format, and is meant to be handed back to 
// DecompressVoice() for playback later as a binary blob. Uncompressed data is 16-bit, signed integer, 11025Hz PCM format.
// Please note that the uncompressed data is not the raw feed from the microphone: data may only be available if audible 
// levels of speech are detected, and may have passed through denoising filters, etc.
// This function should be called as often as possible once recording has started; once per frame at least.
// nBytesWritten is set to the number of bytes written to pDestBuffer. 
// nUncompressedBytesWritten is set to the number of bytes written to pUncompressedDestBuffer. 
// You must grab both compressed and uncompressed here at the same time, if you want both.
// Matching data that is not read during this call will be thrown away.
// GetAvailableVoice() can be used to determine how much data is actually available.
// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nUncompressedVoiceDesiredSampleRate
DLL(EVoiceResult) BS_ISteamUser_GetVoice( ISteamUser* lpSteamUser, uint32_t bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetVoice( bWantCompressed != 0, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed != 0, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate );
}

// Decompresses a chunk of compressed data produced by GetVoice().
// nBytesWritten is set to the number of bytes written to pDestBuffer unless the return value is k_EVoiceResultBufferTooSmall.
// In that case, nBytesWritten is set to the size of the buffer required to decompress the given
// data. The suggested buffer size for the destination buffer is 22 kilobytes.
// The output format of the data is 16-bit signed at the requested samples per second.
// If you're upgrading from an older Steamworks API, you'll want to pass in 11025 to nDesiredSampleRate
DLL(EVoiceResult) BS_ISteamUser_DecompressVoice( ISteamUser* lpSteamUser, const void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nDesiredSampleRate ) {
	return lpSteamUser->DecompressVoice( pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate );
}

// This returns the frequency of the voice data as it's stored internally; calling DecompressVoice() with this size will yield the best results
DLL(uint32_t) BS_ISteamUser_GetVoiceOptimalSampleRate( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetVoiceOptimalSampleRate( );
}

// Retrieve ticket to be sent to the entity who wishes to authenticate you. 
// pcbTicket retrieves the length of the actual ticket.
DLL(HAuthTicket) BS_ISteamUser_GetAuthSessionTicket( ISteamUser* lpSteamUser, void* pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetAuthSessionTicket( pTicket, cbMaxTicket, pcbTicket );
}

// Authenticate ticket from entity steamID to be sure it is valid and isnt reused
// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
DLL(EBeginAuthSessionResult) BS_ISteamUser_BeginAuthSession( ISteamUser* lpSteamUser, const void *pAuthTicket, uint32_t cbAuthTicket, CSteamID* steamID ) {
	return lpSteamUser->BeginAuthSession( pAuthTicket, cbAuthTicket, *steamID );
}

// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
DLL(void) BS_ISteamUser_EndAuthSession( ISteamUser* lpSteamUser, CSteamID* steamID ) {
	lpSteamUser->EndAuthSession( *steamID );
}

// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
DLL(void) BS_ISteamUser_CancelAuthTicket( ISteamUser* lpSteamUser, HAuthTicket hAuthTicket ) {
	lpSteamUser->CancelAuthTicket( hAuthTicket );
}

// After receiving a user's authentication data, and passing it to BeginAuthSession, use this function
// to determine if the user owns downloadable content specified by the provided AppID.
DLL(EUserHasLicenseForAppResult) BS_ISteamUser_UserHasLicenseForApp( ISteamUser* lpSteamUser, CSteamID* steamID, AppId_t appID ) {
	return lpSteamUser->UserHasLicenseForApp( *steamID, appID );
}

// returns true if this users looks like they are behind a NAT device. Only valid once the user has connected to steam 
// (i.e a SteamServersConnected_t has been issued) and may not catch all forms of NAT.
DLL(uint32_t) BS_ISteamUser_IsBehindNAT( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BIsBehindNAT( );
}

// set data to be replicated to friends so that they can join your game
// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
DLL(void) BS_ISteamUser_AdvertiseGame( ISteamUser* lpSteamUser, CSteamID* steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->AdvertiseGame( *steamIDGameServer, unIPServer, usPortServer );
}

// Requests a ticket encrypted with an app specific shared key
// pDataToInclude, cbDataToInclude will be encrypted into the ticket
// ( This is asynchronous, you must wait for the ticket to be completed by the server )
//CALL_RESULT( EncryptedAppTicketResponse_t )
DLL(SteamAPICall_t*) BS_ISteamUser_RequestEncryptedAppTicket( ISteamUser* lpSteamUser, void* pDataToInclude, uint32_t cbDataToInclude ) {
	return new uint64_t(lpSteamUser->RequestEncryptedAppTicket( pDataToInclude, cbDataToInclude ));
}

// retrieve a finished ticket
DLL(uint32_t) BS_ISteamUser_GetEncryptedAppTicket( ISteamUser* lpSteamUser, void *pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetEncryptedAppTicket( pTicket, cbMaxTicket, pcbTicket );
}

// Trading Card badges data access
// if you only have one set of cards, the series will be 1
// the user has can have two different badges for a series; the regular (max level 5) and the foil (max level 1)
DLL(uint32_t) BS_ISteamUser_GetGameBadgeLevel( ISteamUser* lpSteamUser, uint32_t nSeries, uint32_t bFoil ) {
	return lpSteamUser->GetGameBadgeLevel( nSeries, bFoil != 0 );
}

// gets the Steam Level of the user, as shown on their profile
DLL(uint32_t) BS_ISteamUser_GetPlayerSteamLevel( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetPlayerSteamLevel( );
}

// Requests a URL which authenticates an in-game browser for store check-out,
// and then redirects to the specified URL. As long as the in-game browser
// accepts and handles session cookies, Steam microtransaction checkout pages
// will automatically recognize the user instead of presenting a login page.
// The result of this API call will be a StoreAuthURLResponse_t callback.
// NOTE: The URL has a very short lifetime to prevent history-snooping attacks,
// so you should only call this API when you are about to launch the browser,
// or else immediately navigate to the result URL using a hidden browser window.
// NOTE 2: The resulting authorization cookie has an expiration time of one day,
// so it would be a good idea to request and visit a new auth URL every 12 hours.
DLL(SteamAPICall_t*) BS_ISteamUser_RequestStoreAuthURL( ISteamUser* lpSteamUser, const char* pchRedirectURL ) {
	return new uint64_t(lpSteamUser->RequestStoreAuthURL( pchRedirectURL ));
}
