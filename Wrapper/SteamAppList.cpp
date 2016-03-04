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
// Purpose: This is a restricted interface that can only be used by previously approved apps,
//	contact your Steam Account Manager if you believe you need access to this API.
//	This interface lets you detect installed apps for the local Steam client, useful for debugging tools
//	to offer lists of apps to debug via Steam.
//-----------------------------------------------------------------------------
DLL_FUNCTION(ISteamAppList*) BS_SteamAppList() {
	return SteamAppList();
}

DLL_FUNCTION(int32_t) BS_ISteamAppList_GetNumInstalledApps(ISteamAppList* lpSteamAppList) {
	return lpSteamAppList->GetNumInstalledApps();
}

DLL_FUNCTION(int32_t) BS_ISteamAppList_GetInstalledApps(ISteamAppList* lpSteamAppList, AppId_t *pvecAppID, uint32_t unMaxAppIDs) {
	return lpSteamAppList->GetInstalledApps(pvecAppID, unMaxAppIDs);
}

// returns -1 if no name was found
DLL_FUNCTION(int32_t) BS_ISteamAppList_GetAppName(ISteamAppList* lpSteamAppList, AppId_t nAppID, const char* pchName, uint32_t cchNameMax) {
	return lpSteamAppList->GetAppName(nAppID, (char*)pchName, cchNameMax);
}

// returns -1 if no dir was found
DLL_FUNCTION(int32_t) BS_ISteamAppList_GetAppInstallDir(ISteamAppList* lpSteamAppList, AppId_t nAppID, char* pchDirectoryBuffer, uint32_t cchDirectoryMax) {
	return lpSteamAppList->GetAppInstallDir(nAppID, pchDirectoryBuffer, cchDirectoryMax);
}

// return the buildid of this app, may change at any time based on backend updates to the game
DLL_FUNCTION(int32_t) BS_ISteamAppList_GetAppBuildId(ISteamAppList* lpSteamAppList, AppId_t nAppID) {
	return lpSteamAppList->GetAppBuildId(nAppID);
}
