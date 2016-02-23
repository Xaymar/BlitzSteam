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

DLL_FUNCTION(ISteamApps*) BS_Apps() {
#pragma comment(linker, "/EXPORT:BS_Apps=_BS_Apps@0")
	return SteamApps();
}

DLL_FUNCTION(uint32_t) BS_Apps_IsSubscribed(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribed=_BS_Apps_IsSubscribed@4")
	return lpSteamApps->BIsSubscribed();
}

DLL_FUNCTION(uint32_t) BS_Apps_IsLowViolence(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsLowViolence=_BS_Apps_IsLowViolence@4")
	return lpSteamApps->BIsLowViolence();
}

DLL_FUNCTION(uint32_t) BS_Apps_IsCybercafe(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsCybercafe=_BS_Apps_IsCybercafe@4")
	return lpSteamApps->BIsCybercafe();
}

DLL_FUNCTION(uint32_t) BS_Apps_IsVACBanned(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsVACBanned=_BS_Apps_IsVACBanned@4")
	return lpSteamApps->BIsVACBanned();
}

DLL_FUNCTION(const char*) BS_Apps_GetCurrentGameLanguage(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetCurrentGameLanguage=_BS_Apps_GetCurrentGameLanguage@4")
	return lpSteamApps->GetCurrentGameLanguage();
}

DLL_FUNCTION(const char*) BS_Apps_GetAvailableGameLanguages(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetAvailableGameLanguages=_BS_Apps_GetAvailableGameLanguages@4")
	return lpSteamApps->GetAvailableGameLanguages();
}

DLL_FUNCTION(uint32_t) BS_Apps_IsSubscribedApp(ISteamApps* lpSteamApps, AppId_t appID) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribedApp=_BS_Apps_IsSubscribedApp@8")
	return lpSteamApps->BIsSubscribedApp(appID);
}

DLL_FUNCTION(uint32_t) BS_Apps_IsDlcInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsDlcInstalled=_BS_Apps_IsDlcInstalled@8")
	return lpSteamApps->BIsDlcInstalled(appID);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetEarliestPurchaseUnixTime(ISteamApps* lpSteamApps, AppId_t appID) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetEarliestPurchaseUnixTime=_BS_Apps_GetEarliestPurchaseUnixTime@8")
	return lpSteamApps->GetEarliestPurchaseUnixTime(appID);
}

DLL_FUNCTION(uint32_t) BS_Apps_IsSubscribedFromFreeWeekend(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribedFromFreeWeekend=_BS_Apps_IsSubscribedFromFreeWeekend@4")
	return lpSteamApps->BIsSubscribedFromFreeWeekend();
}

DLL_FUNCTION(uint32_t) BS_Apps_GetDLCCount(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetDLCCount=_BS_Apps_GetDLCCount@4")
	return lpSteamApps->GetDLCCount();
}

DLL_FUNCTION(uint32_t) BS_Apps_GetDLCDataByIndex(ISteamApps* lpSteamApps, uint32_t iDLC, AppId_t *pAppIdBuffer, bool* pbAvailableBuffer, char *pchNameBuffer, uint32_t cchNameBufferSize) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetDLCDataByIndex=_BS_Apps_GetDLCDataByIndex@24")
	return lpSteamApps->BGetDLCDataByIndex(iDLC, pAppIdBuffer, (bool*)pbAvailableBuffer, pchNameBuffer, cchNameBufferSize);
}

DLL_FUNCTION(void) BS_Apps_InstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
#pragma comment(linker, "/EXPORT:BS_Apps_InstallDLC=_BS_Apps_InstallDLC@8")
	lpSteamApps->InstallDLC(nAppID);
}

DLL_FUNCTION(void) BS_Apps_UninstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
#pragma comment(linker, "/EXPORT:BS_Apps_UninstallDLC=_BS_Apps_UninstallDLC@8")
	lpSteamApps->UninstallDLC(nAppID);
}

DLL_FUNCTION(void) BS_Apps_RequestAppProofOfPurchaseKey(ISteamApps* lpSteamApps, AppId_t nAppID) {
#pragma comment(linker, "/EXPORT:BS_Apps_RequestAppProofOfPurchaseKey=_BS_Apps_RequestAppProofOfPurchaseKey@8")
	lpSteamApps->RequestAppProofOfPurchaseKey(nAppID);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetCurrentBetaName(ISteamApps* lpSteamApps, char* pchNameBuffer, int cchNameBufferSize) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetCurrentBetaName=_BS_Apps_GetCurrentBetaName@12")
	return lpSteamApps->GetCurrentBetaName(pchNameBuffer, cchNameBufferSize);
}

DLL_FUNCTION(uint32_t) BS_Apps_MarkContentCorrupt(ISteamApps* lpSteamApps, uint32_t bMissingFilesOnly) {
#pragma comment(linker, "/EXPORT:BS_Apps_MarkContentCorrupt=_BS_Apps_MarkContentCorrupt@8")
	return lpSteamApps->MarkContentCorrupt(bMissingFilesOnly != 0);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetInstalledDepots(ISteamApps* lpSteamApps, AppId_t nAppID, DepotId_t *pDepotsBuffer, uint32_t cMaxDepots) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetInstalledDepots=_BS_Apps_GetInstalledDepots@16")
	return lpSteamApps->GetInstalledDepots(nAppID, pDepotsBuffer, cMaxDepots);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetAppInstallDir(ISteamApps* lpSteamApps, AppId_t appID, char *pchFolderBuffer, uint32_t cchFolderBufferSize) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppInstallDir=_BS_Apps_GetAppInstallDir@16")
	return lpSteamApps->GetAppInstallDir(appID, pchFolderBuffer, cchFolderBufferSize);
}

DLL_FUNCTION(uint32_t) BS_Apps_IsAppInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
#pragma comment(linker, "/EXPORT:BS_Apps_IsAppInstalled=_BS_Apps_IsAppInstalled@8")
	return lpSteamApps->BIsAppInstalled(appID);
}

DLL_FUNCTION(CSteamID*) BS_Apps_GetAppOwner(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppOwner=_BS_Apps_GetAppOwner@4")
	return new CSteamID(lpSteamApps->GetAppOwner());
}

DLL_FUNCTION(const char*) BS_Apps_GetLaunchQueryParam(ISteamApps* lpSteamApps, const char *pchKey) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetLaunchQueryParam=_BS_Apps_GetLaunchQueryParam@8")
	return lpSteamApps->GetLaunchQueryParam(pchKey);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetDlcDownloadProgress(ISteamApps* lpSteamApps, AppId_t nAppID, uint64_t* pLLBytesDownloaded, uint64_t* pLLBytesTotal) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetDlcDownloadProgress=_BS_Apps_GetDlcDownloadProgress@16")
	return lpSteamApps->GetDlcDownloadProgress(nAppID, pLLBytesDownloaded, pLLBytesTotal);
}

DLL_FUNCTION(uint32_t) BS_Apps_GetAppBuildId(ISteamApps* lpSteamApps) {
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppBuildId=_BS_Apps_GetAppBuildId@4")
	return lpSteamApps->GetAppBuildId();
}
