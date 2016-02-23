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
;	along with this program.  If not, see <http://www.gnu.org/licenses/>.

;[Block] Enumeration: EDenyReason
;------------------------------------------------------------------------------
;! Enumeration - EDenyReason
;------------------------------------------------------------------------------
; Result codes to GSHandleClientDeny/Kick
Const BS_EDenyReason_Invalid								= 0
Const BS_EDenyReason_InvalidVersion							= 1
Const BS_EDenyReason_Generic								= 2
Const BS_EDenyReason_NotLoggedOn							= 3
Const BS_EDenyReason_NoLicense								= 4
Const BS_EDenyReason_Cheater								= 5
Const BS_EDenyReason_LoggedInElseWhere						= 6
Const BS_EDenyReason_UnknownText							= 7
Const BS_EDenyReason_IncompatibleAnticheat					= 8
Const BS_EDenyReason_MemoryCorruption						= 9
Const BS_EDenyReason_IncompatibleSoftware					= 10
Const BS_EDenyReason_SteamConnectionLost					= 11
Const BS_EDenyReason_SteamConnectionError					= 12
Const BS_EDenyReason_SteamResponseTimedOut					= 13
Const BS_EDenyReason_SteamValidationStalled					= 14
Const BS_EDenyReason_SteamOwnerLeftGuestUser				= 15
;[End Block]

;[Block] Enumeration: EAccountType
;------------------------------------------------------------------------------
;! Enumeration - EAccountType
;------------------------------------------------------------------------------
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
;[End Block]

;[Block] Enumeration: EBeginAuthSessionResult
;------------------------------------------------------------------------------
;! Enumeration - EBeginAuthSessionResult
;------------------------------------------------------------------------------
Const BS_EBeginAuthSessionResult_OK							= 0		; Ticket is valid for this game and this steamID.
Const BS_EBeginAuthSessionResult_InvalidTicket				= 1		; Ticket is not valid.
Const BS_EBeginAuthSessionResult_DuplicateRequest			= 2		; A ticket has already been submitted for this steamID
Const BS_EBeginAuthSessionResult_InvalidVersion				= 3		; Ticket is from an incompatible interface version
Const BS_EBeginAuthSessionResult_GameMismatch				= 4		; Ticket is not for this game
Const BS_EBeginAuthSessionResult_ExpiredTicket				= 5		; Ticket has expired
;[End Block]

;[Block] Enumeration: ECallback
;------------------------------------------------------------------------------
;! Enumeration - ECallback
;------------------------------------------------------------------------------
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
Const BS_ECallback_ClientVRCallbacks						= 4200
;[End Block]

;[Block] Enumeration: ESteamControllerPad
;------------------------------------------------------------------------------
;! Enumeration - ESteamControllerPad
;------------------------------------------------------------------------------
Const BS_ESteamControllerPad_Left							= 0
Const BS_ESteamControllerPad_Right							= 1
;[End Block]

;[Block] Enumeration: EControllerSource
;------------------------------------------------------------------------------
;! Enumeration - EControllerSourceMode
;------------------------------------------------------------------------------
Const BS_EControllerSource_None								= 0
Const BS_EControllerSource_LeftTrackpad						= 1
Const BS_EControllerSource_RightTrackpad					= 2
Const BS_EControllerSource_Joystick							= 3
Const BS_EControllerSource_ABXY								= 4
Const BS_EControllerSource_Switch							= 5
Const BS_EControllerSource_LeftTrigger						= 6
Const BS_EControllerSource_RightTrigger						= 7
Const BS_EControllerSource_Gyro								= 8
;[End Block]

;[Block] Enumeration: EControllerSourceMode
;------------------------------------------------------------------------------
;! Enumeration - EControllerSourceMode
;------------------------------------------------------------------------------
Const BS_EControllerSourceMode_None							= 0
Const BS_EControllerSourceMode_Dpad							= 1
Const BS_EControllerSourceMode_Buttons						= 2
Const BS_EControllerSourceMode_FourButtons					= 3
Const BS_EControllerSourceMode_AbsoluteMouse				= 4
Const BS_EControllerSourceMode_RelativeMouse				= 5
Const BS_EControllerSourceMode_JoystickMove					= 6
Const BS_EControllerSourceMode_JoystickCamera				= 7
Const BS_EControllerSourceMode_ScrollWheel					= 8
Const BS_EControllerSourceMode_Trigger						= 9
Const BS_EControllerSourceMode_TouchMenu					= 10
;[End Block]

;[Block] Enumeration: EControllerActionOrigin
;------------------------------------------------------------------------------
;! Enumeration - EControllerActionOrigin
;------------------------------------------------------------------------------
Const BS_EControllerActionOrigin_None						= 0
Const BS_EControllerActionOrigin_A							= 1
Const BS_EControllerActionOrigin_B							= 2
Const BS_EControllerActionOrigin_X							= 3
Const BS_EControllerActionOrigin_Y							= 4
Const BS_EControllerActionOrigin_LeftBumper					= 5
Const BS_EControllerActionOrigin_RightBumper				= 6
Const BS_EControllerActionOrigin_LeftGrip					= 7
Const BS_EControllerActionOrigin_RightGrip					= 8
Const BS_EControllerActionOrigin_Start						= 9
Const BS_EControllerActionOrigin_Back						= 10
Const BS_EControllerActionOrigin_LeftPad_Touch				= 11
Const BS_EControllerActionOrigin_LeftPad_Swipe				= 12
Const BS_EControllerActionOrigin_LeftPad_Click				= 13
Const BS_EControllerActionOrigin_LeftPad_DPadNorth			= 14
Const BS_EControllerActionOrigin_LeftPad_DPadSouth			= 15
Const BS_EControllerActionOrigin_LeftPad_DPadWest			= 16
Const BS_EControllerActionOrigin_LeftPad_DPadEast			= 17
Const BS_EControllerActionOrigin_RightPad_Touch				= 18
Const BS_EControllerActionOrigin_RightPad_Swipe				= 19
Const BS_EControllerActionOrigin_RightPad_Click				= 20
Const BS_EControllerActionOrigin_RightPad_DPadNorth			= 21
Const BS_EControllerActionOrigin_RightPad_DPadSouth			= 22
Const BS_EControllerActionOrigin_RightPad_DPadWest			= 23
Const BS_EControllerActionOrigin_RightPad_DPadEast			= 24
Const BS_EControllerActionOrigin_LeftTrigger_Pull			= 25
Const BS_EControllerActionOrigin_LeftTrigger_Click			= 26
Const BS_EControllerActionOrigin_RightTrigger_Pull			= 27
Const BS_EControllerActionOrigin_RightTrigger_Click			= 28
Const BS_EControllerActionOrigin_LeftStick_Move				= 29
Const BS_EControllerActionOrigin_LeftStick_Click			= 30
Const BS_EControllerActionOrigin_LeftStick_DPadNorth		= 31
Const BS_EControllerActionOrigin_LeftStick_DPadSouth		= 32
Const BS_EControllerActionOrigin_LeftStick_DPadWest			= 33
Const BS_EControllerActionOrigin_LeftStick_DPadEast			= 34
Const BS_EControllerActionOrigin_Gyro_Move					= 35
Const BS_EControllerActionOrigin_Gyro_Pitch					= 36
Const BS_EControllerActionOrigin_Gyro_Yaw					= 37
Const BS_EControllerActionOrigin_Gyro_Roll					= 38
Const BS_EControllerActionOrigin_Count						= 39
;[End Block]

;[Block] Enumeration: EFriendRelationShip
;------------------------------------------------------------------------------
;! Enumeration - EFriendRelationShip
;------------------------------------------------------------------------------
Const BS_EFriendRelationShip_None							= 0
Const BS_EFriendRelationShip_Blocked						= 1
Const BS_EFriendRelationShip_RequestRecipient				= 2
Const BS_EFriendRelationShip_Friend							= 3
Const BS_EFriendRelationShip_RequestInitiator				= 4
Const BS_EFriendRelationShip_Ignored						= 5
Const BS_EFriendRelationShip_IgnoredFriend					= 6
Const BS_EFriendRelationShip_Suggested						= 7
;[End Block]

;[Block] Enumeration: EFriendFlags
;------------------------------------------------------------------------------
;! Enumeration - EFriendFlags
;------------------------------------------------------------------------------
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
;[End Block]

;[Block] Enumeration: EHTMLMouseButton
;------------------------------------------------------------------------------
;! Enumeration - EHTMLMouseButton
;------------------------------------------------------------------------------
Const BS_EHTMLMouseButton_Left								= 0
Const BS_EHTMLMouseButton_Right								= 1
Const BS_EHTMLMouseButton_Middle							= 2
;[End Block]

;[Block] Enumeration: EHTMLKeyModifiers
;------------------------------------------------------------------------------
;! Enumeration - EHTMLKeyModifiers
;------------------------------------------------------------------------------
Const BS_EHTMLKeyModifiers_None								= 0
Const BS_EHTMLKeyModifiers_AltDown							= 1 Shl 0
Const BS_EHTMLKeyModifiers_CtrlDown							= 1 Shl 1
Const BS_EHTMLKeyModifiers_ShiftDown						= 1 Shl 2
;[End Block]

;[Block] Enumeration: ELeaderboardDataRequest
;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardDataRequest
;------------------------------------------------------------------------------
Const BS_ELeaderboardDataRequest_Global						= 0
Const BS_ELeaderboardDataRequest_GlobalAroundUser			= 1
Const BS_ELeaderboardDataRequest_Friends					= 2
Const BS_ELeaderboardDataRequest_Users						= 3
;[End Block]

;[Block] Enumeration: ELeaderboardDisplayType
;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardDisplayType
;------------------------------------------------------------------------------
Const BS_ELeaderboardDisplayType_None						= 0
Const BS_ELeaderboardDisplayType_Numeric					= 1		; simple numerical score
Const BS_ELeaderboardDisplayType_TimeSeconds				= 2		; the score represents a time, in seconds
Const BS_ELeaderboardDisplayType_TimeMilliSeconds			= 3		; the score represents a time, in milliseconds
;[End Block]

;[Block] Enumeration: ELeaderboardSortMethod
;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardSortMethod
;------------------------------------------------------------------------------
Const BS_ELeaderboardSortMethod_None						= 0
Const BS_ELeaderboardSortMethod_Ascending					= 1		; top-score is lowest number
Const BS_ELeaderboardSortMethod_Descending					= 2		; top-score is highest number
;[End Block]

;[Block] Enumeration: ELeaderboardUploadScoreMethod
;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardUploadScoreMethod
;------------------------------------------------------------------------------
Const BS_ELeaderboardUploadScoreMethod_None					= 0
Const BS_ELeaderboardUploadScoreMethod_KeepBest				= 1		; Leaderboard will keep user's best score
Const BS_ELeaderboardUploadScoreMethod_ForceUpdate			= 2		; Leaderboard will always replace score with specified
;[End Block]

;[Block] Enumeration: EOverlayToStoreFlag
;------------------------------------------------------------------------------
;! Enumeration - EOverlayToStoreFlag
;------------------------------------------------------------------------------
Const BS_EOverlayToStoreFlag_None							= 0
Const BS_EOverlayToStoreFlag_AddToCart						= 1
Const BS_EOverlayToStoreFlag_AddToCartAndShow				= 2
;[End Block]

;[Block] Enumeration: EPersonaChange
;------------------------------------------------------------------------------
;! Enumeration - EPersonaChange
;------------------------------------------------------------------------------
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
;[End Block]

;[Block] Enumeration: EPersonaState
;------------------------------------------------------------------------------
;! Enumeration - EPersonaState
;------------------------------------------------------------------------------
Const BS_EPersonaState_Offline								= 0
Const BS_EPersonaState_Online								= 1
Const BS_EPersonaState_Busy									= 2
Const BS_EPersonaState_Away									= 3
Const BS_EPersonaState_Snooze								= 4
Const BS_EPersonaState_LookingToTrade						= 5
Const BS_EPersonaState_LookingToPlay						= 6
;[End Block]

;[Block] Enumeration: EP2PSend
;------------------------------------------------------------------------------
;! Enumeration - EP2PSend
;------------------------------------------------------------------------------
; SendP2PPacket() send types
; Typically k_EP2PSendUnreliable is what you want for UDP-like packets, k_EP2PSendReliable for TCP-like packets
	; Basic UDP send. Packets can't be bigger than 1200 bytes (your typical MTU size). Can be lost, or arrive out of order (rare).
	; The sending API does have some knowledge of the underlying connection, so if there is no NAT-traversal accomplished or
	; there is a recognized adjustment happening on the connection, the packet will be batched until the connection is open again.
Const BS_EP2PSend_Unreliable								= 0
	; As above, but if the underlying p2p connection isn't yet established the packet will just be thrown away. Using this on the first
	; packet sent to a remote host almost guarantees the packet will be dropped.
	; This is only really useful for kinds of data that should never buffer up, i.e. voice payload packets
Const BS_EP2PSend_UnreliableNoDelay							= 1
	; Reliable message send. Can send up to 1MB of data in a single message. 
	; Does fragmentation/re-assembly of messages under the hood, as well as a sliding window for efficient sends of large chunks of data. 
Const BS_EP2PSend_Reliable									= 2
	; As above, but applies the Nagle algorithm to the send - sends will accumulate 
	; until the current MTU size (typically ~1200 bytes, but can change) or ~200ms has passed (Nagle algorithm). 
	; Useful if you want to send a set of smaller messages but have the coalesced into a single packet
	; Since the reliable stream is all ordered, you can do several small message sends with k_EP2PSendReliableWithBuffering and then
	; do a normal k_EP2PSendReliable to force all the buffered data to be sent.
Const BS_EP2PSend_ReliableWithBuffering						= 3
;[End Block]

;[Block] Enumeration: EP2PSessionError
;------------------------------------------------------------------------------
;! Enumeration - EP2PSessionError
;------------------------------------------------------------------------------
; list of possible errors returned by SendP2PPacket() API
; these will be posted in the P2PSessionConnectFail_t callback
Const BS_EP2PSessionError_None								= 0
Const BS_EP2PSessionError_NotRunningApp						= 1		; target is not running the same game
Const BS_EP2PSessionError_NoRightsToApp						= 2		; local user doesn't own the app that is running
Const BS_EP2PSessionError_DestinationNotLoggedIn			= 3		; target user isn't connected to Steam
Const BS_EP2PSessionError_Timeout							= 4		; target isn't responding, perhaps not calling AcceptP2PSessionWithUser()
																	; corporate firewalls can also block this (NAT traversal is not firewall traversal)
																	; make sure that UDP ports 3478, 4379, and 4380 are open in an outbound direction
Const BS_EP2PSessionError_Max								= 5
;[End Block]

;[Block] Enumeration: EResult
;------------------------------------------------------------------------------
;! Enumeration - EResult
;------------------------------------------------------------------------------
Const BS_EResult_OK											= 1		; success
Const BS_EResult_Fail										= 2		; generic failure 
Const BS_EResult_NoConnection								= 3		; no/failed network connection
Const BS_EResult_NoConnectionRetry							= 4		; OBSOLETE - removed
Const BS_EResult_InvalidPassword							= 5		; password/ticket is invalid
Const BS_EResult_LoggedInElsewhere							= 6		; same user logged in elsewhere
Const BS_EResult_InvalidProtocolVer							= 7		; protocol version is incorrect
Const BS_EResult_InvalidParam								= 8		; a parameter is incorrect
Const BS_EResult_FileNotFound								= 9		; file was not found
Const BS_EResult_Busy										= 10	; called method busy - action not taken
Const BS_EResult_InvalidState								= 11	; called object was in an invalid state
Const BS_EResult_InvalidName								= 12	; name is invalid
Const BS_EResult_InvalidEmail								= 13	; email is invalid
Const BS_EResult_DuplicateName								= 14	; name is not unique
Const BS_EResult_AccessDenied								= 15	; access is denied
Const BS_EResult_Timeout									= 16	; operation timed out
Const BS_EResult_Banned										= 17	; VAC2 banned
Const BS_EResult_AccountNotFound							= 18	; account not found
Const BS_EResult_InvalidSteamID								= 19	; steamID is invalid
Const BS_EResult_ServiceUnavailable							= 20	; The requested service is currently unavailable
Const BS_EResult_NotLoggedOn								= 21	; The user is not logged on
Const BS_EResult_Pending									= 22	; Request is pending (may be in process, or waiting on third party)
Const BS_EResult_EncryptionFailure							= 23	; Encryption or Decryption failed
Const BS_EResult_InsufficientPrivilege						= 24	; Insufficient privilege
Const BS_EResult_LimitExceeded								= 25	; Too much of a good thing
Const BS_EResult_Revoked									= 26	; Access has been revoked (used for revoked guest passes)
Const BS_EResult_Expired									= 27	; License/Guest pass the user is trying to access is expired
Const BS_EResult_AlreadyRedeemed							= 28	; Guest pass has already been redeemed by account, cannot be acked again
Const BS_EResult_DuplicateRequest							= 29	; The request is a duplicate and the action has already occurred in the past, ignored this time
Const BS_EResult_AlreadyOwned								= 30	; All the games in this guest pass redemption request are already owned by the user
Const BS_EResult_IPNotFound									= 31	; IP address not found
Const BS_EResult_PersistFailed								= 32	; failed to write change to the data store
Const BS_EResult_LockingFailed								= 33	; failed to acquire access lock for this operation
Const BS_EResult_LogonSessionReplaced						= 34
Const BS_EResult_ConnectFailed								= 35
Const BS_EResult_HandshakeFailed							= 36
Const BS_EResult_IOFailure									= 37
Const BS_EResult_RemoteDisconnect							= 38
Const BS_EResult_ShoppingCartNotFound						= 39	; failed to find the shopping cart requested
Const BS_EResult_Blocked									= 40	; a user didn't allow it
Const BS_EResult_Ignored									= 41	; target is ignoring sender
Const BS_EResult_NoMatch									= 42	; nothing matching the request found
Const BS_EResult_AccountDisabled							= 43
Const BS_EResult_ServiceReadOnly							= 44	; this service is not accepting content changes right now
Const BS_EResult_AccountNotFeatured							= 45	; account doesn't have value, so this feature isn't available
Const BS_EResult_AdministratorOK							= 46	; allowed to take this action, but only because requester is admin
Const BS_EResult_ContentVersion								= 47	; A Version mismatch in content transmitted within the Steam protocol.
Const BS_EResult_TryAnotherCM								= 48	; The current CM can't service the user making a request, user should try another.
Const BS_EResult_PasswordRequiredToKickSession				= 49	; You are already logged in elsewhere, this cached credential login has failed.
Const BS_EResult_AlreadyLoggedInElsewhere					= 50	; You are already logged in elsewhere, you must wait
Const BS_EResult_Suspended									= 51	; Long running operation (content download) suspended/paused
Const BS_EResult_Cancelled									= 52	; Operation canceled (typically by user: content download)
Const BS_EResult_DataCorruption								= 53	; Operation canceled because data is ill formed or unrecoverable
Const BS_EResult_DiskFull									= 54	; Operation canceled - not enough disk space.
Const BS_EResult_RemoteCallFailed							= 55	; an remote call or IPC call failed
Const BS_EResult_PasswordUnset								= 56	; Password could not be verified as it's unset server side
Const BS_EResult_ExternalAccountUnlinked					= 57	; External account (PSN, Facebook...) is not linked to a Steam account
Const BS_EResult_PSNTicketInvalid							= 58	; PSN ticket was invalid
Const BS_EResult_ExternalAccountAlreadyLinked				= 59	; External account (PSN, Facebook...) is already linked to some other account, must explicitly request to replace/delete the link first
Const BS_EResult_RemoteFileConflict							= 60	; The sync cannot resume due to a conflict between the local and remote files
Const BS_EResult_IllegalPassword							= 61	; The requested new password is not legal
Const BS_EResult_SameAsPreviousValue						= 62	; new value is the same as the old one ( secret question and answer )
Const BS_EResult_AccountLogonDenied							= 63	; account login denied due to 2nd factor authentication failure
Const BS_EResult_CannotUseOldPassword						= 64	; The requested new password is not legal
Const BS_EResult_InvalidLoginAuthCode						= 65	; account login denied due to auth code invalid
Const BS_EResult_AccountLogonDeniedNoMail					= 66	; account login denied due to 2nd factor auth failure - and no mail has been sent
Const BS_EResult_HardwareNotCapableOfIPT					= 67
Const BS_EResult_IPTInitError								= 68
Const BS_EResult_ParentalControlRestricted					= 69	; operation failed due to parental control restrictions for current user
Const BS_EResult_FacebookQueryError							= 70	; Facebook query returned an error
Const BS_EResult_ExpiredLoginAuthCode						= 71	; account login denied due to auth code expired
Const BS_EResult_IPLoginRestrictionFailed					= 72
Const BS_EResult_AccountLockedDown							= 73
Const BS_EResult_AccountLogonDeniedVerifiedEmailRequired	= 74
Const BS_EResult_NoMatchingURL								= 75
Const BS_EResult_BadResponse								= 76	; parse failure, missing field, etc.
Const BS_EResult_RequirePasswordReEntry						= 77	; The user cannot complete the action until they re-enter their password
Const BS_EResult_ValueOutOfRange							= 78	; the value entered is outside the acceptable range
Const BS_EResult_UnexpectedError							= 79	; something happened that we didn't expect to ever happen
Const BS_EResult_Disabled									= 80	; The requested service has been configured to be unavailable
Const BS_EResult_InvalidCEGSubmission						= 81	; The set of files submitted to the CEG server are not valid !
Const BS_EResult_RestrictedDevice							= 82	; The device being used is not allowed to perform this action
Const BS_EResult_RegionLocked								= 83	; The action could not be complete because it is region restricted
Const BS_EResult_RateLimitExceeded							= 84	; Temporary rate limit exceeded, try again later, different from k_EResultLimitExceeded which may be permanent
Const BS_EResult_AccountLoginDeniedNeedTwoFactor			= 85	; Need two-factor code to login
Const BS_EResult_ItemDeleted								= 86	; The thing we're trying to access has been deleted
Const BS_EResult_AccountLoginDeniedThrottle					= 87	; login attempt failed, try to throttle response to possible attacker
Const BS_EResult_TwoFactorCodeMismatch						= 88	; two factor code mismatch
Const BS_EResult_TwoFactorActivationCodeMismatch			= 89	; activation code for two-factor didn't match
Const BS_EResult_AccountAssociatedToMultiplePartners		= 90	; account has been associated with multiple partners
Const BS_EResult_NotModified								= 91	; data not modified
Const BS_EResult_NoMobileDevice								= 92	; the account does not have a mobile device associated with it
Const BS_EResult_TimeNotSynced								= 93	; the time presented is out of range or tolerance
Const BS_EResult_SmsCodeFailed								= 94	; SMS code failure (no match, none pending, etc.)
Const BS_EResult_AccountLimitExceeded						= 95	; Too many accounts access this resource
Const BS_EResult_AccountActivityLimitExceeded				= 96	; Too many changes to this account
Const BS_EResult_PhoneActivityLimitExceeded					= 97	; Too many changes to this phone
Const BS_EResult_RefundToWallet								= 98	; Cannot refund to payment method, must use wallet
Const BS_EResult_EmailSendFailure							= 99	; Cannot send an email
Const BS_EResult_NotSettled									= 100	; Can't perform operation till payment has settled
Const BS_EResult_NeedCaptcha								= 101	; Needs to provide a valid captcha
;[End Block]

;[Block] Enumeration: EServerMode
;------------------------------------------------------------------------------
;! Enumeration - EServerMode
;------------------------------------------------------------------------------
Const BS_EServerMode_Invalid								= 0
Const BS_EServerMode_NoAuthentication						= 1
Const BS_EServerMode_Authentication							= 2
Const BS_EServerMode_AuthenticationAndSecure				= 3
;[End Block]

;[Block] Enumeration: EServerFlag
;------------------------------------------------------------------------------
;! Enumeration - EServerFlag
;------------------------------------------------------------------------------
Const BS_EServerFlag_None									= $00
Const BS_EServerFlag_Active									= $01	; Server has Users playing
Const BS_EServerFlag_Secure									= $02	; Server wants to be Secure
Const BS_EServerFlag_Dedicated								= $04	; Server is Dedicated
Const BS_EServerFlag_Linux									= $08	; Linux Build
Const BS_EServerFlag_Passworded								= $10	; Password Protected
Const BS_EServerFlag_Private								= $20	; server shouldn't list on master server and
																	; won't enforce authentication of users that connect to the server.
																	; Useful when you run a server where the clients may not
																	; be connected to the internet but you want them to play (i.e LANs)
;[End Block]

;[Block] Enumeration: EUserHasLicenseResult
;------------------------------------------------------------------------------
;! Enumeration - EUserHasLicenseResult
;------------------------------------------------------------------------------
Const BS_EUserHasLicenseResult_HasLicense					= 0 ; User has a license for specified app
Const BS_EUserHasLicenseResult_DoesNotHaveLicense			= 1 ; User does not have a license for the specified app
Const BS_EUserHasLicenseResult_NoAuth						= 2 ; User has not been authenticated
;[End Block]

;[Block] Enumeration: EUserRestriction
;------------------------------------------------------------------------------
;! Enumeration - EUserRestriction
;------------------------------------------------------------------------------
Const BS_EUserRestrictionNone								= 0
Const BS_EUserRestrictionUnknown							= 1
Const BS_EUserRestrictionAnyChat							= 2
Const BS_EUserRestrictionVoiceChat							= 4
Const BS_EUserRestrictionGroupChat							= 8
Const BS_EUserRestrictionRating								= 16
Const BS_EUserRestrictionGameInvites						= 32
Const BS_EUserRestrictionTrading							= 64
;[End Block]

;[Block] Enumeration: EVoiceResult
;------------------------------------------------------------------------------
;! Enumeration - EVoiceResult
;------------------------------------------------------------------------------
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
;[End Block]

;[Block] API: AppList
;------------------------------------------------------------------------------
;! AppList
;------------------------------------------------------------------------------
Const BS_CALLBACK_AppInstalled								= BS_ECallback_SteamAppListCallbacks + 1
Const BS_CALLBACK_AppUninstalled							= BS_ECallback_SteamAppListCallbacks + 2

;[End Block]

;[Block] API: Apps
;------------------------------------------------------------------------------
;! Apps
;------------------------------------------------------------------------------
Const BS_CALLBACK_DLCInstalled								= BS_ECallback_SteamAppsCallbacks + 5
Const BS_CALLBACK_APPProofOfPurchaseKeyResponse				= BS_ECallback_SteamAppsCallbacks + 13
Const BS_CALLBACK_NewLaunchQueryParameters					= BS_ECallback_SteamAppsCallbacks + 14
;[End Block]

;[Block] API: Controller
;------------------------------------------------------------------------------
;! Controller
;------------------------------------------------------------------------------

; Memory Structure: ControllerAnalogActionData_t
; Offs.	Len	Description
;			// Type of data coming from this action, this will match what got specified in the action set
;	0	4	<EControllerSourceMode> eMode
;			// The current state of this action; will be delta updates for mouse actions
;	4	4	<float> x
;	8	4	<float> y
;			// Whether or not this action is currently available to be bound in the active action set
;	12	1	<bool> bActive;

; Memory Structure: ControllerDigitalActionData_t
; Offs.	Len	Description
;			// The current state of this action; will be true if currently pressed
;	0	1	<bool> bState;
;			// Whether or not this action is currently available to be bound in the active action set
;	1	1	<bool> bActive;
;[End Block]

;[Block] API: Friends
;------------------------------------------------------------------------------
;! Friends
;------------------------------------------------------------------------------
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

Const BS_cchMaxFriendsGroupName								= 64
Const BS_cFriendsGroupLimit									= 100
Const BS_FriendsGroupID_Invalid								= -1
Const BS_cEnumerateFollowersMax								= 50
Const BS_cchPersonaNameMax									= 128
Const BS_cwchPersonaNameMax									= 32
Const BS_cubChatMetadataMax									= 8192
Const BS_cchMaxRichPresenceKeys								= 20
Const BS_cchMaxRichPresenceKeyLength						= 64
Const BS_cchMaxRichPresenceValueLength						= 256

Type BS_FriendGameInfo_t
	Field m_gameID%
	Field m_unGameIP%
	Field m_usGamePortQueryPort% ; Left/High GamePort, Right/Low QueryPort
	Field m_steamIDLobby%
End Type

Type BS_FriendSessionStateInfo_t
	Field m_uiOnlineSessionInstances
	Field m_uiPublishedToFriendsSessionInstance
End Type
;[End Block]

;[Block] API: HTMLSurface
;------------------------------------------------------------------------------
;! HTMLSurface
;------------------------------------------------------------------------------

;//-----------------------------------------------------------------------------
;// Purpose: The browser is ready for use
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_BrowserReady							= BS_ECallback_SteamHTMLSurfaceCallbacks + 1
;DEFINE_CALLBACK( HTML_BrowserReady_t, k_iSteamHTMLSurfaceCallbacks + 1 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // this browser is now fully created and ready to navigate to pages
;END_DEFINE_CALLBACK_1()

;//-----------------------------------------------------------------------------
;// Purpose: the browser has a pending paint
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_NeedsPaint								= BS_ECallback_SteamHTMLSurfaceCallbacks + 2
;DEFINE_CALLBACK(HTML_NeedsPaint_t, k_iSteamHTMLSurfaceCallbacks + 2)
;CALLBACK_MEMBER(0, HHTMLBrowser, unBrowserHandle) // the browser that needs the paint
;CALLBACK_MEMBER(1, const char *, pBGRA ) // a pointer to the B8G8R8A8 data for this surface, valid until SteamAPI_RunCallbacks is next called
;CALLBACK_MEMBER(2, uint32, unWide) // the total width of the pBGRA texture
;CALLBACK_MEMBER(3, uint32, unTall) // the total height of the pBGRA texture
;CALLBACK_MEMBER(4, uint32, unUpdateX) // the offset in X for the damage rect for this update
;CALLBACK_MEMBER(5, uint32, unUpdateY) // the offset in Y for the damage rect for this update
;CALLBACK_MEMBER(6, uint32, unUpdateWide) // the width of the damage rect for this update
;CALLBACK_MEMBER(7, uint32, unUpdateTall) // the height of the damage rect for this update
;CALLBACK_MEMBER(8, uint32, unScrollX) // the page scroll the browser was at when this texture was rendered
;CALLBACK_MEMBER(9, uint32, unScrollY) // the page scroll the browser was at when this texture was rendered
;CALLBACK_MEMBER(10, float, flPageScale) // the page scale factor on this page when rendered
;CALLBACK_MEMBER(11, uint32, unPageSerial) // incremented on each new page load, you can use this to reject draws while navigating to new pages
;END_DEFINE_CALLBACK_12()

;//-----------------------------------------------------------------------------
;// Purpose: The browser wanted to navigate to a new page
;//   NOTE - you MUST call AllowStartRequest in response to this callback
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_StartRequest							= BS_ECallback_SteamHTMLSurfaceCallbacks + 3
;DEFINE_CALLBACK(HTML_StartRequest_t, k_iSteamHTMLSurfaceCallbacks + 3)
;CALLBACK_MEMBER(0, HHTMLBrowser, unBrowserHandle) // the handle of the surface navigating
;CALLBACK_MEMBER(1, const char *, pchURL) // the url they wish to navigate to 
;CALLBACK_MEMBER(2, const char *, pchTarget) // the html link target type  (i.e _blank, _self, _parent, _top )
;CALLBACK_MEMBER(3, const char *, pchPostData ) // any posted data for the request
;CALLBACK_MEMBER(4, bool, bIsRedirect) // true if this was a http/html redirect from the last load request
;END_DEFINE_CALLBACK_5()

;//-----------------------------------------------------------------------------
;// Purpose: The browser has been requested to close due to user interaction (usually from a javascript window.close() call)
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_CloseBrowser							= BS_ECallback_SteamHTMLSurfaceCallbacks + 4
;DEFINE_CALLBACK(HTML_CloseBrowser_t, k_iSteamHTMLSurfaceCallbacks + 4)
;CALLBACK_MEMBER(0, HHTMLBrowser, unBrowserHandle) // the handle of the surface 
;END_DEFINE_CALLBACK_1()

;//-----------------------------------------------------------------------------
;// Purpose: the browser is navigating to a new url
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_URLChanged 							= BS_ECallback_SteamHTMLSurfaceCallbacks + 5
;DEFINE_CALLBACK( HTML_URLChanged_t, k_iSteamHTMLSurfaceCallbacks + 5 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the handle of the surface navigating
;CALLBACK_MEMBER( 1, const char *, pchURL ) // the url they wish to navigate to 
;CALLBACK_MEMBER( 2, const char *, pchPostData ) // any posted data for the request
;CALLBACK_MEMBER( 3, bool, bIsRedirect ) // true if this was a http/html redirect from the last load request
;CALLBACK_MEMBER( 4, const char *, pchPageTitle ) // the title of the page
;CALLBACK_MEMBER( 5, bool, bNewNavigation ) // true if this was from a fresh tab and not a click on an existing page
;END_DEFINE_CALLBACK_6()

;//-----------------------------------------------------------------------------
;// Purpose: A page is finished loading
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_FinishedRequest						= BS_ECallback_SteamHTMLSurfaceCallbacks + 6
;DEFINE_CALLBACK( HTML_FinishedRequest_t, k_iSteamHTMLSurfaceCallbacks + 6 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchURL ) // 
;CALLBACK_MEMBER( 2, Const char *, pchPageTitle ) // 
;END_DEFINE_CALLBACK_3()

;//-----------------------------------------------------------------------------
;// Purpose: a request To load this url in a New tab
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_OpenLinkInNewTab						= BS_ECallback_SteamHTMLSurfaceCallbacks + 7
;DEFINE_CALLBACK( HTML_OpenLinkInNewTab_t, k_iSteamHTMLSurfaceCallbacks + 7 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchURL ) // 
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: the page has a New title now
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_ChangedTitle							= BS_ECallback_SteamHTMLSurfaceCallbacks + 8
;DEFINE_CALLBACK( HTML_ChangedTitle_t, k_iSteamHTMLSurfaceCallbacks + 8 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchTitle ) // 
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: results from a search
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_SearchResults							= BS_ECallback_SteamHTMLSurfaceCallbacks + 9
;DEFINE_CALLBACK( HTML_SearchResults_t, k_iSteamHTMLSurfaceCallbacks + 9 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, uint32, unResults ) // 
;CALLBACK_MEMBER( 2, uint32, unCurrentMatch ) // 
;END_DEFINE_CALLBACK_3()

;//-----------------------------------------------------------------------------
;// Purpose: page history status changed on the ability To go backwards And forward
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_CanGoBackAndForward					= BS_ECallback_SteamHTMLSurfaceCallbacks + 10
;DEFINE_CALLBACK( HTML_CanGoBackAndForward_t, k_iSteamHTMLSurfaceCallbacks + 10 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, bool, bCanGoBack ) // 
;CALLBACK_MEMBER( 2, bool, bCanGoForward ) // 
;END_DEFINE_CALLBACK_3()

;//-----------------------------------------------------------------------------
;// Purpose: details on the visibility And size of the horizontal scrollbar
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_HorizontalScroll						= BS_ECallback_SteamHTMLSurfaceCallbacks + 11
;DEFINE_CALLBACK( HTML_HorizontalScroll_t, k_iSteamHTMLSurfaceCallbacks + 11 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, uint32, unScrollMax ) // 
;CALLBACK_MEMBER( 2, uint32, unScrollCurrent ) // 
;CALLBACK_MEMBER( 3, Float, flPageScale ) // 
;CALLBACK_MEMBER( 4, bool , bVisible ) // 
;CALLBACK_MEMBER( 5, uint32, unPageSize ) // 
;END_DEFINE_CALLBACK_6()

;//-----------------------------------------------------------------------------
;// Purpose: details on the visibility And size of the vertical scrollbar
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_VerticalScroll							= BS_ECallback_SteamHTMLSurfaceCallbacks + 12
;DEFINE_CALLBACK( HTML_VerticalScroll_t, k_iSteamHTMLSurfaceCallbacks + 12 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, uint32, unScrollMax ) // 
;CALLBACK_MEMBER( 2, uint32, unScrollCurrent ) // 
;CALLBACK_MEMBER( 3, Float, flPageScale ) // 
;CALLBACK_MEMBER( 4, bool, bVisible ) // 
;CALLBACK_MEMBER( 5, uint32, unPageSize ) // 
;END_DEFINE_CALLBACK_6()

;//-----------------------------------------------------------------------------
;// Purpose: response To GetLinkAtPosition call 
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_LinkAtPosition							= BS_ECallback_SteamHTMLSurfaceCallbacks + 13
;DEFINE_CALLBACK( HTML_LinkAtPosition_t, k_iSteamHTMLSurfaceCallbacks + 13 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, uint32, x ) // NOTE - Not currently set
;CALLBACK_MEMBER( 2, uint32, y ) // NOTE - Not currently set
;CALLBACK_MEMBER( 3, Const char *, pchURL ) // 
;CALLBACK_MEMBER( 4, bool, bInput ) // 
;CALLBACK_MEMBER( 5, bool, bLiveLink ) // 
;END_DEFINE_CALLBACK_6()

;//-----------------------------------------------------------------------------
;// Purpose: show a Javascript alert dialog, call JSDialogResponse 
;//   when the user dismisses this dialog (Or Right away To ignore it)
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_JSAlert								= BS_ECallback_SteamHTMLSurfaceCallbacks + 14
;DEFINE_CALLBACK( HTML_JSAlert_t, k_iSteamHTMLSurfaceCallbacks + 14 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchMessage ) // 
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: show a Javascript confirmation dialog, call JSDialogResponse 
;//   when the user dismisses this dialog (Or Right away To ignore it)
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_JSConfirm								= BS_ECallback_SteamHTMLSurfaceCallbacks + 15
;DEFINE_CALLBACK( HTML_JSConfirm_t, k_iSteamHTMLSurfaceCallbacks + 15 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchMessage ) // 
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: when received show a file open dialog
;//   Then call FileLoadDialogResponse with the file(s) the user selected.
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_FileOpenDialog							= BS_ECallback_SteamHTMLSurfaceCallbacks + 16
;DEFINE_CALLBACK( HTML_FileOpenDialog_t, k_iSteamHTMLSurfaceCallbacks + 16 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchTitle ) // 
;CALLBACK_MEMBER( 2, Const char *, pchInitialFile ) // 
;END_DEFINE_CALLBACK_3()

;//-----------------------------------------------------------------------------
;// Purpose: a New html window has been created 
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_NewWindow								= BS_ECallback_SteamHTMLSurfaceCallbacks + 21
;DEFINE_CALLBACK( HTML_NewWindow_t, k_iSteamHTMLSurfaceCallbacks + 21 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the current surface 
;CALLBACK_MEMBER( 1, Const char *, pchURL ) // the page To load
;CALLBACK_MEMBER( 2, uint32, unX ) // the x pos into the page To display the popup
;CALLBACK_MEMBER( 3, uint32, unY ) // the y pos into the page To display the popup
;CALLBACK_MEMBER( 4, uint32, unWide ) // the total width of the pBGRA texture
;CALLBACK_MEMBER( 5, uint32, unTall ) // the total height of the pBGRA texture
;CALLBACK_MEMBER( 6, HHTMLBrowser, unNewWindow_BrowserHandle ) // the Handle of the New window surface 
;END_DEFINE_CALLBACK_7()

;//-----------------------------------------------------------------------------
;// Purpose: change the cursor To display
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_SetCursor								= BS_ECallback_SteamHTMLSurfaceCallbacks + 22
;DEFINE_CALLBACK( HTML_SetCursor_t, k_iSteamHTMLSurfaceCallbacks + 22 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, uint32, eMouseCursor ) // the EMouseCursor To display
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: informational message from the browser
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_StatusText								= BS_ECallback_SteamHTMLSurfaceCallbacks + 23
;DEFINE_CALLBACK( HTML_StatusText_t, k_iSteamHTMLSurfaceCallbacks + 23 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchMsg ) // the EMouseCursor To display
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: show a tooltip
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_ShowToolTip							= BS_ECallback_SteamHTMLSurfaceCallbacks + 24
;DEFINE_CALLBACK( HTML_ShowToolTip_t, k_iSteamHTMLSurfaceCallbacks + 24 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchMsg ) // the EMouseCursor To display
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: update the Text of an existing tooltip
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_UpdateToolTip							= BS_ECallback_SteamHTMLSurfaceCallbacks + 25
;DEFINE_CALLBACK( HTML_UpdateToolTip_t, k_iSteamHTMLSurfaceCallbacks + 25 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;CALLBACK_MEMBER( 1, Const char *, pchMsg ) // the EMouseCursor To display
;END_DEFINE_CALLBACK_2()

;//-----------------------------------------------------------------------------
;// Purpose: hide the tooltip you are showing
;//-----------------------------------------------------------------------------
Const BS_HTMLSurface_HideToolTip							= BS_ECallback_SteamHTMLSurfaceCallbacks + 26
;DEFINE_CALLBACK( HTML_HideToolTip_t, k_iSteamHTMLSurfaceCallbacks + 26 )
;CALLBACK_MEMBER( 0, HHTMLBrowser, unBrowserHandle ) // the Handle of the surface 
;END_DEFINE_CALLBACK_1()
;[End Block]

;[Block] API: GameServer
;------------------------------------------------------------------------------
;! GameServer
;------------------------------------------------------------------------------
Const BS_CALLBACK_GSClientApprove							= BS_ECallback_SteamGameServerCallbacks + 1	; client has been approved to connect to this game server
Type BS_GSClientApprove_t
	Field SteamIDHigh%, SteamIDLow%					; SteamID of approved player
	Field OwnerSteamIDHigh%, OwnerSteamIDLow%		; SteamID of original owner for game license
End Type
Const BS_CALLBACK_GSClientDeny								= BS_ECallback_SteamGameServerCallbacks + 2	; client has been denied to connection to this game server
Type BS_GSClientDeny_t
	Field SteamIDHigh%, SteamIDLow%
	Field eDenyReason%, pad0%
	Field rgchOptionalText%[31]						; 128 Bytes of Optional Text
End Type
Const BS_CALLBACK_GSClientKick								= BS_ECallback_SteamGameServerCallbacks + 3	; request the game server should kick the user
Type BS_GSClientKick_t
	Field SteamIDHigh%, SteamIDLow%
	Field eDenyReason%, pad0%
End Type
Const BS_CALLBACK_GSClientAchievementStatus					= BS_ECallback_SteamGameServerCallbacks + 6	; client achievement info
Type BS_GSClientAchievementStatus_t
	Field SteamIDHigh%, SteamIDLow%
	Field pchAchievement[31]						; 128 byte C-String Achievement
	Field bUnlocked%, pad0%
End Type
Const BS_CALLBACK_GSPolicyResponse							= BS_ECallback_SteamUserCallbacks + 15		; received when the game server requests to be displayed as secure (VAC protected)
Type BS_GSPolicyResponse_t																				; m_bSecure is true if the game server should display itself as secure to users, false otherwise
	Field m_bSecure%, pad0%
End Type
Const BS_CALLBACK_GSGameplayStats							= BS_ECallback_SteamGameServerCallbacks + 7	; GS gameplay stats info
Type BS_GSGameplayStats_t
	Field eResult%, pad0%							; Result of the call
	Field nRank%, pad1%							; Overall rank of the server (0-based)
	Field unTotalConnects%, pad2%					; Total number of clients who have ever connected to the server
	Field unTotalMinutesPlayed%, pad3%				; Total number of minutes ever played on the server
End Type
Const BS_CALLBACK_GSClientGroupStatus						= BS_ECallback_SteamGameServerCallbacks + 8	; Sent as a reply to RequestUserGroupStatus()
Type BS_GSClientGroupStatus_t
	Field SteamIDUserHigh%, SteamIDUserLow%
	Field SteamIDGroupHigh%, SteamIDGroupLow%
	Field bMember%, pad0%
	Field bOfficer%, pad1%
End Type
Const BS_CALLBACK_GSReputation								= BS_ECallback_SteamGameServerCallbacks + 9	; Sent as a reply to GetServerReputation()
Type BS_GSReputation_t
	Field eResult%, pad0%							; Result of the call
	Field unReputationScore%, pad1%				; The reputation score for the game server
	Field bBanned%, pad2%							; True if the server is banned from the Steam
													; master servers
	
	; The following members are only filled out if m_bBanned is true. They will all 
	; be set to zero otherwise. Master server bans are by IP so it is possible to be
	; banned even when the score is good high if there is a bad server on another port.
	; This information can be used to determine which server is bad.
	Field unBannedIP%, pad3%						; The IP of the banned server
	Field usBannedPort%, pad4%					; The port of the banned server
	Field ulBannedGameIDHigh%, ulBannedGameIDLow%	; The game ID the banned server is serving
	Field unBanExpires%, pad5%					; Time the ban expires, expressed in the Unix epoch (seconds since 1/1/1970)
End Type
Const BS_CALLBACK_AssociateWithClanResult					= BS_ECallback_SteamGameServerCallbacks + 10; Sent as a reply to AssociateWithClan()
Type BS_AssociateWithClanResult_t
	Field eResult%									; Result of the call
End Type
Const BS_CALLBACK_ComputeNewPlayerCompatibilityResult		= BS_ECallback_SteamGameServerCallbacks + 11; Sent as a reply to ComputeNewPlayerCompatibility()
Type BS_ComputeNewPlayerCompatibilityResult_t
	Field eResult%, pad0%							; Result of the call
	Field cPlayersThatDontLikeCandidate%, pad1%
	Field cPlayersThatCandidateDoesntLike%, pad2%
	Field cClanPlayersThatDontLikeCandidate%, pad3%
	Field SteamIDCandidateHigh%, SteamIDCandidateLow%
End Type
;[End Block]

;[Block] API: User
;------------------------------------------------------------------------------
;! User
;------------------------------------------------------------------------------
Type BS_CallbackMsg_t
	Field m_hSteamUser%
	Field m_iCallback%
	Field m_pubParamPtr%
	Field m_cubParam%
End Type

; Purpose: called when a connections to the Steam back-end has been established
;			this means the Steam client now has a working connection to the Steam servers
;			usually this will have occurred before the game has launched, and should
;			only be seen if the user has dropped connection due to a networking issue
;			or a Steam server update
Const BS_SteamServersConnected = BS_ECallback_SteamUserCallbacks + 1
; Purpose: called when a connection attempt has failed
;			this will occur periodically if the Steam client is not connected, 
;			and has failed in it's retry to establish a connection
Const BS_SteamServerConnectFailure = BS_ECallback_SteamUserCallbacks + 2
; Purpose: called if the client has lost connection to the Steam servers
;			real-time services will be disabled until a matching SteamServersConnected_t has been posted
Const BS_SteamServersDisconnected = BS_ECallback_SteamUserCallbacks + 3
; Purpose: Sent by the Steam server to the client telling it to disconnect from the specified game server,
;			which it may be in the process of or already connected to.
;			The game client should immediately disconnect upon receiving this message.
;			This can usually occur if the user doesn't have rights to play on the game server.
Const BS_ClientGameServerDeny = BS_ECallback_SteamUserCallbacks + 13
; Purpose: called when the callback system for this client is in an error state (and has flushed pending callbacks)
;			When getting this message the client should disconnect from Steam, reset any stored Steam state and reconnect.
;			This usually occurs in the rare event the Steam client has some kind of fatal error.
Const BS_EIPCFailureType_FlushedCallbackQueue = 0
Const BS_EIPCFailureType_PipeFail = 1
Const BS_IPCFailure = BS_ECallback_SteamUserCallbacks + 17
; Purpose: Signaled whenever licenses change
Const BS_LicensesUpdated = BS_ECallback_SteamUserCallbacks + 25
; callback for BeginAuthSession
Const BS_ValidateAuthTicketResponse = BS_ECallback_SteamUserCallbacks + 43
; Purpose: called when a user has responded to a microtransaction authorization request
Const BS_MicroTxnAuthorizationResponse = BS_ECallback_SteamUserCallbacks + 52
; Purpose: Result from RequestEncryptedAppTicket
Const BS_EncryptedAppTicketResponse = BS_ECallback_SteamUserCallbacks + 54
; callback for GetAuthSessionTicket
Const BS_GetAuthSessionTicketResponse = BS_ECallback_SteamUserCallbacks + 63
; Purpose: sent to your game in response to a steam//gamewebcallback/ command
Const BS_GameWebCallback = BS_ECallback_SteamUserCallbacks + 64
; Purpose: sent to your game in response to ISteamUser::RequestStoreAuthURL
Const BS_StoreAuthURLResponse = BS_ECallback_SteamUserCallbacks + 65
;[End Block]

;[Block] API: UserStats
;------------------------------------------------------------------------------
;! UserStats
;------------------------------------------------------------------------------
Const BS_cchStatNameMax										= 128
Const BS_cchLeaderboardNameMax								= 128
Const BS_cLeaderboardDetailsMax								= 64

Type BS_LeaderboardEntry_t
	Field SteamId_High%, SteamId_Low%
	Field nGlobalRank%
	Field nScore%
	Field cDetails%
	Field hUGC_High%, hUGC_Low%
End Type

Const BS_CALLBACK_UserStatsReceived							= BS_ECallback_SteamUserStatsCallbacks + 1
Type BS_UserStatsReceived_t
	Field nGameId_High%, nGameId_Low%						; Game these stats are for
	Field eResult%											; Success / error fetching the stats
	Field steamIDUser_High%, steamIDUser_Low%				; The user for whom the stats are retrieved for
End Type
Const BS_CALLBACK_UserStatsStored							= BS_ECallback_SteamUserStatsCallbacks + 2
Type BS_UserStatsStored_t
	Field nGameId_High%, nGameId_Low%						; Game these stats are for
	Field eResult%											; Success / error 
End Type
Const BS_CALLBACK_UserAchievementStored						= BS_ECallback_SteamUserStatsCallbacks + 3
Type BS_UserAchievementStored_t
	Field nGameId_High%, nGameId_Low%						; Game this is for
	Field bGroupAchievement%								; if this is a "group" achievement
	Field rgchAchievementName[BS_cchStatNameMax]			; name of the achievement
	Field nCurProgress										; current progress towards the achievement
	Field nMaxProgress										; "out of" this many
End Type
Const BS_CALLBACK_LeaderboardFindResult						= BS_ECallback_SteamUserStatsCallbacks + 4
Type BS_LeaderboardFindResult_t
	Field hSteamLeaderboard_High%, hSteamLeaderboard_Low%	;	 handle to the leaderboard serarched for, 0 if no leaderboard found
	Field bLeaderboardFound%								;				 0 if no leaderboard found
End Type
Const BS_CALLBACK_LeaderboardScoresDownloaded				= BS_ECallback_SteamUserStatsCallbacks + 5
Type BS_LeaderboardScoresDownloaded_t
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		;
	Field hSteamLeaderboardEntries_High, hSteamLeaderboardEntries_Low; the handle to pass into GetDownloadedLeaderboardEntries()
	Field cEntryCount										; the number of entries downloaded
End Type
Const BS_CALLBACK_LeaderboardScoreUploaded					= BS_ECallback_SteamUserStatsCallbacks + 6
Type BS_LeaderboardScoreUploaded_t
	Field bSuccess											; 1 if the call was successful
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		; the leaderboard handle that was
	Field nScore											; the score that was attempted to set
	Field bScoreChanged										; true if the score in the leaderboard change, false if the existing score was better
	Field nGlobalRankNew									; the new global rank of the user in this leaderboard
	Field nGlobalRankPrevious								; the previous global rank of the user in this leaderboard; 0 if the user had no existing entry in the leaderboard
End Type
Const BS_CALLBACK_NumberOfCurrentPlayers					= BS_ECallback_SteamUserStatsCallbacks + 7
Type BS_NumberOfCurrentPlayers_t
	Field bSuccess											; 1 if the call was successful
	Field cPlayers											; Number of players currently playing
End Type
Const BS_CALLBACK_UserStatsUnloaded							= BS_ECallback_SteamUserStatsCallbacks + 8
Type BS_UserStatsUnloaded_t
	Field steamIDUser_High, steamIDUser_Low					; User whose stats have been unloaded
End Type
Const BS_CALLBACK_UserAchievementIconFetched				= BS_ECallback_SteamUserStatsCallbacks + 9
Type BS_UserAchievementIconFetched_t
	Field nGameID_High, nGameID_Low							; Game this is for
	Field rgchAchievementName[BS_cchStatNameMax]			; name of the achievement
	Field bAchieved											; Is the icon for the achieved or not achieved version?
	Field nIconHandle										; Handle to the image, which can be used in SteamUtils()->GetImageRGBA(), 0 means no image is set for the achievement
End Type
Const BS_CALLBACK_GlobalAchievementPercentagesReady			= BS_ECallback_SteamUserStatsCallbacks + 10
Type BS_GlobalAchievementPercentagesReady_t
	Field nGameID_High, nGameID_Low							; Game this is for
	Field eResult											; Result of the operation
End Type
Const BS_CALLBACK_LeaderboardUGCSet							= BS_ECallback_SteamUserStatsCallbacks + 11
Type BS_LeaderboardUGCSet_t
	Field eResult											; The result of the operation
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		; the leaderboard handle that was
End Type
Const BS_CALLBACK_GlobalStatsReceived						= BS_ECallback_SteamUserStatsCallbacks + 12
Type BS_GlobalStatsReceived_t
	Field nGameID_High, nGameId_Low							; Game global stats were requested for
	Field eResult											; The result of the request
End Type
;[End Block]

;[Block] API: Networking
;------------------------------------------------------------------------------
;! Networking
;------------------------------------------------------------------------------
Type BS_P2PSessionState_t
	Field bConnectionActive%, pad0%
	Field bConnecting%, pad1%
	Field eP2PSessionError%, pad2%
	Field bUsingRelay%, pad3%
	Field nBytesQueuedForSend%, pad4%
	Field nPacketsQueuedForSend%, pad5%
	Field nRemoteIP%, pad6%
	Field nRemotePort%, pad7%
End Type

; callback notification - a user wants to talk to us over the P2P channel via the SendP2PPacket() API
; in response, a call to AcceptP2PPacketsFromUser() needs to be made, if you want to talk with them
Const BS_CALLBACK_P2PSessionRequest							= BS_ECallback_SteamNetworkingCallbacks + 2
Type BS_P2PSessionRequest_t
	Field steamIDRemoteHigh%, steamIDRemoteLow%				; user who wants to talk to us
End Type

; callback notification - packets can't get through to the specified user via the SendP2PPacket() API
; all packets queued packets unsent at this point will be dropped
; further attempts to send will retry making the connection (but will be dropped if we fail again)
Const BS_CALLBACK_P2PSessionConnectFail						= BS_ECallback_SteamNetworkingCallbacks + 3
Type BS_P2PSessionConnectFail_t
	Field steamIDRemoteHigh%, steamIDRemoteLow%				; user we were sending packets to
	Field eP2PSessionError									; EP2PSessionError indicating why we're having trouble
End Type
;[End Block]

;~IDEal Editor Parameters:
;~F#10#27#38#44#79#81#90#A1#CF#DD#EF#F8#102#10C#116#11F#128#131#145#152
;~F#16B#17B#1E6#1F0#200#209#217#227#230#239#250#372#3BC#3EF#447
;~C#Blitz3D