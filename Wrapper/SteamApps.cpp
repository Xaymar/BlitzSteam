//	BlitzSteam - Steam wrapper for Blitz
//	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as
//	published by the Free Software Foundation, either version 3 of the 
//	License, or (at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "BlitzSteam.h"

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
DLL_FUNCTION(ISteamApps*) BS_SteamApps() {
	return SteamApps();
}

DLL_FUNCTION(int32_t) BS_ISteamApps_IsSubscribed(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribed();
}

DLL_FUNCTION(int32_t) BS_ISteamApps_IsLowViolence(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsLowViolence();
}

DLL_FUNCTION(int32_t) BS_ISteamApps_IsCybercafe(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsCybercafe();
}

DLL_FUNCTION(int32_t) BS_ISteamApps_IsVACBanned(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsVACBanned();
}

DLL_FUNCTION(const char*) BS_ISteamApps_GetCurrentGameLanguage(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetCurrentGameLanguage();
}

DLL_FUNCTION(const char*) BS_ISteamApps_GetAvailableGameLanguages(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAvailableGameLanguages();
}

// only use this member if you need to check ownership of another game related to yours, a demo for example
DLL_FUNCTION(int32_t) BS_ISteamApps_IsSubscribedApp(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsSubscribedApp(appID);
}

// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
DLL_FUNCTION(int32_t) BS_ISteamApps_IsDlcInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsDlcInstalled(appID);
}

// returns the Unix time of the purchase of the app
DLL_FUNCTION(int32_t) BS_ISteamApps_GetEarliestPurchaseUnixTime(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->GetEarliestPurchaseUnixTime(appID);
}

// Checks if the user is subscribed to the current app through a free weekend
// This function will return false for users who have a retail or other type of license
// Before using, please ask your Valve technical contact how to package and secure your free weekened
DLL_FUNCTION(int32_t) BS_ISteamApps_IsSubscribedFromFreeWeekend(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribedFromFreeWeekend();
}

// Returns the number of DLC pieces for the running app
DLL_FUNCTION(int32_t) BS_ISteamApps_GetDLCCount(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetDLCCount();
}

// Returns metadata for DLC by index, of range [0, GetDLCCount()]
DLL_FUNCTION(int32_t) BS_ISteamApps_GetDLCDataByIndex(ISteamApps* lpSteamApps, uint32_t iDLC, AppId_t *pAppIdBuffer, bool* pbAvailableBuffer, char *pchNameBuffer, uint32_t cchNameBufferSize) {
	return lpSteamApps->BGetDLCDataByIndex(iDLC, pAppIdBuffer, (bool*)pbAvailableBuffer, pchNameBuffer, cchNameBufferSize);
}

// Install/Uninstall control for optional DLC
DLL_FUNCTION(void) BS_ISteamApps_InstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->InstallDLC(nAppID);
}

DLL_FUNCTION(void) BS_ISteamApps_UninstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->UninstallDLC(nAppID);
}

// Request cd-key for yourself or owned DLC. If you are interested in this
// data then make sure you provide us with a list of valid keys to be distributed
// to users when they purchase the game, before the game ships.
// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
// the key is available (which may be immediately).
DLL_FUNCTION(void) BS_ISteamApps_RequestAppProofOfPurchaseKey(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->RequestAppProofOfPurchaseKey(nAppID);
}

// returns current beta branch name, 'public' is the default branch
DLL_FUNCTION(int32_t) BS_ISteamApps_GetCurrentBetaName(ISteamApps* lpSteamApps, char* pchNameBuffer, int cchNameBufferSize) {
	return lpSteamApps->GetCurrentBetaName(pchNameBuffer, cchNameBufferSize);
}

// signal Steam that game files seems corrupt or missing
DLL_FUNCTION(int32_t) BS_ISteamApps_MarkContentCorrupt(ISteamApps* lpSteamApps, uint32_t bMissingFilesOnly) {
	return lpSteamApps->MarkContentCorrupt(bMissingFilesOnly != 0);
}

// return installed depots in mount order
DLL_FUNCTION(int32_t) BS_ISteamApps_GetInstalledDepots(ISteamApps* lpSteamApps, AppId_t nAppID, DepotId_t *pDepotsBuffer, uint32_t cMaxDepots) {
	return lpSteamApps->GetInstalledDepots(nAppID, pDepotsBuffer, cMaxDepots);
}

// returns current app install folder for AppID, returns folder name length
DLL_FUNCTION(int32_t) BS_ISteamApps_GetAppInstallDir(ISteamApps* lpSteamApps, AppId_t appID, char *pchFolderBuffer, uint32_t cchFolderBufferSize) {
	return lpSteamApps->GetAppInstallDir(appID, pchFolderBuffer, cchFolderBufferSize);
}

// returns true if that app is installed (not necessarily owned)
DLL_FUNCTION(int32_t) BS_ISteamApps_IsAppInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsAppInstalled(appID);
}

// returns the SteamID of the original owner. If different from current user, it's borrowed
DLL_FUNCTION(CSteamID*) BS_ISteamApps_GetAppOwner(ISteamApps* lpSteamApps) {
	return new CSteamID(lpSteamApps->GetAppOwner());
}

// Returns the associated launch param if the game is run via steam://run/<appid>//?param1=value1;param2=value2;param3=value3 etc.
// Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
// Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
// but it is advised that you not param names beginning with an underscore for your own features.
DLL_FUNCTION(const char*) BS_ISteamApps_GetLaunchQueryParam(ISteamApps* lpSteamApps, const char *pchKey) {
	return lpSteamApps->GetLaunchQueryParam(pchKey);
}

// get download progress for optional DLC
DLL_FUNCTION(int32_t) BS_ISteamApps_GetDlcDownloadProgress(ISteamApps* lpSteamApps, AppId_t nAppID, uint64_t* pLLBytesDownloaded, uint64_t* pLLBytesTotal) {
	return lpSteamApps->GetDlcDownloadProgress(nAppID, pLLBytesDownloaded, pLLBytesTotal);
}

// return the buildid of this app, may change at any time based on backend updates to the game
DLL_FUNCTION(int32_t) BS_ISteamApps_GetAppBuildId(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAppBuildId();
}
