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

DLL_FUNCTION(ISteamUser*) BS_User() {
	return SteamUser();
}
#pragma comment(linker, "/EXPORT:BS_User=_BS_User@0")

DLL_FUNCTION(HSteamUser) BS_User_GetHSteamUser( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetHSteamUser( );
}
#pragma comment(linker, "/EXPORT:BS_User_GetHSteamUser=_BS_User_GetHSteamUser@4")

DLL_FUNCTION(uint32_t) BS_User_IsLoggedOn( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BLoggedOn( );
}
#pragma comment(linker, "/EXPORT:BS_User_IsLoggedOn=_BS_User_IsLoggedOn@4")

DLL_FUNCTION(CSteamID*) BS_User_GetSteamID( ISteamUser* lpSteamUser ) {
	return &(lpSteamUser->GetSteamID( ));
}
#pragma comment(linker, "/EXPORT:BS_User_GetSteamID=_BS_User_GetSteamID@4")

DLL_FUNCTION(uint32_t) BS_User_InitiateGameConnection( ISteamUser* lpSteamUser, void* pAuthBlob, uint32_t cbMaxAuthBlob, CSteamID* SteamIDGameServer, uint32_t unIPServer, uint16_t usPortServer, uint32_t bSecure ) {
	return lpSteamUser->InitiateGameConnection( pAuthBlob, cbMaxAuthBlob, *SteamIDGameServer, unIPServer, usPortServer, bSecure != 0 );
}
#pragma comment(linker, "/EXPORT:BS_User_InitiateGameConnection=_BS_User_InitiateGameConnection@28")

DLL_FUNCTION(void) BS_User_TerminateGameConnection( ISteamUser* lpSteamUser, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->TerminateGameConnection( unIPServer, usPortServer );
}
#pragma comment(linker, "/EXPORT:BS_User_TerminateGameConnection=_BS_User_TerminateGameConnection@12")

DLL_FUNCTION(void) BS_User_TrackAppUsageEvent( ISteamUser* lpSteamUser, CGameID* gameId, uint32_t eAppUsageEvent, const char* pchExtraInfo ) {
	lpSteamUser->TrackAppUsageEvent( *gameId, eAppUsageEvent, pchExtraInfo );
}
#pragma comment(linker, "/EXPORT:BS_User_TrackAppUsageEvent=_BS_User_TrackAppUsageEvent@16")

DLL_FUNCTION(uint32_t) BS_User_GetUserDataFolder( ISteamUser* lpSteamUser, char* pchBuffer, uint32_t cubBuffer ) {
	return lpSteamUser->GetUserDataFolder( pchBuffer, cubBuffer );
}
#pragma comment(linker, "/EXPORT:BS_User_GetUserDataFolder=_BS_User_GetUserDataFolder@12")

DLL_FUNCTION(void) BS_User_StartVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StartVoiceRecording( );
}
#pragma comment(linker, "/EXPORT:BS_User_StartVoiceRecording=_BS_User_StartVoiceRecording@4")

DLL_FUNCTION(void) BS_User_StopVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StopVoiceRecording( );
}
#pragma comment(linker, "/EXPORT:BS_User_StopVoiceRecording=_BS_User_StopVoiceRecording@4")

DLL_FUNCTION(EVoiceResult) BS_User_GetAvailableVoice( ISteamUser* lpSteamUser, uint32_t* pcbCompressed, uint32_t* pcbUncompressed, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetAvailableVoice( pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_User_GetAvailableVoice=_BS_User_GetAvailableVoice@16")

DLL_FUNCTION(EVoiceResult) BS_User_GetVoice( ISteamUser* lpSteamUser, uint32_t bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetVoice( bWantCompressed != 0, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed != 0, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_User_GetVoice=_BS_User_GetVoice@40")

DLL_FUNCTION(EVoiceResult) BS_User_DecompressVoice( ISteamUser* lpSteamUser, const void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nDesiredSampleRate ) {
	return lpSteamUser->DecompressVoice( pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_User_DecompressVoice=_BS_User_DecompressVoice@28")

DLL_FUNCTION(uint32_t) BS_User_GetVoiceOptimalSampleRate( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetVoiceOptimalSampleRate( );
}
#pragma comment(linker, "/EXPORT:BS_User_GetVoiceOptimalSampleRate=_BS_User_GetVoiceOptimalSampleRate@4")

DLL_FUNCTION(HAuthTicket) BS_User_GetAuthSessionTicket( ISteamUser* lpSteamUser, void* pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetAuthSessionTicket( pTicket, cbMaxTicket, pcbTicket );
}
#pragma comment(linker, "/EXPORT:BS_User_GetAuthSessionTicket=_BS_User_GetAuthSessionTicket@16")

DLL_FUNCTION(EBeginAuthSessionResult) BS_User_BeginAuthSession( ISteamUser* lpSteamUser, const void *pAuthTicket, uint32_t cbAuthTicket, CSteamID* steamID ) {
	return lpSteamUser->BeginAuthSession( pAuthTicket, cbAuthTicket, *steamID );
}
#pragma comment(linker, "/EXPORT:BS_User_BeginAuthSession=_BS_User_BeginAuthSession@16")

DLL_FUNCTION(void) BS_User_EndAuthSession( ISteamUser* lpSteamUser, CSteamID* steamID ) {
	lpSteamUser->EndAuthSession( *steamID );
}
#pragma comment(linker, "/EXPORT:BS_User_EndAuthSession=_BS_User_EndAuthSession@8")

DLL_FUNCTION(void) BS_User_CancelAuthTicket( ISteamUser* lpSteamUser, HAuthTicket hAuthTicket ) {
	lpSteamUser->CancelAuthTicket( hAuthTicket );
}
#pragma comment(linker, "/EXPORT:BS_User_EndAuthSession=_BS_User_EndAuthSession@8")

DLL_FUNCTION(EUserHasLicenseForAppResult) BS_User_UserHasLicenseForApp( ISteamUser* lpSteamUser, CSteamID* steamID, AppId_t appID ) {
	return lpSteamUser->UserHasLicenseForApp( *steamID, appID );
}
#pragma comment(linker, "/EXPORT:BS_User_UserHasLicenseForApp=_BS_User_UserHasLicenseForApp@12")

DLL_FUNCTION(uint32_t) BS_User_IsBehindNAT( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BIsBehindNAT( );
}
#pragma comment(linker, "/EXPORT:BS_User_IsBehindNAT=_BS_User_IsBehindNAT@4")

DLL_FUNCTION(void) BS_User_AdvertiseGame( ISteamUser* lpSteamUser, CSteamID* steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->AdvertiseGame( *steamIDGameServer, unIPServer, usPortServer );
}
#pragma comment(linker, "/EXPORT:BS_User_AdvertiseGame=_BS_User_AdvertiseGame@16")

DLL_FUNCTION(SteamAPICall_t*) BS_User_RequestEncryptedAppTicket( ISteamUser* lpSteamUser, void* pDataToInclude, uint32_t cbDataToInclude ) {
	return new uint64_t(lpSteamUser->RequestEncryptedAppTicket( pDataToInclude, cbDataToInclude ));
}
#pragma comment(linker, "/EXPORT:BS_User_RequestEncryptedAppTicket=_BS_User_RequestEncryptedAppTicket@12")

DLL_FUNCTION(uint32_t) BS_User_GetEncryptedAppTicket( ISteamUser* lpSteamUser, void *pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetEncryptedAppTicket( pTicket, cbMaxTicket, pcbTicket );
}
#pragma comment(linker, "/EXPORT:BS_User_GetEncryptedAppTicket=_BS_User_GetEncryptedAppTicket@16")

DLL_FUNCTION(uint32_t) BS_User_GetGameBadgeLevel( ISteamUser* lpSteamUser, uint32_t nSeries, uint32_t bFoil ) {
	return lpSteamUser->GetGameBadgeLevel( nSeries, bFoil != 0 );
}
#pragma comment(linker, "/EXPORT:BS_User_GetGameBadgeLevel=_BS_User_GetGameBadgeLevel@12")

DLL_FUNCTION(uint32_t) BS_User_GetPlayerSteamLevel( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetPlayerSteamLevel( );
}
#pragma comment(linker, "/EXPORT:BS_User_GetPlayerSteamLevel=_BS_User_GetPlayerSteamLevel@4")

DLL_FUNCTION(SteamAPICall_t*) BS_User_RequestStoreAuthURL( ISteamUser* lpSteamUser, const char* pchRedirectURL ) {
	return new uint64_t(lpSteamUser->RequestStoreAuthURL( pchRedirectURL ));
}
#pragma comment(linker, "/EXPORT:BS_User_RequestStoreAuthURL=_BS_User_RequestStoreAuthURL@8")
