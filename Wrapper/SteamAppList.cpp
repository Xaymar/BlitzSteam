#include "dllmain.h"

DLL_EXPORT uint32_t BlitzSteamAppList_GetNumInstalledApps(ISteamAppList* lpSteamAppList) {
	return lpSteamAppList->GetNumInstalledApps();
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList_GetNumInstalledApps=_BlitzSteamAppList_GetNumInstalledApps@4")

DLL_EXPORT uint32_t BlitzSteamAppList_GetInstalledApps(ISteamAppList* lpSteamAppList, AppId_t *pvecAppID, uint32 unMaxAppIDs) {
	return lpSteamAppList->GetInstalledApps(pvecAppID, unMaxAppIDs);
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList_GetInstalledApps=_BlitzSteamAppList_GetInstalledApps@12")

DLL_EXPORT uint32_t BlitzSteamAppList_GetAppName(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchName, uint32_t cchNameMax) {
	return lpSteamAppList->GetAppName(nAppID, pchName, cchNameMax);
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList_GetAppName=_BlitzSteamAppList_GetAppName@16")

DLL_EXPORT uint32_t BlitzSteamAppList_GetAppInstallDir(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchDirectory, uint32_t cchDirectoryMax) {
	return lpSteamAppList->GetAppInstallDir(nAppID, pchDirectory, cchDirectoryMax);
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList_GetAppName=_BlitzSteamAppList_GetAppName@16")

DLL_EXPORT uint32_t BlitzSteamAppList_GetAppBuildId(ISteamAppList* lpSteamAppList, AppId_t nAppID) {
	return lpSteamAppList->GetAppBuildId(nAppID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamAppList_GetAppBuildId=_BlitzSteamAppList_GetAppBuildId@8")
