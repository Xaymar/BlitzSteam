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

; Steam -------------------------------------------------------------------------

; SteamClient -------------------------------------------------------------------
Const BS_EAccountType_Invalid								= 0
Const BS_EAccountType_Individual							= 1
Const BS_EAccountType_Multiseat								= 2
Const BS_EAccountType_Gameserver							= 3
Const BS_EAccountType_AnonGamerserver						= 4
Const BS_EAccountType_Pending								= 5
Const BS_EAccountType_ContentServer							= 6
Const BS_EAccountType_Clan									= 7
Const BS_EAccountType_Chat									= 8
Const BS_EAccountType_ConsoleUser							= 9
Const BS_EAccountType_AnonUser								= 10

Const BS_ECallback_SteamAppListCallbacks					= 3900
Const BS_ECallback_SteamAppsCallbacks						= 1000
Const BS_ECallback_SteamBillingCallbacks					= 400
Const BS_ECallback_SteamContentServerCallbacks				= 600
Const BS_ECallback_SteamControllerCallbacks					= 2800
Const BS_ECallback_SteamFriendsCallbacks					= 300
Const BS_ECallback_SteamGameCoordinatorCallbacks			= 1700
Const BS_ECallback_SteamGameServerCallbacks					= 200
Const BS_ECallback_SteamGameServerItemsCallbacks			= 1500
Const BS_ECallback_SteamGameServerStatsCallbacks			= 1800
Const BS_ECallback_SteamGameStatsCallbacks					= 2000
Const BS_ECallback_SteamHTMLSurfaceCallbacks				= 4500
Const BS_ECallback_SteamMatchmakingCallbacks				= 500
Const BS_ECallback_SteamMusicCallbacks						= 4000
Const BS_ECallback_SteamMusicRemoteCallbacks				= 4100
Const BS_ECallback_SteamNetworkingCallbacks					= 1200
Const BS_ECallback_SteamReservedCallbacks					= 4400
Const BS_ECallback_SteamScreenshotsCallbacks				= 2300
Const BS_ECallback_SteamStreamLauncherCallbacks				= 2600
Const BS_ECallback_SteamStreamClientCallbacks				= 3500
Const BS_ECallback_SteamUserCallbacks						= 100
Const BS_ECallback_SteamUserStatsCallbacks					= 1100
Const BS_ECallback_SteamUtilsCallbacks						= 700
Const BS_ECallback_Steam2AsyncCallbacks						= 1900
Const BS_ECallback_ClientAudioCallbacks						= 2400
Const BS_ECallback_ClientControllerCallbacks				= 2700
Const BS_ECallback_ClientDepotBuilderCallbacks				= 1400
Const BS_ECallback_ClientDeviceAuthCallbacks				= 3000
Const BS_ECallback_ClientFriendsCallbacks					= 800
Const BS_ECallback_ClientHTTPCallbacks						= 2100
Const BS_ECallback_ClientInventoryCallbacks					= 4700
Const BS_ECallback_ClientMusicCallbacks						= 3200
Const BS_ECallback_ClientNetworkDeviceManagerCallbacks		= 3100
Const BS_ECallback_ClientParentalSettingsCallbacks			= 2900
Const BS_ECallback_ClientProductBuilderCallbacks			= 3600
Const BS_ECallback_ClientRemoteStorageCallbacks				= 1300
Const BS_ECallback_ClientRemoteClientManagerCallbacks		= 3300
Const BS_ECallback_ClientRemoteControlManagerCallbacks		= 3800
Const BS_ECallback_ClientReservedCallbacks					= 4300
Const BS_ECallback_ClientScreenshotsCallbacks				= 2200
Const BS_ECallback_ClientShortcutsCallbacks					= 3700
Const BS_ECallback_ClientUGCCallbacks						= 3400
Const BS_ECallback_ClientUnifiedMessagesCallbacks			= 2500
Const BS_ECallback_ClientUserCallbacks						= 900
Const BS_ECallback_ClientUtilsCallbacks						= 1600
Const BS_ECallback_ClientVideoCallbacks						= 4600
Const BS_ECallback_ClientVRCallbacks							= 4200

; SteamAppList ------------------------------------------------------------------
Const BS_CALLBACK_AppInstalled								= BS_ECallback_SteamAppListCallbacks + 1
Const BS_CALLBACK_AppUninstalled							= BS_ECallback_SteamAppListCallbacks + 2


; SteamApps ---------------------------------------------------------------------
Const BS_CALLBACK_DLCInstalled								= BS_ECallback_SteamAppsCallbacks + 5
Const BS_CALLBACK_APPProofOfPurchaseKeyResponse				= BS_ECallback_SteamAppsCallbacks + 13
Const BS_CALLBACK_NewLaunchQueryParameters					= BS_ECallback_SteamAppsCallbacks + 14
; The following things are PS3 only:
;   ERegisterActivationCodeResult
;   RegisterActivationCodeResponse_t

; SteamController ---------------------------------------------------------------
Const BS_MASK_RIGHT_TRIGGER									= $00000001
Const BS_MASK_LEFT_TRIGGER									= $00000002
Const BS_MASK_RIGHT_BUMPER									= $00000004
Const BS_MASK_LEFT_BUMPER									= $00000008
Const BS_MASK_BUTTON_0										= $00000010
Const BS_MASK_BUTTON_1										= $00000020
Const BS_MASK_BUTTON_2										= $00000040
Const BS_MASK_BUTTON_3										= $00000080
Const BS_MASK_TOUCH_0										= $00000100
Const BS_MASK_TOUCH_1										= $00000200
Const BS_MASK_TOUCH_2										= $00000400
Const BS_MASK_TOUCH_3										= $00000800
Const BS_MASK_BUTTON_MENU									= $0001000
Const BS_MASK_BUTTON_STEAM							        = $0002000
Const BS_MASK_BUTTON_ESCAPE									= $0004000
Const BS_MASK_BUTTON_BACK_LEFT							    = $0008000
Const BS_MASK_BUTTON_BACK_RIGHT								= $0010000
Const BS_MASK_BUTTON_LEFTPAD_CLICKED						= $0020000
Const BS_MASK_BUTTON_RIGHTPAD_CLICKED						= $0040000
Const BS_MASK_LEFTPAD_FINGERDOWN							= $0080000
Const BS_MASK_RIGHTPAD_FINGERDOWN							= $0100000
Const BS_MASK_JOYSTICK_BUTTON								= $0400000
Const BS_ESteamControllerPad_Left							= 0
Const BS_ESteamControllerPad_Right							= 1

Type BS_ControllerState
	Field unPacketNum%
	Field ulButtonsL%, ulButtonsR%
	Field sLeftPadXY ; Left/High = X, Right/Low = Y
	Field sRightPadXY ; Left/High = X, Right/Low = Y
End Type

; SteamFriends ------------------------------------------------------------------
Const BS_EFriendRelationShip_None							= 0
Const BS_EFriendRelationShip_Blocked						= 1
Const BS_EFriendRelationShip_RequestRecipient				= 2
Const BS_EFriendRelationShip_Friend							= 3
Const BS_EFriendRelationShip_RequestInitiator				= 4
Const BS_EFriendRelationShip_Ignored						= 5
Const BS_EFriendRelationShip_IgnoredFriend					= 6
Const BS_EFriendRelationShip_Suggested						= 7

Const BS_EPersonaState_Offline								= 0
Const BS_EPersonaState_Online								= 1
Const BS_EPersonaState_Busy									= 2
Const BS_EPersonaState_Away									= 3
Const BS_EPersonaState_Snooze								= 4
Const BS_EPersonaState_LookingToTrade						= 5
Const BS_EPersonaState_LookingToPlay						= 6

Const BS_EFriendFlags_None									= $00000000
Const BS_EFriendFlags_Blocked								= $00000001
Const BS_EFriendFlags_FriendshipRequested					= $00000002
Const BS_EFriendFlags_Immediate								= $00000004
Const BS_EFriendFlags_ClanMember							= $00000008
Const BS_EFriendFlags_OnGameServer							= $00000010
Const BS_EFriendFlags_RequestingFriendship					= $00000080
Const BS_EFriendFlags_RequestingInfo						= $00000100
Const BS_EFriendFlags_Ignored								= $00000200
Const BS_EFriendFlags_IgnoredFriend							= $00000400
Const BS_EFriendFlags_Suggested								= $00000800
Const BS_EFriendFlags_All									= $0000FFFF

Const BS_cchMaxFriendsGroupName								= 64
Const BS_cFriendsGroupLimit									= 100
Const BS_FriendsGroupID_Invalid								= -1
Const BS_cEnumerateFollowersMax								= 50
Const BS_cchPersonaNameMax									= 128
Const BS_cwchPersonaNameMax									= 32

Type BS_FriendGameInfo
	Field m_gameID%
	Field m_unGameIP%
	Field m_usGamePortQueryPort% ; Left/High GamePort, Right/Low QueryPort
	Field m_steamIDLobby%
End Type

Const BS_EUserRestrictionNone								= 0
Const BS_EUserRestrictionUnknown							= 1
Const BS_EUserRestrictionAnyChat							= 2
Const BS_EUserRestrictionVoiceChat							= 4
Const BS_EUserRestrictionGroupChat							= 8
Const BS_EUserRestrictionRating								= 16
Const BS_EUserRestrictionGameInvites						= 32
Const BS_EUserRestrictionTrading							= 64

Type BS_FriendSessionStateInfo
	Field m_uiOnlineSessionInstances
	Field m_uiPublishedToFriendsSessionInstance
End Type

Const BS_cubChatMetadataMax									= 8192
Const BS_cchMaxRichPresenceKeys								= 20
Const BS_cchMaxRichPresenceKeyLength						= 64
Const BS_cchMaxRichPresenceValueLength						= 256

Const BS_EOverlayToStoreFlag_None							= 0
Const BS_EOverlayToStoreFlag_AddToCart						= 1
Const BS_EOverlayToStoreFlag_AddToCartAndShow				= 2

Const BS_EPersonaChange_Name								= $0001
Const BS_EPersonaChange_Status								= $0002
Const BS_EPersonaChange_ComeOnline							= $0004
Const BS_EPersonaChange_GoneOffline							= $0008
Const BS_EPersonaChange_GamePlayed							= $0010
Const BS_EPersonaChange_GameServer							= $0020
Const BS_EPersonaChange_Avatar								= $0040
Const BS_EPersonaChange_JoinedSource						= $0080
Const BS_EPersonaChange_LeftSource							= $0100
Const BS_EPersonaChange_RelationshipChanged					= $0200
Const BS_EPersonaChange_NameFirstSet						= $0400
Const BS_EPersonaChange_FacebookInfo						= $0800
Const BS_EPersonaChange_Nickname							= $1000
Const BS_EPersonaChange_SteamLevel							= $2000

Const BS_CALLBACK_PersonaStateChange						= BS_ECallback_SteamFriendsCallbacks + 4
Const BS_CALLBACK_GameOverlayActivated						= BS_ECallback_SteamFriendsCallbacks + 31
Const BS_CALLBACK_GameServerChangeRequested					= BS_ECallback_SteamFriendsCallbacks + 32
Const BS_CALLBACK_GameLobbyJoinRequested					= BS_ECallback_SteamFriendsCallbacks + 33
Const BS_CALLBACK_AvatarImageLoaded							= BS_ECallback_SteamFriendsCallbacks + 34
Const BS_CALLBACK_ClanOfficerListResponse					= BS_ECallback_SteamFriendsCallbacks + 35
Const BS_CALLBACK_FriendRichPresenceUpdate					= BS_ECallback_SteamFriendsCallbacks + 36
Const BS_CALLBACK_GameRichPresenceJoinRequested				= BS_ECallback_SteamFriendsCallbacks + 37
Const BS_CALLBACK_GameConnectedClanChatMsg					= BS_ECallback_SteamFriendsCallbacks + 38
Const BS_CALLBACK_GameConnectedChatJoin						= BS_ECallback_SteamFriendsCallbacks + 39
Const BS_CALLBACK_GameConnectedChatLeave					= BS_ECallback_SteamFriendsCallbacks + 40
Const BS_CALLBACK_DownloadClanActivityCountsResult			= BS_ECallback_SteamFriendsCallbacks + 41
Const BS_CALLBACK_JoinClanChatRoomCompletionResult			= BS_ECallback_SteamFriendsCallbacks + 42
Const BS_CALLBACK_GameConnectedFriendChatMsg				= BS_ECallback_SteamFriendsCallbacks + 43
Const BS_CALLBACK_FriendsGetFollowerCount					= BS_ECallback_SteamFriendsCallbacks + 44
Const BS_CALLBACK_FriendsIsFollowing						= BS_ECallback_SteamFriendsCallbacks + 45
Const BS_CALLBACK_FriendsEnumerateFollowingList				= BS_ECallback_SteamFriendsCallbacks + 46
Const BS_CALLBACK_SetPersonaNameResponse					= BS_ECallback_SteamFriendsCallbacks + 47

; SteamGameServer ---------------------------------------------------------------
Const BS_EServerMode_Invalid								= 0
Const BS_EServerMode_NoAuthentication						= 1
Const BS_EServerMode_Authentication							= 2
Const BS_EServerMode_AuthenticationAndSecure				= 3

; SteamUser ---------------------------------------------------------------------
Const BS_EVoiceResult_OK									= 0
Const BS_EVoiceResult_NotInitialized						= 1
Const BS_EVoiceResult_NotRecording							= 2
Const BS_EVoiceResult_NoData								= 3
Const BS_EVoiceResult_BufferTooSmall						= 4
Const BS_EVoiceResult_DataCorrupted							= 5
Const BS_EVoiceResult_Restricted							= 6
Const BS_EVoiceResult_UnsupportedCodec						= 7
Const BS_EVoiceResult_ReceiverOutOfDate						= 8
Const BS_EVoiceResult_ReceiverDidNotAnswer					= 9

Const BS_EBeginAuthSessionResult_OK							= 0	; Ticket is valid for this game and this steamID.
Const BS_EBeginAuthSessionResult_InvalidTicket				= 1	; Ticket is not valid.
Const BS_EBeginAuthSessionResult_DuplicateRequest			= 2	; A ticket has already been submitted for this steamID
Const BS_EBeginAuthSessionResult_InvalidVersion				= 3	; Ticket is from an incompatible interface version
Const BS_EBeginAuthSessionResult_GameMismatch				= 4	; Ticket is not for this game
Const BS_EBeginAuthSessionResult_ExpiredTicket				= 5	; Ticket has expired

Const BS_EUserHasLicenseResult_HasLicense					= 0 ; User has a license for specified app
Const BS_EUserHasLicenseResult_DoesNotHaveLicense			= 1 ; User does not have a license for the specified app
Const BS_EUserHasLicenseResult_NoAuth						= 2 ; User has not been authenticated

; SteamUserStats ----------------------------------------------------------------
Const BS_cchStatNameMax										= 128
Const BS_cchLeaderboardNameMax								= 128
Const BS_k_cLeaderboardDetailsMax							= 64

Const BS_ELeaderboardDataRequest_Global						= 0
Const BS_ELeaderboardDataRequest_GlobalAroundUser			= 1
Const BS_ELeaderboardDataRequest_Friends					= 2
Const BS_ELeaderboardDataRequest_Users						= 3

Const BS_ELeaderboardSortMethod_None						= 0
Const BS_ELeaderboardSortMethod_Ascending					= 1 ; top-score is lowest number
Const BS_ELeaderboardSortMethod_Descending					= 2	; top-score is highest number

Const BS_ELeaderboardDisplayType_None						= 0
Const BS_ELeaderboardDisplayType_Numeric					= 1 ; simple numerical score
Const BS_ELeaderboardDisplayType_TimeSeconds				= 2 ; the score represents a time, in seconds
Const BS_ELeaderboardDisplayType_TimeMilliSeconds			= 3 ; the score represents a time, in milliseconds

Const BS_ELeaderboardUploadScoreMethod_None					= 0
Const BS_ELeaderboardUploadScoreMethod_KeepBest				= 1 ; Leaderboard will keep user's best score
Const BS_ELeaderboardUploadScoreMethod_ForceUpdate			= 2 ; Leaderboard will always replace score with specified

Type BS_LeaderboardEntry
	Field SteamId_High%, SteamId_Low%
	Field nGlobalRank%
	Field nScore%
	Field cDetails%
	Field hUGC_High%, hUGC_Low%
End Type

Const BS_CALLBACK_UserStatsReceived							= BS_ECallback_SteamUserStatsCallbacks + 1
Type BS_UserStatsReceived
	Field nGameId_High%, nGameId_Low%						; Game these stats are for
	Field eResult%											; Success / error fetching the stats
	Field steamIDUser_High%, steamIDUser_Low%				; The user for whom the stats are retrieved for
End Type

Const BS_CALLBACK_UserStatsStored							= BS_ECallback_SteamUserStatsCallbacks + 2
Type BS_UserStatsStored
	Field nGameId_High%, nGameId_Low%						; Game these stats are for
	Field eResult%											; Success / error 
End Type

Const BS_CALLBACK_UserAchievementStored						= BS_ECallback_SteamUserStatsCallbacks + 3
Type BS_UserAchievementStored
	Field nGameId_High%, nGameId_Low%						; Game this is for
	Field bGroupAchievement%								; if this is a "group" achievement
	Field rgchAchievementName[BS_cchStatNameMax]			; name of the achievement
	Field nCurProgress										; current progress towards the achievement
	Field nMaxProgress										; "out of" this many
End Type

Const BS_CALLBACK_LeaderboardFindResult						= BS_ECallback_SteamUserStatsCallbacks + 4
Type BS_LeaderboardFindResult
	Field hSteamLeaderboard_High%, hSteamLeaderboard_Low%	;	// handle to the leaderboard serarched for, 0 if no leaderboard found
	Field bLeaderboardFound%								;				// 0 if no leaderboard found
End Type

Const BS_CALLBACK_LeaderboardScoresDownloaded				= BS_ECallback_SteamUserStatsCallbacks + 5
Type BS_LeaderboardScoresDownloaded
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		;
	Field hSteamLeaderboardEntries_High, hSteamLeaderboardEntries_Low; the handle to pass into GetDownloadedLeaderboardEntries()
	Field cEntryCount										; the number of entries downloaded
End Type

Const BS_CALLBACK_LeaderboardScoreUploaded					= BS_ECallback_SteamUserStatsCallbacks + 6
Type BS_LeaderboardScoreUploaded
	Field bSuccess											; 1 if the call was successful
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		; the leaderboard handle that was
	Field nScore											; the score that was attempted to set
	Field bScoreChanged										; true if the score in the leaderboard change, false if the existing score was better
	Field nGlobalRankNew									; the new global rank of the user in this leaderboard
	Field nGlobalRankPrevious								; the previous global rank of the user in this leaderboard; 0 if the user had no existing entry in the leaderboard
End Type

Const BS_CALLBACK_NumberOfCurrentPlayers					= BS_ECallback_SteamUserStatsCallbacks + 7
Type BS_NumberOfCurrentPlayers
	Field bSuccess											; 1 if the call was successful
	Field cPlayers											; Number of players currently playing
End Type

Const BS_CALLBACK_UserStatsUnloaded							= BS_ECallback_SteamUserStatsCallback + 8
Type BS_UserStatsUnloaded
	Field steamIDUser_High, steamIDUser_Low					; User whose stats have been unloaded
End Type

Const BS_CALLBACK_UserAchievementIconFetched				= BS_ECallback_SteamUserStatsCallback + 9
Type BS_UserAchievementIconFetched
	Field nGameID_High, nGameID_Low							; Game this is for
	Field rgchAchievementName[BS_cchStatNameMax]			; name of the achievement
	Field bAchieved											; Is the icon for the achieved or not achieved version?
	Field nIconHandle										; Handle to the image, which can be used in SteamUtils()->GetImageRGBA(), 0 means no image is set for the achievement
End Type

Const BS_CALLBACK_GlobalAchievementPercentagesReady			= BS_ECallback_SteamUserStatsCallback + 10
Type BS_GlobalAchievementPercentagesReady
	Field nGameID_High, nGameID_Low							; Game this is for
	Field eResult											; Result of the operation
End Type

Const BS_CALLBACK_LeaderboardUGCSet							= BS_ECallback_SteamUserStatsCallback + 11
Type BS_LeaderboardUGCSet
	Field eResult											; The result of the operation
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		; the leaderboard handle that was
End Type

Const BS_CALLBACK_GlobalStatsReceived						= BS_ECallback_SteamUserStatsCallback + 12
Type BS_GlobalStatsReceived
	Field nGameID_High, nGameId_Low							; Game global stats were requested for
	Field eResult											; The result of the request
End Type
