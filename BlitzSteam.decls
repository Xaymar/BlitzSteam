.lib "BlitzSteam.dll"
; Steam -------------------------------------------------------------------------
BlitzSteam_Init%()
BlitzSteam_Shutdown()
BlitzSteam_IsSteamRunning%()
BlitzSteam_RestartAppIfNecessary%(unOwnAppID%)
BlitzSteam_SetMiniDumpComment(pchMsg$)
BlitzSteam_WriteMiniDump(uStructuredExceptionCode%, pvExceptionInfo%, uBuildID%)
BlitzSteam_WriteMiniDumpBank(uStructuredExceptionCode%, pvExceptionInfo*, uBuildID%) : "BlitzSteam_WriteMiniDump"
; -- Callbacks & Hooks
BlitzSteam_RunCallbacks()
BlitzSteam_RegisterCallback(pCallback%, iCallback%)
BlitzSteam_UnregisterCallback(pCallback%)
BlitzSteam_RegisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)
BlitzSteam_UnregisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)
; -- Interfaces
BlitzSteamClient%()
BlitzSteamUser%()
BlitzSteamFriends%()
BlitzSteamUtils%()
BlitzSteamMatchmaking%()
BlitzSteamUserStats%()
BlitzSteamApps%()
BlitzSteamNetworking%()
BlitzSteamMatchmakingServers%()
BlitzSteamRemoteStorage%()
BlitzSteamScreenshots%()
BlitzSteamHTTP%()
BlitzSteamUnifiedMessages%()
BlitzSteamController%()
BlitzSteamUGC%()
BlitzSteamAppList%()
BlitzSteamMusic%()
BlitzSteamMusicRemote%()
BlitzSteamHTMLSurface%()
BlitzSteamInventory%()
BlitzSteamVideo%()

; SteamAppList ------------------------------------------------------------------
BlitzSteamAppList_GetNumInstalledApps%(lpSteamAppList%)
BlitzSteamAppList_GetInstalledApps%(lpSteamAppList%, pvecAppID%, unMaxIDs%)
BlitzSteamAppList_GetInstalledAppsBank%(lpSteamAppList%, pvecAppID*, unMaxIDs%) : "BlitzSteamAppList_GetInstalledApps"
BlitzSteamAppList_GetAppName%(lpSteamAppList%, nAppId%, pchName%, cchNameMax%)
BlitzSteamAppList_GetAppNameBank%(lpSteamAppList%, nAppId%, pchName*, cchNameMax%) : "BlitzSteamAppList_GetAppName"
BlitzSteamAppList_GetAppInstallDir%(lpSteamAppList%, nAppId%, pchDirectory%, cchDirectoryMax%)
BlitzSteamAppList_GetAppInstallDirBank%(lpSteamAppList%, nAppId%, pchDirectory*, cchDirectoryMax%) : "BlitzSteamAppList_GetAppInstallDir"
BlitzSteamAppList_GetAppBuildId%(lpSteamAppList%, nAppId%)

; SteamApps ---------------------------------------------------------------------
BlitzSteamApps_IsSubscribed%(lpSteamApps%)
BlitzSteamApps_IsLowViolence%(lpSteamApps%)
BlitzSteamApps_IsCybercafe%(lpSteamApps%)
BlitzSteamApps_IsVACBanned%(lpSteamApps%)
BlitzSteamApps_GetCurrentGameLanguage$(lpSteamApps%)
BlitzSteamApps_GetAvailableGameLanguages$(lpSteamApps%)
BlitzSteamApps_IsSubscribedApp%(lpSteamApps%, appID%)
BlitzSteamApps_IsDlcInstalled%(lpSteamApps%, appID%)
BlitzSteamApps_GetEarliestPurchaseUnixTime%(lpSteamApps%, appID%)
BlitzSteamApps_IsSubscribedFromFreeWeekend%(lpSteamApps%)
BlitzSteamApps_GetDLCDataByIndexEx%(lpSteamApps%, iDLC%, pAppId%, pbAvailable%, pchName%, cchNameBufferSize%) : "BlitzSteamApps_GetDLCDataByIndex"
BlitzSteamApps_GetDLCDataByIndex%(lpSteamApps%, iDLC%, pAppId%, pbAvailable*, pchName*, cchNameBufferSize%)
BlitzSteamApps_InstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_UninstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_RequestAppProofOfPurchaseKey(lpSteamApps%, nAppID%)
BlitzSteamApps_GetCurrentBetaNameEx%(lpSteamApps%, pchName%, cchNameBufferSize%) : "BlitzSteamApps_GetCurrentBetaName"
BlitzSteamApps_GetCurrentBetaName%(lpSteamApps%, pchName*, cchNameBufferSize%)
BlitzSteamApps_MarkContentCorrupt%(lpSteamApps%, bMissingFilesOnly%)
BlitzSteamApps_GetInstalledDepotsEx%(lpSteamApps%, nAppID%, pvecDepots%, cMaxDepots%) : "BlitzSteamApps_GetInstalledDepots"
BlitzSteamApps_GetInstalledDepots%(lpSteamApps%, nAppID%, pvecDepots%, cMaxDepots%)
BlitzSteamApps_GetAppOwner%(lpSteamApps%)
BlitzSteamApps_GetLaunchQueryParam$(lpSteamApps%, pchKey$)
BlitzSteamApps_GetDlcDownloadProgress%(lpSteamApps%, nAppID%, pOutputBank*)
BlitzSteamApps_GetAppBuildId%(lpSteamApps%)

; SteamController ---------------------------------------------------------------
