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

DLL_FUNCTION(ISteamUserStats*) BS_UserStats() {
	return SteamUserStats();
}
#pragma comment(linker, "/EXPORT:BS_UserStats=_BS_UserStats@0")

DLL_FUNCTION(uint32_t) BS_UserStats_RequestCurrentStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->RequestCurrentStats( );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_RequestCurrentStats=_BS_UserStats_RequestCurrentStats@4")

DLL_FUNCTION(uint32_t) BS_UserStats_GetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetStat=_BS_UserStats_GetStat@12")

DLL_FUNCTION(uint32_t) BS_UserStats_GetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetStatF=_BS_UserStats_GetStatF@12")

DLL_FUNCTION(uint32_t) BS_UserStats_SetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_SetStat=_BS_UserStats_SetStat@12")

DLL_FUNCTION(uint32_t) BS_UserStats_SetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_SetStatF=_BS_UserStats_SetStatF@12")

DLL_FUNCTION(uint32_t) BS_UserStats_UpdateAvgRateStat( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t flCountThisSession, double_t* dSessionLength ) {
	return lpSteamUserStats->UpdateAvgRateStat( pchName, flCountThisSession, *dSessionLength );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_UpdateAvgRateStat=_BS_UserStats_UpdateAvgRateStat@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetAchievement( pchName, (bool*)pbAchieved );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievement=_BS_UserStats_GetAchievement@12")

DLL_FUNCTION(uint32_t) BS_UserStats_SetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->SetAchievement( pchName );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_SetAchievement=_BS_UserStats_SetAchievement@8")

DLL_FUNCTION(uint32_t) BS_UserStats_ClearAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->ClearAchievement( pchName );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_ClearAchievement=_BS_UserStats_ClearAchievement@8")

DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetAchievementAndUnlockTime( pchName, (bool*)pbAchieved, punUnlockTime );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievementAndUnlockTime=_BS_UserStats_GetAchievementAndUnlockTime@16")

DLL_FUNCTION(uint32_t) BS_UserStats_StoreStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->StoreStats( );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_StoreStats=_BS_UserStats_StoreStats@4")

DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementIcon( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->GetAchievementIcon( pchName );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievementIcon=_BS_UserStats_GetAchievementIcon@8")

DLL_FUNCTION(const char*) BS_UserStats_GetAchievementDisplayAttribute( ISteamUserStats* lpSteamUserStats, const char* pchName, const char* pchKey ) {
	return lpSteamUserStats->GetAchievementDisplayAttribute( pchName, pchKey );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievementDisplayAttribute=_BS_UserStats_GetAchievementDisplayAttribute@12")

DLL_FUNCTION(uint32_t) BS_UserStats_IndicateAchievementProgress( ISteamUserStats* lpSteamUserStats, const char* pchName, uint32_t nCurProgress, uint32_t nMaxProgress ) {
	return lpSteamUserStats->IndicateAchievementProgress( pchName, nCurProgress, nMaxProgress );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_IndicateAchievementProgress=_BS_UserStats_IndicateAchievementProgress@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetNumAchievements( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->GetNumAchievements( );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetNumAchievements=_BS_UserStats_GetNumAchievements@4")

DLL_FUNCTION(const char*) BS_UserStats_GetAchievementName( ISteamUserStats* lpSteamUserStats, uint32_t iAchievement ) {
	return lpSteamUserStats->GetAchievementName( iAchievement );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievementName=_BS_UserStats_GetAchievementName@8")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestUserStats( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser ) {
	return new uint64_t( lpSteamUserStats->RequestUserStats( *steamIDUser ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_RequestUserStats=_BS_UserStats_RequestUserStats@8")

DLL_FUNCTION(uint32_t) BS_UserStats_GetUserStat( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, (int32_t*)pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetUserStat=_BS_UserStats_GetUserStat@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetUserStatF( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetUserStatF=_BS_UserStats_GetUserStatF@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetUserAchievement( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetUserAchievement( *steamIDUser, pchName, (bool*)pbAchieved );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetUserAchievement=_BS_UserStats_GetUserAchievement@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetUserAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetUserAchievementAndUnlockTime( *steamIDUser, pchName, (bool*)pbAchieved, punUnlockTime );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetUserAchievementAndUnlockTime=_BS_UserStats_GetUserAchievementAndUnlockTime@20")

DLL_FUNCTION(uint32_t) BS_UserStats_ResetAllStats( ISteamUserStats* lpSteamUserStats, uint32_t bAchievementsToo ) {
	return lpSteamUserStats->ResetAllStats( bAchievementsToo != 0 );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_ResetAllStats=_BS_UserStats_ResetAllStats@8")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_FindOrCreateLeaderboard( ISteamUserStats* lpSteamUserStats, const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) {
	return new uint64_t( lpSteamUserStats->FindOrCreateLeaderboard( pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_FindOrCreateLeaderboard=_BS_UserStats_FindOrCreateLeaderboard@16")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_FindLeaderboard( ISteamUserStats* lpSteamUserStats, const char *pchLeaderboardName ) {
	return new uint64_t( lpSteamUserStats->FindLeaderboard( pchLeaderboardName ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_FindLeaderboard=_BS_UserStats_FindLeaderboard@8")

DLL_FUNCTION(const char*) BS_UserStats_GetLeaderboardName( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardName( *hSteamLeaderboard );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetLeaderboardName=_BS_UserStats_GetLeaderboardName@8")

DLL_FUNCTION(int) BS_UserStats_GetLeaderboardEntryCount( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardEntryCount( *hSteamLeaderboard );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetLeaderboardEntryCount=_BS_UserStats_GetLeaderboardEntryCount@8")

DLL_FUNCTION(ELeaderboardSortMethod) BS_UserStats_GetLeaderboardSortMethod( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardSortMethod( *hSteamLeaderboard );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetLeaderboardSortMethod=_BS_UserStats_GetLeaderboardSortMethod@8")

DLL_FUNCTION(ELeaderboardDisplayType) BS_UserStats_GetLeaderboardDisplayType( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardDisplayType( *hSteamLeaderboard );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetLeaderboardDisplayType=_BS_UserStats_GetLeaderboardDisplayType@8")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_DownloadLeaderboardEntries( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntries( *hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_DownloadLeaderboardEntries=_BS_UserStats_DownloadLeaderboardEntries@20")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_DownloadLeaderboardEntriesForUsers( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, CSteamID* prgUsers, int cUsers ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntriesForUsers( *hSteamLeaderboard, prgUsers, cUsers ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_DownloadLeaderboardEntriesForUsers=_BS_UserStats_DownloadLeaderboardEntriesForUsers@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetDownloadedLeaderboardEntry( ISteamUserStats* lpSteamUserStats, SteamLeaderboardEntries_t* hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax ) {
	return lpSteamUserStats->GetDownloadedLeaderboardEntry( *hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetDownloadedLeaderboardEntry=_BS_UserStats_GetDownloadedLeaderboardEntry@24")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_UploadLeaderboardScore( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32_t* pScoreDetails, int cScoreDetailsCount ) {
	return new uint64_t(lpSteamUserStats->UploadLeaderboardScore( *hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount ));
}
#pragma comment(linker, "/EXPORT:BS_UserStats_UploadLeaderboardScore=_BS_UserStats_UploadLeaderboardScore@24")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_AttachLeaderboardUGC( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, UGCHandle_t* hUGC ) {
	return new uint64_t( lpSteamUserStats->AttachLeaderboardUGC( *hSteamLeaderboard, *hUGC ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_AttachLeaderboardUGC=_BS_UserStats_AttachLeaderboardUGC@12")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_GetNumberOfCurrentPlayers( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->GetNumberOfCurrentPlayers( ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetNumberOfCurrentPlayers=_BS_UserStats_GetNumberOfCurrentPlayers@4")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestGlobalAchievementPercentages( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalAchievementPercentages( ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_RequestGlobalAchievementPercentages=_BS_UserStats_RequestGlobalAchievementPercentages@4")

DLL_FUNCTION(uint32_t) BS_UserStats_GetMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool* pbAchieved ) {
	return lpSteamUserStats->GetMostAchievedAchievementInfo( pchName, unNameBufLen, pflPercent, pbAchieved );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetMostAchievedAchievementInfo=_BS_UserStats_GetMostAchievedAchievementInfo@20")

DLL_FUNCTION(uint32_t) BS_UserStats_GetNextMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, int iIteratorPrevious, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool *pbAchieved ) {
	return lpSteamUserStats->GetNextMostAchievedAchievementInfo( iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetNextMostAchievedAchievementInfo=_BS_UserStats_GetNextMostAchievedAchievementInfo@24")

DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementAchievedPercent( ISteamUserStats* lpSteamUserStats, const char *pchName, float *pflPercent ) {
	return lpSteamUserStats->GetAchievementAchievedPercent( pchName, pflPercent );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetAchievementAchievedPercent=_BS_UserStats_GetAchievementAchievedPercent@12")

DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestGlobalStats( ISteamUserStats* lpSteamUserStats, int nHistoryDays ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalStats( nHistoryDays ) );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_RequestGlobalStats=_BS_UserStats_RequestGlobalStats@8")

DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatLL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetGlobalStatLL=_BS_UserStats_GetGlobalStatLL@12")

DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetGlobalStatD=_BS_UserStats_GetGlobalStatD@12")

DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatHistoryLL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64 *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetGlobalStatHistoryLL=_BS_UserStats_GetGlobalStatHistoryLL@16")

DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatHistoryD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetGlobalStatHistoryD=_BS_UserStats_GetGlobalStatHistoryD@16")
