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

;------------------------------------------------------------------------------
;! Enumeration - EBeginAuthSessionResult
;------------------------------------------------------------------------------
Const BS_EBeginAuthSessionResult_OK							= 0		; Ticket is valid for this game and this steamID.
Const BS_EBeginAuthSessionResult_InvalidTicket				= 1		; Ticket is not valid.
Const BS_EBeginAuthSessionResult_DuplicateRequest			= 2		; A ticket has already been submitted for this steamID
Const BS_EBeginAuthSessionResult_InvalidVersion				= 3		; Ticket is from an incompatible interface version
Const BS_EBeginAuthSessionResult_GameMismatch				= 4		; Ticket is not for this game
Const BS_EBeginAuthSessionResult_ExpiredTicket				= 5		; Ticket has expired

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

;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardDataRequest
;------------------------------------------------------------------------------
Const BS_ELeaderboardDataRequest_Global						= 0
Const BS_ELeaderboardDataRequest_GlobalAroundUser			= 1
Const BS_ELeaderboardDataRequest_Friends					= 2
Const BS_ELeaderboardDataRequest_Users						= 3

;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardDisplayType
;------------------------------------------------------------------------------
Const BS_ELeaderboardDisplayType_None						= 0
Const BS_ELeaderboardDisplayType_Numeric					= 1		; simple numerical score
Const BS_ELeaderboardDisplayType_TimeSeconds				= 2		; the score represents a time, in seconds
Const BS_ELeaderboardDisplayType_TimeMilliSeconds			= 3		; the score represents a time, in milliseconds

;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardSortMethod
;------------------------------------------------------------------------------
Const BS_ELeaderboardSortMethod_None						= 0
Const BS_ELeaderboardSortMethod_Ascending					= 1		; top-score is lowest number
Const BS_ELeaderboardSortMethod_Descending					= 2		; top-score is highest number

;------------------------------------------------------------------------------
;! Enumeration - ELeaderboardUploadScoreMethod
;------------------------------------------------------------------------------
Const BS_ELeaderboardUploadScoreMethod_None					= 0
Const BS_ELeaderboardUploadScoreMethod_KeepBest				= 1		; Leaderboard will keep user's best score
Const BS_ELeaderboardUploadScoreMethod_ForceUpdate			= 2		; Leaderboard will always replace score with specified

;------------------------------------------------------------------------------
;! Enumeration - EOverlayToStoreFlag
;------------------------------------------------------------------------------
Const BS_EOverlayToStoreFlag_None							= 0
Const BS_EOverlayToStoreFlag_AddToCart						= 1
Const BS_EOverlayToStoreFlag_AddToCartAndShow				= 2

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

;------------------------------------------------------------------------------
;! Enumeration - EServerMode
;------------------------------------------------------------------------------
Const BS_EServerMode_Invalid								= 0
Const BS_EServerMode_NoAuthentication						= 1
Const BS_EServerMode_Authentication							= 2
Const BS_EServerMode_AuthenticationAndSecure				= 3

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

;------------------------------------------------------------------------------
;! Enumeration - EUserHasLicenseResult
;------------------------------------------------------------------------------
Const BS_EUserHasLicenseResult_HasLicense					= 0 ; User has a license for specified app
Const BS_EUserHasLicenseResult_DoesNotHaveLicense			= 1 ; User does not have a license for the specified app
Const BS_EUserHasLicenseResult_NoAuth						= 2 ; User has not been authenticated

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



;[Block] Old 
;! AppList ---------------------------------------------------------------------
Const BS_CALLBACK_AppInstalled								= BS_ECallback_SteamAppListCallbacks + 1
Const BS_CALLBACK_AppUninstalled							= BS_ECallback_SteamAppListCallbacks + 2
;! Apps ------------------------------------------------------------------------
Const BS_CALLBACK_DLCInstalled								= BS_ECallback_SteamAppsCallbacks + 5
Const BS_CALLBACK_APPProofOfPurchaseKeyResponse				= BS_ECallback_SteamAppsCallbacks + 13
Const BS_CALLBACK_NewLaunchQueryParameters					= BS_ECallback_SteamAppsCallbacks + 14

;! Controller ------------------------------------------------------------------
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

;! Friends ---------------------------------------------------------------------
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


Type BS_FriendSessionStateInfo
	Field m_uiOnlineSessionInstances
	Field m_uiPublishedToFriendsSessionInstance
End Type

Const BS_cubChatMetadataMax									= 8192
Const BS_cchMaxRichPresenceKeys								= 20
Const BS_cchMaxRichPresenceKeyLength						= 64
Const BS_cchMaxRichPresenceValueLength						= 256


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

;! GameServer ------------------------------------------------------------------

; client has been approved to connect to this game server
Const BS_CALLBACK_GSClientApprove							= BS_ECallback_SteamGameServerCallbacks + 1
Type BS_GSClientApprove_t
	Field SteamIDHigh%, SteamIDLow%					; SteamID of approved player
	Field OwnerSteamIDHigh%, OwnerSteamIDLow%		; SteamID of original owner for game license
End Type

; client has been denied to connection to this game server
Const BS_CALLBACK_GSClientDeny								= BS_ECallback_SteamGameServerCallbacks + 2
Type BS_GSClientDeny_t
	Field SteamIDHigh%, SteamIDLow%
	Field eDenyReason%, pad0%
	Field rgchOptionalText%[31]						; 128 Bytes of Optional Text
End Type

; request the game server should kick the user
Const BS_CALLBACK_GSClientKick								= BS_ECallback_SteamGameServerCallbacks + 3
Type BS_GSClientKick_t
	Field SteamIDHigh%, SteamIDLow%
	Field eDenyReason%, pad0%
End Type

; client achievement info
Const BS_CALLBACK_GSClientAchievementStatus					= BS_ECallback_SteamGameServerCallbacks + 6
Type BS_GSClientAchievementStatus_t
	Field SteamIDHigh%, SteamIDLow%
	Field pchAchievement[31]						; 128 byte C-String Achievement
	Field bUnlocked%, pad0%
End Type

; received when the game server requests to be displayed as secure (VAC protected)
; m_bSecure is true if the game server should display itself as secure to users, false otherwise
Const BS_CALLBACK_GSPolicyResponse							= BS_ECallback_SteamUserCallbacks + 15
Type BS_GSPolicyResponse_t
	Field m_bSecure%, pad0%
End Type

; GS gameplay stats info
Const BS_CALLBACK_GSGameplayStats							= BS_ECallback_SteamGameServerCallbacks + 7
Type BS_GSGameplayStats_t
	Field eResult%, pad0%							; Result of the call
	Field nRank%, pad1%							; Overall rank of the server (0-based)
	Field unTotalConnects%, pad2%					; Total number of clients who have ever connected to the server
	Field unTotalMinutesPlayed%, pad3%				; Total number of minutes ever played on the server
End Type

; send as a reply to RequestUserGroupStatus()
Const BS_CALLBACK_GSClientGroupStatus						= BS_ECallback_SteamGameServerCallbacks + 8
Type BS_GSClientGroupStatus_t
	Field SteamIDUserHigh%, SteamIDUserLow%
	Field SteamIDGroupHigh%, SteamIDGroupLow%
	Field bMember%, pad0%
	Field bOfficer%, pad1%
End Type

; Sent as a reply to GetServerReputation()
Const BS_CALLBACK_GSReputation								= BS_ECallback_SteamGameServerCallbacks + 9
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

; Sent as a reply to AssociateWithClan()
Const BS_CALLBACK_AssociateWithClanResult					= BS_ECallback_SteamGameServerCallbacks + 10
Type BS_AssociateWithClanResult_t
	Field eResult%									; Result of the call
End Type

; Sent as a reply to ComputeNewPlayerCompatibility()
Const BS_CALLBACK_ComputeNewPlayerCompatibilityResult		= BS_ECallback_SteamGameServerCallbacks + 11
Type BS_ComputeNewPlayerCompatibilityResult_t
	Field eResult%, pad0%							; Result of the call
	Field cPlayersThatDontLikeCandidate%, pad1%
	Field cPlayersThatCandidateDoesntLike%, pad2%
	Field cClanPlayersThatDontLikeCandidate%, pad3%
	Field SteamIDCandidateHigh%, SteamIDCandidateLow%
End Type

;! Networking ------------------------------------------------------------------

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

;! User ------------------------------------------------------------------------

;! UserStats -------------------------------------------------------------------
Const BS_cchStatNameMax										= 128
Const BS_cchLeaderboardNameMax								= 128
Const BS_cLeaderboardDetailsMax								= 64

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
	Field hSteamLeaderboard_High%, hSteamLeaderboard_Low%	;	 handle to the leaderboard serarched for, 0 if no leaderboard found
	Field bLeaderboardFound%								;				 0 if no leaderboard found
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

Const BS_CALLBACK_UserStatsUnloaded							= BS_ECallback_SteamUserStatsCallbacks + 8
Type BS_UserStatsUnloaded
	Field steamIDUser_High, steamIDUser_Low					; User whose stats have been unloaded
End Type

Const BS_CALLBACK_UserAchievementIconFetched				= BS_ECallback_SteamUserStatsCallbacks + 9
Type BS_UserAchievementIconFetched
	Field nGameID_High, nGameID_Low							; Game this is for
	Field rgchAchievementName[BS_cchStatNameMax]			; name of the achievement
	Field bAchieved											; Is the icon for the achieved or not achieved version?
	Field nIconHandle										; Handle to the image, which can be used in SteamUtils()->GetImageRGBA(), 0 means no image is set for the achievement
End Type

Const BS_CALLBACK_GlobalAchievementPercentagesReady			= BS_ECallback_SteamUserStatsCallbacks + 10
Type BS_GlobalAchievementPercentagesReady
	Field nGameID_High, nGameID_Low							; Game this is for
	Field eResult											; Result of the operation
End Type

Const BS_CALLBACK_LeaderboardUGCSet							= BS_ECallback_SteamUserStatsCallbacks + 11
Type BS_LeaderboardUGCSet
	Field eResult											; The result of the operation
	Field hSteamLeaderboard_High, hSteamLeaderboard_Low		; the leaderboard handle that was
End Type

Const BS_CALLBACK_GlobalStatsReceived						= BS_ECallback_SteamUserStatsCallbacks + 12
Type BS_GlobalStatsReceived
	Field nGameID_High, nGameId_Low							; Game global stats were requested for
	Field eResult											; The result of the request
End Type

;[End Block]
;~IDEal Editor Parameters:
;~F#196#1B9
;~C#Blitz3D