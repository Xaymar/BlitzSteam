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
// Purpose: Functions for making connections and sending data between clients,
//			traversing NAT's where possible
//-----------------------------------------------------------------------------
DLL_FUNCTION(ISteamNetworking*) BS_SteamNetworking() {
	return SteamNetworking();
}

DLL_FUNCTION(ISteamNetworking*) BS_SteamGameServerNetworking() {
	return SteamGameServerNetworking();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Session-less connection functions
//    automatically establishes NAT-traversing or Relay server connections

// Sends a P2P packet to the specified user
// UDP-like, unreliable and a max packet size of 1200 bytes
// the first packet send may be delayed as the NAT-traversal code runs
// if we can't get through to the user, an error will be posted via the callback P2PSessionConnectFail_t
// see EP2PSend enum above for the descriptions of the different ways of sending packets
//
// nChannel is a routing number you can use to help route message to different systems 	- you'll have to call ReadP2PPacket() 
// with the same channel number in order to retrieve the data on the other end
// using different channels to talk to the same user will still use the same underlying p2p connection, saving on resources
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_SendP2PPacket(ISteamNetworking* pThis, CSteamID* pSteamIDRemote, const void* pubData, uint32_t cubData, EP2PSend eP2PSendType, uint32_t nChannel) {
	return pThis->SendP2PPacket(*pSteamIDRemote, pubData, cubData, eP2PSendType, nChannel);
}

// returns true if any data is available for read, and the amount of data that will need to be read
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_IsP2PPacketAvailable(ISteamNetworking* pThis, uint32_t* pcubMsgSize, uint32_t nChannel) {
	return pThis->IsP2PPacketAvailable(pcubMsgSize, nChannel);
}

// reads in a packet that has been sent from another user via SendP2PPacket()
// returns the size of the message and the steamID of the user who sent it in the last two parameters
// if the buffer passed in is too small, the message will be truncated
// this call is not blocking, and will return false if no data is available
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_ReadP2PPacket(ISteamNetworking* pThis, void* pubDest, uint32_t cubDest, uint32_t* pcubMsgSize, CSteamID* pSteamIDRemote, uint32_t nChannel) {
	return pThis->ReadP2PPacket(pubDest, cubDest, pcubMsgSize, pSteamIDRemote, nChannel);
}

// AcceptP2PSessionWithUser() should only be called in response to a P2PSessionRequest_t callback
// P2PSessionRequest_t will be posted if another user tries to send you a packet that you haven't talked to yet
// if you don't want to talk to the user, just ignore the request
// if the user continues to send you packets, another P2PSessionRequest_t will be posted periodically
// this may be called multiple times for a single user
// (if you've called SendP2PPacket() on the other user, this implicitly accepts the session request)
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_AcceptP2PSessionWithUser(ISteamNetworking* pThis, CSteamID* pSteamIDRemote) {
	return pThis->AcceptP2PSessionWithUser(*pSteamIDRemote);
}

// call CloseP2PSessionWithUser() when you're done talking to a user, will free up resources under-the-hood
// if the remote user tries to send data to you again, another P2PSessionRequest_t callback will be posted
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_CloseP2PSessionWithUser(ISteamNetworking* pThis, CSteamID* pSteamIDRemote) {
	return pThis->CloseP2PSessionWithUser(*pSteamIDRemote);
}

// call CloseP2PChannelWithUser() when you're done talking to a user on a specific channel. Once all channels
// open channels to a user have been closed, the open session to the user will be closed and new data from this
// user will trigger a P2PSessionRequest_t callback
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_CloseP2PChannelWithUser(ISteamNetworking* pThis, CSteamID* pSteamIDRemote, uint32_t nChannel) {
	return pThis->CloseP2PChannelWithUser(*pSteamIDRemote, nChannel);
}

// fills out P2PSessionState_t structure with details about the underlying connection to the user
// should only needed for debugging purposes
// returns false if no connection exists to the specified user
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_GetP2PSessionState(ISteamNetworking* pThis, CSteamID* pSteamIDRemote, P2PSessionState_t* pConnectionState) {
	return pThis->GetP2PSessionState(*pSteamIDRemote, pConnectionState);
}

// Allow P2P connections to fall back to being relayed through the Steam servers if a direct connection
// or NAT-traversal cannot be established. Only applies to connections created after setting this value,
// or to existing connections that need to automatically reconnect after this value is set.
//
// P2P packet relay is allowed by default
DLL_FUNCTION(uint32_t) BS_ISteamNetworking_AllowP2PPacketRelay(ISteamNetworking* pThis, uint32_t bAllow) {
	return pThis->AllowP2PPacketRelay(!!bAllow);
}
