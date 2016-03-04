;	BlitzSteam - Steam wrapper for Blitz
;	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
;
;	This program is free software: you can redistribute it and/or modify
;	it under the terms of the GNU Lesser General Public License as
;	published by the Free Software Foundation, either version 3 of the 
;	License, or (at your option) any later version.
;
;	This program is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;
;	You should have received a copy of the GNU Lesser General Public License
;	along with this program.  If not, see <http:;www.gnu.org/licenses/>.

.lib "BlitzSteam.dll"

; Networking ------------------------------------------------------------------
BS_Networking%()
BS_GameServerNetworking%()
BS_Networking_SendP2PPacket%(pSteamNetworking%, pSteamIDRemote%, pubData*, cubData%, eP2PSendType%, nChannel%)
BS_Networking_SendP2PPacketEx%(pSteamNetworking%, pSteamIDRemote%, pubData%, cubData%, eP2PSendType%, nChannel%) : "BS_Networking_SendP2PPacket"
BS_Networking_IsP2PPacketAvailable%(pSteamNetworking%, pcubMsgSize*, nChannel%)
BS_Networking_IsP2PPacketAvailableEx%(pSteamNetworking%, pcubMsgSize*, nChannel%) : "BS_Networking_IsP2PPacketAvailable"
BS_Networking_ReadP2PPacket%(pSteamNetworking%, pubDest*, cubDest%, pcubMsgSize*, pSteamIDRemote%, nChannel%)
BS_Networking_ReadP2PPacketEx%(pSteamNetworking%, pubDest%, cubDest%, pcubMsgSize%, pSteamIDRemote%, nChannel%) : "BS_Networking_ReadP2PPacket"
BS_Networking_AcceptP2PSessionWithUser%(pSteamNetworking%, pSteamIDRemote%)
BS_Networking_CloseP2PSessionWithUser%(pSteamNetworking%, pSteamIDRemote%)
BS_Networking_CloseP2PChannelWithUser%(pSteamNetworking%, pSteamIDRemote%, nChannel%)
BS_Networking_GetP2PSessionState%(pSteamNetworking%, pSteamIDRemote%, pConnectionState*)
BS_Networking_AllowP2PPacketRelay%(pSteamNetworking%, bAllow%)

; User ------------------------------------------------------------------------
BS_User%()
BS_User_GetHSteamUser%(lpSteamUser%)
BS_User_IsLoggedOn%(lpSteamUser%)
BS_User_GetSteamID%(lpSteamUser%)
BS_User_InitiateGameConnection%(lpSteamUser%, pAuthBlob*, cbMaxAuthBlob%, SteamIDGameServer%, unIPServer%, usPortServer%, bSecure%)
BS_User_TerminateGameConnection(lpSteamUser%, unIPServer%, usPortServer%)
BS_User_TrackAppUsageEvent(lpSteamUser%, gameId%, eAppUsageEvent%, pchExtraInfo$)
BS_User_GetUserDataFolder%(lpSteamUser%, pchBuffer*, cubBuffer%)
BS_User_StartVoiceRecording(lpSteamUser%)
BS_User_StopVoiceRecording(lpSteamUser%)
BS_User_GetAvailableVoice%(lpSteamUser%, pcbCompressed*, pcbUncompressed*, nUncompressedVoiceDesiredSampleRate%)
BS_User_GetAvailableVoiceEx%(lpSteamUser%, pcbCompressed%, pcbUncompressed%, nUncompressedVoiceDesiredSampleRate%) : "BS_User_GetAvailableVoice"
BS_User_GetVoice%(lpSteamUser%, bWantCompressed%, pDestBuffer*, cbDestBufferSize%, nBytesWritten*, bWantUncompressed%, pUncompressedDestBuffer*, cbUncompressedDestBufferSize%, nUncompressBytesWritten*, nUncompressedVoiceDesiredSampleRate%)
BS_User_GetVoiceEx%(lpSteamUser%, bWantCompressed%, pDestBuffer*, cbDestBufferSize%, nBytesWritten%, bWantUncompressed%, pUncompressedDestBuffer*, cbUncompressedDestBufferSize%, nUncompressBytesWritten%, nUncompressedVoiceDesiredSampleRate%) : "BS_User_GetVoice"
BS_User_DecompressVoice(lpSteamUser%, pCompressed*, cbCompressed%, pDestBuffer*, cbDestBufferSize%, nBytesWritten*, nDesiredSampleRate%)
BS_User_DecompressVoiceEx(lpSteamUser%, pCompressed*, cbCompressed%, pDestBuffer*, cbDestBufferSize%, nBytesWritten%, nDesiredSampleRate%) : "BS_User_DecompressVoice"
BS_User_GetVoiceOptimalSampleRate%(lpSteamUser%)
BS_User_GetAuthSessionTicket%(lpSteamUser%, pTicket*, cbMaxTicket%, pcbTicket*)
BS_User_GetAuthSessionTicketEx%(lpSteamUser%, pTicket*, cbMaxTicket%, pcbTicket%) : "BS_User_GetAuthSessionTicket"
BS_User_BeginAuthSession%(lpSteamUser%, pAuthTicket*, cbAuthTicker%, steamID%)
BS_User_EndAuthSession(lpSteamUser%, steamID%)
BS_User_CancelAuthTicket(lpSteamUser%, hAuthTicket%)
BS_User_UserHasLicenseForApp%(lpSteamUser%, steamID%, appID%)
BS_User_IsBehindNAT%(lpSteamUser%)
BS_User_AdvertiseGame%(lpSteamUser%, steamIDGameServer%, unIPServer%, usPortServer%)
BS_User_RequestEncryptedAppTicket%(lpSteamUser%, pDataToInclude*, cbDataToInclude%)
BS_User_GetEncryptedAppTicket%(lpSteamUser%, pTicket*, cbMaxTicket%, pcbTicket*)
BS_User_GetEncryptedAppTicketEx%(lpSteamUser%, pTicket*, cbMaxTicket%, pcbTicket%) : "BS_User_GetEncryptedAppTicket"
BS_User_GetGameBadgeLevel%(lpSteamUser%, nSeries%, bFoil%)
BS_User_GetPlayerSteamLevel%(lpSteamUser%)
BS_User_RequestStoreAuthURL%(lpSteamUser%, pchRedirectUrl$)

; UserStats -------------------------------------------------------------------
BS_UserStats%()
BS_UserStats_RequestCurrentStats%(lpSteamUserStats%)
BS_UserStats_GetStat%(lpSteamUserStats%, pchName$, pData*)
BS_UserStats_GetStatEx%(lpSteamUserStats%, pchName$, pData%) : "BS_UserStats_GetStat"
BS_UserStats_GetStatF%(lpSteamUserStats%, pchName$, pData*)
BS_UserStats_GetStatFEx%(lpSteamUserStats%, pchName$, pData%) : "BS_UserStats_GetStatF"
BS_UserStats_SetStat%(lpSteamUserStats%, pchName$, pData%)
BS_UserStats_SetStatF%(lpSteamUserStats%, pchName$, pData#)
BS_UserStats_UpdateAvgRateStat%(lpSteamUserStats%, pchName$, flCountThisSession#, dSessionLength%)
BS_UserStats_GetAchievement%(lpSteamUserStats%, pchName$, pbAchieved*)
BS_UserStats_GetAchievementEx%(lpSteamUserStats%, pchName$, pbAchieved%) : "BS_UserStats_GetAchievement"
BS_UserStats_SetAchievement%(lpSteamUserStats%, pchName$)
BS_UserStats_ClearAchievement%(lpSteamUserStats%, pchName$)
BS_UserStats_GetAchievementAndUnlockTime%(lpSteamUserStats%, pchName$, pbAchieved*, punUnlockTime*)
BS_UserStats_GetAchievementAndUnlockTimeEx%(lpSteamUserStats%, pchName$, pbAchieved%, punUnlockTime%) : "BS_UserStats_GetAchievementAndUnlockTime"
BS_UserStats_StoreStats%(lpSteamUserStats%)
BS_UserStats_GetAchievementIcon%(lpSteamUserStats%, pchName$)
BS_UserStats_GetAchievementDisplayAttribute$(lpSteamUserStats%, pchName$, pchKey$)
BS_UserStats_IndicateAchievementProgress%(lpSteamUserStats%, pchName$, nCurProgress%, nMaxProgress%)
BS_UserStats_GetNumAchievements%(lpSteamUserStats%)
BS_UserStats_GetAchievementName$(lpSteamUserStats%, iAchievement%)
BS_UserStats_RequestUserStats%(lpSteamUserStats%, steamIDUser%)
BS_UserStats_GetUserStat%(lpSteamUserStats%, steamIDUser%, pchName$, pData*)
BS_UserStats_GetUserStatEx%(lpSteamUserStats%, steamIDUser%, pchName$, pData%) : "BS_UserStats_GetUserStat"
BS_UserStats_GetUserStatF%(lpSteamUserStats%, steamIDUser%, pchName$, pData*)
BS_UserStats_GetUserStatFEx%(lpSteamUserStats%, steamIDUser%, pchName$, pData%) : "BS_UserStats_GetUserStatF"
BS_UserStats_GetUserAchievement%(lpSteamUserStats%, steamIDUser%, pchName$, pbAchieved*)
BS_UserStats_GetUserAchievementEx%(lpSteamUserStats%, steamIDUser%, pchName$, pbAchieved%) : "BS_UserStats_GetUserAchievement"
BS_UserStats_GetUserAchievementAndUnlockTime%(lpSteamUserStats%, steamIDUser%, pchName$, pbAchieved*, punUnlockTime*)
BS_UserStats_GetUserAchievementAndUnlockTimeEx%(lpSteamUserStats%, steamIDUser%, pchName$, pbAchieved%, punUnlockTime%) : "BS_UserStats_GetUserAchievementAndUnlockTime"
BS_UserStats_ResetAllStats%(lpSteamUserStats%, bAchievementsToo%)
BS_UserStats_FindOrCreateLeaderboard%(lpSteamUserStats%, pchLeaderboardName$, eLeaderboardSortMethod%, eLeaderboardDisplayType%)
BS_UserStats_FindLeaderboard%(lpSteamUserStats%, pchLeaderboardName$)
BS_UserStats_GetLeaderboardName$(lpSteamUserStats%, hSteamLeaderboard%)
BS_UserStats_GetLeaderboardEntryCount%(lpSteamUserStats%, hSteamLeaderboard%)
BS_UserStats_GetLeaderboardSortMethod%(lpSteamUserStats%, hSteamLeaderboard%)
BS_UserStats_GetLeaderboardDisplayType%(lpSteamUserStats%, hSteamLeaderboard%)
BS_UserStats_DownloadLeaderboardEntries%(lpSteamUserStats%, hSteamLeaderboard%, eLeaderboardDataRequest%, nRangeStart%, nRangeEnd%)
BS_UserStats_DownloadLeaderboardEntriesForUsers%(lpSteamUserStats%, hSteamLeaderboard%, prgUsers*, cUsers%)
BS_UserStats_DownloadLeaderboardEntriesForUsersEx%(lpSteamUserStats%, hSteamLeaderboard%, prgUsers%, cUsers%) : "BS_UserStats_DownloadLeaderboardEntriesForUsers"
BS_UserStats_GetDownloadedLeaderboardEntry%(lpSteamUsers%, hSteamLeaderboardEntries%, index%, pLeaderboardEntry*, pDetails*, cDetailsMax%)
BS_UserStats_GetDownloadedLeaderboardEntryEx%(lpSteamUsers%, hSteamLeaderboardEntries%, index%, pLeaderboardEntry%, pDetails%, cDetailsMax%)
BS_UserStats_UploadLeaderboardScore%(lpSteamUserStats%, hSteamLeaderboard%, eLeaderboardUploadScoreMethod%, nScore%, pScoreDetails*, cScoreDetailsCount%)
BS_UserStats_UploadLeaderboardScoreEx%(lpSteamUserStats%, hSteamLeaderboard%, eLeaderboardUploadScoreMethod%, nScore%, pScoreDetails%, cScoreDetailsCount%) : "BS_UserStats_UploadLeaderboardScore"
BS_UserStats_AttachLeaderboardUGC%(lpSteamUserStats%, hSteamLeaderboard%, hUGB%)
BS_UserStats_GetNumberOfCurrentPlayers%(lpSteamUserstats%)
BS_UserStats_RequestGlobalAchievementPercentages%(lpSteamUserStats%)
BS_UserStats_GetMostAchievedAchievementInfo%(lpSteamUserStats%, pchName$, unNameBufLen%, pflPercent*, pbAchieved*)
BS_UserStats_GetMostAchievedAchievementInfoEx%(lpSteamUserStats%, pchName$, unNameBufLen%, pflPercent%, pbAchieved%) : "BS_UserStats_GetMostAchievedAchievementInfo"
BS_UserStats_GetNextMostAchievedAchievementInfo%(lpSteamUserStats%, iIteratorPrevious%, pchName$, unNameBufLen%, pflPercent*, pbAchieved*)
BS_UserStats_GetNextMostAchievedAchievementInfoEx%(lpSteamUserStats%, iIteratorPrevious%, pchName$, unNameBufLen%, pflPercent%, pbAchieved%) : "BS_UserStats_GetNextMostAchievedAchievementInfo"
BS_UserStats_GetAchievementAchievedPercent%(lpSteamUserStats%, pchName$, pflPercent*)
BS_UserStats_GetAchievementAchievedPercentEx%(lpSteamUserStats%, pchName$, pflPercent%) : "BS_UserStats_GetAchievementAchievedPercent"
BS_UserStats_RequestGlobalStats%(lpSteamUserStats%, nHistoryDays%)
BS_UserStats_GetGlobalStatLL%(lpSteamUserStats, pchStatName$, pData%)
BS_UserStats_GetGlobalStatD%(lpSteamUserStats, pchStatName$, pData%)
BS_UserStats_GetGlobalStatHistoryLL%(lpSteamUserStats, pchStatName$, pData*, cubData%)
BS_UserStats_GetGlobalStatHistoryLLEx%(lpSteamUserStats, pchStatName$, pData%, cubData%) : "BS_UserStats_GetGlobalStatHistoryLL"
BS_UserStats_GetGlobalStatHistoryD%(lpSteamUserStats, pchStatName$, pData*, cubData%)
BS_UserStats_GetGlobalStatHistoryDEx%(lpSteamUserStats, pchStatName$, pData%, cubData%) : "BS_UserStats_GetGlobalStatHistoryD"

; -- Interfaces
BS_HTTP%()
BS_GameServerHTTP%()
BS_Inventory%()
BS_GameServerInventory%()
BS_Matchmaking%()
BS_MatchmakingServers%()
BS_Music%()
BS_MusicRemote%()
BS_RemoteStorage%()
BS_Screenshots%()
BS_UGC%()
BS_GameServerUGC%()
BS_UnifiedMessages%()
BS_Utils%()
BS_GameServerUtils%()
BS_Video%()

; Helpers ---------------------------------------------------------------------
; -- Generic
BS_Helper_FormatUnixTime$(unixTime%, pchFormat$)
; -- Memory
BS_Memory_Alloc%(iSize%)
BS_Memory_ReAlloc%(pMemory%, iSize%)
BS_Memory_Free(pMemory%)
BS_Memory_PeekByte%(pMemory%, offset%)
BS_Memory_PeekShort%(pMemory%, offset%)
BS_Memory_PeekInt%(pMemory%, offset%)
BS_Memory_PeekFloat#(pMemory%, offset%)
BS_Memory_PokeByte(pMemory%, offset%, value%)
BS_Memory_PokeShort(pMemory%, offset%, value%)
BS_Memory_PokeInt(pMemory%, offset%, value%)
BS_Memory_PokeFloat(pMemory%, offset%, value#)