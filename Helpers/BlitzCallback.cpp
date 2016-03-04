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

std::map<uint32_t, size_t>* BlitzCallback_Sizes;
#define BlitzCallback_Sizes_Add(T) BlitzCallback_Sizes->emplace(T::k_iCallback, sizeof(T))

void BlitzCallback_Init() {
	BlitzCallback_Sizes = new std::map<uint32_t, size_t>();
	BlitzCallback_Sizes->emplace(0, sizeof(BlitzCallback));

	// SteamAPI

	// SteamAppList
	BlitzCallback_Sizes_Add(SteamAppInstalled_t);
	BlitzCallback_Sizes_Add(SteamAppUninstalled_t);

	// SteamApps
	BlitzCallback_Sizes_Add(DlcInstalled_t);
	BlitzCallback_Sizes_Add(RegisterActivationCodeResponse_t);
	BlitzCallback_Sizes_Add(AppProofOfPurchaseKeyResponse_t);
	BlitzCallback_Sizes_Add(NewLaunchQueryParameters_t);

	// SteamController
	
	// SteamFriends
	BlitzCallback_Sizes_Add(PersonaStateChange_t);
	BlitzCallback_Sizes_Add(GameOverlayActivated_t);
	BlitzCallback_Sizes_Add(GameServerChangeRequested_t);
	BlitzCallback_Sizes_Add(GameLobbyJoinRequested_t);
	BlitzCallback_Sizes_Add(AvatarImageLoaded_t);
	BlitzCallback_Sizes_Add(ClanOfficerListResponse_t);
	BlitzCallback_Sizes_Add(FriendRichPresenceUpdate_t);
	BlitzCallback_Sizes_Add(GameRichPresenceJoinRequested_t);
	BlitzCallback_Sizes_Add(GameConnectedClanChatMsg_t);
	BlitzCallback_Sizes_Add(GameConnectedChatJoin_t);
	BlitzCallback_Sizes_Add(GameConnectedChatLeave_t);
	BlitzCallback_Sizes_Add(DownloadClanActivityCountsResult_t);
	BlitzCallback_Sizes_Add(JoinClanChatRoomCompletionResult_t);
	BlitzCallback_Sizes_Add(GameConnectedFriendChatMsg_t);
	BlitzCallback_Sizes_Add(FriendsGetFollowerCount_t);
	BlitzCallback_Sizes_Add(FriendsIsFollowing_t);
	BlitzCallback_Sizes_Add(FriendsEnumerateFollowingList_t);
	BlitzCallback_Sizes_Add(SetPersonaNameResponse_t);

	// SteamGameServer
	BlitzCallback_Sizes_Add(GSClientApprove_t);
	BlitzCallback_Sizes_Add(GSClientDeny_t);
	BlitzCallback_Sizes_Add(GSClientKick_t);
	BlitzCallback_Sizes_Add(GSClientAchievementStatus_t);
	BlitzCallback_Sizes_Add(GSPolicyResponse_t);
	BlitzCallback_Sizes_Add(GSGameplayStats_t);
	BlitzCallback_Sizes_Add(GSClientGroupStatus_t);
	BlitzCallback_Sizes_Add(GSReputation_t);
	BlitzCallback_Sizes_Add(AssociateWithClanResult_t);
	BlitzCallback_Sizes_Add(ComputeNewPlayerCompatibilityResult_t);

	// SteamGameServerStats
	BlitzCallback_Sizes_Add(GSStatsReceived_t);
	BlitzCallback_Sizes_Add(GSStatsStored_t);
	BlitzCallback_Sizes_Add(GSStatsUnloaded_t);

	// SteamHTMLSurface
	BlitzCallback_Sizes_Add(HTML_BrowserReady_t);
}

BlitzCallback::BlitzCallback(BP_BlitzFunction3_t pFunctionPointer) {
	this->m_pFunctionPointer = pFunctionPointer;
	this->m_hSteamAPICall = 0;
	this->m_iCallback = 0;

	// Initialize BlitzCallback_Sizes
	if (BlitzCallback_Sizes == 0)
		BlitzCallback_Init();
}

BlitzCallback::~BlitzCallback() {
	this->Unregister();
	this->UnregisterResult();
}

int BlitzCallback::GetCallbackSizeBytes() {
	return (BlitzCallback_Sizes->find(this->m_iCallback)->second);
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

bool BlitzCallback::IsRegistered() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsRegistered) != 0;
}

void BlitzCallback::Register(uint32_t iCallback) {
	if (this->IsRegistered())
		this->Unregister();

	SteamAPI_RegisterCallback(this, iCallback);
}

void BlitzCallback::Unregister() {
	if (this->IsRegistered())
		SteamAPI_UnregisterCallback(this);
}

void BlitzCallback::RegisterResult(SteamAPICall_t hSteamAPICall, uint32_t iCallback) {
	if (this->m_hSteamAPICall == 0)
		this->UnregisterResult();

	this->m_hSteamAPICall = hSteamAPICall;
	this->m_iCallback = iCallback;

	SteamAPI_RegisterCallResult(this, hSteamAPICall);
}

void BlitzCallback::UnregisterResult() {
	if (this->m_hSteamAPICall != 0)
		SteamAPI_UnregisterCallResult(this, this->m_hSteamAPICall);

	this->m_hSteamAPICall = 0;
	this->m_iCallback = 0;
}

bool BlitzCallback::IsGameServer() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsGameServer) != 0;
}

void BlitzCallback::SetGameServer(bool bIsGameServer) {
	this->m_nCallbackFlags &= ~k_ECallbackFlagsGameServer;
	if (bIsGameServer)
		this->m_nCallbackFlags |= k_ECallbackFlagsGameServer;
}

// DLL-Callables
DLL_FUNCTION(BlitzCallback*) BS_Callback_Create(BP_BlitzFunction3_t pFunctionPointer) {
	return new BlitzCallback(pFunctionPointer);
}

DLL_FUNCTION(void) BS_Callback_Destroy(BlitzCallback* pCallback) {
	delete pCallback;
}

DLL_FUNCTION(int32_t) BS_Callback_IsRegistered(BlitzCallback* pCallback) {
	return pCallback->IsRegistered();
}

DLL_FUNCTION(int32_t) BS_Callback_IsGameServer(BlitzCallback* pCallback) {
	return pCallback->IsGameServer();
}

DLL_FUNCTION(int32_t) BS_Callback_SetGameServerFlag(BlitzCallback* pCallback, int32_t bIsGameServer) {
	bool isGameServer = pCallback->IsGameServer();
	pCallback->SetGameServer(!!bIsGameServer);
	return isGameServer;
}

DLL_FUNCTION(void) BS_Callback_Register(BlitzCallback* pCallback, uint32_t iCallback) {
	pCallback->Register(iCallback);
}

DLL_FUNCTION(void) BS_Callback_Unregister(BlitzCallback* pCallback) {
	pCallback->Unregister();
}

DLL_FUNCTION(void) BS_Callback_RegisterResult(BlitzCallback* pCallback, SteamAPICall_t* pSteamAPICall, uint32_t iCallback) {
	pCallback->RegisterResult(*pSteamAPICall, iCallback);
}

DLL_FUNCTION(void) BS_Callback_UnregisterResult(BlitzCallback* pCallback) {
	pCallback->UnregisterResult();
}