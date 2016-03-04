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

DLL_FUNCTION(ISteamNetworking*) BS_Networking() {
	return SteamNetworking();
}

DLL_FUNCTION(ISteamNetworking*) BS_GameServerNetworking() {
	return SteamGameServerNetworking();
}

DLL_FUNCTION(uint32_t) BS_Networking_SendP2PPacket(ISteamNetworking* pSteamNetworking, CSteamID* pSteamIDRemote, const void* pubData, uint32_t cubData, EP2PSend eP2PSendType, uint32_t nChannel) {
	return pSteamNetworking->SendP2PPacket(*pSteamIDRemote, pubData, cubData, eP2PSendType, nChannel);
}

DLL_FUNCTION(uint32_t) BS_Networking_IsP2PPacketAvailable(ISteamNetworking* pSteamNetworking, uint32_t* pcubMsgSize, uint32_t nChannel) {
	return pSteamNetworking->IsP2PPacketAvailable(pcubMsgSize, nChannel);
}

DLL_FUNCTION(uint32_t) BS_Networking_ReadP2PPacket(ISteamNetworking* pSteamNetworking, void* pubDest, uint32_t cubDest, uint32_t* pcubMsgSize, CSteamID* pSteamIDRemote, uint32_t nChannel) {
	return pSteamNetworking->ReadP2PPacket(pubDest, cubDest, pcubMsgSize, pSteamIDRemote, nChannel);
}

DLL_FUNCTION(uint32_t) BS_Networking_AcceptP2PSessionWithUser(ISteamNetworking* pSteamNetworking, CSteamID* pSteamIDRemote) {
	return pSteamNetworking->AcceptP2PSessionWithUser(*pSteamIDRemote);
}

DLL_FUNCTION(uint32_t) BS_Networking_CloseP2PSessionWithUser(ISteamNetworking* pSteamNetworking, CSteamID* pSteamIDRemote) {
	return pSteamNetworking->CloseP2PSessionWithUser(*pSteamIDRemote);
}

DLL_FUNCTION(uint32_t) BS_Networking_CloseP2PChannelWithUser(ISteamNetworking* pSteamNetworking, CSteamID* pSteamIDRemote, uint32_t nChannel) {
	return pSteamNetworking->CloseP2PChannelWithUser(*pSteamIDRemote, nChannel);
}

DLL_FUNCTION(uint32_t) BS_Networking_GetP2PSessionState(ISteamNetworking* pSteamNetworking, CSteamID* pSteamIDRemote, P2PSessionState_t* pConnectionState) {
	return pSteamNetworking->GetP2PSessionState(*pSteamIDRemote, pConnectionState);
}

DLL_FUNCTION(uint32_t) BS_Networking_AllowP2PPacketRelay(ISteamNetworking* pSteamNetworking, uint32_t bAllow) {
	return pSteamNetworking->AllowP2PPacketRelay(!!bAllow);
}
