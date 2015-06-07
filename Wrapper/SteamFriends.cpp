//	BlitzSteam - Steam wrapper for Blitz.
//	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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

DLL_EXPORT const char* BlitzSteamFriends_GetPersonaName(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaName();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetPersonaName=_BlitzSteamFriends_GetPersonaName@4")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_SetPersonaName(ISteamFriends* lpSteamFriends, const char* pchPersonaName) {
	return lpSteamFriends->SetPersonaName(pchPersonaName);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SetPersonaName=_BlitzSteamFriends_SetPersonaName@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetPersonaState(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaState();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetPersonaState=_BlitzSteamFriends_GetPersonaState@4")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendCount(ISteamFriends* lpSteamFriends, int32_t iFriendFlags) {
	return lpSteamFriends->GetFriendCount(iFriendFlags);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendCount=_BlitzSteamFriends_GetFriendCount@8")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetFriendByIndex(ISteamFriends* lpSteamFriends, int32_t iFriend, int32_t iFriendFlags) {
	CSteamID* pSteamID = new CSteamID(lpSteamFriends->GetFriendByIndex(iFriend, iFriendFlags));
	return pSteamID;
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendByIndex=_BlitzSteamFriends_GetFriendByIndex@12")

DLL_EXPORT EFriendRelationship BlitzSteamFriends_GetFriendRelationship(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRelationship(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendRelationship=_BlitzSteamFriends_GetFriendRelationship@8")

DLL_EXPORT EPersonaState BlitzSteamFriends_GetFriendPersonaState(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaState(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendPersonaState=_BlitzSteamFriends_GetFriendPersonaState@8")

DLL_EXPORT const char* BlitzSteamFriends_GetFriendPersonaName(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaName(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendPersonaName=_BlitzSteamFriends_GetFriendPersonaName@8")

DLL_EXPORT uint32_t BlitzSteamFriends_GetFriendGamePlayed(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, FriendGameInfo_t *pFriendGameInfo) {
	return lpSteamFriends->GetFriendGamePlayed(*steamIDFriend, pFriendGameInfo);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendGamePlayed=_BlitzSteamFriends_GetFriendGamePlayed@12")

DLL_EXPORT const char* BlitzSteamFriends_GetFriendPersonaNameHistory(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iPersonaName) {
	return lpSteamFriends->GetFriendPersonaNameHistory(*steamIDFriend, iPersonaName);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendPersonaNameHistory=_BlitzSteamFriends_GetFriendPersonaNameHistory@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendSteamLevel(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendSteamLevel(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendSteamLevel=_BlitzSteamFriends_GetFriendSteamLevel@8")

DLL_EXPORT const char* BlitzSteamFriends_GetPlayerNickname(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriends) {
	const char* nickname = lpSteamFriends->GetPlayerNickname(*steamIDFriends);
	if (nickname == NULL) {
		nickname = "";
	}
	return nickname;
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetPlayerNickname=_BlitzSteamFriends_GetPlayerNickname@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendsGroupCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetFriendsGroupCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendsGroupCount=_BlitzSteamFriends_GetFriendsGroupCount@4")

DLL_EXPORT FriendsGroupID_t BlitzSteamFriends_GetFriendsGroupIDByIndex(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupIDByIndex(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendsGroupIDByIndex=_BlitzSteamFriends_GetFriendsGroupIDByIndex@8")

DLL_EXPORT const char* BlitzSteamFriends_GetFriendsGroupName(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupName(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendsGroupName=_BlitzSteamFriends_GetFriendsGroupName@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendsGroupMembersCount(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupMembersCount(friendsGroupID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendsGroupMembersCount=_BlitzSteamFriends_GetFriendsGroupMembersCount@8")

DLL_EXPORT void BlitzSteamFriends_GetFriendsGroupMembersList(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int32_t nMembersCount) {
	lpSteamFriends->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendsGroupMembersList=_BlitzSteamFriends_GetFriendsGroupMembersList@16")

DLL_EXPORT uint32_t BlitzSteamFriends_HasFriend(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iFriendsFlags) {
	return lpSteamFriends->HasFriend(*steamIDFriend, iFriendsFlags);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_HasFriends=_BlitzSteamFriends_HasFriend@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetClanCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetClanCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanCount=_BlitzSteamFriends_GetClanCount@4")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetClanByIndex(ISteamFriends* lpSteamFriends, int32_t iClan) {
	return new CSteamID(lpSteamFriends->GetClanByIndex(iClan));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanByIndex=_BlitzSteamFriends_GetClanByIndex@8")

DLL_EXPORT const char* BlitzSteamFriends_GetClanName(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanName(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanName=_BlitzSteamFriends_GetClanName@8")

DLL_EXPORT const char* BlitzSteamFriends_GetClanTag(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanTag(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanTag=_BlitzSteamFriends_GetClanTag@8")

DLL_EXPORT uint32_t BlitzSteamFriends_GetClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t* pnOnline, int32_t* pnInGame, int32_t* pnChatting) {
	return lpSteamFriends->GetClanActivityCounts(*steamIDClan, pnOnline, pnInGame, pnChatting);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanActivityCounts=_BlitzSteamFriends_GetClanActivityCounts@20")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_DownloadClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* psteamIDClans, int32_t cClansToRequest) {
	return lpSteamFriends->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_DownloadClanActivityCounts=_BlitzSteamFriends_DownloadClanActivityCounts@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendCountFromSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource) {
	return lpSteamFriends->GetFriendCountFromSource(*steamIDSource);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendCountFromSource=_BlitzSteamFriends_GetFriendCountFromSource@8")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetFriendFromSourceByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource, int32_t iFriend) {
	return new CSteamID(lpSteamFriends->GetFriendFromSourceByIndex(*steamIDSource, iFriend));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendFromSourceByIndex=_BlitzSteamFriends_GetFriendFromSourceByIndex@12")

DLL_EXPORT uint32_t BlitzSteamFriends_IsUserInSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, CSteamID* steamIDSource) {
	return lpSteamFriends->IsUserInSource(*steamIDUser, *steamIDSource);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_IsUserInSource=_BlitzSteamFriends_IsUserInSource@12")

DLL_EXPORT void BlitzSteamFriends_SetInGameVoiceSpeaking(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, bool bSpeaking) {
	lpSteamFriends->SetInGameVoiceSpeaking(*steamIDUser, bSpeaking);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SetInGameVoiceSpeaking=_BlitzSteamFriends_SetInGameVoiceSpeaking@12")

DLL_EXPORT void BlitzSteamFriends_ActivateGameOverlay(ISteamFriends* lpSteamFriends, const char* pchDialog) {
	lpSteamFriends->ActivateGameOverlay(pchDialog);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ActivateGameOverlay=_BlitzSteamFriends_ActivateGameOverlay@8")

DLL_EXPORT void BlitzSteamFriends_ActivateGameOverlayToUser(ISteamFriends* lpSteamFriends, const char* pchDialog, CSteamID* steamID) {
	lpSteamFriends->ActivateGameOverlayToUser(pchDialog, *steamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ActivateGameOverlayToUser=_BlitzSteamFriends_ActivateGameOverlayToUser@12")

DLL_EXPORT void BlitzSteamFriends_ActivateGameOverlayToWebPage(ISteamFriends* lpSteamFriends, const char* pchURL) {
	lpSteamFriends->ActivateGameOverlayToWebPage(pchURL);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ActivateGameOverlayToWebPage=_BlitzSteamFriends_ActivateGameOverlayToWebPage@8")

DLL_EXPORT void BlitzSteamFriends_ActivateGameOverlayToStore(ISteamFriends* lpSteamFriends, AppId_t nAppID, EOverlayToStoreFlag eFlag) {
	lpSteamFriends->ActivateGameOverlayToStore(nAppID, eFlag);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ActivateGameOverlayToStore=_BlitzSteamFriends_ActivateGameOverlayToStore@12")

DLL_EXPORT void BlitzSteamFriends_SetPlayedWith(ISteamFriends* lpSteamFriends, CSteamID* steamIDUserPlayedWith) {
	lpSteamFriends->SetPlayedWith(*steamIDUserPlayedWith);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SetPlayedWith=_BlitzSteamFriends_SetPlayedWith@8")

DLL_EXPORT void BlitzSteamFriends_ActivateGameOverlayInviteDialog(ISteamFriends* lpSteamFriends, CSteamID* steamIDLobby) {
	lpSteamFriends->ActivateGameOverlayInviteDialog(*steamIDLobby);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ActivateGameOverlayInviteDialog=_BlitzSteamFriends_ActivateGameOverlayInviteDialog@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetSmallFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetSmallFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetSmallFriendAvatar=_BlitzSteamFriends_GetSmallFriendAvatar@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetMediumFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetMediumFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetMediumFriendAvatar=_BlitzSteamFriends_GetMediumFriendAvatar@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetLargeFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetLargeFriendAvatar(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetLargeFriendAvatar=_BlitzSteamFriends_GetLargeFriendAvatar@8")

DLL_EXPORT uint32_t BlitzSteamFriends_RequestUserInformation(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, bool bRequireNameOnly) {
	return lpSteamFriends->RequestUserInformation(*steamIDUser, bRequireNameOnly);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_RequestUserInformation=_BlitzSteamFriends_RequestUserInformation@12")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_RequestClanOfficerList(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->RequestClanOfficerList(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_RequestClanOfficerList=_BlitzSteamFriends_RequestClanOfficerList@8")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetClanOwner(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return new CSteamID(lpSteamFriends->GetClanOwner(*steamIDClan));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanOwner=_BlitzSteamFriends_GetClanOwner@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetClanOfficerCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanOfficerCount(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanOfficerCount=_BlitzSteamFriends_GetClanOfficerCount@8")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetClanOfficerByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iOfficer) {
	return new CSteamID(lpSteamFriends->GetClanOfficerByIndex(*steamIDClan, iOfficer));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanOfficerByIndex=_BlitzSteamFriends_GetClanOfficerByIndex@12")

DLL_EXPORT EUserRestriction BlitzSteamFriends_GetUserRestrictions(ISteamFriends* lpSteamFriends) {
	return (EUserRestriction)lpSteamFriends->GetUserRestrictions();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetUserRestrictions=_BlitzSteamFriends_GetUserRestrictions@4")

DLL_EXPORT uint32_t BlitzSteamFriends_SetRichPresence(ISteamFriends* lpSteamFriends, const char* pchKey, const char* pchValue) {
	return lpSteamFriends->SetRichPresence(pchKey, pchValue);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SetRichPresence=_BlitzSteamFriends_SetRichPresence@12")

DLL_EXPORT void BlitzSteamFriends_ClearRichPresence(ISteamFriends* lpSteamFriends) {
	lpSteamFriends->ClearRichPresence();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ClearRichPresence=_BlitzSteamFriends_ClearRichPresence@4")

DLL_EXPORT const char* BlitzSteamFriends_GetFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchKey) {
	return lpSteamFriends->GetFriendRichPresence(*steamIDFriend, pchKey);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendRichPresence=_BlitzSteamFriends_GetFriendRichPresence@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendRichPresenceKeyCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRichPresenceKeyCount(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendRichPresenceKeyCount=_BlitzSteamFriends_GetFriendRichPresenceKeyCount@8")

DLL_EXPORT const char* BlitzSteamFriends_GetFriendRichPresenceKeyByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iKey) {
	return lpSteamFriends->GetFriendRichPresenceKeyByIndex(*steamIDFriend, iKey);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendRichPresenceKeyByIndex=_BlitzSteamFriends_GetFriendRichPresenceKeyByIndex@12")

DLL_EXPORT void BlitzSteamFriends_RequestFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	lpSteamFriends->RequestFriendRichPresence(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_RequestFriendRichPresence=_BlitzSteamFriends_RequestFriendRichPresence@8")

DLL_EXPORT uint32_t BlitzSteamFriends_InviteUserToGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char *pchConnectString) {
	return lpSteamFriends->InviteUserToGame(*steamIDFriend, pchConnectString);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_InviteUserToGame=_BlitzSteamFriends_InviteUserToGame@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetCoplayFriendCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetCoplayFriendCount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetCoplayFriendCount=_BlitzSteamFriends_GetCoplayFriendCount@4")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetCoplayFriend(ISteamFriends* lpSteamFriends, int32_t iCoplayFriend) {
	return new CSteamID(lpSteamFriends->GetCoplayFriend(iCoplayFriend));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetCoplayFriend=_BlitzSteamFriends_GetCoplayFriend@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendCoplayTime(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayTime(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendCoplayTime=_BlitzSteamFriends_GetFriendCoplayTime@8")

DLL_EXPORT AppId_t BlitzSteamFriends_GetFriendCoplayGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayGame(*steamIDFriend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendCoplayGame=_BlitzSteamFriends_GetFriendCoplayGame@8")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_JoinClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->JoinClanChatRoom(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_JoinClanChatRoom=_BlitzSteamFriends_JoinClanChatRoom@8")

DLL_EXPORT uint32_t BlitzSteamFriends_LeaveClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->LeaveClanChatRoom(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_LeaveClanChatRoom=_BlitzSteamFriends_LeaveClanChatRoom@8")

DLL_EXPORT int32_t BlitzSteamFriends_GetClanChatMemberCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanChatMemberCount(*steamIDClan);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanChatMemberCount=_BlitzSteamFriends_GetClanChatMemberCount@8")

DLL_EXPORT CSteamID* BlitzSteamFriends_GetChatMemberByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iUser) {
	return new CSteamID(lpSteamFriends->GetChatMemberByIndex(*steamIDClan, iUser));
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetChatMemberByIndex=_BlitzSteamFriends_GetChatMemberByIndex@12")

DLL_EXPORT uint32_t BlitzSteamFriends_SendClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, const char *pchText) {
	return lpSteamFriends->SendClanChatMessage(*steamIDClanChat, pchText);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SendClanChatMessage=_BlitzSteamFriends_SendClanChatMessage@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, int32_t iMessage, void* prgchText, int32_t cchTextMax, EChatEntryType* peChatEntryType, CSteamID* psteamidChatter) {
	return lpSteamFriends->GetClanChatMessage(*steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetClanChatMessage=_BlitzSteamFriends_GetClanChatMessage@28")

DLL_EXPORT uint32_t BlitzSteamFriends_IsClanChatAdmin(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, CSteamID* steamIDUser) {
	return lpSteamFriends->IsClanChatAdmin(*steamIDClanChat, *steamIDUser);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_IsClanChatAdmin=_BlitzSteamFriends_IsClanChatAdmin@12")

DLL_EXPORT uint32_t BlitzSteamFriends_IsClanChatWindowOpenInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->IsClanChatWindowOpenInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_IsClanChatWindowOpenInSteam=_BlitzSteamFriends_IsClanChatWindowOpenInSteam@8")

DLL_EXPORT uint32_t BlitzSteamFriends_OpenClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->OpenClanChatWindowInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_OpenClanChatWindowInSteam=_BlitzSteamFriends_OpenClanChatWindowInSteam@8")

DLL_EXPORT uint32_t BlitzSteamFriends_CloseClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->CloseClanChatWindowInSteam(*steamIDClanChat);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_CloseClanChatWindowInSteam=_BlitzSteamFriends_CloseClanChatWindowInSteam@8")

DLL_EXPORT uint32_t BlitzSteamFriends_SetListenForFriendsMessages(ISteamFriends* lpSteamFriends, bool bInterceptEnabled) {
	return lpSteamFriends->SetListenForFriendsMessages(bInterceptEnabled);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_SetListenForFriendsMessages=_BlitzSteamFriends_SetListenForFriendsMessages@8")

DLL_EXPORT uint32_t BlitzSteamFriends_ReplyToFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchMsgToSend) {
	return lpSteamFriends->ReplyToFriendMessage(*steamIDFriend, pchMsgToSend);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_ReplyToFriendMessage=_BlitzSteamFriends_ReplyToFriendMessage@12")

DLL_EXPORT int32_t BlitzSteamFriends_GetFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iMessageID, void* pvData, int32_t cubData, EChatEntryType* peChatEntryType) {
	return lpSteamFriends->GetFriendMessage(*steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFriendMessage=_BlitzSteamFriends_GetFriendMessage@24")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_GetFollowerCount(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return lpSteamFriends->GetFollowerCount(*steamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_GetFollowerCount=_BlitzSteamFriends_GetFollowerCount@8")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_IsFollowing(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return lpSteamFriends->IsFollowing(*steamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_IsFollowing=_BlitzSteamFriends_IsFollowing@8")

DLL_EXPORT SteamAPICall_t BlitzSteamFriends_EnumerateFollowingList(ISteamFriends* lpSteamFriends, uint32 unStartIndex) {
	return lpSteamFriends->EnumerateFollowingList(unStartIndex);
}
#pragma comment(linker, "/EXPORT:BlitzSteamFriends_EnumerateFollowingList=_BlitzSteamFriends_EnumerateFollowingList@8")
