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

#include "dllmain.h"
#include "Helpers/CSteamID.h"

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsSubscribed(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribed();
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribed=_BS_Apps_IsSubscribed@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsLowViolence(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsLowViolence();
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsLowViolence=_BS_Apps_IsLowViolence@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsCybercafe(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsCybercafe();
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsCybercafe=_BS_Apps_IsCybercafe@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsVACBanned(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsVACBanned();
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsVACBanned=_BS_Apps_IsVACBanned@4")

DLL_EXPORT const char* DLL_CALL BS_Apps_GetCurrentGameLanguage(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetCurrentGameLanguage();
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetCurrentGameLanguage=_BS_Apps_GetCurrentGameLanguage@4")

DLL_EXPORT const char* DLL_CALL BS_Apps_GetAvailableGameLanguages(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAvailableGameLanguages();
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetAvailableGameLanguages=_BS_Apps_GetAvailableGameLanguages@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsSubscribedApp(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsSubscribedApp(appID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribedApp=_BS_Apps_IsSubscribedApp@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsDlcInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsDlcInstalled(appID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsDlcInstalled=_BS_Apps_IsDlcInstalled@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetEarliestPurchaseUnixTime(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->GetEarliestPurchaseUnixTime(appID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetEarliestPurchaseUnixTime=_BS_Apps_GetEarliestPurchaseUnixTime@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsSubscribedFromFreeWeekend(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribedFromFreeWeekend();
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsSubscribedFromFreeWeekend=_BS_Apps_IsSubscribedFromFreeWeekend@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetDLCCount(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetDLCCount();
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetDLCCount=_BS_Apps_GetDLCCount@4")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetDLCDataByIndex(ISteamApps* lpSteamApps, uint32_t iDLC, AppId_t *pAppId, bool* pbAvailable, char *pchName, uint32_t cchNameBufferSize) {
	return lpSteamApps->BGetDLCDataByIndex(iDLC, pAppId, (bool*)pbAvailable, pchName, cchNameBufferSize);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetDLCDataByIndex=_BS_Apps_GetDLCDataByIndex@24")

DLL_EXPORT void DLL_CALL BS_Apps_InstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->InstallDLC(nAppID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_InstallDLC=_BS_Apps_InstallDLC@8")

DLL_EXPORT void DLL_CALL BS_Apps_UninstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->UninstallDLC(nAppID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_UninstallDLC=_BS_Apps_UninstallDLC@8")

DLL_EXPORT void DLL_CALL BS_Apps_RequestAppProofOfPurchaseKey(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->RequestAppProofOfPurchaseKey(nAppID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_RequestAppProofOfPurchaseKey=_BS_Apps_RequestAppProofOfPurchaseKey@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetCurrentBetaName(ISteamApps* lpSteamApps, char *pchName, int cchNameBufferSize) {
	return lpSteamApps->GetCurrentBetaName(pchName, cchNameBufferSize);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetCurrentBetaName=_BS_Apps_GetCurrentBetaName@12")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_MarkContentCorrupt(ISteamApps* lpSteamApps, uint32_t bMissingFilesOnly) {
	return lpSteamApps->MarkContentCorrupt(bMissingFilesOnly != 0);
}
#pragma comment(linker, "/EXPORT:BS_Apps_MarkContentCorrupt=_BS_Apps_MarkContentCorrupt@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetInstalledDepots(ISteamApps* lpSteamApps, AppId_t nAppID, DepotId_t *pvecDepots, uint32_t cMaxDepots) {
	return lpSteamApps->GetInstalledDepots(nAppID, pvecDepots, cMaxDepots);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetInstalledDepots=_BS_Apps_GetInstalledDepots@16")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetAppInstallDir(ISteamApps* lpSteamApps, AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize) {
	return lpSteamApps->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppInstallDir=_BS_Apps_GetAppInstallDir@16")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_IsAppInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsAppInstalled(appID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_IsAppInstalled=_BS_Apps_IsAppInstalled@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Apps_GetAppOwner(ISteamApps* lpSteamApps) {
	CSteamID* steamID = new CSteamID(lpSteamApps->GetAppOwner());
	return BS_CSteamID_Copy(steamID);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppOwner=_BS_Apps_GetAppOwner@4")

DLL_EXPORT const char* DLL_CALL BS_Apps_GetLaunchQueryParam(ISteamApps* lpSteamApps, const char *pchKey) {
	return lpSteamApps->GetLaunchQueryParam(pchKey);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetLaunchQueryParam=_BS_Apps_GetLaunchQueryParam@8")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetDlcDownloadProgress(ISteamApps* lpSteamApps, AppId_t nAppID, uint64_t* punBytesDownloaded, uint64_t* punBytesTotal) {
	return lpSteamApps->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetDlcDownloadProgress=_BS_Apps_GetDlcDownloadProgress@16")

DLL_EXPORT uint32_t DLL_CALL BS_Apps_GetAppBuildId(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAppBuildId();
}
#pragma comment(linker, "/EXPORT:BS_Apps_GetAppBuildId=_BS_Apps_GetAppBuildId@4")
