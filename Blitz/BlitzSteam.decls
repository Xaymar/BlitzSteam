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
; Helpers -----------------------------------------------------------------------
; -- Int64
BlitzSteamInt64_New%()
BlitzSteamInt64_Copy%(other%)
BlitzSteamInt64_Destroy(this%)
BlitzSteamInt64_SetP(this%, other%)
BlitzSteamInt64_SetV(this%, left%, right%)
BlitzSteamInt64_AddP(this%, other%)
BlitzSteamInt64_AddV(this%, left%, right%)
BlitzSteamInt64_SubP(this%, other%)
BlitzSteamInt64_SubV(this%, left%, right%)
BlitzSteamInt64_MulP(this%, other%)
BlitzSteamInt64_MulV(this%, left%, right%)
BlitzSteamInt64_DivP(this%, other%)
BlitzSteamInt64_DivV(this%, left%, right%)
BlitzSteamInt64_EqualsP%(this%, other%)
BlitzSteamInt64_EqualsV%(this%, left%, right%)
BlitzSteamInt64_GreaterP%(this%, other%)
BlitzSteamInt64_GreaterV%(this%, left%, right%)
BlitzSteamInt64_GEqualsP%(this%, other%)
BlitzSteamInt64_GEqualsV%(this%, left%, right%)
BlitzSteamInt64_SmallerP%(this%, other%)
BlitzSteamInt64_SmallerV%(this%, left%, right%)
BlitzSteamInt64_SEqualsP%(this%, other%)
BlitzSteamInt64_SEqualsV%(this%, left%, right%)
BlitzSteamInt64_ToString$(this%)
BlitzSteamInt64_ValueL%(this%)
BlitzSteamInt64_ValueR%(this%)
BlitzSteamInt64_FromFloat%(value#)
BlitzSteamInt64_ToFloat#(this%)
BlitzSteamInt64_ToDouble%(this%)
; -- Double
BlitzSteamDouble_New%()
BlitzSteamDouble_Copy%(other%)
BlitzSteamDouble_Destroy(this%)
BlitzSteamDouble_SetP(this%, other%)
BlitzSteamDouble_SetV(this%, left%, right%)
BlitzSteamDouble_AddP(this%, other%)
BlitzSteamDouble_AddV(this%, left%, right%)
BlitzSteamDouble_SubP(this%, other%)
BlitzSteamDouble_SubV(this%, left%, right%)
BlitzSteamDouble_MulP(this%, other%)
BlitzSteamDouble_MulV(this%, left%, right%)
BlitzSteamDouble_DivP(this%, other%)
BlitzSteamDouble_DivV(this%, left%, right%)
BlitzSteamDouble_EqualsP%(this%, other%)
BlitzSteamDouble_EqualsV%(this%, left%, right%)
BlitzSteamDouble_GreaterP%(this%, other%)
BlitzSteamDouble_GreaterV%(this%, left%, right%)
BlitzSteamDouble_GEqualsP%(this%, other%)
BlitzSteamDouble_GEqualsV%(this%, left%, right%)
BlitzSteamDouble_SmallerP%(this%, other%)
BlitzSteamDouble_SmallerV%(this%, left%, right%)
BlitzSteamDouble_SEqualsP%(this%, other%)
BlitzSteamDouble_SEqualsV%(this%, left%, right%)
BlitzSteamDouble_ToString$(this%)
BlitzSteamDouble_ToFloat#(this%)
BlitzSteamDouble_FromFloat%(value#)
BlitzSteamDouble_ToInt32%(this%)
BlitzSteamDouble_FromInt32%(value%)
BlitzSteamDouble_ToInt64%(this%)

; Steam -------------------------------------------------------------------------
BlitzSteam_Init%()
BlitzSteam_Shutdown()
BlitzSteam_IsSteamRunning%()
BlitzSteam_RestartAppIfNecessary%(unOwnAppID%)
BlitzSteam_SetMiniDumpComment(pchMsg$)
BlitzSteam_WriteMiniDumpEx(uStructuredExceptionCode%, pvExceptionInfo%, uBuildID%) : "BlitzSteam_WriteMiniDump"
BlitzSteam_WriteMiniDump(uStructuredExceptionCode%, pvExceptionInfo*, uBuildID%)
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
BlitzSteamAppList_GetInstalledApps%(lpSteamAppList%, pvecAppID*, unMaxIDs%)
BlitzSteamAppList_GetAppNameEx%(lpSteamAppList%, nAppId%, pchName%, cchNameMax%) : "BlitzSteamAppList_GetAppName"
BlitzSteamAppList_GetAppName%(lpSteamAppList%, nAppId%, pchName*, cchNameMax%)
BlitzSteamAppList_GetAppInstallDirEx%(lpSteamAppList%, nAppId%, pchDirectory%, cchDirectoryMax%) : "BlitzSteamAppList_GetAppInstallDir"
BlitzSteamAppList_GetAppInstallDir%(lpSteamAppList%, nAppId%, pchDirectory*, cchDirectoryMax%)
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
BlitzSteamApps_GetDLCDataByIndex%(lpSteamApps%, iDLC%, pAppId*, pbAvailable*, pchName*, cchNameBufferSize%)
BlitzSteamApps_InstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_UninstallDLC(lpSteamApps%, nAppID%)
BlitzSteamApps_RequestAppProofOfPurchaseKey(lpSteamApps%, nAppID%)
BlitzSteamApps_GetCurrentBetaNameEx%(lpSteamApps%, pchName%, cchNameBufferSize%) : "BlitzSteamApps_GetCurrentBetaName"
BlitzSteamApps_GetCurrentBetaName%(lpSteamApps%, pchName*, cchNameBufferSize%)
BlitzSteamApps_MarkContentCorrupt%(lpSteamApps%, bMissingFilesOnly%)
BlitzSteamApps_GetInstalledDepotsEx%(lpSteamApps%, nAppID%, pvecDepots%, cMaxDepots%) : "BlitzSteamApps_GetInstalledDepots"
BlitzSteamApps_GetInstalledDepots%(lpSteamApps%, nAppID%, pvecDepots*, cMaxDepots%)
BlitzSteamApps_GetAppInstallDirEx%(lpSteamApps%, nAppID%, pchFolder%, cchFolderBufferSize%) : "BlitzSteamApps_GetAppInstallDir"
BlitzSteamApps_GetAppInstallDir%(lpSteamApps%, nAppID%, pchFolder*, cchFolderBufferSize%)
BlitzSteamApps_IsAppInstalled%(lpSteamApps%, nAppID%)
BlitzSteamApps_GetAppOwner%(lpSteamApps%)
BlitzSteamApps_GetLaunchQueryParam$(lpSteamApps%, pchKey$)
BlitzSteamApps_GetDlcDownloadProgressEx%(lpSteamApps%, nAppID%, punBytesDownloaded%, punBytesTotal%) : "BlitzSteamApps_GetDlcDownloadProgress"
BlitzSteamApps_GetDlcDownloadProgress%(lpSteamApps%, nAppID%, punBytesDownloaded*, punBytesTotal*)
BlitzSteamApps_GetAppBuildId%(lpSteamApps%)

; SteamClient -------------------------------------------------------------------
BlitzSteamClient_CreateSteamPipe%(lpSteamClient%)
BlitzSteamClient_ReleaseSteamPipe%(lpSteamClient%, hSteamPipe%)
BlitzSteamClient_ConnectToGlobalUser%(lpSteamClient%, hSteamPipe%)
BlitzSteamClient_SetLocalIPBinding(lpSteamClient, unIP%, usPort%)
BlitzSteamClient_CreateLocalUserEx%(lpSteamClient%, phSteamPipe*, eAccountType%) : "BlitzSteamClient_CreateLocalUser"
BlitzSteamClient_CreateLocalUser%(lpSteamClient%, phSteamPipe*, eAccountType%)
BlitzSteamClient_ReleaseUser(lpSteamClient%, hSteamPipe%, hSteamUser%)
BlitzSteamClient_RunFrame(lpSteamClient%)
BlitzSteamClient_GetIPCCallCount%(lpSteamClient%)
BlitzSteamClient_ShutdownIfAllPipesClosed%(lpSteamClient%)
; -- Interfaces
BlitzSteamClient_GetSteamAppList%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamApps%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamController%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamFriends%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamGameServer%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamGameServerStats%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamHTMLSurface%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamHTTP%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamInventory%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamMatchmaking%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamMatchmakingServers%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamMusic%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamMusicRemote%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamNetworking%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamRemoteStorage%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamScreenshots%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamUGC%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamUnifiedMessages%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamUser%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamUserStats%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamUtils%(lpSteamClient%, hSteamPipe%, pchVersion$)
BlitzSteamClient_GetSteamVideo%(lpSteamClient%, hSteamUser%, hSteamPipe%, pchVersion$)
; -- Callbacks & Hooks
BlitzSteamClient_SetWarningMessageHook(lpSteamClient%, fpFunction%)
BlitzSteamClient_Set_SteamAPI_CPostAPIResultInProcess(lpSteamClient%, fpFunction%)
BlitzSteamClient_Remove_SteamAPI_CPostAPIResultInProcess(lpSteamClient%, fpFunction%)
BlitzSteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(lpSteamClient%, fpFunction%)

; SteamController ---------------------------------------------------------------
BlitzSteamController_Init%(lpSteamController%, pchAbsolutePathToControllerConfigVDF$)
BlitzSteamController_Shutdown%(lpSteamController%)
BlitzSteamController_RunFrame(lpSteamController%)
BlitzSteamController_GetControllerStateEx%(lpSteamController%, unControllerIndex%, pState%) : "BlitzSteamController_GetControllerState"
BlitzSteamController_GetControllerState%(lpSteamController%, unControllerIndex%, pState*)
BlitzSteamController_TriggerHapticPulse(lpSteamController%, unControllerIndex%, eTargetPad%, usDurationMicroSec%)
BlitzSteamController_SetOverrideMode(lpSteamController%, pchMode$)