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
// Purpose: Functions for accessing stats, achievements, and leaderboard information
//-----------------------------------------------------------------------------
DLL(ISteamUserStats*) BS_SteamUserStats() {
	return SteamUserStats();
}

// Ask the server to send down this user's data and achievements for this game
//CALL_BACK(UserStatsReceived_t)
DLL(uint32_t) BS_ISteamUserStats_RequestCurrentStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->RequestCurrentStats( );
}

// Data accessors
DLL(uint32_t) BS_ISteamUserStats_GetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}

DLL(uint32_t) BS_ISteamUserStats_GetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetStat( pchName, pData );
}

// Set / update data
DLL(uint32_t) BS_ISteamUserStats_SetStat( ISteamUserStats* lpSteamUserStats, const char* pchName, int32_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}

DLL(uint32_t) BS_ISteamUserStats_SetStatF( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t pData ) {
	return lpSteamUserStats->SetStat( pchName, pData );
}

DLL(uint32_t) BS_ISteamUserStats_UpdateAvgRateStat( ISteamUserStats* lpSteamUserStats, const char* pchName, float_t flCountThisSession, double_t* dSessionLength ) {
	return lpSteamUserStats->UpdateAvgRateStat( pchName, flCountThisSession, *dSessionLength );
}

// Achievement flag accessors
DLL(uint32_t) BS_ISteamUserStats_GetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetAchievement( pchName, (bool*)pbAchieved );
}

DLL(uint32_t) BS_ISteamUserStats_SetAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->SetAchievement( pchName );
}

DLL(uint32_t) BS_ISteamUserStats_ClearAchievement( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->ClearAchievement( pchName );
}

// Get the achievement status, and the time it was unlocked if unlocked.
// If the return value is true, but the unlock time is zero, that means it was unlocked before Steam 
// began tracking achievement unlock times (December 2009). Time is seconds since January 1, 1970.
DLL(uint32_t) BS_ISteamUserStats_GetAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetAchievementAndUnlockTime( pchName, (bool*)pbAchieved, punUnlockTime );
}

// Store the current data on the server, will get a callback when set
// And one callback for every new achievement
//
// If the callback has a result of k_EResultInvalidParam, one or more stats 
// uploaded has been rejected, either because they broke constraints
// or were out of date. In this case the server sends back updated values.
// The stats should be re-iterated to keep in sync.
DLL(uint32_t) BS_ISteamUserStats_StoreStats( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->StoreStats( );
}

// Achievement / GroupAchievement metadata

// Gets the icon of the achievement, which is a handle to be used in ISteamUtils::GetImageRGBA(), or 0 if none set. 
// A return value of 0 may indicate we are still fetching data, and you can wait for the UserAchievementIconFetched_t callback
// which will notify you when the bits are ready. If the callback still returns zero, then there is no image set for the
// specified achievement.
DLL(uint32_t) BS_ISteamUserStats_GetAchievementIcon( ISteamUserStats* lpSteamUserStats, const char* pchName ) {
	return lpSteamUserStats->GetAchievementIcon( pchName );
}

// Get general attributes for an achievement. Accepts the following keys:
// - "name" and "desc" for retrieving the localized achievement name and description (returned in UTF8)
// - "hidden" for retrieving if an achievement is hidden (returns "0" when not hidden, "1" when hidden)
DLL(const char*) BS_ISteamUserStats_GetAchievementDisplayAttribute( ISteamUserStats* lpSteamUserStats, const char* pchName, const char* pchKey ) {
	return lpSteamUserStats->GetAchievementDisplayAttribute( pchName, pchKey );
}

// Achievement progress - triggers an AchievementProgress callback, that is all.
// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
DLL(uint32_t) BS_ISteamUserStats_IndicateAchievementProgress( ISteamUserStats* lpSteamUserStats, const char* pchName, uint32_t nCurProgress, uint32_t nMaxProgress ) {
	return lpSteamUserStats->IndicateAchievementProgress( pchName, nCurProgress, nMaxProgress );
}

// Used for iterating achievements. In general games should not need these functions because they should have a
// list of existing achievements compiled into them
DLL(uint32_t) BS_ISteamUserStats_GetNumAchievements( ISteamUserStats* lpSteamUserStats ) {
	return lpSteamUserStats->GetNumAchievements( );
}

// Get achievement name iAchievement in [0,GetNumAchievements)
DLL(const char*) BS_ISteamUserStats_GetAchievementName( ISteamUserStats* lpSteamUserStats, uint32_t iAchievement ) {
	return lpSteamUserStats->GetAchievementName( iAchievement );
}

// Friends stats & achievements

// downloads stats for the user
// returns a UserStatsReceived_t received when completed
// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
//CALL_RESULT(UserStatsReceived_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_RequestUserStats( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser ) {
	return new uint64_t( lpSteamUserStats->RequestUserStats( *steamIDUser ) );
}

// requests stat information for a user, usable after a successful call to RequestUserStats()
DLL(uint32_t) BS_ISteamUserStats_GetUserStat( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, uint32_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, (int32_t*)pData );
}

DLL(uint32_t) BS_ISteamUserStats_GetUserStatF( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, float_t* pData ) {
	return lpSteamUserStats->GetUserStat( *steamIDUser, pchName, pData );
}

DLL(uint32_t) BS_ISteamUserStats_GetUserAchievement( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved ) {
	return lpSteamUserStats->GetUserAchievement( *steamIDUser, pchName, (bool*)pbAchieved );
}

// See notes for GetAchievementAndUnlockTime above
DLL(uint32_t) BS_ISteamUserStats_GetUserAchievementAndUnlockTime( ISteamUserStats* lpSteamUserStats, CSteamID* steamIDUser, const char* pchName, bool* pbAchieved, uint32_t* punUnlockTime ) {
	return lpSteamUserStats->GetUserAchievementAndUnlockTime( *steamIDUser, pchName, (bool*)pbAchieved, punUnlockTime );
}

// Reset stats 
DLL(uint32_t) BS_ISteamUserStats_ResetAllStats( ISteamUserStats* lpSteamUserStats, uint32_t bAchievementsToo ) {
	return lpSteamUserStats->ResetAllStats( bAchievementsToo != 0 );
}

// Leaderboard functions

// asks the Steam back-end for a leaderboard by name, and will create it if it's not yet
// This call is asynchronous, with the result returned in LeaderboardFindResult_t
//CALL_RESULT(LeaderboardFindResult_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_FindOrCreateLeaderboard( ISteamUserStats* lpSteamUserStats, const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) {
	return new uint64_t( lpSteamUserStats->FindOrCreateLeaderboard( pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType ) );
}

// as above, but won't create the leaderboard if it's not found
// This call is asynchronous, with the result returned in LeaderboardFindResult_t
//CALL_RESULT(LeaderboardFindResult_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_FindLeaderboard( ISteamUserStats* lpSteamUserStats, const char *pchLeaderboardName ) {
	return new uint64_t( lpSteamUserStats->FindLeaderboard( pchLeaderboardName ) );
}

// returns the name of a leaderboard
DLL(const char*) BS_ISteamUserStats_GetLeaderboardName( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardName( *hSteamLeaderboard );
}

// returns the total number of entries in a leaderboard, as of the last request
DLL(int) BS_ISteamUserStats_GetLeaderboardEntryCount( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardEntryCount( *hSteamLeaderboard );
}

// returns the sort method of the leaderboard
DLL(ELeaderboardSortMethod) BS_ISteamUserStats_GetLeaderboardSortMethod( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardSortMethod( *hSteamLeaderboard );
}

// returns the display type of the leaderboard
DLL(ELeaderboardDisplayType) BS_ISteamUserStats_GetLeaderboardDisplayType( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard ) {
	return lpSteamUserStats->GetLeaderboardDisplayType( *hSteamLeaderboard );
}

// Asks the Steam back-end for a set of rows in the leaderboard.
// This call is asynchronous, with the result returned in LeaderboardScoresDownloaded_t
// LeaderboardScoresDownloaded_t will contain a handle to pull the results from GetDownloadedLeaderboardEntries() (below)
// You can ask for more entries than exist, and it will return as many as do exist.
// k_ELeaderboardDataRequestGlobal requests rows in the leaderboard from the full table, with nRangeStart & nRangeEnd in the range [1, TotalEntries]
// k_ELeaderboardDataRequestGlobalAroundUser requests rows around the current user, nRangeStart being negate
//   e.g. DownloadLeaderboardEntries( hLeaderboard, k_ELeaderboardDataRequestGlobalAroundUser, -3, 3 ) will return 7 rows, 3 before the user, 3 after
// k_ELeaderboardDataRequestFriends requests all the rows for friends of the current user 
//CALL_RESULT(LeaderboardScoresDownloaded_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_DownloadLeaderboardEntries( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntries( *hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd ) );
}
///#####

// as above, but downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers
// if a user doesn't have a leaderboard entry, they won't be included in the result
// a max of 100 users can be downloaded at a time, with only one outstanding call at a time
//CALL_RESULT(LeaderboardScoresDownloaded_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_DownloadLeaderboardEntriesForUsers( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, CSteamID* prgUsers, int cUsers ) {
	return new uint64_t( lpSteamUserStats->DownloadLeaderboardEntriesForUsers( *hSteamLeaderboard, prgUsers, cUsers ) );
}

// Returns data about a single leaderboard entry
// use a for loop from 0 to LeaderboardScoresDownloaded_t::m_cEntryCount to get all the downloaded entries
// e.g.
//		void OnLeaderboardScoresDownloaded( LeaderboardScoresDownloaded_t *pLeaderboardScoresDownloaded )
//		{
//			for ( int index = 0; index < pLeaderboardScoresDownloaded->m_cEntryCount; index++ )
//			{
//				LeaderboardEntry_t leaderboardEntry;
//				int32 details[3];		// we know this is how many we've stored previously
//				GetDownloadedLeaderboardEntry( pLeaderboardScoresDownloaded->m_hSteamLeaderboardEntries, index, &leaderboardEntry, details, 3 );
//				assert( leaderboardEntry.m_cDetails == 3 );
//				...
//			}
// once you've accessed all the entries, the data will be free'd, and the SteamLeaderboardEntries_t handle will become invalid
DLL(uint32_t) BS_ISteamUserStats_GetDownloadedLeaderboardEntry( ISteamUserStats* lpSteamUserStats, SteamLeaderboardEntries_t* hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax ) {
	return lpSteamUserStats->GetDownloadedLeaderboardEntry( *hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax );
}

// Uploads a user score to the Steam back-end.
// This call is asynchronous, with the result returned in LeaderboardScoreUploaded_t
// Details are extra game-defined information regarding how the user got that score
// pScoreDetails points to an array of int32's, cScoreDetailsCount is the number of int32's in the list
//CALL_RESULT(LeaderboardScoreUploaded_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_UploadLeaderboardScore( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32_t* pScoreDetails, int cScoreDetailsCount ) {
	return new uint64_t(lpSteamUserStats->UploadLeaderboardScore( *hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount ));
}

// Attaches a piece of user generated content the user's entry on a leaderboard.
// hContent is a handle to a piece of user generated content that was shared using ISteamUserRemoteStorage::FileShare().
// This call is asynchronous, with the result returned in LeaderboardUGCSet_t.
//CALL_RESULT(LeaderboardUGCSet_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_AttachLeaderboardUGC( ISteamUserStats* lpSteamUserStats, SteamLeaderboard_t* hSteamLeaderboard, UGCHandle_t* hUGC ) {
	return new uint64_t( lpSteamUserStats->AttachLeaderboardUGC( *hSteamLeaderboard, *hUGC ) );
}

// Retrieves the number of players currently playing your game (online + offline)
// This call is asynchronous, with the result returned in NumberOfCurrentPlayers_t
//CALL_RESULT(NumberOfCurrentPlayers_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_GetNumberOfCurrentPlayers( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->GetNumberOfCurrentPlayers( ) );
}

// Requests that Steam fetch data on the percentage of players who have received each achievement
// for the game globally.
// This call is asynchronous, with the result returned in GlobalAchievementPercentagesReady_t.
//CALL_RESULT(GlobalAchievementPercentagesReady_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_RequestGlobalAchievementPercentages( ISteamUserStats* lpSteamUserStats ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalAchievementPercentages( ) );
}

// Get the info on the most achieved achievement for the game, returns an iterator index you can use to fetch
// the next most achieved afterwards.  Will return -1 if there is no data on achievement 
// percentages (ie, you haven't called RequestGlobalAchievementPercentages and waited on the callback).
DLL(uint32_t) BS_ISteamUserStats_GetMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool* pbAchieved ) {
	return lpSteamUserStats->GetMostAchievedAchievementInfo( pchName, unNameBufLen, pflPercent, pbAchieved );
}

// Get the info on the next most achieved achievement for the game. Call this after GetMostAchievedAchievementInfo or another
// GetNextMostAchievedAchievementInfo call passing the iterator from the previous call. Returns -1 after the last
// achievement has been iterated.
DLL(uint32_t) BS_ISteamUserStats_GetNextMostAchievedAchievementInfo( ISteamUserStats* lpSteamUserStats, int iIteratorPrevious, char *pchName, uint32_t unNameBufLen, float *pflPercent, bool *pbAchieved ) {
	return lpSteamUserStats->GetNextMostAchievedAchievementInfo( iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved );
}

// Returns the percentage of users who have achieved the specified achievement.
DLL(uint32_t) BS_ISteamUserStats_GetAchievementAchievedPercent( ISteamUserStats* lpSteamUserStats, const char *pchName, float *pflPercent ) {
	return lpSteamUserStats->GetAchievementAchievedPercent( pchName, pflPercent );
}

// Requests global stats data, which is available for stats marked as "aggregated".
// This call is asynchronous, with the results returned in GlobalStatsReceived_t.
// nHistoryDays specifies how many days of day-by-day history to retrieve in addition
// to the overall totals. The limit is 60.
//CALL_RESULT(GlobalStatsReceived_t)
DLL(SteamAPICall_t*) BS_ISteamUserStats_RequestGlobalStats( ISteamUserStats* lpSteamUserStats, int nHistoryDays ) {
	return new uint64_t( lpSteamUserStats->RequestGlobalStats( nHistoryDays ) );
}

// Gets the lifetime totals for an aggregated stat
DLL(uint32_t) BS_ISteamUserStats_GetGlobalStatL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}

DLL(uint32_t) BS_ISteamUserStats_GetGlobalStatD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double* pData ) {
	return lpSteamUserStats->GetGlobalStat( pchStatName, pData );
}

// Gets history for an aggregated stat. pData will be filled with daily values, starting with today.
// So when called, pData[0] will be today, pData[1] will be yesterday, and pData[2] will be two days ago, 
// etc. cubData is the size in bytes of the pubData buffer. Returns the number of 
// elements actually set.
DLL(uint32_t) BS_ISteamUserStats_GetGlobalStatHistoryL( ISteamUserStats* lpSteamUserStats, const char *pchStatName, int64 *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}

DLL(uint32_t) BS_ISteamUserStats_GetGlobalStatHistoryD( ISteamUserStats* lpSteamUserStats, const char *pchStatName, double *pData, uint32_t cubData ) {
	return lpSteamUserStats->GetGlobalStatHistory( pchStatName, pData, cubData );
}