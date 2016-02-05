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

DLL_FUNCTION(ISteamGameServerStats*) BS_GameServerStats() {
#pragma comment(linker, "/EXPORT:BS_GameServerStats=_BS_GameServerStats@0")
	return SteamGameServerStats();
}

DLL_FUNCTION(SteamAPICall_t*) BS_GameServerStats_RequestUserStats(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser) {
	return new uint64_t(pSteamGameServerStats->RequestUserStats(*steamIDUser));
}

DLL_FUNCTION(SteamAPICall_t*) BS_GameServerStats_StoreUserStats(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser) {
	return new uint64_t(pSteamGameServerStats->StoreUserStats(*steamIDUser));
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_GetUserStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pData) {
	return pSteamGameServerStats->GetUserStat(*steamIDUser, pchName, (int32_t*)pData);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_GetUserStatF(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, float_t* pData) {
	return pSteamGameServerStats->GetUserStat(*steamIDUser, pchName, pData);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_GetUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pbAchieved) {
	return pSteamGameServerStats->GetUserAchievement(*steamIDUser, pchName, (bool*)pbAchieved);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_SetUserStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, uint32_t nData) {
	return pSteamGameServerStats->SetUserStat(*steamIDUser, pchName, (int32_t)nData);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_SetUserStatF(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName, float_t fData) {
	return pSteamGameServerStats->SetUserStat(*steamIDUser, pchName, fData);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_UpdateUserAvgRateStat(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char *pchName, float flCountThisSession, double* pdSessionLength) {
	return pSteamGameServerStats->UpdateUserAvgRateStat(*steamIDUser, pchName, flCountThisSession, *pdSessionLength);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_SetUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName) {
	return pSteamGameServerStats->SetUserAchievement(*steamIDUser, pchName);
}

DLL_FUNCTION(uint32_t) BS_GameServerStats_ClearUserAchievement(ISteamGameServerStats* pSteamGameServerStats, CSteamID* steamIDUser, const char* pchName) {
	return pSteamGameServerStats->ClearUserAchievement(*steamIDUser, pchName);
}

