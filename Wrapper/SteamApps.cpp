#include "dllmain.h"

DLL_EXPORT uint32_t BlitzSteamApps_IsSubscribed(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribed();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsSubscribed=_BlitzSteamApps_IsSubscribed@4")

DLL_EXPORT uint32_t BlitzSteamApps_IsLowViolence(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsLowViolence();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsLowViolence=_BlitzSteamApps_IsLowViolence@4")

DLL_EXPORT uint32_t BlitzSteamApps_IsCybercafe(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsCybercafe();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsCybercafe=_BlitzSteamApps_IsCybercafe@4")

DLL_EXPORT uint32_t BlitzSteamApps_IsVACBanned(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsVACBanned();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsVACBanned=_BlitzSteamApps_IsVACBanned@4")

DLL_EXPORT const char* BlitzSteamApps_GetCurrentGameLanguage(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetCurrentGameLanguage();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetCurrentGameLanguage=_BlitzSteamApps_GetCurrentGameLanguage@4")

DLL_EXPORT const char* BlitzSteamApps_GetAvailableGameLanguages(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAvailableGameLanguages();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetAvailableGameLanguages=_BlitzSteamApps_GetAvailableGameLanguages@4")

DLL_EXPORT uint32_t BlitzSteamApps_IsSubscribedApp(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsSubscribedApp(appID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsSubscribedApp=_BlitzSteamApps_IsSubscribedApp@8")

DLL_EXPORT uint32_t BlitzSteamApps_IsDlcInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsDlcInstalled(appID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsDlcInstalled=_BlitzSteamApps_IsDlcInstalled@8")

DLL_EXPORT uint32_t BlitzSteamApps_GetEarliestPurchaseUnixTime(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->GetEarliestPurchaseUnixTime(appID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetEarliestPurchaseUnixTime=_BlitzSteamApps_GetEarliestPurchaseUnixTime@8")

DLL_EXPORT uint32_t BlitzSteamApps_IsSubscribedFromFreeWeekend(ISteamApps* lpSteamApps) {
	return lpSteamApps->BIsSubscribedFromFreeWeekend();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsSubscribedFromFreeWeekend=_BlitzSteamApps_IsSubscribedFromFreeWeekend@4")

DLL_EXPORT uint32_t BlitzSteamApps_GetDLCCount(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetDLCCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetDLCCount=_BlitzSteamApps_GetDLCCount@4")

DLL_EXPORT uint32_t BlitzSteamApps_GetDLCDataByIndex(ISteamApps* lpSteamApps, uint32_t iDLC, AppId_t *pAppId, bool *pbAvailable, char *pchName, uint32_t cchNameBufferSize) {
	return lpSteamApps->BGetDLCDataByIndex(iDLC, pAppId, pbAvailable, pchName, cchNameBufferSize);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetDLCDataByIndex=_BlitzSteamApps_GetDLCDataByIndex@24")

DLL_EXPORT void BlitzSteamApps_InstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->InstallDLC(nAppID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_InstallDLC=_BlitzSteamApps_InstallDLC@8")

DLL_EXPORT void BlitzSteamApps_UninstallDLC(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->UninstallDLC(nAppID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_UninstallDLC=_BlitzSteamApps_UninstallDLC@8")

DLL_EXPORT void BlitzSteamApps_RequestAppProofOfPurchaseKey(ISteamApps* lpSteamApps, AppId_t nAppID) {
	lpSteamApps->RequestAppProofOfPurchaseKey(nAppID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_RequestAppProofOfPurchaseKey=_BlitzSteamApps_RequestAppProofOfPurchaseKey@8")

DLL_EXPORT uint32_t BlitzSteamApps_GetCurrentBetaName(ISteamApps* lpSteamApps, char *pchName, int cchNameBufferSize) {
	return lpSteamApps->GetCurrentBetaName(pchName, cchNameBufferSize);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetCurrentBetaName=_BlitzSteamApps_GetCurrentBetaName@12")

DLL_EXPORT uint32_t BlitzSteamApps_MarkContentCorrupt(ISteamApps* lpSteamApps, bool bMissingFilesOnly) {
	return lpSteamApps->MarkContentCorrupt(bMissingFilesOnly);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_MarkContentCorrupt=_BlitzSteamApps_MarkContentCorrupt@8")

DLL_EXPORT uint32_t BlitzSteamApps_GetInstalledDepots(ISteamApps* lpSteamApps, AppId_t nAppID, DepotId_t *pvecDepots, uint32_t cMaxDepots) {
	return lpSteamApps->GetInstalledDepots(nAppID, pvecDepots, cMaxDepots);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetInstalledDepots=_BlitzSteamApps_GetInstalledDepots@16")

DLL_EXPORT uint32_t BlitzSteamApps_GetAppInstallDir(ISteamApps* lpSteamApps, AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize) {
	return lpSteamApps->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetAppInstallDir=_BlitzSteamApps_GetAppInstallDir@16")

DLL_EXPORT uint32_t BlitzSteamApps_IsAppInstalled(ISteamApps* lpSteamApps, AppId_t appID) {
	return lpSteamApps->BIsAppInstalled(appID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_IsAppInstalled=_BlitzSteamApps_IsAppInstalled@8")

DLL_EXPORT CSteamID* BlitzSteamApps_GetAppOwner(ISteamApps* lpSteamApps) {
	return &lpSteamApps->GetAppOwner();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetAppOwner=_BlitzSteamApps_GetAppOwner@4")

DLL_EXPORT const char* BlitzSteamApps_GetLaunchQueryParam(ISteamApps* lpSteamApps, const char *pchKey) {
	return lpSteamApps->GetLaunchQueryParam(pchKey);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetLaunchQueryParam=_BlitzSteamApps_GetLaunchQueryParam@8")

DLL_EXPORT uint32_t BlitzSteamApps_GetDlcDownloadProgress(ISteamApps* lpSteamApps, AppId_t nAppID, uint64_t* pOutputBank) {
	return lpSteamApps->GetDlcDownloadProgress(nAppID, pOutputBank, pOutputBank + 1);
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetDlcDownloadProgress=_BlitzSteamApps_GetDlcDownloadProgress@12")

DLL_EXPORT uint32_t BlitzSteamApps_GetAppBuildId(ISteamApps* lpSteamApps) {
	return lpSteamApps->GetAppBuildId();
}
#pragma comment(linker, "/EXPORT:BlitzSteamApps_GetAppBuildId=_BlitzSteamApps_GetAppBuildId@4")