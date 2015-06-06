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

.lib "BlitzSteam.dll"
; Steam -------------------------------------------------------------------------
BlitzSteam_Init%()
BlitzSteam_Shutdown()
BlitzSteam_IsSteamRunning%()
BlitzSteam_RestartAppIfNecessary%(unOwnAppID%)
BlitzSteam_SetMiniDumpComment(pchMsg$)
BlitzSteam_WriteMiniDump(uStructuredExceptionCode%, pvExceptionInfo%, uBuildID%)
BlitzSteam_WriteMiniDumpBank(uStructuredExceptionCode%, pvExceptionInfo*, uBuildID%) : "BlitzSteam_WriteMiniDump"
; -- Interfaces
BlitzSteamAppList%()
BlitzSteamApps%()
BlitzSteamClient%()
BlitzSteamController%()
BlitzSteamFriends%()
BlitzSteamHTTP%()
BlitzSteamHTMLSurface%()
BlitzSteamInventory%()
BlitzSteamMatchmaking%()
BlitzSteamMatchmakingServers%()
BlitzSteamMusic%()
BlitzSteamMusicRemote%()
BlitzSteamNetworking%()
BlitzSteamRemoteStorage%()
BlitzSteamScreenshots%()
BlitzSteamUGC%()
BlitzSteamUnifiedMessages%()
BlitzSteamUser%()
BlitzSteamUserStats%()
BlitzSteamUtils%()
BlitzSteamVideo%()
; -- Callbacks & Hooks
BlitzSteam_RunCallbacks()
BlitzSteam_RegisterCallback(pCallback%, iCallback%)
BlitzSteam_UnregisterCallback(pCallback%)
BlitzSteam_RegisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)
BlitzSteam_UnregisterCallResult(pCallback%, hAPICall_L%, hAPICall_R%)

; SteamAppList ------------------------------------------------------------------
BlitzSteamAppList_GetNumInstalledApps%(lpSteamAppList%)
BlitzSteamAppList_GetInstalledAppsEx%(lpSteamAppList%, pvecAppID%, unMaxIDs%) : "BlitzSteamAppList_GetInstalledApps"
BlitzSteamAppList_GetInstalledApps%(lpSteamAppList%, pvecAppIDBank*, unMaxIDs%)
BlitzSteamAppList_GetAppNameEx%(lpSteamAppList%, nAppId%, pchName%, cchNameMax%) : "BlitzSteamAppList_GetAppName"
BlitzSteamAppList_GetAppName%(lpSteamAppList%, nAppId%, pchNameBank*, cchNameMax%)
BlitzSteamAppList_GetAppInstallDirEx%(lpSteamAppList%, nAppId%, pchDirectory%, cchDirectoryMax%) : "BlitzSteamAppList_GetAppInstallDir"
BlitzSteamAppList_GetAppInstallDir%(lpSteamAppList%, nAppId%, pchDirectoryBank*, cchDirectoryMax%)
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
BlitzSteamApps_GetDLCCount%(lpSteamApps%)
BlitzSteamApps_GetDLCDataByIndexEx%(lpSteamApps%, iDLC%, pAppId%, pbAvailable%, pchName%, cchNameBufferSize%) : "BlitzSteamApps_GetDLCDataByIndex"
BlitzSteamApps_GetDLCDataByIndex%(lpSteamApps%, iDLC%, pAppIdBank*, pbAvailableBank*, pchNameBank*, cchNameBufferSize%)
BlitzSteamApps_InstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_UninstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_RequestAppProofOfPurchaseKey(lpSteamApps%, nAppID%)
BlitzSteamApps_GetCurrentBetaNameEx%(lpSteamApps%, pchName%, cchNameBufferSize%) : "BlitzSteamApps_GetCurrentBetaName"
BlitzSteamApps_GetCurrentBetaName%(lpSteamApps%, pchNameBank*, cchNameBufferSize%)
BlitzSteamApps_MarkContentCorrupt%(lpSteamApps%, bMissingFilesOnly%)
BlitzSteamApps_GetInstalledDepotsEx%(lpSteamApps%, nAppID%, pvecDepots%, cMaxDepots%) : "BlitzSteamApps_GetInstalledDepots"
BlitzSteamApps_GetInstalledDepots%(lpSteamApps%, nAppID%, pvecDepotsBank*, cMaxDepots%)
BlitzSteamApps_GetAppInstallDirEx%(lpSteamApps%, nAppID%, pchFolder%, cchFolderBufferSize%) : "BlitzSteamApps_GetAppInstallDir"
BlitzSteamApps_GetAppInstallDir%(lpSteamApps%, nAppID%, pchFolderBank*, cchFolderBufferSize%)
BlitzSteamApps_IsAppInstalled%(lpSteamApps%, nAppID%)
BlitzSteamApps_GetAppOwner%(lpSteamApps%)
BlitzSteamApps_GetLaunchQueryParam$(lpSteamApps%, pchKey$)
BlitzSteamApps_GetDlcDownloadProgress%(lpSteamApps%, nAppID%, pOutputBank*)
BlitzSteamApps_GetAppBuildId%(lpSteamApps%)

; SteamController ---------------------------------------------------------------
