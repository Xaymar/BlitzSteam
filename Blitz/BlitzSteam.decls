;	BS_ - Steam wrapper for Blitz.
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
; Helpers -----------------------------------------------------------------------
; -- CSteamID
BS_CSteamID_New%()
BS_CSteamID_FromID%(unAccountID%, eUniverse%, eAccountType%)
BS_CSteamID_FromIDInstance%(unAccountID%, unInstance%, eUniverse%, eAccountType%)
BS_CSteamID_FromSteamID%(ulSteamID%)
BS_CSteamID_Copy%(pSteamID%)
BS_CSteamID_Destroy(pSteamID%)
BS_CSteamID_Set(pSteamID%, unAccountID%, eUniverse%, eAccountType%)
BS_CSteamID_InstancedSet(pSteamID%, unAccountID%, unInstance%, eUniverse%, eAccountType%)
BS_CSteamID_FullSet(pSteamID%, ulIdentifier%, eUniverse%, eAccountType%)
BS_CSteamID_SetFromUInt64(pSteamID%, ulSteamID%)
BS_CSteamID_Clear(pSteamID%)
BS_CSteamID_ConvertToUInt64%(pSteamID%)
BS_CSteamID_GetStaticAccountKey%(pSteamID%)
BS_CSteamID_CreateBlankAnonLogon(pSteamID%, eUniverse%)
BS_CSteamID_CreateBlankAnonUserLogon(pSteamID%, eUniverse%)
BS_CSteamID_BlankAnonAccount%(pSteamID%)
BS_CSteamID_GameServerAccount%(pSteamID%)
BS_CSteamID_PersistentGameServerAccount%(pSteamID%)
BS_CSteamID_AnonGameServerAccount%(pSteamID%)
BS_CSteamID_ContentServerAccount%(pSteamID%)
BS_CSteamID_ClanAccount%(pSteamID%)
BS_CSteamID_ChatAccount%(pSteamID%)
BS_CSteamID_IsLobby%(pSteamID%)
BS_CSteamID_IndividualAccount%(pSteamID%)
BS_CSteamID_AnonAccount%(pSteamID%)
BS_CSteamID_AnonUserAccount%(pSteamID%)
BS_CSteamID_ConsoleUserAccount%(pSteamID%)
BS_CSteamID_SetAccountID(pSteamID%, unAccountID%)
BS_CSteamID_SetAccountInstance(pSteamID, unInstance%)
BS_CSteamID_ClearIndividualInstance(pSteamID%)
BS_CSteamID_HasNoIndividualInstance%(pSteamID%)
BS_CSteamID_GetAccountID%(pSteamID%)
BS_CSteamID_GetAccountInstance%(pSteamID%)
BS_CSteamID_GetEAccountType%(pSteamID%)
BS_CSteamID_GetEUniverse%(pSteamID%)
BS_CSteamID_SetEUniverse(pSteamID%, eUniverse%)
BS_CSteamID_IsValid%(pSteamID%)
BS_CSteamID_Compare%(pSteamID%, pSteamIDOther%)

; Steam -------------------------------------------------------------------------
BS_Init%()
BS_Shutdown()
BS_IsSteamRunning%()
BS_RestartAppIfNecessary%(unOwnAppID%)
BS_SetMiniDumpComment(pchMsg$)
BS_WriteMiniDumpEx(uStructuredExceptionCode%, pvExceptionInfo%, uBuildID%) : "BS_WriteMiniDump"
BS_WriteMiniDump(uStructuredExceptionCode%, pvExceptionInfo*, uBuildID%)
; -- Interfaces
BS_AppList%()
BS_Apps%()
BS_Client%()
BS_Controller%()
BS_Friends%()
BS_HTTP%()
BS_HTMLSurface%()
BS_Inventory%()
BS_Matchmaking%()
BS_MatchmakingServers%()
BS_Music%()
BS_MusicRemote%()
BS_Networking%()
BS_RemoteStorage%()
BS_Screenshots%()
BS_UGC%()
BS_UnifiedMessages%()
BS_User%()
BS_UserStats%()
BS_Utils%()
BS_Video%()
; -- Callbacks & Hooks
BS_RunCallbacks()
BS_RegisterCallback(pCallback%, iCallback%)
BS_UnregisterCallback(pCallback%)
BS_RegisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)
BS_UnregisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)

; SteamAppList ------------------------------------------------------------------
BS_AppList_GetNumInstalledApps%(lpSteamAppList%)
BS_AppList_GetInstalledAppsEx%(lpSteamAppList%, pvecAppID%, unMaxIDs%) : "BS_AppList_GetInstalledApps"
BS_AppList_GetInstalledApps%(lpSteamAppList%, pvecAppID*, unMaxIDs%)
BS_AppList_GetAppNameEx%(lpSteamAppList%, nAppId%, pchName%, cchNameMax%) : "BS_AppList_GetAppName"
BS_AppList_GetAppName%(lpSteamAppList%, nAppId%, pchName*, cchNameMax%)
BS_AppList_GetAppInstallDirEx%(lpSteamAppList%, nAppId%, pchDirectory%, cchDirectoryMax%) : "BS_AppList_GetAppInstallDir"
BS_AppList_GetAppInstallDir%(lpSteamAppList%, nAppId%, pchDirectory*, cchDirectoryMax%)
BS_AppList_GetAppBuildId%(lpSteamAppList%, nAppId%)

; SteamApps ---------------------------------------------------------------------
BS_Apps_IsSubscribed%(lpSteamApps%)
BS_Apps_IsLowViolence%(lpSteamApps%)
BS_Apps_IsCybercafe%(lpSteamApps%)
BS_Apps_IsVACBanned%(lpSteamApps%)
BS_Apps_GetCurrentGameLanguage$(lpSteamApps%)
BS_Apps_GetAvailableGameLanguages$(lpSteamApps%)
BS_Apps_IsSubscribedApp%(lpSteamApps%, appID%)
BS_Apps_IsDlcInstalled%(lpSteamApps%, appID%)
BS_Apps_GetEarliestPurchaseUnixTime%(lpSteamApps%, appID%)
BS_Apps_IsSubscribedFromFreeWeekend%(lpSteamApps%)
BS_Apps_GetDLCCount%(lpSteamApps%)
BS_Apps_GetDLCDataByIndexEx%(lpSteamApps%, iDLC%, pAppId%, pbAvailable%, pchName%, cchNameBufferSize%) : "BS_Apps_GetDLCDataByIndex"
BS_Apps_GetDLCDataByIndex%(lpSteamApps%, iDLC%, pAppId*, pbAvailable*, pchName*, cchNameBufferSize%)
BS_Apps_InstallDLC(lpSteamApps%, nAppID%)
BS_Apps_UninstallDLC(lpSteamApps%, nAppID%)
BS_Apps_RequestAppProofOfPurchaseKey(lpSteamApps%, nAppID%)
BS_Apps_GetCurrentBetaNameEx%(lpSteamApps%, pchName%, cchNameBufferSize%) : "BS_Apps_GetCurrentBetaName"
BS_Apps_GetCurrentBetaName%(lpSteamApps%, pchName*, cchNameBufferSize%)
BS_Apps_MarkContentCorrupt%(lpSteamApps%, bMissingFilesOnly%)
BS_Apps_GetInstalledDepotsEx%(lpSteamApps%, nAppID%, pvecDepots%, cMaxDepots%) : "BS_Apps_GetInstalledDepots"
BS_Apps_GetInstalledDepots%(lpSteamApps%, nAppID%, pvecDepots*, cMaxDepots%)
BS_Apps_GetAppInstallDirEx%(lpSteamApps%, nAppID%, pchFolder%, cchFolderBufferSize%) : "BS_Apps_GetAppInstallDir"
BS_Apps_GetAppInstallDir%(lpSteamApps%, nAppID%, pchFolder*, cchFolderBufferSize%)
BS_Apps_IsAppInstalled%(lpSteamApps%, nAppID%)
BS_Apps_GetAppOwner%(lpSteamApps%)
BS_Apps_GetLaunchQueryParam$(lpSteamApps%, pchKey$)
BS_Apps_GetDlcDownloadProgressEx%(lpSteamApps%, nAppID%, punBytesDownloaded%, punBytesTotal%) : "BS_Apps_GetDlcDownloadProgress"
BS_Apps_GetDlcDownloadProgress%(lpSteamApps%, nAppID%, punBytesDownloaded*, punBytesTotal*)
BS_Apps_GetAppBuildId%(lpSteamApps%)

; SteamClient -------------------------------------------------------------------
BS_Client_CreateSteamPipe%(lpSteamClient%)
BS_Client_ReleaseSteamPipe%(lpSteamClient%, hSteamPipe%)
BS_Client_ConnectToGlobalUser%(lpSteamClient%, hSteamPipe%)
BS_Client_SetLocalIPBinding(lpSteamClient, unIP%, usPort%)
BS_Client_CreateLocalUserEx%(lpSteamClient%, phSteamPipe*, eAccountType%) : "BS_Client_CreateLocalUser"
BS_Client_CreateLocalUser%(lpSteamClient%, phSteamPipe*, eAccountType%)
BS_Client_ReleaseUser(lpSteamClient%, hSteamPipe%, hSteamUser%)
BS_Client_RunFrame(lpSteamClient%)
BS_Client_GetIPCCallCount%(lpSteamClient%)
BS_Client_ShutdownIfAllPipesClosed%(lpSteamClient%)
; -- Interfaces
BS_Client_GetSteamAppList%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamApps%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamController%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamFriends%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamGameServer%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamGameServerStats%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamHTMLSurface%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamHTTP%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamInventory%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamMatchmaking%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamMatchmakingServers%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamMusic%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamMusicRemote%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamNetworking%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamRemoteStorage%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamScreenshots%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamUGC%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamUnifiedMessages%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamUser%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamUserStats%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamUtils%(lpSteamClient%, hSteamPipe%, pchVersion$)
BS_Client_GetSteamVideo%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
; -- Callbacks & Hooks
BS_Client_SetWarningMessageHook(lpSteamClient%, fpFunction%)
BS_Client_Set_SteamAPI_CPostAPIResultInProcess(lpSteamClient%, fpFunction%)
BS_Client_Remove_SteamAPI_CPostAPIResultInProcess(lpSteamClient%, fpFunction%)
BS_Client_Set_SteamAPI_CCheckCallbackRegisteredInProcess(lpSteamClient%, fpFunction%)

; SteamController ---------------------------------------------------------------
BS_Controller_Init%(lpSteamController%, pchAbsolutePathToControllerConfigVDF$)
BS_Controller_Shutdown%(lpSteamController%)
BS_Controller_RunFrame(lpSteamController%)
BS_Controller_GetControllerStateEx%(lpSteamController%, unControllerIndex%, pState%) : "BS_Controller_GetControllerState"
BS_Controller_GetControllerState%(lpSteamController%, unControllerIndex%, pState*)
BS_Controller_TriggerHapticPulse(lpSteamController%, unControllerIndex%, eTargetPad%, usDurationMicroSec%)
BS_Controller_SetOverrideMode(lpSteamController%, pchMode$)

; SteamFriends ------------------------------------------------------------------
BS_Friends_GetPersonaName$(lpSteamFriends%)
BS_Friends_SetPersonaName%(lpSteamFriends%, pchPersonaName$)
BS_Friends_GetPersonaState%(lpSteamFriends%)
BS_Friends_GetFriendCount%(lpSteamFriends%, iFriendFlags%)
BS_Friends_GetFriendByIndex%(lpSteamFriends%, iFriend%, iFriendFlags%)
BS_Friends_GetFriendRelationship%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendPersonaState%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendPersonaName$(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendGamePlayedEx%(lpSteamFriends%, steamIDFriend%, pFriendGameInfo%) : "BS_Friends_GetFriendGamePlayed"
BS_Friends_GetFriendGamePlayed%(lpSteamFriends%, steamIDFriend%, pFriendGameInfo*)
BS_Friends_GetFriendPersonaNameHistory$(lpSteamFriends%, steamIDFriend%, iPersonaName%)
BS_Friends_GetFriendSteamLevel%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetPlayerNickname$(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendsGroupCount%(lpSteamFriends%)
BS_Friends_GetFriendsGroupIDByIndex%(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupName$(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupMembersCount%(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupMembersListEx(lpSteamFriends%, friendsGroupID%, pOutSteamIDMembers%, nMembersCount%) : "BS_Friends_GetFriendsGroupMembersList"
BS_Friends_GetFriendsGroupMembersList(lpSteamFriends%, friendsGroupID%, pOutSteamIDMembers*, nMembersCount%)
BS_Friends_HasFriend(lpSteamFriends%, steamIDFriend%, iFriendFlags%)
BS_Friends_GetClanCount%(lpSteamFriends%)
BS_Friends_GetClanByIndex%(lpSteamFriends%, iClan%)
BS_Friends_GetClanName$(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanTag$(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanActivityCountsEx%(lpSteamFriends%, steamIDClan%, pnOnline%, pnInGame%, pnChatting%) : "BS_Friends_GetClanActivityCounts"
BS_Friends_GetClanActivityCounts%(lpSteamFriends%, steamIDClan%, pnOnline*, pnInGame*, pnChatting*)
BS_Friends_DownloadClanActivityCounts%(lpSteamFriends%, steamIDClan%, cClansToRequest%)
BS_Friends_GetFriendCountFromSource%(lpSteamFriends%, steamIDSource%)
BS_Friends_GetFriendFromSourceByIndex%(lpSteamFriends%, steamIDSource%, iFriend%)
BS_Friends_IsUserInSource%(lpSteamFriends%, steamIDUser%, steamIDSource%)
BS_Friends_SetInGameVoiceSpeaking(lpSteamFriends%, steamIDUser%, bSpeaking%)
BS_Friends_ActivateGameOverlay(lpSteamFriends%, pchDialog$)
BS_Friends_ActivateGameOverlayToUser(lpSteamFriends%, pchDialog$, steamID%)
BS_Friends_ActivateGameOverlayToWebPage(lpSteamFriends%, pchURL$)
BS_Friends_ActivateGameOverlayToStore(lpSteamFriends%, nAppID%, eFlag%)
BS_Friends_SetPlayedWith(lpSteamFriends%, steamIDUserPlayedWith%)
BS_Friends_ActivateGameOverlayInviteDialog(lpSteamFriends%, steamIDLobby%)
BS_Friends_GetSmallFriendAvatar%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetMediumFriendAvatar%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetLargeFriendAvatar%(lpSteamFriends%, steamIDFriend%)
BS_Friends_RequestUserInformation%(lpSteamFriends%, steamIDUser%, bRequireNameOnly%)
BS_Friends_RequestClanOfficerList%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanOwner%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanOfficerCount%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanOfficerByIndex%(lpSteamFriends%, steamIDClan%, iOfficer%)
BS_Friends_GetUserRestrictions%(lpSteamFriends%)
BS_Friends_SetRichPresence%(lpSteamFriends%, pchKey$, pchValue$)
BS_Friends_ClearRichPresence(lpSteamFriends%)
BS_Friends_GetFriendRichPresence$(lpSteamFriends%, steamIDFriend%, pchKey$)
BS_Friends_GetFriendRichPresenceKeyCount%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendRichPresenceKeyByIndex$(lpSteamFriends%, steamIDFriend%, iKey%)
BS_Friends_RequestFriendRichPresence(lpSteamFriends%, steamIDFriend%)
BS_Friends_InviteUserToGame%(lpSteamFriends%, steamIDFriend%, pchConnectString%)
BS_Friends_GetCoplayFriendCount%(lpSteamFriends%)
BS_Friends_GetCoplayFriend%(lpSteamFriends%, iCoplayFriend%)
BS_Friends_GetFriendCoplayTime%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendCoplayGame%(lpSteamFriends%, steamIDFriend%)
BS_Friends_JoinClanChatRoom%(lpSteamFriends%, steamIDClan%)
BS_Friends_LeaveClanChatRoom%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanChatMemberCount%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetChatMemberByIndex%(lpSteamFriends%, steamIDClan%, iUser%)
BS_Friends_SendClanChatMessage%(lpSteamFriends%, steamIDClanChat%, pchText$)
BS_Friends_GetClanChatMessageEx%(lpSteamFriends%, steamIDClanChat%, iMessage%, prgchText%, cchTextMax%, peChatEntryType%, psteamidChatter%) : "BS_Friends_GetClanChatMessage"
BS_Friends_GetClanChatMessage%(lpSteamFriends%, steamIDClanChat%, iMessage%, prgchText*, cchTextMax%, peChatEntryType*, psteamidChatter*)
BS_Friends_IsClanChatAdmin%(lpSteamFriends%, steamIDClanChat%, steamIDUser%)
BS_Friends_IsClanChatWindowOpenInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_OpenClanChatWindowInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_CloseClanChatWindowInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_SetListenForFriendsMessages%(lpSteamFriends%, bInterceptEnabled%)
BS_Friends_ReplyToFriendMessage%(lpSteamFriends%, steamIDFriend%, pchMsgToSend$)
BS_Friends_GetFriendMessageEx%(lpSteamFriends%, steamIDFriend%, iMessageID%, pvData%, cubData%, peChatEntryType%) : "BS_Friends_GetFriendMessage"
BS_Friends_GetFriendMessage%(lpSteamFriends%, steamIDFriend%, iMessageID%, pvData*, cubData%, peChatEntryType*)
BS_Friends_GetFollowerCount%(lpSteamFriends%, steamID%)
BS_Friends_IsFollowing%(lpSteamFriends%, steamID%)
BS_Friends_EnumerateFollowingList%(lpSteamFriends%, unStartIndex%)

; SteamGameServer ---------------------------------------------------------------
