//	BS_ - Steam wrapper for Blitz.
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

DLL_EXPORT uint32_t DLL_CALL BS_AppList_GetNumInstalledApps(ISteamAppList* lpSteamAppList) {
	return lpSteamAppList->GetNumInstalledApps();
}
#pragma comment(linker, "/EXPORT:BS_AppList_GetNumInstalledApps=_BS_AppList_GetNumInstalledApps@4")

DLL_EXPORT uint32_t DLL_CALL BS_AppList_GetInstalledApps(ISteamAppList* lpSteamAppList, AppId_t *pvecAppID, uint32 unMaxAppIDs) {
	return lpSteamAppList->GetInstalledApps(pvecAppID, unMaxAppIDs);
}
#pragma comment(linker, "/EXPORT:BS_AppList_GetInstalledApps=_BS_AppList_GetInstalledApps@12")

DLL_EXPORT uint32_t DLL_CALL BS_AppList_GetAppName(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchName, uint32_t cchNameMax) {
	return lpSteamAppList->GetAppName(nAppID, pchName, cchNameMax);
}
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppName=_BS_AppList_GetAppName@16")

DLL_EXPORT uint32_t DLL_CALL BS_AppList_GetAppInstallDir(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchDirectory, uint32_t cchDirectoryMax) {
	return lpSteamAppList->GetAppInstallDir(nAppID, pchDirectory, cchDirectoryMax);
}
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppInstallDir=_BS_AppList_GetAppInstallDir@16")

DLL_EXPORT uint32_t DLL_CALL BS_AppList_GetAppBuildId(ISteamAppList* lpSteamAppList, AppId_t nAppID) {
	return lpSteamAppList->GetAppBuildId(nAppID);
}
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppBuildId=_BS_AppList_GetAppBuildId@8")
