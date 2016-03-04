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
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_RequestCurrentStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->RequestCurrentStats( );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_SetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_SetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_UpdateAvgRateStat( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t flCountThisSession, double_t* dSessionLength ) {
	return lpSteamUserStats->UpdateAvgRateStat( pchName, flCountThisSession, *dSessionLength );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetAchievement( pchName, (bool*)pbAchieved );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_SetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->SetAchievement( pchName );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_ClearAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->ClearAchievement( pchName );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetAchievementAndUnlockTime( pchName, (bool*)pbAchieved, punUnlockTime );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_StoreStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->StoreStats( );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementIcon( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->GetAchievementIcon( pchName );
}
BS_I
DLL_FUNCTION(const char*) BS_UserStats_GetAchievementDisplayAttribute( ISteamUserStats* lpSteamUserStats, const char* pchName, const char* pchKey ) {
	return lpSteamUserStats->GetAchievementDisplayAttribute( pchName, pchKey );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_IndicateAchievementProgress( ISteamUserStats* lpSteamUserStats, const char* pchName, uint32_t nCurProgress, uint32_t nMaxProgress ) {
	return lpSteamUserStats->IndicateAchievementProgress( pchName, nCurProgress, nMaxProgress );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetNumAchievements( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->GetNumAchievements( );
}
BS_I
DLL_FUNCTION(const char*) BS_UserStats_GetAchievementName( ISteamUserStats* lpSteamUserStats, uint32_t iAchievement ) {
	return lpSteamUserStats->GetAchievementName( iAchievement );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestUserStats( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser ) {
	return new uint64_t( lpSteamUserStats->RequestUserStats( *steamIDUser ) );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetUserStat( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, (int32_t*)pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetUserStatF( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetUserAchievement( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetUserAchievement( *steamIDUser, pchName, (bool*)pbAchieved );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetUserAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetUserAchievementAndUnlockTime( *steamIDUser, pchName, (bool*)pbAchieved, punUnlockTime );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_ResetAllStats( ISteamUserStats* lpSteamUserStats, uint32_t bAchievementsToo ) {
	return lpSteamUserStats->ResetAllStats( bAchievementsToo != 0 );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_FindOrCreateLeaderboard( ISteamUserStats* lpSteamUserStats, const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) {
	return new uint64_t( lpSteamUserStats->FindOrCreateLeaderboard( pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType ) );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_FindLeaderboard( ISteamUserStats* lpSteamUserStats, const char *pchLeaderboardName ) {
	return new uint64_t( lpSteamUserStats->FindLeaderboard( pchLeaderboardName ) );
}
BS_I
DLL_FUNCTION(const char*) BS_UserStats_GetLeaderboardName( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardName( *hSteamLeaderboard );
}
BS_I
DLL_FUNCTION(int) BS_UserStats_GetLeaderboardEntryCount( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardEntryCount( *hSteamLeaderboard );
}
BS_I
DLL_FUNCTION(ELeaderboardSortMethod) BS_UserStats_GetLeaderboardSortMethod( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardSortMethod( *hSteamLeaderboard );
}
BS_I
DLL_FUNCTION(ELeaderboardDisplayType) BS_UserStats_GetLeaderboardDisplayType( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardDisplayType( *hSteamLeaderboard );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_DownloadLeaderboardEntries( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntries( *hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd ) );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_DownloadLeaderboardEntriesForUsers( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, CSteamID* prgUsers, int cUsers ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntriesForUsers( *hSteamLeaderboard, prgUsers, cUsers ) );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetDownloadedLeaderboardEntry( ISteamUserStats* lpSteamUserStats, SteamLeaderboardEntries_t* hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax ) {
	return lpSteamUserStats->GetDownloadedLeaderboardEntry( *hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_UploadLeaderboardScore( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32_t* pScoreDetails, int cScoreDetailsCount ) {
	return new uint64_t(lpSteamUserStats->UploadLeaderboardScore( *hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount ));
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_AttachLeaderboardUGC( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, UGCHandle_t* hUGC ) {
	return new uint64_t( lpSteamUserStats->AttachLeaderboardUGC( *hSteamLeaderboard, *hUGC ) );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_GetNumberOfCurrentPlayers( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->GetNumberOfCurrentPlayers( ) );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestGlobalAchievementPercentages( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalAchievementPercentages( ) );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool* pbAchieved ) {
	return lpSteamUserStats->GetMostAchievedAchievementInfo( pchName, unNameBufLen, pflPercent, pbAchieved );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetNextMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, int iIteratorPrevious, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool *pbAchieved ) {
	return lpSteamUserStats->GetNextMostAchievedAchievementInfo( iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetAchievementAchievedPercent( ISteamUserStats* lpSteamUserStats, const char *pchName, float *pflPercent ) {
	return lpSteamUserStats->GetAchievementAchievedPercent( pchName, pflPercent );
}
BS_I
DLL_FUNCTION(SteamAPICall_t*) BS_UserStats_RequestGlobalStats( ISteamUserStats* lpSteamUserStats, int nHistoryDays ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalStats( nHistoryDays ) );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatLL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatHistoryLL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64 *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}
BS_I
DLL_FUNCTION(uint32_t) BS_UserStats_GetGlobalStatHistoryD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}
#pragma comment(linker, "/EXPORT:BS_UserStats_GetGlobalStatHistoryD=_BS_UserStats_GetGlobalStatHistoryD@16")
