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
#include "SteamworksSDK/public/steam/steam_gameserver.h"

DLL_EXPORT uint32_t DLL_CALL BS_GameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, EServerMode eServerMode, const char *pchVersionString) {
	return SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
}

DLL_EXPORT void DLL_CALL BS_GameServer_Shutdown() {
	SteamGameServer_Shutdown();
}

DLL_EXPORT void DLL_CALL BS_GameServer_RunCallbacks() {
	SteamGameServer_RunCallbacks();
}

DLL_EXPORT uint32_t DLL_CALL BS_GameServer_Secure() {
	return SteamGameServer_BSecure();
}

DLL_EXPORT uint64_t* DLL_CALL BS_GameServer_GetSteamID() {
	uint64_t* val = new uint64_t(SteamGameServer_GetSteamID());
	return val;
}

DLL_EXPORT HSteamPipe DLL_CALL BS_GameServer_GetHSteamPipe() {
	return SteamGameServer_GetHSteamPipe();
}

// Interfaces
DLL_EXPORT ISteamGameServer* DLL_CALL BS_GameServer() {
	return SteamGameServer();
}

DLL_EXPORT ISteamUtils* DLL_CALL BS_GameServerUtils() {
	return SteamGameServerUtils();
}

DLL_EXPORT ISteamNetworking* DLL_CALL BS_GameServerNetworking() {
	return SteamGameServerNetworking();
}

DLL_EXPORT ISteamGameServerStats* DLL_CALL BS_GameServerStats() {
	return SteamGameServerStats();
}

DLL_EXPORT ISteamHTTP* DLL_CALL BS_GameServerHTTP() {
	return SteamGameServerHTTP();
}

DLL_EXPORT ISteamInventory* DLL_CALL BS_GameServerInventory() {
	return SteamGameServerInventory();
}