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
Const BLITZSTEAM_ENUM_CALLBACK_SteamAppListCallbacks					= 3900
Const BLITZSTEAM_ENUM_CALLBACK_SteamAppsCallbacks						= 1000
Const BLITZSTEAM_ENUM_CALLBACK_SteamBillingCallbacks					= 400
Const BLITZSTEAM_ENUM_CALLBACK_SteamContentServerCallbacks				= 600
Const BLITZSTEAM_ENUM_CALLBACK_SteamControllerCallbacks					= 2800
Const BLITZSTEAM_ENUM_CALLBACK_SteamFriendsCallbacks					= 300
Const BLITZSTEAM_ENUM_CALLBACK_SteamGameCoordinatorCallbacks			= 1700
Const BLITZSTEAM_ENUM_CALLBACK_SteamGameServerCallbacks					= 200
Const BLITZSTEAM_ENUM_CALLBACK_SteamGameServerItemsCallbacks			= 1500
Const BLITZSTEAM_ENUM_CALLBACK_SteamGameServerStatsCallbacks			= 1800
Const BLITZSTEAM_ENUM_CALLBACK_SteamGameStatsCallbacks					= 2000
Const BLITZSTEAM_ENUM_CALLBACK_SteamHTMLSurfaceCallbacks				= 4500
Const BLITZSTEAM_ENUM_CALLBACK_SteamMatchmakingCallbacks				= 500
Const BLITZSTEAM_ENUM_CALLBACK_SteamMusicCallbacks						= 4000
Const BLITZSTEAM_ENUM_CALLBACK_SteamMusicRemoteCallbacks				= 4100
Const BLITZSTEAM_ENUM_CALLBACK_SteamNetworkingCallbacks					= 1200
Const BLITZSTEAM_ENUM_CALLBACK_SteamReservedCallbacks					= 4400
Const BLITZSTEAM_ENUM_CALLBACK_SteamScreenshotsCallbacks				= 2300
Const BLITZSTEAM_ENUM_CALLBACK_SteamStreamLauncherCallbacks				= 2600
Const BLITZSTEAM_ENUM_CALLBACK_SteamStreamClientCallbacks				= 3500
Const BLITZSTEAM_ENUM_CALLBACK_SteamUserCallbacks						= 100
Const BLITZSTEAM_ENUM_CALLBACK_SteamUserStatsCallbacks					= 1100
Const BLITZSTEAM_ENUM_CALLBACK_SteamUtilsCallbacks						= 700
Const BLITZSTEAM_ENUM_CALLBACK_Steam2AsyncCallbacks						= 1900
Const BLITZSTEAM_ENUM_CALLBACK_ClientAudioCallbacks						= 2400
Const BLITZSTEAM_ENUM_CALLBACK_ClientControllerCallbacks				= 2700
Const BLITZSTEAM_ENUM_CALLBACK_ClientDepotBuilderCallbacks				= 1400
Const BLITZSTEAM_ENUM_CALLBACK_ClientDeviceAuthCallbacks				= 3000
Const BLITZSTEAM_ENUM_CALLBACK_ClientFriendsCallbacks					= 800
Const BLITZSTEAM_ENUM_CALLBACK_ClientHTTPCallbacks						= 2100
Const BLITZSTEAM_ENUM_CALLBACK_ClientInventoryCallbacks					= 4700
Const BLITZSTEAM_ENUM_CALLBACK_ClientMusicCallbacks						= 3200
Const BLITZSTEAM_ENUM_CALLBACK_ClientNetworkDeviceManagerCallbacks		= 3100
Const BLITZSTEAM_ENUM_CALLBACK_ClientParentalSettingsCallbacks			= 2900
Const BLITZSTEAM_ENUM_CALLBACK_ClientProductBuilderCallbacks			= 3600
Const BLITZSTEAM_ENUM_CALLBACK_ClientRemoteStorageCallbacks				= 1300
Const BLITZSTEAM_ENUM_CALLBACK_ClientRemoteClientManagerCallbacks		= 3300
Const BLITZSTEAM_ENUM_CALLBACK_ClientRemoteControlManagerCallbacks		= 3800
Const BLITZSTEAM_ENUM_CALLBACK_ClientReservedCallbacks					= 4300
Const BLITZSTEAM_ENUM_CALLBACK_ClientScreenshotsCallbacks				= 2200
Const BLITZSTEAM_ENUM_CALLBACK_ClientShortcutsCallbacks					= 3700
Const BLITZSTEAM_ENUM_CALLBACK_ClientUGCCallbacks						= 3400
Const BLITZSTEAM_ENUM_CALLBACK_ClientUnifiedMessagesCallbacks			= 2500
Const BLITZSTEAM_ENUM_CALLBACK_ClientUserCallbacks						= 900
Const BLITZSTEAM_ENUM_CALLBACK_ClientUtilsCallbacks						= 1600
Const BLITZSTEAM_ENUM_CALLBACK_ClientVideoCallbacks						= 4600
Const BLITZSTEAM_ENUM_CALLBACK_ClientVRCallbacks						= 4200

; SteamAppList ------------------------------------------------------------------
Const BLITZSTEAM_CALLBACK_APPINSTALLED								= BLITZSTEAM_ENUM_CALLBACK_SteamAppListCallbacks + 1
Const BLITZSTEAM_CALLBACK_APPUNINSTALLED							= BLITZSTEAM_ENUM_CALLBACK_SteamAppListCallbacks + 2

; SteamApps ---------------------------------------------------------------------
Const BLITZSTEAM_CALLBACK_DLCINSTALLED								= BLITZSTEAM_ENUM_CALLBACK_SteamAppsCallbacks + 5
Const BLITZSTEAM_CALLBACK_APPPROOFOFPURCHASEKEYRESPONSE				= BLITZSTEAM_ENUM_CALLBACK_SteamAppsCallbacks + 13
Const BLITZSTEAM_CALLBACK_NEWLAUNCHQUERYPARAMETERS					= BLITZSTEAM_ENUM_CALLBACK_SteamAppsCallbacks + 14
; The following things are PS3 only:
;   ERegisterActivationCodeResult
;   RegisterActivationCodeResponse_t

; SteamClient -------------------------------------------------------------------
Const BLITZSTEAM_EACCOUNTYPE_INVALID								= 0
Const BLITZSTEAM_EACCOUNTYPE_INDIVIDUAL								= 1
Const BLITZSTEAM_EACCOUNTYPE_MULTISEAT								= 2
Const BLITZSTEAM_EACCOUNTYPE_GAMESERVER								= 3
Const BLITZSTEAM_EACCOUNTYPE_ANONGAMESERVER							= 4
Const BLITZSTEAM_EACCOUNTYPE_PENDING								= 5
Const BLITZSTEAM_EACCOUNTYPE_CONTENTSERVER							= 6
Const BLITZSTEAM_EACCOUNTYPE_CLAN									= 7
Const BLITZSTEAM_EACCOUNTYPE_CHAT									= 8
;Const BLITZSTEAM_EACCOUNTYPE_CONSOLEUSER							= 9
Const BLITZSTEAM_EACCOUNTYPE_ANONUSER								= 10

; SteamController ---------------------------------------------------------------
Const BLITZSTEAM_RIGHT_TRIGGER_MASK									= $00000001
Const BLITZSTEAM_LEFT_TRIGGER_MASK									= $00000002
Const BLITZSTEAM_RIGHT_BUMPER_MASK									= $00000004
Const BLITZSTEAM_LEFT_BUMPER_MASK									= $00000008
Const BLITZSTEAM_BUTTON_0_MASK										= $00000010
Const BLITZSTEAM_BUTTON_1_MASK										= $00000020
Const BLITZSTEAM_BUTTON_2_MASK										= $00000040
Const BLITZSTEAM_BUTTON_3_MASK										= $00000080
Const BLITZSTEAM_TOUCH_0_MASK										= $00000100
Const BLITZSTEAM_TOUCH_1_MASK										= $00000200
Const BLITZSTEAM_TOUCH_2_MASK										= $00000400
Const BLITZSTEAM_TOUCH_3_MASK										= $00000800
Const BLITZSTEAM_BUTTON_MENU_MASK									= $0001000
Const BLITZSTEAM_BUTTON_STEAM_MASK							        = $0002000
Const BLITZSTEAM_BUTTON_ESCAPE_MASK									= $0004000
Const BLITZSTEAM_BUTTON_BACK_LEFT_MASK							    = $0008000
Const BLITZSTEAM_BUTTON_BACK_RIGHT_MASK								= $0010000
Const BLITZSTEAM_BUTTON_LEFTPAD_CLICKED_MASK						= $0020000
Const BLITZSTEAM_BUTTON_RIGHTPAD_CLICKED_MASK						= $0040000
Const BLITZSTEAM_LEFTPAD_FINGERDOWN_MASK							= $0080000
Const BLITZSTEAM_RIGHTPAD_FINGERDOWN_MASK							= $0100000
Const BLITZSTEAM_JOYSTICK_BUTTON_MASK								= $0400000
Const BLITZSTEAM_ESTEAMCONTROLLERPAD_LEFT							= 0
Const BLITZSTEAM_ESTEAMCONTROLLERPAD_RIGHT							= 1

Type BlitzSteamControllerState
	Field unPacketNum%
	Field ulButtonsL%, ulButtonsR%
	Field sLeftPadXY // Left/High = X, Right/Low = Y
	Field sRightPadXY // Left/High = X, Right/Low = Y
End Type

;----------------------------------------------------------------
;-- Enumerations
;----------------------------------------------------------------
Const EResultOK	= 1;							; success
Const EResultFail = 2;							; generic failure 
Const EResultNoConnection = 3;					; no/failed network connection
Const EResultInvalidPassword = 5;				; password/ticket is invalid
Const EResultLoggedInElsewhere = 6;				; same user logged in elsewhere
Const EResultInvalidProtocolVer = 7;			; protocol version is incorrect
Const EResultInvalidParam = 8;					; a parameter is incorrect
Const EResultFileNotFound = 9;					; file was not found
Const EResultBusy = 10;							; called method busy - action not taken
Const EResultInvalidState = 11;					; called object was in an invalid state
Const EResultInvalidName = 12;					; name is invalid
Const EResultInvalidEmail = 13;					; email is invalid
Const EResultDuplicateName = 14;				; name is not unique
Const EResultAccessDenied = 15;					; access is denied
Const EResultTimeout = 16;						; operation timed out
Const EResultBanned = 17;						; VAC2 banned
Const EResultAccountNotFound = 18;				; account not found
Const EResultInvalidSteamID = 19;				; steamID is invalid
Const EResultServiceUnavailable = 20;			; The requested service is currently unavailable
Const EResultNotLoggedOn = 21;					; The user is not logged on
Const EResultPending = 22;						; Request is pending (may be in process; or waiting on third party)
Const EResultEncryptionFailure = 23;			; Encryption or Decryption failed
Const EResultInsufficientPrivilege = 24;		; Insufficient privilege
Const EResultLimitExceeded = 25;				; Too much of a good thing
Const EResultRevoked = 26;						; Access has been revoked (used for revoked guest passes)
Const EResultExpired = 27;						; License/Guest pass the user is trying to access is expired
Const EResultAlreadyRedeemed = 28;				; Guest pass has already been redeemed by account; cannot be acked again
Const EResultDuplicateRequest = 29;				; The request is a duplicate and the action has already occurred in the past; ignored this time
Const EResultAlreadyOwned = 30;					; All the games in this guest pass redemption request are already owned by the user
Const EResultIPNotFound = 31;					; IP address not found
Const EResultPersistFailed = 32;				; failed to write change to the data store
Const EResultLockingFailed = 33;				; failed to acquire access lock for this operation
Const EResultLogonSessionReplaced = 34;
Const EResultConnectFailed = 35;
Const EResultHandshakeFailed = 36;
Const EResultIOFailure = 37;
Const EResultRemoteDisconnect = 38;
Const EResultShoppingCartNotFound = 39;			; failed to find the shopping cart requested
Const EResultBlocked = 40;						; a user didn't allow it
Const EResultIgnored = 41;						; target is ignoring sender
Const EResultNoMatch = 42;						; nothing matching the request found
Const EResultAccountDisabled = 43;
Const EResultServiceReadOnly = 44;				; this service is not accepting content changes right now
Const EResultAccountNotFeatured = 45;			; account doesn't have value; so this feature isn't available
Const EResultAdministratorOK = 46;				; allowed to take this action; but only because requester is admin
Const EResultContentVersion = 47;				; A Version mismatch in content transmitted within the Steam protocol.
Const EResultTryAnotherCM = 48;					; The current CM can't service the user making a request; user should try another.
Const EResultPasswordRequiredToKickSession = 49;; You are already logged in elsewhere; this cached credential login has failed.
Const EResultAlreadyLoggedInElsewhere = 50;		; You are already logged in elsewhere; you must wait
Const EResultSuspended = 51;					; Long running operation (content download) suspended/paused
Const EResultCancelled = 52;					; Operation canceled (typically by user: content download)
Const EResultDataCorruption = 53;				; Operation canceled because data is ill formed or unrecoverable
Const EResultDiskFull = 54;						; Operation canceled - not enough disk space.
Const EResultRemoteCallFailed = 55;				; an remote call or IPC call failed
Const EResultPasswordUnset = 56;				; Password could not be verified as it's unset server side
Const EResultExternalAccountUnlinked = 57;		; External account (PSN; Facebook...) is not linked to a Steam account
Const EResultPSNTicketInvalid = 58;				; PSN ticket was invalid
Const EResultExternalAccountAlreadyLinked = 59;	; External account (PSN; Facebook...) is already linked to some other account; must explicitly request to replace/delete the link first
Const EResultRemoteFileConflict = 60;			; The sync cannot resume due to a conflict between the local and remote files
Const EResultIllegalPassword = 61;				; The requested new password is not legal
Const EResultSameAsPreviousValue = 62;			; new value is the same as the old one ( secret question and answer )
Const EResultAccountLogonDenied = 63;			; account login denied due to 2nd factor authentication failure
Const EResultCannotUseOldPassword = 64;			; The requested new password is not legal
Const EResultInvalidLoginAuthCode = 65;			; account login denied due to auth code invalid
Const EResultAccountLogonDeniedNoMail = 66;		; account login denied due to 2nd factor auth failure - and no mail has been sent
Const EResultHardwareNotCapableOfIPT = 67;		; 
Const EResultIPTInitError = 68;					; 
Const EResultParentalControlRestricted = 69;	; operation failed due to parental control restrictions for current user
Const EResultFacebookQueryError = 70;			; Facebook query returned an error
Const EResultExpiredLoginAuthCode = 71;			; account login denied due to auth code expired
Const EResultIPLoginRestrictionFailed = 72;
Const EResultAccountLockedDown = 73;
Const EResultAccountLogonDeniedVerifiedEmailRequired = 74;
Const EResultNoMatchingURL = 75;
Const EResultBadResponse = 76;					; parse failure; missing field; etc.
Const EResultRequirePasswordReEntry = 77;		; The user cannot complete the action until they re-enter their password
Const EResultValueOutOfRange = 78;				; the value entered is outside the acceptable range
Const EResultUnexpectedError = 79;				; something happened that we didn't expect to ever happen
Const EResultDisabled = 80;						; The requested service has been configured to be unavailable
Const EResultInvalidCEGSubmission = 81;			; The set of files submitted to the CEG server are not valid !
Const EResultRestrictedDevice = 82;				; The device being used is not allowed to perform this action
Const EResultRegionLocked = 83;					; The action could not be complete because it is region restricted
Const EResultRateLimitExceeded = 84;			; Temporary rate limit exceeded; try again later; different from k_EResultLimitExceeded which may be permanent
Const EResultAccountLoginDeniedNeedTwoFactor = 85;	; Need two-factor code to login
Const EResultItemDeleted = 86;					; The thing we're trying to access has been deleted
Const EResultAccountLoginDeniedThrottle = 87;	; login attempt failed; try to throttle response to possible attacker
Const EResultTwoFactorCodeMismatch = 88;		; two factor code mismatch
Const EResultTwoFactorActivationCodeMismatch = 89;	; activation code for two-factor didn't match
Const EResultAccountAssociatedToMultiplePartners = 90;	; account has been associated with multiple partners
Const EResultNotModified = 91;					; data not modified
Const EResultNoMobileDevice = 92;				; the account does not have a mobile device associated with it
Const EResultTimeNotSynced = 93;				; the time presented is out of range or tolerance
Const EResultSmsCodeFailed = 94;				; SMS code failure (no match; none pending; etc.)
Const EResultAccountLimitExceeded = 95;			; Too many accounts access this resource
Const EResultAccountActivityLimitExceeded = 96;	; Too many changes to this account
Const EResultPhoneActivityLimitExceeded = 97;	; Too many changes to this phone

Const EVoiceResultOK = 0;
Const EVoiceResultNotInitialized = 1;
Const EVoiceResultNotRecording = 2;
Const EVoiceResultNoData = 3;
Const EVoiceResultBufferTooSmall = 4;
Const EVoiceResultDataCorrupted = 5;
Const EVoiceResultRestricted = 6;
Const EVoiceResultUnsupportedCodec = 7;
Const EVoiceResultReceiverOutOfDate = 8;
Const EVoiceResultReceiverDidNotAnswer = 9;

Const EDenyInvalid = 0;
Const EDenyInvalidVersion = 1;
Const EDenyGeneric = 2;
Const EDenyNotLoggedOn = 3;
Const EDenyNoLicense = 4;
Const EDenyCheater = 5;
Const EDenyLoggedInElseWhere = 6;
Const EDenyUnknownText = 7;
Const EDenyIncompatibleAnticheat = 8;
Const EDenyMemoryCorruption = 9;
Const EDenyIncompatibleSoftware = 10;
Const EDenySteamConnectionLost = 11;
Const EDenySteamConnectionError = 12;
Const EDenySteamResponseTimedOut = 13;
Const EDenySteamValidationStalled = 14;
Const EDenySteamOwnerLeftGuestUser = 15;

Const EBeginAuthSessionResultOK = 0;						; Ticket is valid for this game and this steamID.
Const EBeginAuthSessionResultInvalidTicket = 1;				; Ticket is not valid.
Const EBeginAuthSessionResultDuplicateRequest = 2;			; A ticket has already been submitted for this steamID
Const EBeginAuthSessionResultInvalidVersion = 3;			; Ticket is from an incompatible interface version
Const EBeginAuthSessionResultGameMismatch = 4;				; Ticket is not for this game
Const EBeginAuthSessionResultExpiredTicket = 5;				; Ticket has expired

Const EAuthSessionResponseOK = 0;							; Steam has verified the user is online; the ticket is valid and ticket has not been reused.
Const EAuthSessionResponseUserNotConnectedToSteam = 1;		; The user in question is not connected to steam
Const EAuthSessionResponseNoLicenseOrExpired = 2;			; The license has expired.
Const EAuthSessionResponseVACBanned = 3;					; The user is VAC banned for this game.
Const EAuthSessionResponseLoggedInElseWhere = 4;			; The user account has logged in elsewhere and the session containing the game instance has been disconnected.
Const EAuthSessionResponseVACCheckTimedOut = 5;				; VAC has been unable to perform anti-cheat checks on this user
Const EAuthSessionResponseAuthTicketCanceled = 6;			; The ticket has been canceled by the issuer
Const EAuthSessionResponseAuthTicketInvalidAlreadyUsed = 7;	; This ticket has already been used; it is not valid.
Const EAuthSessionResponseAuthTicketInvalid = 8;			; This ticket is not from a user instance currently connected to steam.
Const EAuthSessionResponsePublisherIssuedBan = 9;			; The user is banned for this game. The ban came via the web api and not VAC

Const EUserHasLicenseResultHasLicense = 0;					; User has a license for specified app
Const EUserHasLicenseResultDoesNotHaveLicense = 1;			; User does not have a license for the specified app
Const EUserHasLicenseResultNoAuth = 2;						; User has not been authenticated
