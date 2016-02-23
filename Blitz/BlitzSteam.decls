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

; Steam -----------------------------------------------------------------------
BS_Steam_Init%()
BS_Steam_Shutdown()
BS_Steam_IsSteamRunning%()
BS_Steam_RestartAppIfNecessary%(unOwnAppID%)
BS_Steam_SetMiniDumpComment(pchMsg$)
BS_Steam_WriteMiniDump(uStructuredExceptionCode%, pvExceptionInfo*, uBuildID%)
BS_Steam_WriteMiniDumpEx(uStructuredExceptionCode%, pvExceptionInfo%, uBuildID%) : "BS_WriteMiniDump"
BS_Steam_RunCallbacks()
BS_Steam_RegisterCallback(pCallback%, iCallback%)
BS_Steam_UnregisterCallback(pCallback%)
BS_Steam_RegisterCallResult(pCallback%, hAPICall%)
BS_Steam_UnregisterCallResult(pCallback%, hAPICall%)

; AppList ---------------------------------------------------------------------
BS_AppList%()
BS_AppList_GetNumInstalledApps%(lpSteamAppList%)
BS_AppList_GetInstalledApps%(lpSteamAppList%, pvecAppID*, unMaxIDs%)
BS_AppList_GetInstalledAppsEx%(lpSteamAppList%, pvecAppID%, unMaxIDs%) : "BS_AppList_GetInstalledApps"
BS_AppList_GetAppName%(lpSteamAppList%, nAppId%, pchNameBuffer*, cchNameMax%)
BS_AppList_GetAppNameEx%(lpSteamAppList%, nAppId%, pchNameBuffer%, cchNameMax%) : "BS_AppList_GetAppName"
BS_AppList_GetAppInstallDir%(lpSteamAppList%, nAppId%, pchDirectoryBuffer*, cchDirectoryMax%)
BS_AppList_GetAppInstallDirEx%(lpSteamAppList%, nAppId%, pchDirectoryBuffer%, cchDirectoryMax%) : "BS_AppList_GetAppInstallDir"
BS_AppList_GetAppBuildId%(lpSteamAppList%, nAppId%)

; Apps ------------------------------------------------------------------------
BS_Apps%()
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
BS_Apps_GetDLCDataByIndex%(lpSteamApps%, iDLC%, pAppIdBuffer*, pbAvailableBuffer*, pchNameBuffer*, cchNameBufferSize%)
BS_Apps_GetDLCDataByIndexEx%(lpSteamApps%, iDLC%, pAppIdBuffer%, pbAvailableBuffer%, pchNameBuffer%, cchNameBufferSize%) : "BS_Apps_GetDLCDataByIndex"
BS_Apps_InstallDLC(lpSteamApps%, nAppID%)
BS_Apps_UninstallDLC(lpSteamApps%, nAppID%)
BS_Apps_RequestAppProofOfPurchaseKey(lpSteamApps%, nAppID%)
BS_Apps_GetCurrentBetaName%(lpSteamApps%, pchNameBuffer*, cchNameBufferSize%)
BS_Apps_GetCurrentBetaNameEx%(lpSteamApps%, pchNameBuffer%, cchNameBufferSize%) : "BS_Apps_GetCurrentBetaName"
BS_Apps_MarkContentCorrupt%(lpSteamApps%, bMissingFilesOnly%)
BS_Apps_GetInstalledDepots%(lpSteamApps%, nAppID%, pDepotsBuffer*, cMaxDepots%)
BS_Apps_GetInstalledDepotsEx%(lpSteamApps%, nAppID%, pDepotsBuffer%, cMaxDepots%) : "BS_Apps_GetInstalledDepots"
BS_Apps_GetAppInstallDir%(lpSteamApps%, nAppID%, pchFolderBuffer*, cchFolderBufferSize%)
BS_Apps_GetAppInstallDirEx%(lpSteamApps%, nAppID%, pchFolderBuffer%, cchFolderBufferSize%) : "BS_Apps_GetAppInstallDir"
BS_Apps_IsAppInstalled%(lpSteamApps%, nAppID%)
BS_Apps_GetAppOwner%(lpSteamApps%)
BS_Apps_GetLaunchQueryParam$(lpSteamApps%, pchKey$)
BS_Apps_GetDlcDownloadProgress%(lpSteamApps%, nAppID%, pLLBytesDownloaded*, pLLBytesTotal*)
BS_Apps_GetDlcDownloadProgressEx%(lpSteamApps%, nAppID%, pLLBytesDownloaded%, pLLBytesTotal%) : "BS_Apps_GetDlcDownloadProgress"
BS_Apps_GetAppBuildId%(lpSteamApps%)

; Client ----------------------------------------------------------------------
BS_Client%()
BS_Client_CreateSteamPipe%(lpSteamClient%)
BS_Client_ReleaseSteamPipe%(lpSteamClient%, hSteamPipe%)
BS_Client_ConnectToGlobalUser%(lpSteamClient%, hSteamPipe%)
BS_Client_SetLocalIPBinding(lpSteamClient, unIP%, usPort%)
BS_Client_CreateLocalUser%(lpSteamClient%, phSteamPipe%, eAccountType%)
BS_Client_ReleaseUser(lpSteamClient%, hSteamPipe%, hSteamUser%)
BS_Client_GetIPCCallCount%(lpSteamClient%)
BS_Client_ShutdownIfAllPipesClosed%(lpSteamClient%)
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
BS_Client_SetWarningMessageHook(lpSteamClient%, fpFunction%)

; Controller ------------------------------------------------------------------
BS_Controller%()
BS_Controller_Init%(lpSteamController%, pchAbsolutePathToControllerConfigVDF$)
BS_Controller_Shutdown%(lpSteamController%)
BS_Controller_RunFrame(lpSteamController%)
BS_Controller_GetConnectedControllers%(lpSteamController%, pHandlesOut*)
BS_Controller_GetConnectedControllersEx%(lpSteamController%, pHandlesOut%) : "BS_Controller_GetConnectedControllersEx"
BS_Controller_GetConnectedControllersSimple%(lpSteamController%)
BS_Controller_GetConnectedControllersSimple_Index%(index%)
BS_Controller_ShowBindingPanel%(lpSteamController%, pControllerHandle%)
BS_Controller_GetActionSetHandle%(lpSteamController%, pszActionSetName$)
;! Function above returns a ControllerActionSetHandle_t*, clean it up afterwards!
BS_Controller_ActivateActionSet(lpSteamController%, pControllerHandle%, pActionSetHandle%)
BS_Controller_GetCurrentActionSet%(lpSteamController%, )
;! Function above returns a ControllerActionSetHandle_t*, clean it up afterwards!
BS_Controller_GetDigitalActionHandle%(lpSteamController%, pszActionName$)
;! Function above returns a ControllerDigitalActionHandle_t*, clean it up afterwards!
BS_Controller_GetDigitalActionData%(lpSteamController%, pControllerHandle%, pDigitalActionHandle%)
;! Function above returns a ControllerDigitalActionData_t*, clean it up afterwards?
BS_Controller_GetDigitalActionOrigins%(lpSteamController%, pControllerHandle%, pActionSetHandle%, pDigitalActionHandle%, pEControllerActionOrigin*)
BS_Controller_GetDigitalActionOriginsEx%(lpSteamController%, pControllerHandle%, pActionSetHandle%, pDigitalActionHandle%, pEControllerActionOrigin%) : "BS_Controller_GetDigitalActionOrigins"
BS_Controller_GetAnalogActionHandle%(lpSteamController%, pszActionName$)
;! Function above returns a ControllerAnalogActionHandle_t*, clean it up afterwards!
BS_Controller_GetAnalogActionData%(lpSteamController%, pControllerHandle%, pAnalogActionHandle%)
;! Function above returns a ControllerAnalogActionData_t*, clean it up afterwards?
BS_Controller_GetAnalogActionOrigins%(lpSteamController%, pControllerHandle%, pActionSetHandle%, pAnalogActionHandle%, pEControllerActionOrigin*)
BS_Controller_GetAnalogActionOriginsEx%(lpSteamController%, pControllerHandle%, pActionSetHandle%, pAnalogActionHandle%, pEControllerActionOrigin*) : "BS_Controller_GetAnalogActionOrigins"
BS_Controller_StopAnalogActionMomentum(lpSteamController%, pControllerHandle%, pAnalogActionHandle%)
BS_Controller_TriggerHapticPulse(lpSteamController%, pControllerHandle%, ESteamControllerPad%, usDurationMicroSec%)
BS_Controller_TriggerRepeatedHapticPulse(lpSteamController%, pControllerHandle%, ESteamControllerPad%, usDurationMicroSec%, osOffMicroSec%, unRepeat%, nFlags%)

; Friends ---------------------------------------------------------------------
BS_Friends%()
BS_Friends_GetPersonaName$(lpSteamFriends%)
BS_Friends_SetPersonaName%(lpSteamFriends%, pchPersonaName$)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_Friends_GetPersonaState%(lpSteamFriends%)
BS_Friends_GetFriendCount%(lpSteamFriends%, iFriendFlags%)
BS_Friends_GetFriendByIndex%(lpSteamFriends%, iFriend%, iFriendFlags%)
;! Function above returns a CSteamID*, clean it up afterwards!
BS_Friends_GetFriendRelationship%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendPersonaState%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendPersonaName$(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendGamePlayed%(lpSteamFriends%, steamIDFriend%, pFriendGameInfo*)
BS_Friends_GetFriendGamePlayedEx%(lpSteamFriends%, steamIDFriend%, pFriendGameInfo%) : "BS_Friends_GetFriendGamePlayed"
BS_Friends_GetFriendPersonaNameHistory$(lpSteamFriends%, steamIDFriend%, iPersonaName%)
BS_Friends_GetFriendSteamLevel%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetPlayerNickname$(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendsGroupCount%(lpSteamFriends%)
BS_Friends_GetFriendsGroupIDByIndex%(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupName$(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupMembersCount%(lpSteamFriends%, friendsGroupID%)
BS_Friends_GetFriendsGroupMembersList(lpSteamFriends%, friendsGroupID%, pOutSteamIDMembers*, nMembersCount%)
BS_Friends_GetFriendsGroupMembersListEx(lpSteamFriends%, friendsGroupID%, pOutSteamIDMembers%, nMembersCount%) : "BS_Friends_GetFriendsGroupMembersList"
BS_Friends_HasFriend(lpSteamFriends%, steamIDFriend%, iFriendFlags%)
BS_Friends_GetClanCount%(lpSteamFriends%)
BS_Friends_GetClanByIndex%(lpSteamFriends%, iClan%)
BS_Friends_GetClanName$(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanTag$(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanActivityCounts%(lpSteamFriends%, steamIDClan%, pnOnline*, pnInGame*, pnChatting*)
BS_Friends_GetClanActivityCountsEx%(lpSteamFriends%, steamIDClan%, pnOnline%, pnInGame%, pnChatting%) : "BS_Friends_GetClanActivityCounts"
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
;! Function above returns a CSteamID*, clean it up afterwards!
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
;! Function above returns a CSteamID*, clean it up afterwards!
BS_Friends_GetFriendCoplayTime%(lpSteamFriends%, steamIDFriend%)
BS_Friends_GetFriendCoplayGame%(lpSteamFriends%, steamIDFriend%)
BS_Friends_JoinClanChatRoom%(lpSteamFriends%, steamIDClan%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_Friends_LeaveClanChatRoom%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetClanChatMemberCount%(lpSteamFriends%, steamIDClan%)
BS_Friends_GetChatMemberByIndex%(lpSteamFriends%, steamIDClan%, iUser%)
;! Function above returns a CSteamID*, clean it up afterwards!
BS_Friends_SendClanChatMessage%(lpSteamFriends%, steamIDClanChat%, pchText$)
BS_Friends_GetClanChatMessage%(lpSteamFriends%, steamIDClanChat%, iMessage%, prgchText*, cchTextMax%, peChatEntryType*, psteamidChatter*)
BS_Friends_GetClanChatMessageEx%(lpSteamFriends%, steamIDClanChat%, iMessage%, prgchText%, cchTextMax%, peChatEntryType%, psteamidChatter%) : "BS_Friends_GetClanChatMessage"
BS_Friends_IsClanChatAdmin%(lpSteamFriends%, steamIDClanChat%, steamIDUser%)
BS_Friends_IsClanChatWindowOpenInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_OpenClanChatWindowInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_CloseClanChatWindowInSteam%(lpSteamFriends%, steamIDClanChat%)
BS_Friends_SetListenForFriendsMessages%(lpSteamFriends%, bInterceptEnabled%)
BS_Friends_ReplyToFriendMessage%(lpSteamFriends%, steamIDFriend%, pchMsgToSend$)
BS_Friends_GetFriendMessage%(lpSteamFriends%, steamIDFriend%, iMessageID%, pvData*, cubData%, peChatEntryType*)
BS_Friends_GetFriendMessageEx%(lpSteamFriends%, steamIDFriend%, iMessageID%, pvData%, cubData%, peChatEntryType%) : "BS_Friends_GetFriendMessage"
BS_Friends_GetFollowerCount%(lpSteamFriends%, steamID%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_Friends_IsFollowing%(lpSteamFriends%, steamID%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_Friends_EnumerateFollowingList%(lpSteamFriends%, unStartIndex%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!

; GameServer ------------------------------------------------------------------
BS_SteamGameServer_Init%(unIP%, usSteamPort%, usGamePort%, usQueryPort%, eServerMode%, pchVersionString$)
BS_SteamGameServer_Shutdown()
BS_SteamGameServer_RunCallbacks()
BS_SteamGameServer_GetHSteamPipe%()
BS_SteamGameServer_IsSecure%()
BS_SteamGameServer_GetSteamID%()
;! Function above returns a CSteamID*, clean it up afterwards!
BS_GameServer%()
BS_GameServer_InitGameServer%(pSteamGameServer%, unIP%, usGamePort%, usQueryPort%, unFlags%, nGameAppId%, pchVersionString$)
BS_GameServer_SetProduct(pSteamGameServer%, pszProduct$)
BS_GameServer_SetGameDescription(pSteamGameServer%, pszGameDescription$)
BS_GameServer_SetModDir(pSteamGameServer%, pszModDir$)
BS_GameServer_SetDedicatedServer(pSteamGameServer%, bDedicated%)
BS_GameServer_LogOn(pSteamGameServer%, pszToken$)
BS_GameServer_LogOnAnonymous(pSteamGameServer%)
BS_GameServer_LogOff(pSteamGameServer%)
BS_GameServer_IsLoggedOn%(pSteamGameServer%)
BS_GameServer_IsSecure%(pSteamGameServer%)
BS_GameServer_GetSteamID%(pSteamGameServer%)
BS_GameServer_WasRestartRequested%(pSteamGameServer%)
BS_GameServer_SetMaxPlayerCount(pSteamGameServer%, cPlayersMax%)
BS_GameServer_SetBotPlayerCount(pSteamGameServer%, cBotPlayers%)
BS_GameServer_SetServerName(pSteamGameServer%, pszServerName$)
BS_GameServer_SetMapName(pSteamGameServer%, pszMapName$)
BS_GameServer_SetPasswordProtected(pSteamGameServer%, bPasswordProtected%)
BS_GameServer_SetSpectatorPort(pSteamGameServer%, unSpectatorPort%)
BS_GameServer_SetSpectatorServerName(pSteamGameServer%, pszSpectatorServerName$)
BS_GameServer_ClearAllKeyValues(pSteamGameServer%)
BS_GameServer_SetKeyValue(pSteamGameServer%, pKey$, pValue$)
BS_GameServer_SetGameTags(pSteamGameServer%, pchGameTags$)
BS_GameServer_SetGameData(pSteamGameServer%, pchGameData$)
BS_GameServer_SetRegion(pSteamGameServer%, pszRegion$)
BS_GameServer_SendUserConnectAndAuthenticate%(pSteamGameServer%, unIPClient%, pvAuthBlob*, cubAuthBlobSize%, pSteamIDUser%)
BS_GameServer_SendUserConnectAndAuthenticateEx%(pSteamGameServer%, unIPClient%, pvAuthBlob%, cubAuthBlobSize%, pSteamIDUser%) : "BS_GameServer_SendUserConnectAndAuthenticate"
BS_GameServer_CreateUnauthenticatedUserConnection%(pSteamGameServer%)
;! Function above returns a CSteamID*, clean it up afterwards!
BS_GameServer_SendUserDisconnect(pSteamGameServer%, pSteamIDUser%)
BS_GameServer_UpdateUserData%(pSteamGameServer%, pSteamIDUser%, pchPlayerName$, uScore%)
BS_GameServer_GetAuthSessionTicket%(pSteamGameServer%, pTicket*, cbMaxTicket%, pcbTicket%)
BS_GameServer_GetAuthSessionTicketEx%(pSteamGameServer%, pTicket%, cbMaxTicket%, pcbTicket%) : "BS_GameServer_GetAuthSessionTicket"
BS_GameServer_BeginAuthSession%(pSteamGameServer%, pAuthTicker*, cbAuthTicket%, pSteamID%)
BS_GameServer_BeginAuthSessionEx%(pSteamGameServer%, pAuthTicker%, cbAuthTicket%, pSteamID%) : "BS_GameServer_BeginAuthSession"
BS_GameServer_EndAuthSession(pSteamGameServer%, pSteamID%)
BS_GameServer_CancelAuthTicket(pSteamGameServer%, hAuthTicket%)
BS_GameServer_UserHasLicenseForApp%(pSteamGameServer%, pSteamID%, appID%)
BS_GameServer_RequestUserGroupStatus%(pSteamGameServer%, pSteamIDUser%, pSteamIDGroup%)
BS_GameServer_GetGameplayStats(pSteamGameServer%)
BS_GameServer_GetServerReputation%(pSteamGameServer%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_GameServer_GetPublicIP%(pSteamGameServer%)
BS_GameServer_HandleIncomingPacket%(pSteamGameServer%, pData*, cbData%, srvIP%, srvPort%)
BS_GameServer_HandleIncomingPacketEx%(pSteamGameServer%, pData%, cbData%, srvIP%, srvPort%) : "BS_GameServer_HandleIncomingPacket"
BS_GameServer_GetNextOutgoingPacket%(pSteamGameServer%, pOut*, cbMaxOut%, pNetAdr*, pPort*)
BS_GameServer_GetNextOutgoingPacketEx%(pSteamGameServer%, pOut%, cbMaxOut%, pNetAdr%, pPort%) : "BS_GameServer_GetNextOutgoingPacket"
BS_GameServer_EnableHeartbeats(pSteamGameServer%, bActive%)
BS_GameServer_SetHeartbeatInterval(pSteamGameServer%, iHeartbeatInterval%)
BS_GameServer_ForceHeartbeat(pSteamGameServer%)
BS_GameServer_AssociateWithClan%(pSteamGameServer%, pSteamIDClan%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_GameServer_ComputeNewPlayerCompatibility%(pSteamGameServer%, pSteamIDNewPlayer%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!

; GameServerStats -------------------------------------------------------------
BS_GameServerStats%()
BS_GameServerStats_RequestUserStats%(pSteamGameServerStats%, steamIDUser%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_GameServerStats_StoreUserStats%(pSteamGameServerStats%, steamIDUser%)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_GameServerStats_GetUserStat%(pSteamGameServerStats%, steamIDUser%, pchName$, pData*)
BS_GameServerStats_GetUserStatEx%(pSteamGameServerStats%, steamIDUser%, pchName$, pData%) : "BS_GameServerStats_GetUserStat"
BS_GameServerStats_GetUserStatF%(pSteamGameServerStats%, steamIDUser%, pchName$, pData*)
BS_GameServerStats_GetUserStatFEx%(pSteamGameServerStats%, steamIDUser%, pchName$, pData%) : "BS_GameServerStats_GetUserStatF"
BS_GameServerStats_GetUserAchievement%(pSteamGameServerStats%, steamIDUser%, pchName$, pbAchieved*)
BS_GameServerStats_GetUserAchievementEx%(pSteamGameServerStats%, steamIDUser%, pchName$, pbAchieved%) : "BS_GameServerStats_GetUserAchievement"
BS_GameServerStats_SetUserStat%(pSteamGameServerStats%, steamIDUser%, pchName%, nData%)
BS_GameServerStats_SetUserStatF%(pSteamGameServerStats%, steamIDUser%, pchName%, fData#)
BS_GameServerStats_UpdateUserAvgRateStat%(pSteamGameServerStats%, steamIDUser%, pchName$, flCountThisSession#, pdSessionLength%)
;! Function above takes a Double* as last parameter.
BS_GameServerStats_SetUserAchievement%(pSteamGameServerStats%, steamIDUser%, pchName$)
BS_GameServerStats_ClearUserAchievement%(pSteamGameServerStats%, steamIDUser%, pchName$)

; HTMLSurface -----------------------------------------------------------------
BS_HTMLSurface%()
BS_HTMLSurface_Init%(pSteamHTMLSurface%)
BS_HTMLSurface_Shutdown%(pSteamHTMLSurface%)
BS_HTMLSurface_CreateBrowser%(pSteamHTMLSurface%, pchUserAgent$, pchUserCSS$)
;! Function above returns a SteamAPICall_t*, clean it up afterwards!
BS_HTMLSurface_RemoveBrowser(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_LoadURL(pSteamHTMLSurface%, unBrowserHandle%, pchURL$, pchPostData$)
BS_HTMLSurface_SetSize(pSteamHTMLSurface%, unBrowserHandle%, unWidth%, unHeight%)
BS_HTMLSurface_StopLoad(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_Reload(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_GoBack(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_GoForward(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_AddHeader(pSteamHTMLSurface%, unBrowserHandle%, pchKey$, pchValue$)
BS_HTMLSurface_ExecuteJavascript(pSteamHTMLSurface%, unBrowserHandle%, pchScript$)
BS_HTMLSurface_MouseUp(pSteamHTMLSurface%, unBrowserHandle%, EMouseButton%)
BS_HTMLSurface_MouseDown(pSteamHTMLSurface%, unBrowserHandle%, EMouseButton%)
BS_HTMLSurface_MouseDoubleClick(pSteamHTMLSurface%, unBrowserHandle%, EMouseButton%)
BS_HTMLSurface_MouseMove(pSteamHTMLSurface%, unBrowserHandle%, X%, Y%)
BS_HTMLSurface_MouseWheel(pSteamHTMLSurface%, unBrowserHandle%, nDelta%)
BS_HTMLSurface_KeyDown(pSteamHTMLSurface%, unBrowserHandle%, nNativeKeyCode%, EHTMLKeyModifiers%)
BS_HTMLSurface_KeyUp(pSteamHTMLSurface%, unBrowserHandle%, nNativeKeyCode%, EHTMLKeyModifiers%)
BS_HTMLSurface_KeyChar(pSteamHTMLSurface%, unBrowserHandle%, cUnicodeChar%, EHTMLKeyModifiers%)
BS_HTMLSurface_SetHorizontalScroll(pSteamHTMLSurface%, unBrowserHandle%, nAbsolutePixelScroll%)
BS_HTMLSurface_SetVerticalScroll(pSteamHTMLSurface%, unBrowserHandle%, nAbsolutePixelScroll%)
BS_HTMLSurface_SetKeyFocus(pSteamHTMLSurface%, unBrowserHandle%, bHasKeyFocus%)
BS_HTMLSurface_ViewSource(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_CopyToClipboard(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_PasteFromClipboard(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_Find(pSteamHTMLSurface%, unBrowserHandle%, pchSearchStr$, bCurrentlyInFind%, bReverse%)
BS_HTMLSurface_StopFind(pSteamHTMLSurface%, unBrowserHandle%)
BS_HTMLSurface_GetLinkAtPosition(pSteamHTMLSurface%, unBrowserHandle%, X%, Y%)
BS_HTMLSurface_SetCookie(pSteamHTMLSurface%, unBrowserHandle%, pchHostname$, pchKey$, pchValue$, pchPath$, nExpires%, bSecure%, bHTTPOnly%)
BS_HTMLSurface_SetPageScaleFactor(pSteamHTMLSurface%, unBrowserHandle%, flZoom#, nPointX%, nPointY%)
BS_HTMLSurface_SetBackgroundMode(pSteamHTMLSurface%, unBrowserHandle%, bBackgroundMode%)
BS_HTMLSurface_AllowStartRequest(pSteamHTMLSurface%, unBrowserHandle%, bAllowed%)
BS_HTMLSurface_JSDialogResponse(pSteamHTMLSurface%, unBrowserHandle%, bResult%)
BS_HTMLSurface_FileLoadDialogResponse(pSteamHTMLSurface%, unBrowserHandle%, pchSelectedFiles%)

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
BS_Helper_DeleteLong(longlong%)
BS_Helper_CreateDouble%(value#)
BS_Helper_DeleteDouble(pDouble%)
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
; -- Callbacks
BS_Callback_Create%(pFunctionPointer%)
BS_Callback_Destroy%(pCallback%)
BS_Callback_IsRegistered%(pCallback%)
BS_Callback_IsGameServer%(pCallback%)
BS_Callback_SetGameServerFlag%(pCallback%, bIsGameServer%)
BS_Callback_Register(pCallback%, iCallback%)
BS_Callback_Unregister(pCallback%)
BS_Callback_RegisterResult(pCallback%, pSteamAPICall%)
BS_Callback_UnregisterResult(pCallback%)
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