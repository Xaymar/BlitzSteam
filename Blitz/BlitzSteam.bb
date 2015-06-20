;	BlitzSteam - Steam wrapper for Blitz.
;	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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
Const BLITZSTEAM_EAccountType_Invalid								= 0
Const BLITZSTEAM_EAccountType_Individual							= 1
Const BLITZSTEAM_EAccountType_Multiseat								= 2
Const BLITZSTEAM_EAccountType_Gameserver							= 3
Const BLITZSTEAM_EAccountType_AnonGamerserver						= 4
Const BLITZSTEAM_EAccountType_Pending								= 5
Const BLITZSTEAM_EAccountType_ContentServer							= 6
Const BLITZSTEAM_EAccountType_Clan									= 7
Const BLITZSTEAM_EAccountType_Chat									= 8
Const BLITZSTEAM_EAccountType_ConsoleUser							= 9
Const BLITZSTEAM_EAccountType_AnonUser								= 10

Const BLITZSTEAM_ECallback_SteamAppListCallbacks						= 3900
Const BLITZSTEAM_ECallback_SteamAppsCallbacks						= 1000
Const BLITZSTEAM_ECallback_SteamBillingCallbacks						= 400
Const BLITZSTEAM_ECallback_SteamContentServerCallbacks				= 600
Const BLITZSTEAM_ECallback_SteamControllerCallbacks					= 2800
Const BLITZSTEAM_ECallback_SteamFriendsCallbacks						= 300
Const BLITZSTEAM_ECallback_SteamGameCoordinatorCallbacks				= 1700
Const BLITZSTEAM_ECallback_SteamGameServerCallbacks					= 200
Const BLITZSTEAM_ECallback_SteamGameServerItemsCallbacks				= 1500
Const BLITZSTEAM_ECallback_SteamGameServerStatsCallbacks				= 1800
Const BLITZSTEAM_ECallback_SteamGameStatsCallbacks					= 2000
Const BLITZSTEAM_ECallback_SteamHTMLSurfacECallback_s					= 4500
Const BLITZSTEAM_ECallback_SteamMatchmakingCallbacks					= 500
Const BLITZSTEAM_ECallback_SteamMusicCallbacks						= 4000
Const BLITZSTEAM_ECallback_SteamMusicRemotECallback_s					= 4100
Const BLITZSTEAM_ECallback_SteamNetworkingCallbacks					= 1200
Const BLITZSTEAM_ECallback_SteamReservedCallbacks					= 4400
Const BLITZSTEAM_ECallback_SteamScreenshotsCallbacks					= 2300
Const BLITZSTEAM_ECallback_SteamStreamLauncherCallbacks				= 2600
Const BLITZSTEAM_ECallback_SteamStreamClientCallbacks				= 3500
Const BLITZSTEAM_ECallback_SteamUserCallbacks						= 100
Const BLITZSTEAM_ECallback_SteamUserStatsCallbacks					= 1100
Const BLITZSTEAM_ECallback_SteamUtilsCallbacks						= 700
Const BLITZSTEAM_ECallback_Steam2AsyncCallbacks						= 1900
Const BLITZSTEAM_ECallback_ClientAudioCallbacks						= 2400
Const BLITZSTEAM_ECallback_ClientControllerCallbacks					= 2700
Const BLITZSTEAM_ECallback_ClientDepotBuilderCallbacks				= 1400
Const BLITZSTEAM_ECallback_ClientDeviceAuthCallbacks					= 3000
Const BLITZSTEAM_ECallback_ClientFriendsCallbacks					= 800
Const BLITZSTEAM_ECallback_ClientHTTPCallbacks						= 2100
Const BLITZSTEAM_ECallback_ClientInventoryCallbacks					= 4700
Const BLITZSTEAM_ECallback_ClientMusicCallbacks						= 3200
Const BLITZSTEAM_ECallback_ClientNetworkDeviceManagerCallbacks		= 3100
Const BLITZSTEAM_ECallback_ClientParentalSettingsCallbacks			= 2900
Const BLITZSTEAM_ECallback_ClientProductBuilderCallbacks				= 3600
Const BLITZSTEAM_ECallback_ClientRemoteStoragECallback_s				= 1300
Const BLITZSTEAM_ECallback_ClientRemoteClientManagerCallbacks		= 3300
Const BLITZSTEAM_ECallback_ClientRemoteControlManagerCallbacks		= 3800
Const BLITZSTEAM_ECallback_ClientReservedCallbacks					= 4300
Const BLITZSTEAM_ECallback_ClientScreenshotsCallbacks				= 2200
Const BLITZSTEAM_ECallback_ClientShortcutsCallbacks					= 3700
Const BLITZSTEAM_ECallback_ClientUGCCallbacks						= 3400
Const BLITZSTEAM_ECallback_ClientUnifiedMessagesCallbacks			= 2500
Const BLITZSTEAM_ECallback_ClientUserCallbacks						= 900
Const BLITZSTEAM_ECallback_ClientUtilsCallbacks						= 1600
Const BLITZSTEAM_ECallback_ClientVideoCallbacks						= 4600
Const BLITZSTEAM_ECallback_ClientVRCallbacks							= 4200

; SteamAppList ------------------------------------------------------------------
Const BLITZSTEAM_CALLBACK_AppInstalled								= BLITZSTEAM_ECallback_SteamAppListCallbacks + 1
Const BLITZSTEAM_CALLBACK_AppUninstalled							= BLITZSTEAM_ECallback_SteamAppListCallbacks + 2


; SteamApps ---------------------------------------------------------------------
Const BLITZSTEAM_CALLBACK_DLCInstalled								= BLITZSTEAM_ECallback_SteamAppsCallbacks + 5
Const BLITZSTEAM_CALLBACK_APPProofOfPurchaseKeyResponse				= BLITZSTEAM_ECallback_SteamAppsCallbacks + 13
Const BLITZSTEAM_CALLBACK_NewLaunchQueryParameters					= BLITZSTEAM_ECallback_SteamAppsCallbacks + 14
; The following things are PS3 only:
;   ERegisterActivationCodeResult
;   RegisterActivationCodeResponse_t

; SteamController ---------------------------------------------------------------
Const BLITZSTEAM_MASK_RIGHT_TRIGGER									= $00000001
Const BLITZSTEAM_MASK_LEFT_TRIGGER									= $00000002
Const BLITZSTEAM_MASK_RIGHT_BUMPER									= $00000004
Const BLITZSTEAM_MASK_LEFT_BUMPER									= $00000008
Const BLITZSTEAM_MASK_BUTTON_0										= $00000010
Const BLITZSTEAM_MASK_BUTTON_1										= $00000020
Const BLITZSTEAM_MASK_BUTTON_2										= $00000040
Const BLITZSTEAM_MASK_BUTTON_3										= $00000080
Const BLITZSTEAM_MASK_TOUCH_0										= $00000100
Const BLITZSTEAM_MASK_TOUCH_1										= $00000200
Const BLITZSTEAM_MASK_TOUCH_2										= $00000400
Const BLITZSTEAM_MASK_TOUCH_3										= $00000800
Const BLITZSTEAM_MASK_BUTTON_MENU									= $0001000
Const BLITZSTEAM_MASK_BUTTON_STEAM							        = $0002000
Const BLITZSTEAM_MASK_BUTTON_ESCAPE									= $0004000
Const BLITZSTEAM_MASK_BUTTON_BACK_LEFT							    = $0008000
Const BLITZSTEAM_MASK_BUTTON_BACK_RIGHT								= $0010000
Const BLITZSTEAM_MASK_BUTTON_LEFTPAD_CLICKED						= $0020000
Const BLITZSTEAM_MASK_BUTTON_RIGHTPAD_CLICKED						= $0040000
Const BLITZSTEAM_MASK_LEFTPAD_FINGERDOWN							= $0080000
Const BLITZSTEAM_MASK_RIGHTPAD_FINGERDOWN							= $0100000
Const BLITZSTEAM_MASK_JOYSTICK_BUTTON								= $0400000
Const BLITZSTEAM_ESteamControllerPad_Left							= 0
Const BLITZSTEAM_ESteamControllerPad_Right							= 1

Type BlitzSteamControllerState
	Field unPacketNum%
	Field ulButtonsL%, ulButtonsR%
	Field sLeftPadXY ; Left/High = X, Right/Low = Y
	Field sRightPadXY ; Left/High = X, Right/Low = Y
End Type

; SteamFriends ------------------------------------------------------------------
Const BLITZSTEAM_EFriendRelationShip_None							= 0
Const BLITZSTEAM_EFriendRelationShip_Blocked						= 1
Const BLITZSTEAM_EFriendRelationShip_RequestRecipient				= 2
Const BLITZSTEAM_EFriendRelationShip_Friend							= 3
Const BLITZSTEAM_EFriendRelationShip_RequestInitiator				= 4
Const BLITZSTEAM_EFriendRelationShip_Ignored						= 5
Const BLITZSTEAM_EFriendRelationShip_IgnoredFriend					= 6
Const BLITZSTEAM_EFriendRelationShip_Suggested						= 7
Const BLITZSTEAM_EPersonaState_Offline								= 0
Const BLITZSTEAM_EPersonaState_Online								= 1
Const BLITZSTEAM_EPersonaState_Busy									= 2
Const BLITZSTEAM_EPersonaState_Away									= 3
Const BLITZSTEAM_EPersonaState_Snooze								= 4
Const BLITZSTEAM_EPersonaState_LookingToTrade						= 5
Const BLITZSTEAM_EPersonaState_LookingToPlay						= 6
Const BLITZSTEAM_EFriendFlags_None									= $00000000
Const BLITZSTEAM_EFriendFlags_Blocked								= $00000001
Const BLITZSTEAM_EFriendFlags_FriendshipRequested					= $00000002
Const BLITZSTEAM_EFriendFlags_Immediate								= $00000004
Const BLITZSTEAM_EFriendFlags_ClanMember							= $00000008
Const BLITZSTEAM_EFriendFlags_OnGameServer							= $00000010
Const BLITZSTEAM_EFriendFlags_RequestingFriendship					= $00000080
Const BLITZSTEAM_EFriendFlags_RequestingInfo						= $00000100
Const BLITZSTEAM_EFriendFlags_Ignored								= $00000200
Const BLITZSTEAM_EFriendFlags_IgnoredFriend							= $00000400
Const BLITZSTEAM_EFriendFlags_Suggested								= $00000800
Const BLITZSTEAM_EFriendFlags_All									= $0000FFFF
Const BLITZSTEAM_cchMaxFriendsGroupName								= 64
Const BLITZSTEAM_cFriendsGroupLimit									= 100
Const BLITZSTEAM_FriendsGroupID_Invalid								= -1
Const BLITZSTEAM_cEnumerateFollowersMax								= 50
Const BLITZSTEAM_cchPersonaNameMax									= 128
Const BLITZSTEAM_cwchPersonaNameMax									= 32

Type BlitzSteamFriendGameInfo
	Field m_gameID%
	Field m_unGameIP%
	Field m_usGamePortQueryPort% ; Left/High GamePort, Right/Low QueryPort
	Field m_steamIDLobby%
End Type

Const BLITZSTEAM_EUserRestrictionNone								= 0
Const BLITZSTEAM_EUserRestrictionUnknown							= 1
Const BLITZSTEAM_EUserRestrictionAnyChat							= 2
Const BLITZSTEAM_EUserRestrictionVoiceChat							= 4
Const BLITZSTEAM_EUserRestrictionGroupChat							= 8
Const BLITZSTEAM_EUserRestrictionRating								= 16
Const BLITZSTEAM_EUserRestrictionGameInvites						= 32
Const BLITZSTEAM_EUserRestrictionTrading							= 64

Type BlitzSteamFriendSessionStateInfo
	Field m_uiOnlineSessionInstances
	Field m_uiPublishedToFriendsSessionInstance
End Type

Const BLITZSTEAM_cubChatMetadataMax									= 8192
Const BLITZSTEAM_cchMaxRichPresenceKeys								= 20
Const BLITZSTEAM_cchMaxRichPresenceKeyLength						= 64
Const BLITZSTEAM_cchMaxRichPresenceValueLength						= 256
Const BLITZSTEAM_EOverlayToStoreFlag_None							= 0
Const BLITZSTEAM_EOverlayToStoreFlag_AddToCart						= 1
Const BLITZSTEAM_EOverlayToStoreFlag_AddToCartAndShow				= 2
Const BLITZSTEAM_CALLBACK_PersonaStateChange						= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 4
Const BLITZSTEAM_EPersonaChange_Name								= $0001
Const BLITZSTEAM_EPersonaChange_Status								= $0002
Const BLITZSTEAM_EPersonaChange_ComeOnline							= $0004
Const BLITZSTEAM_EPersonaChange_GoneOffline							= $0008
Const BLITZSTEAM_EPersonaChange_GamePlayed							= $0010
Const BLITZSTEAM_EPersonaChange_GameServer							= $0020
Const BLITZSTEAM_EPersonaChange_Avatar								= $0040
Const BLITZSTEAM_EPersonaChange_JoinedSource						= $0080
Const BLITZSTEAM_EPersonaChange_LeftSource							= $0100
Const BLITZSTEAM_EPersonaChange_RelationshipChanged					= $0200
Const BLITZSTEAM_EPersonaChange_NameFirstSet						= $0400
Const BLITZSTEAM_EPersonaChange_FacebookInfo						= $0800
Const BLITZSTEAM_EPersonaChange_Nickname							= $1000
Const BLITZSTEAM_EPersonaChange_SteamLevel							= $2000
Const BLITZSTEAM_CALLBACK_GameOverlayActivated						= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 31
Const BLITZSTEAM_CALLBACK_GameServerChangeRequested					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 32
Const BLITZSTEAM_CALLBACK_GameLobbyJoinRequested					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 33
Const BLITZSTEAM_CALLBACK_AvatarImageLoaded							= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 34
Const BLITZSTEAM_CALLBACK_ClanOfficerListResponse					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 35
Const BLITZSTEAM_CALLBACK_FriendRichPresenceUpdate					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 36
Const BLITZSTEAM_CALLBACK_GameRichPresenceJoinRequested				= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 37
Const BLITZSTEAM_CALLBACK_GameConnectedClanChatMsg					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 38
Const BLITZSTEAM_CALLBACK_GameConnectedChatJoin						= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 39
Const BLITZSTEAM_CALLBACK_GameConnectedChatLeave					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 40
Const BLITZSTEAM_CALLBACK_DownloadClanActivityCountsResult			= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 41
Const BLITZSTEAM_CALLBACK_JoinClanChatRoomCompletionResult			= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 42
Const BLITZSTEAM_CALLBACK_GameConnectedFriendChatMsg				= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 43
Const BLITZSTEAM_CALLBACK_FriendsGetFollowerCount					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 44
Const BLITZSTEAM_CALLBACK_FriendsIsFollowing						= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 45
Const BLITZSTEAM_CALLBACK_FriendsEnumerateFollowingList				= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 46
Const BLITZSTEAM_CALLBACK_SetPersonaNameResponse					= BLITZSTEAM_ECallback_SteamFriendsCallbacks + 47

; SteamGameServer ---------------------------------------------------------------
Const BLITZSTEAM_EServerMode_Invalid								= 0
Const BLITZSTEAM_EServerMode_NoAuthentication						= 1
Const BLITZSTEAM_EServerMode_Authentication							= 2
Const BLITZSTEAM_EServerMode_AuthenticationAndSecure				= 3
