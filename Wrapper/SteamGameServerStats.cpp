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
// Purpose: Functions for authenticating users via Steam to play on a game server
//-----------------------------------------------------------------------------
DLL(ISteamGameServerStats*) BS_SteamGameServerStats() {
	return SteamGameServerStats();
}

// downloads stats for the user
// returns a GSStatsReceived_t callback when completed
// if the user has no stats, GSStatsReceived_t.m_eResult will be set to k_EResultFail
// these stats will only be auto-updated for clients playing on the server. For other
// users you'll need to call RequestUserStats() again to refresh any data
DLL(SteamAPICall_t*) BS_ISteamGameServerStats_RequestUserStats(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser) {
	return new SteamAPICall_t(pSteamGameServerStats->RequestUserStats(*steamIDUser));
}

// Store the current data on the server, will get a GSStatsStored_t callback when set.
//
// If the callback has a result of k_EResultInvalidParam, one or more stats 
// uploaded has been rejected, either because they broke constraints
// or were out of date. In this case the server sends back updated values.
// The stats should be re-iterated to keep in sync.
DLL(SteamAPICall_t*) BS_ISteamGameServerStats_StoreUserStats(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser) {
	return new SteamAPICall_t(pSteamGameServerStats->StoreUserStats(*steamIDUser));
}

// requests stat information for a user, usable after a successful call to RequestUserStats()
DLL(uint32_t) BS_ISteamGameServerStats_GetUserStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pData) {
	return pSteamGameServerStats->GetUserStat(*steamIDUser, pchName, (int32_t*)pData);
}

DLL(uint32_t) BS_ISteamGameServerStats_GetUserStatF(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, float_t* pData) {
	return pSteamGameServerStats->GetUserStat(*steamIDUser, pchName, pData);
}

DLL(uint32_t) BS_ISteamGameServerStats_GetUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pbAchieved) {
	return pSteamGameServerStats->GetUserAchievement(*steamIDUser, pchName, (bool*)pbAchieved);
}

// Set / update stats and achievements. 
// Note: These updates will work only on stats game servers are allowed to edit and only for 
// game servers that have been declared as officially controlled by the game creators. 
// Set the IP range of your official servers on the Steamworks page
DLL(uint32_t) BS_ISteamGameServerStats_SetUserStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t nData) {
	return pSteamGameServerStats->SetUserStat(*steamIDUser, pchName, (int32_t)nData);
}

DLL(uint32_t) BS_ISteamGameServerStats_SetUserStatF(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, float_t fData) {
	return pSteamGameServerStats->SetUserStat(*steamIDUser, pchName, fData);
}

DLL(uint32_t) BS_ISteamGameServerStats_UpdateUserAvgRateStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char *pchName, float flCountThisSession, double* pdSessionLength) {
	return pSteamGameServerStats->UpdateUserAvgRateStat(*steamIDUser, pchName, flCountThisSession, *pdSessionLength);
}

DLL(uint32_t) BS_ISteamGameServerStats_SetUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName) {
	return pSteamGameServerStats->SetUserAchievement(*steamIDUser, pchName);
}

DLL(uint32_t) BS_ISteamGameServerStats_ClearUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName) {
	return pSteamGameServerStats->ClearUserAchievement(*steamIDUser, pchName);
}

