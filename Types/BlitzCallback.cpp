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

#include "BlitzCallback.h"

void BlitzCallback::Initialize() {
#define BlitzCallback_DefineSize(T) BlitzCallback::Sizes.emplace(T::k_iCallback, sizeof(T));
	// Do nothing if it was already done.
	if (BlitzCallback::Sizes.size() > 0)
		return;

	// Default to the size of the class itself if no callback id is given.
	BlitzCallback::Sizes.emplace(0, sizeof(BlitzCallback));

	// SteamAPI
	// SteamAppList
	BlitzCallback_DefineSize(SteamAppInstalled_t);
	BlitzCallback_DefineSize(SteamAppUninstalled_t);
	// SteamApps
	BlitzCallback_DefineSize(DlcInstalled_t);
	BlitzCallback_DefineSize(RegisterActivationCodeResponse_t);
	BlitzCallback_DefineSize(AppProofOfPurchaseKeyResponse_t);
	BlitzCallback_DefineSize(NewLaunchQueryParameters_t);
	// SteamController
	// SteamFriends
	BlitzCallback_DefineSize(PersonaStateChange_t);
	BlitzCallback_DefineSize(GameOverlayActivated_t);
	BlitzCallback_DefineSize(GameServerChangeRequested_t);
	BlitzCallback_DefineSize(GameLobbyJoinRequested_t);
	BlitzCallback_DefineSize(AvatarImageLoaded_t);
	BlitzCallback_DefineSize(ClanOfficerListResponse_t);
	BlitzCallback_DefineSize(FriendRichPresenceUpdate_t);
	BlitzCallback_DefineSize(GameRichPresenceJoinRequested_t);
	BlitzCallback_DefineSize(GameConnectedClanChatMsg_t);
	BlitzCallback_DefineSize(GameConnectedChatJoin_t);
	BlitzCallback_DefineSize(GameConnectedChatLeave_t);
	BlitzCallback_DefineSize(DownloadClanActivityCountsResult_t);
	BlitzCallback_DefineSize(JoinClanChatRoomCompletionResult_t);
	BlitzCallback_DefineSize(GameConnectedFriendChatMsg_t);
	BlitzCallback_DefineSize(FriendsGetFollowerCount_t);
	BlitzCallback_DefineSize(FriendsIsFollowing_t);
	BlitzCallback_DefineSize(FriendsEnumerateFollowingList_t);
	BlitzCallback_DefineSize(SetPersonaNameResponse_t);
	// SteamGameServer
	BlitzCallback_DefineSize(GSClientApprove_t);
	BlitzCallback_DefineSize(GSClientDeny_t);
	BlitzCallback_DefineSize(GSClientKick_t);
	BlitzCallback_DefineSize(GSClientAchievementStatus_t);
	BlitzCallback_DefineSize(GSPolicyResponse_t);
	BlitzCallback_DefineSize(GSGameplayStats_t);
	BlitzCallback_DefineSize(GSClientGroupStatus_t);
	BlitzCallback_DefineSize(GSReputation_t);
	BlitzCallback_DefineSize(AssociateWithClanResult_t);
	BlitzCallback_DefineSize(ComputeNewPlayerCompatibilityResult_t);
	// SteamGameServerStats
	BlitzCallback_DefineSize(GSStatsReceived_t);
	BlitzCallback_DefineSize(GSStatsStored_t);
	BlitzCallback_DefineSize(GSStatsUnloaded_t);
	// SteamHTMLSurface
	BlitzCallback_DefineSize(HTML_BrowserReady_t);
	// SteamHTTP
	BlitzCallback_DefineSize(HTTPRequestCompleted_t);
	BlitzCallback_DefineSize(HTTPRequestHeadersReceived_t);
	BlitzCallback_DefineSize(HTTPRequestDataReceived_t);
	// SteamInventory
	BlitzCallback_DefineSize(SteamInventoryResultReady_t);
	BlitzCallback_DefineSize(SteamInventoryFullUpdate_t);
	BlitzCallback_DefineSize(SteamInventoryDefinitionUpdate_t);
	// SteamMatchmaking
	// SteamMatchmakingServers
	// SteamMusic
	// SteamMusicRemote
	// SteamNetworking
	BlitzCallback_DefineSize(P2PSessionRequest_t);
	BlitzCallback_DefineSize(P2PSessionConnectFail_t);
	BlitzCallback_DefineSize(SocketStatusCallback_t);
}

std::map<int32_t, size_t> BlitzCallback::Sizes;

BlitzCallback::BlitzCallback(BP_BlitzFunction3_t pFunctionPointer) {
	BlitzCallback::Initialize();

	// Initialize all values to 0.
	this->m_iCallback = 0;
	this->m_nCallbackFlags = 0;
	this->m_hSteamAPICall = 0;

	// Set function pointer.
	this->m_pFunctionPointer = pFunctionPointer;
}

BlitzCallback::~BlitzCallback() {
	// Unregister if we are still registered.
	this->UnregisterResult();
	this->Unregister();

	// Reset all variables to 0.
	this->m_iCallback = 0;
	this->m_nCallbackFlags = 0;
	this->m_hSteamAPICall = 0;
	this->m_pFunctionPointer = 0;
}

void BlitzCallback::Run(void *pvParam) {
	if (m_hSteamAPICall != 0)
		m_hSteamAPICall = 0; // Caller unregisters for us.

	BP_CallFunction3(m_pFunctionPointer, reinterpret_cast<int32_t>(pvParam), 0, 0);
}

void BlitzCallback::Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) {
	if (m_hSteamAPICall != 0)
		m_hSteamAPICall = 0; // Caller unregisters for us.

	BP_CallFunction3(m_pFunctionPointer, reinterpret_cast<int32_t>(pvParam), (bIOFailure ? 0 : 1), reinterpret_cast<int32_t>(&hSteamAPICall));
}

int BlitzCallback::GetCallbackSizeBytes() {
	return (BlitzCallback::Sizes.find(this->m_iCallback)->second);
}

void BlitzCallback::SetCallback(int32_t iCallback) {
	this->m_iCallback = iCallback;
}

int32_t BlitzCallback::GetCallback() {
	return this->m_iCallback;
}

void BlitzCallback::SetFunction(BP_BlitzFunction3_t pFunction) {
	this->m_pFunctionPointer = pFunction;
}

BP_BlitzFunction3_t BlitzCallback::GetFunction() {
	return this->m_pFunctionPointer;
}

bool BlitzCallback::IsRegistered() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsRegistered) != 0;
}

void BlitzCallback::SetRegistered(bool bIsRegistered) {
	this->m_nCallbackFlags &= ~k_ECallbackFlagsRegistered;
	if (bIsRegistered)
		this->m_nCallbackFlags |= k_ECallbackFlagsRegistered;
}

bool BlitzCallback::IsGameServer() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsGameServer) != 0;
}

void BlitzCallback::SetGameServer(bool bIsGameServer) {
	this->m_nCallbackFlags &= ~k_ECallbackFlagsGameServer;
	if (bIsGameServer)
		this->m_nCallbackFlags |= k_ECallbackFlagsGameServer;
}

void BlitzCallback::Register(uint32_t iCallback) {
	if (this->IsRegistered())
		this->Unregister();

	SteamAPI_RegisterCallback(this, iCallback);
	this->m_iCallback = iCallback;
}

void BlitzCallback::Unregister() {
	if (this->IsRegistered()) {
		SteamAPI_UnregisterCallback(this);
		this->m_iCallback = 0;
	}
}

void BlitzCallback::RegisterResult(SteamAPICall_t hSteamAPICall, uint32_t iCallback) {
	if (this->m_hSteamAPICall != 0)
		this->UnregisterResult();

	this->m_hSteamAPICall = hSteamAPICall;
	this->m_iCallback = iCallback;

	SteamAPI_RegisterCallResult(this, hSteamAPICall);
}

void BlitzCallback::UnregisterResult() {
	if (this->m_hSteamAPICall != 0) {
		SteamAPI_UnregisterCallResult(this, this->m_hSteamAPICall);
		this->m_hSteamAPICall = 0;
		this->m_iCallback = 0;
	}
}

//-----------------------------------------------------------------------------
// C-Callables
//-----------------------------------------------------------------------------
DLL(BlitzCallback*) BS_Callback_New(BP_BlitzFunction3_t pFunctionPointer) {
	return new BlitzCallback(pFunctionPointer);
}

DLL(void) BS_Callback_Destroy(BlitzCallback* pCallback) {
	delete pCallback;
}

DLL(int32_t) BS_Callback_GetCallbackSizeBytes(BlitzCallback* pCallback) {
	return pCallback->GetCallbackSizeBytes();
}

DLL(void) BS_Callback_SetCallback(BlitzCallback* pCallback, int32_t iCallback) {
	pCallback->SetCallback(iCallback);
}

DLL(int32_t) BS_Callback_GetCallback(BlitzCallback* pCallback) {
	return pCallback->GetCallback();
}

DLL(void) BS_Callback_SetFunction(BlitzCallback* pCallback, BP_BlitzFunction3_t pFunction) {
	pCallback->SetFunction(pFunction);
}

DLL(BP_BlitzFunction3_t) BS_Callback_GetFunction(BlitzCallback* pCallback) {
	return pCallback->GetFunction();
}

DLL(int32_t) BS_Callback_IsRegistered(BlitzCallback* pCallback) {
	return pCallback->IsRegistered();
}

DLL(void) BS_Callback_SetRegistered(BlitzCallback* pCallback, int32_t bIsRegistered) {
	pCallback->SetRegistered(!!bIsRegistered);
}

DLL(int32_t) BS_Callback_IsGameServer(BlitzCallback* pCallback) {
	return pCallback->IsGameServer();
}

DLL(void) BS_Callback_SetGameServer(BlitzCallback* pCallback, int32_t bIsGameServer) {
	pCallback->SetGameServer(!!bIsGameServer);
}

DLL(void) BS_Callback_Register(BlitzCallback* pCallback, uint32_t iCallback) {
	pCallback->Register(iCallback);
}

DLL(void) BS_Callback_Unregister(BlitzCallback* pCallback) {
	pCallback->Unregister();
}

DLL(void) BS_Callback_RegisterResult(BlitzCallback* pCallback, SteamAPICall_t* pSteamAPICall, uint32_t iCallback) {
	pCallback->RegisterResult(*pSteamAPICall, iCallback);
}

DLL(void) BS_Callback_UnregisterResult(BlitzCallback* pCallback) {
	pCallback->UnregisterResult();
}