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

DLL_FUNCTION(ISteamAppList*) BS_AppList() {
#pragma comment(linker, "/EXPORT:BS_AppList=_BS_AppList@0")
	return SteamAppList();
}

DLL_FUNCTION(uint32_t) BS_AppList_GetNumInstalledApps(ISteamAppList* lpSteamAppList) {
#pragma comment(linker, "/EXPORT:BS_AppList_GetNumInstalledApps=_BS_AppList_GetNumInstalledApps@4")
	return lpSteamAppList->GetNumInstalledApps();
}

DLL_FUNCTION(uint32_t) BS_AppList_GetInstalledApps(ISteamAppList* lpSteamAppList, AppId_t *pvecAppID, uint32_t unMaxAppIDs) {
#pragma comment(linker, "/EXPORT:BS_AppList_GetInstalledApps=_BS_AppList_GetInstalledApps@12")
	return lpSteamAppList->GetInstalledApps(pvecAppID, unMaxAppIDs);
}

DLL_FUNCTION(uint32_t) BS_AppList_GetAppName(ISteamAppList* lpSteamAppList, AppId_t nAppID, const char* pchName, uint32_t cchNameMax) {
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppName=_BS_AppList_GetAppName@16")
	return lpSteamAppList->GetAppName(nAppID, (char*)pchName, cchNameMax);
}

DLL_FUNCTION(uint32_t) BS_AppList_GetAppInstallDir(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchDirectoryBuffer, uint32_t cchDirectoryMax) {
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppInstallDir=_BS_AppList_GetAppInstallDir@16")
	return lpSteamAppList->GetAppInstallDir(nAppID, pchDirectoryBuffer, cchDirectoryMax);
}

DLL_FUNCTION(uint32_t) BS_AppList_GetAppBuildId(ISteamAppList* lpSteamAppList, AppId_t nAppID) {
#pragma comment(linker, "/EXPORT:BS_AppList_GetAppBuildId=_BS_AppList_GetAppBuildId@8")
	return lpSteamAppList->GetAppBuildId(nAppID);
}
