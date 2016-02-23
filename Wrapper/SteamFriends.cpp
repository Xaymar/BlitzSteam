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

DLL_FUNCTION(ISteamFriends*) BS_Friends() {
#pragma comment(linker, "/EXPORT:BS_Friends=_BS_Friends@0")
	return SteamFriends();
}

DLL_FUNCTION(const char*) BS_Friends_GetPersonaName(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetPersonaName=_BS_Friends_GetPersonaName@4")
	return lpSteamFriends->GetPersonaName();
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_SetPersonaName(ISteamFriends* lpSteamFriends, const char* pchPersonaName) {
#pragma comment(linker, "/EXPORT:BS_Friends_SetPersonaName=_BS_Friends_SetPersonaName@8")
	return new uint64_t(lpSteamFriends->SetPersonaName(pchPersonaName));
}

DLL_FUNCTION(int32_t) BS_Friends_GetPersonaState(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetPersonaState=_BS_Friends_GetPersonaState@4")
	return lpSteamFriends->GetPersonaState();
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendCount(ISteamFriends* lpSteamFriends, int32_t iFriendFlags) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCount=_BS_Friends_GetFriendCount@8")
	return lpSteamFriends->GetFriendCount(iFriendFlags);
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetFriendByIndex(ISteamFriends* lpSteamFriends, int32_t iFriend, int32_t iFriendFlags) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendByIndex=_BS_Friends_GetFriendByIndex@12")
	return new CSteamID(lpSteamFriends->GetFriendByIndex(iFriend, iFriendFlags));
}

DLL_FUNCTION(EFriendRelationship) BS_Friends_GetFriendRelationship(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRelationship=_BS_Friends_GetFriendRelationship@8")
	return lpSteamFriends->GetFriendRelationship(*steamIDFriend);
}

DLL_FUNCTION(EPersonaState) BS_Friends_GetFriendPersonaState(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaState=_BS_Friends_GetFriendPersonaState@8")
	return lpSteamFriends->GetFriendPersonaState(*steamIDFriend);
}

DLL_FUNCTION(const char*) BS_Friends_GetFriendPersonaName(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaName=_BS_Friends_GetFriendPersonaName@8")
	return lpSteamFriends->GetFriendPersonaName(*steamIDFriend);
}

DLL_FUNCTION(uint32_t) BS_Friends_GetFriendGamePlayed(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, FriendGameInfo_t *pFriendGameInfo) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendGamePlayed=_BS_Friends_GetFriendGamePlayed@12")
	return lpSteamFriends->GetFriendGamePlayed(*steamIDFriend, pFriendGameInfo);
}

DLL_FUNCTION(const char*) BS_Friends_GetFriendPersonaNameHistory(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iPersonaName) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaNameHistory=_BS_Friends_GetFriendPersonaNameHistory@12")
	return lpSteamFriends->GetFriendPersonaNameHistory(*steamIDFriend, iPersonaName);
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendSteamLevel(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendSteamLevel=_BS_Friends_GetFriendSteamLevel@8")
	return lpSteamFriends->GetFriendSteamLevel(*steamIDFriend);
}

DLL_FUNCTION(const char*) BS_Friends_GetPlayerNickname(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetPlayerNickname=_BS_Friends_GetPlayerNickname@8")
	const char* nickname = lpSteamFriends->GetPlayerNickname(*steamIDFriends);
	if (nickname == NULL) {
		nickname = "";
	}
	return nickname;
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendsGroupCount(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupCount=_BS_Friends_GetFriendsGroupCount@4")
	return lpSteamFriends->GetFriendsGroupCount();
}

DLL_FUNCTION(FriendsGroupID_t) BS_Friends_GetFriendsGroupIDByIndex(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupIDByIndex=_BS_Friends_GetFriendsGroupIDByIndex@8")
	return lpSteamFriends->GetFriendsGroupIDByIndex(friendsGroupID);
}

DLL_FUNCTION(const char*) BS_Friends_GetFriendsGroupName(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupName=_BS_Friends_GetFriendsGroupName@8")
	return lpSteamFriends->GetFriendsGroupName(friendsGroupID);
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendsGroupMembersCount(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupMembersCount=_BS_Friends_GetFriendsGroupMembersCount@8")
	return lpSteamFriends->GetFriendsGroupMembersCount(friendsGroupID);
}

DLL_FUNCTION(void) BS_Friends_GetFriendsGroupMembersList(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int32_t nMembersCount) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupMembersList=_BS_Friends_GetFriendsGroupMembersList@16")
	lpSteamFriends->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}

DLL_FUNCTION(uint32_t) BS_Friends_HasFriend(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iFriendsFlags) {
#pragma comment(linker, "/EXPORT:BS_Friends_HasFriends=_BS_Friends_HasFriend@12")
	return lpSteamFriends->HasFriend(*steamIDFriend, iFriendsFlags);
}

DLL_FUNCTION(int32_t) BS_Friends_GetClanCount(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanCount=_BS_Friends_GetClanCount@4")
	return lpSteamFriends->GetClanCount();
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetClanByIndex(ISteamFriends* lpSteamFriends, int32_t iClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanByIndex=_BS_Friends_GetClanByIndex@8")
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetClanByIndex(iClan));
	return steamID;
}

DLL_FUNCTION(const char*) BS_Friends_GetClanName(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanName=_BS_Friends_GetClanName@8")
	return lpSteamFriends->GetClanName(*steamIDClan);
}

DLL_FUNCTION(const char*) BS_Friends_GetClanTag(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanTag=_BS_Friends_GetClanTag@8")
	return lpSteamFriends->GetClanTag(*steamIDClan);
}

DLL_FUNCTION(uint32_t) BS_Friends_GetClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t* pnOnline, int32_t* pnInGame, int32_t* pnChatting) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanActivityCounts=_BS_Friends_GetClanActivityCounts@20")
	return lpSteamFriends->GetClanActivityCounts(*steamIDClan, pnOnline, pnInGame, pnChatting);
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_DownloadClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* psteamIDClans, int32_t cClansToRequest) {
#pragma comment(linker, "/EXPORT:BS_Friends_DownloadClanActivityCounts=_BS_Friends_DownloadClanActivityCounts@12")
	return new uint64_t(lpSteamFriends->DownloadClanActivityCounts(psteamIDClans, cClansToRequest));
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendCountFromSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCountFromSource=_BS_Friends_GetFriendCountFromSource@8")
	return lpSteamFriends->GetFriendCountFromSource(*steamIDSource);
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetFriendFromSourceByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource, int32_t iFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendFromSourceByIndex=_BS_Friends_GetFriendFromSourceByIndex@12")
	return new CSteamID(lpSteamFriends->GetFriendFromSourceByIndex(*steamIDSource, iFriend));
}

DLL_FUNCTION(uint32_t) BS_Friends_IsUserInSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, CSteamID* steamIDSource) {
#pragma comment(linker, "/EXPORT:BS_Friends_IsUserInSource=_BS_Friends_IsUserInSource@12")
	return lpSteamFriends->IsUserInSource(*steamIDUser, *steamIDSource);
}

DLL_FUNCTION(void) BS_Friends_SetInGameVoiceSpeaking(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, uint32_t bSpeaking) {
#pragma comment(linker, "/EXPORT:BS_Friends_SetInGameVoiceSpeaking=_BS_Friends_SetInGameVoiceSpeaking@12")
	lpSteamFriends->SetInGameVoiceSpeaking(*steamIDUser, bSpeaking != 0);
}

DLL_FUNCTION(void) BS_Friends_ActivateGameOverlay(ISteamFriends* lpSteamFriends, const char* pchDialog) {
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlay=_BS_Friends_ActivateGameOverlay@8")
	lpSteamFriends->ActivateGameOverlay(pchDialog);
}

DLL_FUNCTION(void) BS_Friends_ActivateGameOverlayToUser(ISteamFriends* lpSteamFriends, const char* pchDialog, CSteamID* steamID) {
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToUser=_BS_Friends_ActivateGameOverlayToUser@12")
	lpSteamFriends->ActivateGameOverlayToUser(pchDialog, *steamID);
}

DLL_FUNCTION(void) BS_Friends_ActivateGameOverlayToWebPage(ISteamFriends* lpSteamFriends, const char* pchURL) {
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToWebPage=_BS_Friends_ActivateGameOverlayToWebPage@8")
	lpSteamFriends->ActivateGameOverlayToWebPage(pchURL);
}

DLL_FUNCTION(void) BS_Friends_ActivateGameOverlayToStore(ISteamFriends* lpSteamFriends, AppId_t nAppID, EOverlayToStoreFlag eFlag) {
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToStore=_BS_Friends_ActivateGameOverlayToStore@12")
	lpSteamFriends->ActivateGameOverlayToStore(nAppID, eFlag);
}

DLL_FUNCTION(void) BS_Friends_SetPlayedWith(ISteamFriends* lpSteamFriends, CSteamID* steamIDUserPlayedWith) {
#pragma comment(linker, "/EXPORT:BS_Friends_SetPlayedWith=_BS_Friends_SetPlayedWith@8")
	lpSteamFriends->SetPlayedWith(*steamIDUserPlayedWith);
}

DLL_FUNCTION(void) BS_Friends_ActivateGameOverlayInviteDialog(ISteamFriends* lpSteamFriends, CSteamID* steamIDLobby) {
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayInviteDialog=_BS_Friends_ActivateGameOverlayInviteDialog@8")
	lpSteamFriends->ActivateGameOverlayInviteDialog(*steamIDLobby);
}

DLL_FUNCTION(int32_t) BS_Friends_GetSmallFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetSmallFriendAvatar=_BS_Friends_GetSmallFriendAvatar@8")
	return lpSteamFriends->GetSmallFriendAvatar(*steamIDFriend);
}

DLL_FUNCTION(int32_t) BS_Friends_GetMediumFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetMediumFriendAvatar=_BS_Friends_GetMediumFriendAvatar@8")
	return lpSteamFriends->GetMediumFriendAvatar(*steamIDFriend);
}

DLL_FUNCTION(int32_t) BS_Friends_GetLargeFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetLargeFriendAvatar=_BS_Friends_GetLargeFriendAvatar@8")
	return lpSteamFriends->GetLargeFriendAvatar(*steamIDFriend);
}

DLL_FUNCTION(uint32_t) BS_Friends_RequestUserInformation(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, uint32_t bRequireNameOnly) {
#pragma comment(linker, "/EXPORT:BS_Friends_RequestUserInformation=_BS_Friends_RequestUserInformation@12")
	return lpSteamFriends->RequestUserInformation(*steamIDUser, bRequireNameOnly != 0);
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_RequestClanOfficerList(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_RequestClanOfficerList=_BS_Friends_RequestClanOfficerList@8")
	return new uint64_t(lpSteamFriends->RequestClanOfficerList(*steamIDClan));
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetClanOwner(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOwner=_BS_Friends_GetClanOwner@8")
	return new CSteamID(lpSteamFriends->GetClanOwner(*steamIDClan));
}

DLL_FUNCTION(int32_t) BS_Friends_GetClanOfficerCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOfficerCount=_BS_Friends_GetClanOfficerCount@8")
	return lpSteamFriends->GetClanOfficerCount(*steamIDClan);
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetClanOfficerByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iOfficer) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOfficerByIndex=_BS_Friends_GetClanOfficerByIndex@12")
	return new CSteamID(lpSteamFriends->GetClanOfficerByIndex(*steamIDClan, iOfficer));
}

DLL_FUNCTION(EUserRestriction) BS_Friends_GetUserRestrictions(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetUserRestrictions=_BS_Friends_GetUserRestrictions@4")
	return (EUserRestriction)lpSteamFriends->GetUserRestrictions();
}

DLL_FUNCTION(uint32_t) BS_Friends_SetRichPresence(ISteamFriends* lpSteamFriends, const char* pchKey, const char* pchValue) {
#pragma comment(linker, "/EXPORT:BS_Friends_SetRichPresence=_BS_Friends_SetRichPresence@12")
	return lpSteamFriends->SetRichPresence(pchKey, pchValue);
}

DLL_FUNCTION(void) BS_Friends_ClearRichPresence(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_ClearRichPresence=_BS_Friends_ClearRichPresence@4")
	lpSteamFriends->ClearRichPresence();
}

DLL_FUNCTION(const char*) BS_Friends_GetFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchKey) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresence=_BS_Friends_GetFriendRichPresence@12")
	return lpSteamFriends->GetFriendRichPresence(*steamIDFriend, pchKey);
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendRichPresenceKeyCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresenceKeyCount=_BS_Friends_GetFriendRichPresenceKeyCount@8")
	return lpSteamFriends->GetFriendRichPresenceKeyCount(*steamIDFriend);
}

DLL_FUNCTION(const char*) BS_Friends_GetFriendRichPresenceKeyByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iKey) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresenceKeyByIndex=_BS_Friends_GetFriendRichPresenceKeyByIndex@12")
	return lpSteamFriends->GetFriendRichPresenceKeyByIndex(*steamIDFriend, iKey);
}

DLL_FUNCTION(void) BS_Friends_RequestFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_RequestFriendRichPresence=_BS_Friends_RequestFriendRichPresence@8")
	lpSteamFriends->RequestFriendRichPresence(*steamIDFriend);
}

DLL_FUNCTION(uint32_t) BS_Friends_InviteUserToGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char *pchConnectString) {
#pragma comment(linker, "/EXPORT:BS_Friends_InviteUserToGame=_BS_Friends_InviteUserToGame@12")
	return lpSteamFriends->InviteUserToGame(*steamIDFriend, pchConnectString);
}

DLL_FUNCTION(int32_t) BS_Friends_GetCoplayFriendCount(ISteamFriends* lpSteamFriends) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetCoplayFriendCount=_BS_Friends_GetCoplayFriendCount@4")
	return lpSteamFriends->GetCoplayFriendCount();
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetCoplayFriend(ISteamFriends* lpSteamFriends, int32_t iCoplayFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetCoplayFriend=_BS_Friends_GetCoplayFriend@8")
	return new CSteamID(lpSteamFriends->GetCoplayFriend(iCoplayFriend));
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendCoplayTime(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCoplayTime=_BS_Friends_GetFriendCoplayTime@8")
	return lpSteamFriends->GetFriendCoplayTime(*steamIDFriend);
}

DLL_FUNCTION(AppId_t) BS_Friends_GetFriendCoplayGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCoplayGame=_BS_Friends_GetFriendCoplayGame@8")
	return lpSteamFriends->GetFriendCoplayGame(*steamIDFriend);
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_JoinClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_JoinClanChatRoom=_BS_Friends_JoinClanChatRoom@8")
	return new SteamAPICall_t(lpSteamFriends->JoinClanChatRoom(*steamIDClan));
}

DLL_FUNCTION(uint32_t) BS_Friends_LeaveClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_LeaveClanChatRoom=_BS_Friends_LeaveClanChatRoom@8")
	return lpSteamFriends->LeaveClanChatRoom(*steamIDClan);
}

DLL_FUNCTION(int32_t) BS_Friends_GetClanChatMemberCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanChatMemberCount=_BS_Friends_GetClanChatMemberCount@8")
	return lpSteamFriends->GetClanChatMemberCount(*steamIDClan);
}

DLL_FUNCTION(CSteamID*) BS_Friends_GetChatMemberByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iUser) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetChatMemberByIndex=_BS_Friends_GetChatMemberByIndex@12")
	return new CSteamID(lpSteamFriends->GetChatMemberByIndex(*steamIDClan, iUser));
}

DLL_FUNCTION(uint32_t) BS_Friends_SendClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, const char *pchText) {
#pragma comment(linker, "/EXPORT:BS_Friends_SendClanChatMessage=_BS_Friends_SendClanChatMessage@12")
	return lpSteamFriends->SendClanChatMessage(*steamIDClanChat, pchText);
}

DLL_FUNCTION(int32_t) BS_Friends_GetClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, int32_t iMessage, void* prgchText, int32_t cchTextMax, EChatEntryType* peChatEntryType, CSteamID* psteamidChatter) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanChatMessage=_BS_Friends_GetClanChatMessage@28")
	return lpSteamFriends->GetClanChatMessage(*steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}

DLL_FUNCTION(uint32_t) BS_Friends_IsClanChatAdmin(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, CSteamID* steamIDUser) {
#pragma comment(linker, "/EXPORT:BS_Friends_IsClanChatAdmin=_BS_Friends_IsClanChatAdmin@12")
	return lpSteamFriends->IsClanChatAdmin(*steamIDClanChat, *steamIDUser);
}

DLL_FUNCTION(uint32_t) BS_Friends_IsClanChatWindowOpenInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
#pragma comment(linker, "/EXPORT:BS_Friends_IsClanChatWindowOpenInSteam=_BS_Friends_IsClanChatWindowOpenInSteam@8")
	return lpSteamFriends->IsClanChatWindowOpenInSteam(*steamIDClanChat);
}

DLL_FUNCTION(uint32_t) BS_Friends_OpenClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
#pragma comment(linker, "/EXPORT:BS_Friends_OpenClanChatWindowInSteam=_BS_Friends_OpenClanChatWindowInSteam@8")
	return lpSteamFriends->OpenClanChatWindowInSteam(*steamIDClanChat);
}

DLL_FUNCTION(uint32_t) BS_Friends_CloseClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
#pragma comment(linker, "/EXPORT:BS_Friends_CloseClanChatWindowInSteam=_BS_Friends_CloseClanChatWindowInSteam@8")
	return lpSteamFriends->CloseClanChatWindowInSteam(*steamIDClanChat);
}

DLL_FUNCTION(uint32_t) BS_Friends_SetListenForFriendsMessages(ISteamFriends* lpSteamFriends, uint32_t bInterceptEnabled) {
#pragma comment(linker, "/EXPORT:BS_Friends_SetListenForFriendsMessages=_BS_Friends_SetListenForFriendsMessages@8")
	return lpSteamFriends->SetListenForFriendsMessages(bInterceptEnabled != 0);
}

DLL_FUNCTION(uint32_t) BS_Friends_ReplyToFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchMsgToSend) {
#pragma comment(linker, "/EXPORT:BS_Friends_ReplyToFriendMessage=_BS_Friends_ReplyToFriendMessage@12")
	return lpSteamFriends->ReplyToFriendMessage(*steamIDFriend, pchMsgToSend);
}

DLL_FUNCTION(int32_t) BS_Friends_GetFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iMessageID, void* pvData, int32_t cubData, EChatEntryType* peChatEntryType) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendMessage=_BS_Friends_GetFriendMessage@24")
	return lpSteamFriends->GetFriendMessage(*steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_GetFollowerCount(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
#pragma comment(linker, "/EXPORT:BS_Friends_GetFollowerCount=_BS_Friends_GetFollowerCount@8")
	return new SteamAPICall_t(lpSteamFriends->GetFollowerCount(*steamID));
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_IsFollowing(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
#pragma comment(linker, "/EXPORT:BS_Friends_IsFollowing=_BS_Friends_IsFollowing@8")
	return new SteamAPICall_t(lpSteamFriends->IsFollowing(*steamID));
}

DLL_FUNCTION(SteamAPICall_t*) BS_Friends_EnumerateFollowingList(ISteamFriends* lpSteamFriends, uint32_t unStartIndex) {
#pragma comment(linker, "/EXPORT:BS_Friends_EnumerateFollowingList=_BS_Friends_EnumerateFollowingList@8")
	return new SteamAPICall_t(lpSteamFriends->EnumerateFollowingList(unStartIndex));
}
