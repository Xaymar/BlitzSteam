//	BS_ - Steam wrapper for Blitz.
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

#include "dllmain.h"

DLL_EXPORT HSteamUser DLL_CALL BS_SteamUser_GetHSteamUser( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetHSteamUser( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetHSteamUser=_BS_SteamUser_GetHSteamUser@4")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_IsLoggedOn( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BLoggedOn( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_IsLoggedOn=_BS_SteamUser_IsLoggedOn@4")

DLL_EXPORT CSteamID* DLL_CALL BS_SteamUser_GetSteamID( ISteamUser* lpSteamUser ) {
	return &(lpSteamUser->GetSteamID( ));
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetSteamID=_BS_SteamUser_GetSteamID@4")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_InitiateGameConnection( ISteamUser* lpSteamUser, void* pAuthBlob, uint32_t cbMaxAuthBlob, CSteamID* SteamIDGameServer, uint32_t unIPServer, uint16_t usPortServer, uint32_t bSecure ) {
	return lpSteamUser->InitiateGameConnection( pAuthBlob, cbMaxAuthBlob, *SteamIDGameServer, unIPServer, usPortServer, bSecure != 0);
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_InitiateGameConnection=_BS_SteamUser_InitiateGameConnection@28")

DLL_EXPORT void DLL_CALL BS_SteamUser_TerminateGameConnection( ISteamUser* lpSteamUser, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->TerminateGameConnection( unIPServer, usPortServer );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_TerminateGameConnection=_BS_SteamUser_TerminateGameConnection@12")

DLL_EXPORT void DLL_CALL BS_SteamUser_TrackAppUsageEvent( ISteamUser* lpSteamUser, CGameID* gameId, uint32_t eAppUsageEvent, const char* pchExtraInfo ) {
	lpSteamUser->TrackAppUsageEvent( *gameId, eAppUsageEvent, pchExtraInfo );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_TrackAppUsageEvent=_BS_SteamUser_TrackAppUsageEvent@16")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_GetUserDataFolder( ISteamUser* lpSteamUser, char* pchBuffer, uint32_t cubBuffer ) {
	return lpSteamUser->GetUserDataFolder( pchBuffer, cubBuffer );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetUserDataFolder=_BS_SteamUser_GetUserDataFolder@12")

DLL_EXPORT void DLL_CALL BS_SteamUser_StartVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StartVoiceRecording( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_StartVoiceRecording=_BS_SteamUser_StartVoiceRecording@4")

DLL_EXPORT void DLL_CALL BS_SteamUser_StopVoiceRecording( ISteamUser* lpSteamUser ) {
	lpSteamUser->StopVoiceRecording( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_StopVoiceRecording=_BS_SteamUser_StopVoiceRecording@4")

DLL_EXPORT EVoiceResult DLL_CALL BS_SteamUser_GetAvailableVoice( ISteamUser* lpSteamUser, uint32_t* pcbCompressed, uint32_t* pcbUncompressed, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetAvailableVoice( pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetAvailableVoice=_BS_SteamUser_GetAvailableVoice@16")

DLL_EXPORT EVoiceResult DLL_CALL BS_SteamUser_GetVoice( ISteamUser* lpSteamUser, bool bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten, uint32_t nUncompressedVoiceDesiredSampleRate ) {
	return lpSteamUser->GetVoice( bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetVoice=_BS_SteamUser_GetVoice@40")

DLL_EXPORT EVoiceResult DLL_CALL BS_SteamUser_DecompressVoice( ISteamUser* lpSteamUser, const void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nDesiredSampleRate ) {
	return lpSteamUser->DecompressVoice( pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_DecompressVoice=_BS_SteamUser_DecompressVoice@28")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_GetVoiceOptimalSampleRate( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetVoiceOptimalSampleRate( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetVoiceOptimalSampleRate=_BS_SteamUser_GetVoiceOptimalSampleRate@4")

DLL_EXPORT HAuthTicket DLL_CALL BS_SteamUser_GetAuthSessionTicket( ISteamUser* lpSteamUser, void* pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetAuthSessionTicket( pTicket, cbMaxTicket, pcbTicket );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetAuthSessionTicket=_BS_SteamUser_GetAuthSessionTicket@16")

DLL_EXPORT EBeginAuthSessionResult DLL_CALL BS_SteamUser_BeginAuthSession( ISteamUser* lpSteamUser, const void *pAuthTicket, uint32_t cbAuthTicket, CSteamID* steamID ) {
	return lpSteamUser->BeginAuthSession( pAuthTicket, cbAuthTicket, *steamID );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_BeginAuthSession=_BS_SteamUser_BeginAuthSession@16")

DLL_EXPORT void DLL_CALL BS_SteamUser_EndAuthSession( ISteamUser* lpSteamUser, CSteamID* steamID ) {
	lpSteamUser->EndAuthSession( *steamID );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_EndAuthSession=_BS_SteamUser_EndAuthSession@8")

DLL_EXPORT void DLL_CALL BS_SteamUser_CancelAuthTicket( ISteamUser* lpSteamUser, HAuthTicket hAuthTicket ) {
	lpSteamUser->CancelAuthTicket( hAuthTicket );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_EndAuthSession=_BS_SteamUser_EndAuthSession@8")

DLL_EXPORT EUserHasLicenseForAppResult DLL_CALL BS_SteamUser_UserHasLicenseForApp( ISteamUser* lpSteamUser, CSteamID* steamID, AppId_t appID ) {
	return lpSteamUser->UserHasLicenseForApp( *steamID, appID );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_UserHasLicenseForApp=_BS_SteamUser_UserHasLicenseForApp@12")

DLL_EXPORT bool DLL_CALL BS_SteamUser_IsBehindNAT( ISteamUser* lpSteamUser ) {
	return lpSteamUser->BIsBehindNAT( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_IsBehindNAT=_BS_SteamUser_IsBehindNAT@4")

DLL_EXPORT void DLL_CALL BS_SteamUser_AdvertiseGame( ISteamUser* lpSteamUser, CSteamID* steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer ) {
	lpSteamUser->AdvertiseGame( *steamIDGameServer, unIPServer, usPortServer );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_AdvertiseGame=_BS_SteamUser_AdvertiseGame@16")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_SteamUser_RequestEncryptedAppTicket( ISteamUser* lpSteamUser, void* pDataToInclude, uint32_t cbDataToInclude ) {
	return lpSteamUser->RequestEncryptedAppTicket( pDataToInclude, cbDataToInclude );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_RequestEncryptedAppTicket=_BS_SteamUser_RequestEncryptedAppTicket@12")

DLL_EXPORT bool DLL_CALL BS_SteamUser_GetEncryptedAppTicket( ISteamUser* lpSteamUser, void *pTicket, uint32_t cbMaxTicket, uint32_t* pcbTicket ) {
	return lpSteamUser->GetEncryptedAppTicket( pTicket, cbMaxTicket, pcbTicket );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetEncryptedAppTicket=_BS_SteamUser_GetEncryptedAppTicket@16")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_GetGameBadgeLevel( ISteamUser* lpSteamUser, uint32_t nSeries, bool bFoil ) {
	return lpSteamUser->GetGameBadgeLevel( nSeries, bFoil );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetGameBadgeLevel=_BS_SteamUser_GetGameBadgeLevel@12")

DLL_EXPORT uint32_t DLL_CALL BS_SteamUser_GetPlayerSteamLevel( ISteamUser* lpSteamUser ) {
	return lpSteamUser->GetPlayerSteamLevel( );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_GetPlayerSteamLevel=_BS_SteamUser_GetPlayerSteamLevel@4")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_SteamUser_RequestStoreAuthURL( ISteamUser* lpSteamUser, const char* pchRedirectURL ) {
	return lpSteamUser->RequestStoreAuthURL( pchRedirectURL );
}
#pragma comment(linker, "/EXPORT:BS_SteamUser_RequestStoreAuthURL=_BS_SteamUser_RequestStoreAuthURL@8")