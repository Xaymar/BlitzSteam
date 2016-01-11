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

DLL_EXPORT const char* DLL_CALL BS_Friends_GetPersonaName(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaName();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetPersonaName=_BS_Friends_GetPersonaName@4")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_SetPersonaName(ISteamFriends* lpSteamFriends, const char* pchPersonaName) {
	return lpSteamFriends->SetPersonaName(pchPersonaName);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SetPersonaName=_BS_Friends_SetPersonaName@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetPersonaState(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaState();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetPersonaState=_BS_Friends_GetPersonaState@4")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendCount(ISteamFriends* lpSteamFriends, int32_t iFriendFlags) {
	return lpSteamFriends->GetFriendCount(iFriendFlags);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCount=_BS_Friends_GetFriendCount@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetFriendByIndex(ISteamFriends* lpSteamFriends, int32_t iFriend, int32_t iFriendFlags) {
	CSteamID* pSteamID = new CSteamID(lpSteamFriends->GetFriendByIndex(iFriend, iFriendFlags));
	return pSteamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendByIndex=_BS_Friends_GetFriendByIndex@12")

DLL_EXPORT EFriendRelationship DLL_CALL BS_Friends_GetFriendRelationship(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRelationship(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRelationship=_BS_Friends_GetFriendRelationship@8")

DLL_EXPORT EPersonaState DLL_CALL BS_Friends_GetFriendPersonaState(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaState(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaState=_BS_Friends_GetFriendPersonaState@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetFriendPersonaName(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaName(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaName=_BS_Friends_GetFriendPersonaName@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_GetFriendGamePlayed(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, FriendGameInfo_t *pFriendGameInfo) {
	return lpSteamFriends->GetFriendGamePlayed(*steamIDFriend, pFriendGameInfo);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendGamePlayed=_BS_Friends_GetFriendGamePlayed@12")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetFriendPersonaNameHistory(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iPersonaName) {
	return lpSteamFriends->GetFriendPersonaNameHistory(*steamIDFriend, iPersonaName);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendPersonaNameHistory=_BS_Friends_GetFriendPersonaNameHistory@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendSteamLevel(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendSteamLevel(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendSteamLevel=_BS_Friends_GetFriendSteamLevel@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetPlayerNickname(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriends) {
	const char* nickname = lpSteamFriends->GetPlayerNickname(*steamIDFriends);
	if (nickname == NULL) {
		nickname = "";
	}
	return nickname;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetPlayerNickname=_BS_Friends_GetPlayerNickname@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendsGroupCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetFriendsGroupCount();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupCount=_BS_Friends_GetFriendsGroupCount@4")

DLL_EXPORT FriendsGroupID_t DLL_CALL BS_Friends_GetFriendsGroupIDByIndex(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupIDByIndex(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupIDByIndex=_BS_Friends_GetFriendsGroupIDByIndex@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetFriendsGroupName(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupName(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupName=_BS_Friends_GetFriendsGroupName@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendsGroupMembersCount(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupMembersCount(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupMembersCount=_BS_Friends_GetFriendsGroupMembersCount@8")

DLL_EXPORT void DLL_CALL BS_Friends_GetFriendsGroupMembersList(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int32_t nMembersCount) {
	lpSteamFriends->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendsGroupMembersList=_BS_Friends_GetFriendsGroupMembersList@16")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_HasFriend(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iFriendsFlags) {
	return lpSteamFriends->HasFriend(*steamIDFriend, iFriendsFlags);
}
#pragma comment(linker, "/EXPORT:BS_Friends_HasFriends=_BS_Friends_HasFriend@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetClanCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetClanCount();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanCount=_BS_Friends_GetClanCount@4")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetClanByIndex(ISteamFriends* lpSteamFriends, int32_t iClan) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetClanByIndex(iClan));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanByIndex=_BS_Friends_GetClanByIndex@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetClanName(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanName(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanName=_BS_Friends_GetClanName@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetClanTag(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanTag(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanTag=_BS_Friends_GetClanTag@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_GetClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t* pnOnline, int32_t* pnInGame, int32_t* pnChatting) {
	return lpSteamFriends->GetClanActivityCounts(*steamIDClan, pnOnline, pnInGame, pnChatting);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanActivityCounts=_BS_Friends_GetClanActivityCounts@20")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_DownloadClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* psteamIDClans, int32_t cClansToRequest) {
	return lpSteamFriends->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
}
#pragma comment(linker, "/EXPORT:BS_Friends_DownloadClanActivityCounts=_BS_Friends_DownloadClanActivityCounts@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendCountFromSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource) {
	return lpSteamFriends->GetFriendCountFromSource(*steamIDSource);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCountFromSource=_BS_Friends_GetFriendCountFromSource@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetFriendFromSourceByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource, int32_t iFriend) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetFriendFromSourceByIndex(*steamIDSource, iFriend));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendFromSourceByIndex=_BS_Friends_GetFriendFromSourceByIndex@12")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_IsUserInSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, CSteamID* steamIDSource) {
	return lpSteamFriends->IsUserInSource(*steamIDUser, *steamIDSource);
}
#pragma comment(linker, "/EXPORT:BS_Friends_IsUserInSource=_BS_Friends_IsUserInSource@12")

DLL_EXPORT void DLL_CALL BS_Friends_SetInGameVoiceSpeaking(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, bool bSpeaking) {
	lpSteamFriends->SetInGameVoiceSpeaking(*steamIDUser, bSpeaking);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SetInGameVoiceSpeaking=_BS_Friends_SetInGameVoiceSpeaking@12")

DLL_EXPORT void DLL_CALL BS_Friends_ActivateGameOverlay(ISteamFriends* lpSteamFriends, const char* pchDialog) {
	lpSteamFriends->ActivateGameOverlay(pchDialog);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlay=_BS_Friends_ActivateGameOverlay@8")

DLL_EXPORT void DLL_CALL BS_Friends_ActivateGameOverlayToUser(ISteamFriends* lpSteamFriends, const char* pchDialog, CSteamID* steamID) {
	lpSteamFriends->ActivateGameOverlayToUser(pchDialog, *steamID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToUser=_BS_Friends_ActivateGameOverlayToUser@12")

DLL_EXPORT void DLL_CALL BS_Friends_ActivateGameOverlayToWebPage(ISteamFriends* lpSteamFriends, const char* pchURL) {
	lpSteamFriends->ActivateGameOverlayToWebPage(pchURL);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToWebPage=_BS_Friends_ActivateGameOverlayToWebPage@8")

DLL_EXPORT void DLL_CALL BS_Friends_ActivateGameOverlayToStore(ISteamFriends* lpSteamFriends, AppId_t nAppID, EOverlayToStoreFlag eFlag) {
	lpSteamFriends->ActivateGameOverlayToStore(nAppID, eFlag);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayToStore=_BS_Friends_ActivateGameOverlayToStore@12")

DLL_EXPORT void DLL_CALL BS_Friends_SetPlayedWith(ISteamFriends* lpSteamFriends, CSteamID* steamIDUserPlayedWith) {
	lpSteamFriends->SetPlayedWith(*steamIDUserPlayedWith);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SetPlayedWith=_BS_Friends_SetPlayedWith@8")

DLL_EXPORT void DLL_CALL BS_Friends_ActivateGameOverlayInviteDialog(ISteamFriends* lpSteamFriends, CSteamID* steamIDLobby) {
	lpSteamFriends->ActivateGameOverlayInviteDialog(*steamIDLobby);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ActivateGameOverlayInviteDialog=_BS_Friends_ActivateGameOverlayInviteDialog@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetSmallFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetSmallFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetSmallFriendAvatar=_BS_Friends_GetSmallFriendAvatar@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetMediumFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetMediumFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetMediumFriendAvatar=_BS_Friends_GetMediumFriendAvatar@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetLargeFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetLargeFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetLargeFriendAvatar=_BS_Friends_GetLargeFriendAvatar@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_RequestUserInformation(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, bool bRequireNameOnly) {
	return lpSteamFriends->RequestUserInformation(*steamIDUser, bRequireNameOnly);
}
#pragma comment(linker, "/EXPORT:BS_Friends_RequestUserInformation=_BS_Friends_RequestUserInformation@12")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_RequestClanOfficerList(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->RequestClanOfficerList(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_RequestClanOfficerList=_BS_Friends_RequestClanOfficerList@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetClanOwner(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetClanOwner(*steamIDClan));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOwner=_BS_Friends_GetClanOwner@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetClanOfficerCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanOfficerCount(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOfficerCount=_BS_Friends_GetClanOfficerCount@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetClanOfficerByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iOfficer) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetClanOfficerByIndex(*steamIDClan, iOfficer));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanOfficerByIndex=_BS_Friends_GetClanOfficerByIndex@12")

DLL_EXPORT EUserRestriction DLL_CALL BS_Friends_GetUserRestrictions(ISteamFriends* lpSteamFriends) {
	return (EUserRestriction)lpSteamFriends->GetUserRestrictions();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetUserRestrictions=_BS_Friends_GetUserRestrictions@4")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_SetRichPresence(ISteamFriends* lpSteamFriends, const char* pchKey, const char* pchValue) {
	return lpSteamFriends->SetRichPresence(pchKey, pchValue);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SetRichPresence=_BS_Friends_SetRichPresence@12")

DLL_EXPORT void DLL_CALL BS_Friends_ClearRichPresence(ISteamFriends* lpSteamFriends) {
	lpSteamFriends->ClearRichPresence();
}
#pragma comment(linker, "/EXPORT:BS_Friends_ClearRichPresence=_BS_Friends_ClearRichPresence@4")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchKey) {
	return lpSteamFriends->GetFriendRichPresence(*steamIDFriend, pchKey);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresence=_BS_Friends_GetFriendRichPresence@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendRichPresenceKeyCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRichPresenceKeyCount(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresenceKeyCount=_BS_Friends_GetFriendRichPresenceKeyCount@8")

DLL_EXPORT const char* DLL_CALL BS_Friends_GetFriendRichPresenceKeyByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iKey) {
	return lpSteamFriends->GetFriendRichPresenceKeyByIndex(*steamIDFriend, iKey);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendRichPresenceKeyByIndex=_BS_Friends_GetFriendRichPresenceKeyByIndex@12")

DLL_EXPORT void DLL_CALL BS_Friends_RequestFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	lpSteamFriends->RequestFriendRichPresence(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_RequestFriendRichPresence=_BS_Friends_RequestFriendRichPresence@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_InviteUserToGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char *pchConnectString) {
	return lpSteamFriends->InviteUserToGame(*steamIDFriend, pchConnectString);
}
#pragma comment(linker, "/EXPORT:BS_Friends_InviteUserToGame=_BS_Friends_InviteUserToGame@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetCoplayFriendCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetCoplayFriendCount();
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetCoplayFriendCount=_BS_Friends_GetCoplayFriendCount@4")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetCoplayFriend(ISteamFriends* lpSteamFriends, int32_t iCoplayFriend) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetCoplayFriend(iCoplayFriend));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetCoplayFriend=_BS_Friends_GetCoplayFriend@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendCoplayTime(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayTime(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCoplayTime=_BS_Friends_GetFriendCoplayTime@8")

DLL_EXPORT AppId_t DLL_CALL BS_Friends_GetFriendCoplayGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayGame(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendCoplayGame=_BS_Friends_GetFriendCoplayGame@8")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_JoinClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->JoinClanChatRoom(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_JoinClanChatRoom=_BS_Friends_JoinClanChatRoom@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_LeaveClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->LeaveClanChatRoom(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_LeaveClanChatRoom=_BS_Friends_LeaveClanChatRoom@8")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetClanChatMemberCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanChatMemberCount(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanChatMemberCount=_BS_Friends_GetClanChatMemberCount@8")

DLL_EXPORT CSteamID* DLL_CALL BS_Friends_GetChatMemberByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iUser) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetChatMemberByIndex(*steamIDClan, iUser));
	return steamID;
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetChatMemberByIndex=_BS_Friends_GetChatMemberByIndex@12")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_SendClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, const char *pchText) {
	return lpSteamFriends->SendClanChatMessage(*steamIDClanChat, pchText);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SendClanChatMessage=_BS_Friends_SendClanChatMessage@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, int32_t iMessage, void* prgchText, int32_t cchTextMax, EChatEntryType* peChatEntryType, CSteamID* psteamidChatter) {
	return lpSteamFriends->GetClanChatMessage(*steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetClanChatMessage=_BS_Friends_GetClanChatMessage@28")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_IsClanChatAdmin(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, CSteamID* steamIDUser) {
	return lpSteamFriends->IsClanChatAdmin(*steamIDClanChat, *steamIDUser);
}
#pragma comment(linker, "/EXPORT:BS_Friends_IsClanChatAdmin=_BS_Friends_IsClanChatAdmin@12")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_IsClanChatWindowOpenInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->IsClanChatWindowOpenInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BS_Friends_IsClanChatWindowOpenInSteam=_BS_Friends_IsClanChatWindowOpenInSteam@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_OpenClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->OpenClanChatWindowInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BS_Friends_OpenClanChatWindowInSteam=_BS_Friends_OpenClanChatWindowInSteam@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_CloseClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->CloseClanChatWindowInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BS_Friends_CloseClanChatWindowInSteam=_BS_Friends_CloseClanChatWindowInSteam@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_SetListenForFriendsMessages(ISteamFriends* lpSteamFriends, bool bInterceptEnabled) {
	return lpSteamFriends->SetListenForFriendsMessages(bInterceptEnabled);
}
#pragma comment(linker, "/EXPORT:BS_Friends_SetListenForFriendsMessages=_BS_Friends_SetListenForFriendsMessages@8")

DLL_EXPORT uint32_t DLL_CALL BS_Friends_ReplyToFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchMsgToSend) {
	return lpSteamFriends->ReplyToFriendMessage(*steamIDFriend, pchMsgToSend);
}
#pragma comment(linker, "/EXPORT:BS_Friends_ReplyToFriendMessage=_BS_Friends_ReplyToFriendMessage@12")

DLL_EXPORT int32_t DLL_CALL BS_Friends_GetFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iMessageID, void* pvData, int32_t cubData, EChatEntryType* peChatEntryType) {
	return lpSteamFriends->GetFriendMessage(*steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFriendMessage=_BS_Friends_GetFriendMessage@24")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_GetFollowerCount(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return lpSteamFriends->GetFollowerCount(*steamID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_GetFollowerCount=_BS_Friends_GetFollowerCount@8")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_IsFollowing(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return lpSteamFriends->IsFollowing(*steamID);
}
#pragma comment(linker, "/EXPORT:BS_Friends_IsFollowing=_BS_Friends_IsFollowing@8")

DLL_EXPORT SteamAPICall_t DLL_CALL BS_Friends_EnumerateFollowingList(ISteamFriends* lpSteamFriends, uint32 unStartIndex) {
	return lpSteamFriends->EnumerateFollowingList(unStartIndex);
}
#pragma comment(linker, "/EXPORT:BS_Friends_EnumerateFollowingList=_BS_Friends_EnumerateFollowingList@8")
