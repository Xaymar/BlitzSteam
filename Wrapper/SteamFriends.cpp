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
// Purpose: interface to accessing information about individual users,
//			that can be a friend, in a group, on a game server or in a lobby with the local user
//-----------------------------------------------------------------------------
DLL_FUNCTION(ISteamFriends*) BS_SteamFriends() {
	return SteamFriends();
}

// returns the local players name - guaranteed to not be NULL.
// this is the same name as on the users community profile page
// this is stored in UTF-8 format
// like all the other interface functions that return a char *, it's important that this pointer is not saved
// off; it will eventually be free'd or re-allocated
DLL_FUNCTION(const char*) BS_ISteamFriends_GetPersonaName(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaName();
}

// Sets the player name, stores it on the server and publishes the changes to all friends who are online.
// Changes take place locally immediately, and a PersonaStateChange_t is posted, presuming success.
//
// The final results are available through the return value SteamAPICall_t, using SetPersonaNameResponse_t.
//
// If the name change fails to happen on the server, then an additional global PersonaStateChange_t will be posted
// to change the name back, in addition to the SetPersonaNameResponse_t callback.
DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_SetPersonaName(ISteamFriends* lpSteamFriends, const char* pchPersonaName) {
	return new uint64_t(lpSteamFriends->SetPersonaName(pchPersonaName));
}

// gets the status of the current user
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetPersonaState(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetPersonaState();
}

// friend iteration
// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
// then GetFriendByIndex() can then be used to return the id's of each of those users
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendCount(ISteamFriends* lpSteamFriends, int32_t iFriendFlags) {
	return lpSteamFriends->GetFriendCount(iFriendFlags);
}

// returns the steamID of a user
// iFriend is a index of range [0, GetFriendCount())
// iFriendsFlags must be the same value as used in GetFriendCount()
// the returned CSteamID can then be used by all the functions below to access details about the user
DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetFriendByIndex(ISteamFriends* lpSteamFriends, int32_t iFriend, int32_t iFriendFlags) {
	return new CSteamID(lpSteamFriends->GetFriendByIndex(iFriend, iFriendFlags));
}

// returns a relationship to a user
DLL_FUNCTION(EFriendRelationship) BS_ISteamFriends_GetFriendRelationship(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRelationship(*steamIDFriend);
}

// returns the current status of the specified user
// this will only be known by the local user if steamIDFriend is in their friends list; on the same game server; in a chat room or lobby; or in a small group with the local user
DLL_FUNCTION(EPersonaState) BS_ISteamFriends_GetFriendPersonaState(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaState(*steamIDFriend);
}

// returns the name another user - guaranteed to not be NULL.
// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically; that information will arrive asyncronously
DLL_FUNCTION(const char*) BS_ISteamFriends_GetFriendPersonaName(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendPersonaName(*steamIDFriend);
}

// returns true if the friend is actually in a game, and fills in pFriendGameInfo with an extra details 
DLL_FUNCTION(uint32_t) BS_ISteamFriends_GetFriendGamePlayed(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, FriendGameInfo_t *pFriendGameInfo) {
	return lpSteamFriends->GetFriendGamePlayed(*steamIDFriend, pFriendGameInfo);
}

// accesses old friends names - returns an empty string when their are no more items in the history
DLL_FUNCTION(const char*) BS_ISteamFriends_GetFriendPersonaNameHistory(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iPersonaName) {
	return lpSteamFriends->GetFriendPersonaNameHistory(*steamIDFriend, iPersonaName);
}

// friends steam level
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendSteamLevel(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendSteamLevel(*steamIDFriend);
}

// Returns nickname the current user has set for the specified player. Returns NULL if the no nickname has been set for that player.
DLL_FUNCTION(const char*) BS_ISteamFriends_GetPlayerNickname(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriends) {
	const char* nickname = lpSteamFriends->GetPlayerNickname(*steamIDFriends);
	if (nickname == NULL) {
		nickname = "";
	}
	return nickname;
}

// friend grouping (tag) apis
// returns the number of friends groups
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendsGroupCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetFriendsGroupCount();
}

// returns the friends group ID for the given index (invalid indices return k_FriendsGroupID_Invalid)
DLL_FUNCTION(FriendsGroupID_t) BS_ISteamFriends_GetFriendsGroupIDByIndex(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupIDByIndex(friendsGroupID);
}

// returns the name for the given friends group (NULL in the case of invalid friends group IDs)
DLL_FUNCTION(const char*) BS_ISteamFriends_GetFriendsGroupName(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupName(friendsGroupID);
}

// returns the number of members in a given friends group
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendsGroupMembersCount(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID) {
	return lpSteamFriends->GetFriendsGroupMembersCount(friendsGroupID);
}

// gets up to nMembersCount members of the given friends group, if fewer exist than requested those positions' SteamIDs will be invalid
DLL_FUNCTION(void) BS_ISteamFriends_GetFriendsGroupMembersList(ISteamFriends* lpSteamFriends, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int32_t nMembersCount) {
	lpSteamFriends->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}

// returns true if the specified user meets any of the criteria specified in iFriendFlags
// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
DLL_FUNCTION(uint32_t) BS_ISteamFriends_HasFriend(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iFriendsFlags) {
	return lpSteamFriends->HasFriend(*steamIDFriend, iFriendsFlags);
}

// clan (group) iteration and access functions
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetClanCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetClanCount();
}

DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetClanByIndex(ISteamFriends* lpSteamFriends, int32_t iClan) {
	CSteamID* steamID = new CSteamID(lpSteamFriends->GetClanByIndex(iClan));
	return steamID;
}

DLL_FUNCTION(const char*) BS_ISteamFriends_GetClanName(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanName(*steamIDClan);
}

DLL_FUNCTION(const char*) BS_ISteamFriends_GetClanTag(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanTag(*steamIDClan);
}

// returns the most recent information we have about what's happening in a clan
DLL_FUNCTION(uint32_t) BS_ISteamFriends_GetClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t* pnOnline, int32_t* pnInGame, int32_t* pnChatting) {
	return lpSteamFriends->GetClanActivityCounts(*steamIDClan, pnOnline, pnInGame, pnChatting);
}

// for clans a user is a member of, they will have reasonably up-to-date information, but for others you'll have to download the info to have the latest
DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_DownloadClanActivityCounts(ISteamFriends* lpSteamFriends, CSteamID* psteamIDClans, int32_t cClansToRequest) {
	return new uint64_t(lpSteamFriends->DownloadClanActivityCounts(psteamIDClans, cClansToRequest));
}

// iterators for getting users in a chat room, lobby, game server or clan
// note that large clans that cannot be iterated by the local user
// note that the current user must be in a lobby to retrieve CSteamIDs of other users in that lobby
// steamIDSource can be the steamID of a group, game server, lobby or chat room
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendCountFromSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource) {
	return lpSteamFriends->GetFriendCountFromSource(*steamIDSource);
}

DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetFriendFromSourceByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDSource, int32_t iFriend) {
	return new CSteamID(lpSteamFriends->GetFriendFromSourceByIndex(*steamIDSource, iFriend));
}

// returns true if the local user can see that steamIDUser is a member or in steamIDSource
DLL_FUNCTION(uint32_t) BS_ISteamFriends_IsUserInSource(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, CSteamID* steamIDSource) {
	return lpSteamFriends->IsUserInSource(*steamIDUser, *steamIDSource);
}

// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
DLL_FUNCTION(void) BS_ISteamFriends_SetInGameVoiceSpeaking(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, uint32_t bSpeaking) {
	lpSteamFriends->SetInGameVoiceSpeaking(*steamIDUser, bSpeaking != 0);
}

// activates the game overlay, with an optional dialog to open 
// valid options are "Friends", "Community", "Players", "Settings", "OfficialGameGroup", "Stats", "Achievements"
DLL_FUNCTION(void) BS_ISteamFriends_ActivateGameOverlay(ISteamFriends* lpSteamFriends, const char* pchDialog) {
	lpSteamFriends->ActivateGameOverlay(pchDialog);
}

// activates game overlay to a specific place
// valid options are
//		"steamid" - opens the overlay web browser to the specified user or groups profile
//		"chat" - opens a chat window to the specified user, or joins the group chat 
//		"jointrade" - opens a window to a Steam Trading session that was started with the ISteamEconomy/StartTrade Web API
//		"stats" - opens the overlay web browser to the specified user's stats
//		"achievements" - opens the overlay web browser to the specified user's achievements
//		"friendadd" - opens the overlay in minimal mode prompting the user to add the target user as a friend
//		"friendremove" - opens the overlay in minimal mode prompting the user to remove the target friend
//		"friendrequestaccept" - opens the overlay in minimal mode prompting the user to accept an incoming friend invite
//		"friendrequestignore" - opens the overlay in minimal mode prompting the user to ignore an incoming friend invite
DLL_FUNCTION(void) BS_ISteamFriends_ActivateGameOverlayToUser(ISteamFriends* lpSteamFriends, const char* pchDialog, CSteamID* steamID) {
	lpSteamFriends->ActivateGameOverlayToUser(pchDialog, *steamID);
}

// activates game overlay web browser directly to the specified URL
// full address with protocol type is required, e.g. http://www.steamgames.com/
DLL_FUNCTION(void) BS_ISteamFriends_ActivateGameOverlayToWebPage(ISteamFriends* lpSteamFriends, const char* pchURL) {
	lpSteamFriends->ActivateGameOverlayToWebPage(pchURL);
}

// activates game overlay to store page for app
DLL_FUNCTION(void) BS_ISteamFriends_ActivateGameOverlayToStore(ISteamFriends* lpSteamFriends, AppId_t nAppID, EOverlayToStoreFlag eFlag) {
	lpSteamFriends->ActivateGameOverlayToStore(nAppID, eFlag);
}

// Mark a target user as 'played with'. This is a client-side only feature that requires that the calling user is 
// in game 
DLL_FUNCTION(void) BS_ISteamFriends_SetPlayedWith(ISteamFriends* lpSteamFriends, CSteamID* steamIDUserPlayedWith) {
	lpSteamFriends->SetPlayedWith(*steamIDUserPlayedWith);
}

// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
DLL_FUNCTION(void) BS_ISteamFriends_ActivateGameOverlayInviteDialog(ISteamFriends* lpSteamFriends, CSteamID* steamIDLobby) {
	lpSteamFriends->ActivateGameOverlayInviteDialog(*steamIDLobby);
}

// gets the small (32x32) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetSmallFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetSmallFriendAvatar(*steamIDFriend);
}

// gets the medium (64x64) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetMediumFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetMediumFriendAvatar(*steamIDFriend);
}

// gets the large (184x184) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
// returns -1 if this image has yet to be loaded, in this case wait for a AvatarImageLoaded_t callback and then call this again
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetLargeFriendAvatar(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetLargeFriendAvatar(*steamIDFriend);
}

// requests information about a user - persona name & avatar
// if bRequireNameOnly is set, then the avatar of a user isn't downloaded 
// - it's a lot slower to download avatars and churns the local cache, so if you don't need avatars, don't request them
// if returns true, it means that data is being requested, and a PersonaStateChanged_t callback will be posted when it's retrieved
// if returns false, it means that we already have all the details about that user, and functions can be called immediately
DLL_FUNCTION(uint32_t) BS_ISteamFriends_RequestUserInformation(ISteamFriends* lpSteamFriends, CSteamID* steamIDUser, uint32_t bRequireNameOnly) {
	return lpSteamFriends->RequestUserInformation(*steamIDUser, bRequireNameOnly != 0);
}

// requests information about a clan officer list
// when complete, data is returned in ClanOfficerListResponse_t call result
// this makes available the calls below
// you can only ask about clans that a user is a member of
// note that this won't download avatars automatically; if you get an officer,
// and no avatar image is available, call RequestUserInformation( steamID, false ) to download the avatar
DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_RequestClanOfficerList(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return new uint64_t(lpSteamFriends->RequestClanOfficerList(*steamIDClan));
}

// iteration of clan officers - can only be done when a RequestClanOfficerList() call has completed

// returns the steamID of the clan owner
DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetClanOwner(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return new CSteamID(lpSteamFriends->GetClanOwner(*steamIDClan));
}

// returns the number of officers in a clan (including the owner)
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetClanOfficerCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanOfficerCount(*steamIDClan);
}

// returns the steamID of a clan officer, by index, of range [0,GetClanOfficerCount)
DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetClanOfficerByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iOfficer) {
	return new CSteamID(lpSteamFriends->GetClanOfficerByIndex(*steamIDClan, iOfficer));
}

// if current user is chat restricted, he can't send or receive any text/voice chat messages.
// the user can't see custom avatars. But the user can be online and send/recv game invites.
// a chat restricted user can't add friends or join any groups.
DLL_FUNCTION(EUserRestriction) BS_ISteamFriends_GetUserRestrictions(ISteamFriends* lpSteamFriends) {
	return (EUserRestriction)lpSteamFriends->GetUserRestrictions();
}

// Rich Presence data is automatically shared between friends who are in the same game
// Each user has a set of Key/Value pairs
// Up to 20 different keys can be set
// There are two magic keys:
//		"status"  - a UTF-8 string that will show up in the 'view game info' dialog in the Steam friends list
//		"connect" - a UTF-8 string that contains the command-line for how a friend can connect to a game
// GetFriendRichPresence() returns an empty string "" if no value is set
// SetRichPresence() to a NULL or an empty string deletes the key
// You can iterate the current set of keys for a friend with GetFriendRichPresenceKeyCount()
// and GetFriendRichPresenceKeyByIndex() (typically only used for debugging)
DLL_FUNCTION(uint32_t) BS_ISteamFriends_SetRichPresence(ISteamFriends* lpSteamFriends, const char* pchKey, const char* pchValue) {
	return lpSteamFriends->SetRichPresence(pchKey, pchValue);
}

DLL_FUNCTION(void) BS_ISteamFriends_ClearRichPresence(ISteamFriends* lpSteamFriends) {
	lpSteamFriends->ClearRichPresence();
}

DLL_FUNCTION(const char*) BS_ISteamFriends_GetFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchKey) {
	return lpSteamFriends->GetFriendRichPresence(*steamIDFriend, pchKey);
}

DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendRichPresenceKeyCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendRichPresenceKeyCount(*steamIDFriend);
}

DLL_FUNCTION(const char*) BS_ISteamFriends_GetFriendRichPresenceKeyByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iKey) {
	return lpSteamFriends->GetFriendRichPresenceKeyByIndex(*steamIDFriend, iKey);
}

// Requests rich presence for a specific user.
DLL_FUNCTION(void) BS_ISteamFriends_RequestFriendRichPresence(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	lpSteamFriends->RequestFriendRichPresence(*steamIDFriend);
}

// rich invite support
// if the target accepts the invite, the pchConnectString gets added to the command-line for launching the game
// if the game is already running, a GameRichPresenceJoinRequested_t callback is posted containing the connect string
// invites can only be sent to friends
DLL_FUNCTION(uint32_t) BS_ISteamFriends_InviteUserToGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char *pchConnectString) {
	return lpSteamFriends->InviteUserToGame(*steamIDFriend, pchConnectString);
}

// recently-played-with friends iteration
// this iterates the entire list of users recently played with, across games
// GetFriendCoplayTime() returns as a unix time
DLL_FUNCTION(int32_t) BS_ISteamFriends_GetCoplayFriendCount(ISteamFriends* lpSteamFriends) {
	return lpSteamFriends->GetCoplayFriendCount();
}

DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetCoplayFriend(ISteamFriends* lpSteamFriends, int32_t iCoplayFriend) {
	return new CSteamID(lpSteamFriends->GetCoplayFriend(iCoplayFriend));
}

DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendCoplayTime(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayTime(*steamIDFriend);
}

DLL_FUNCTION(AppId_t) BS_ISteamFriends_GetFriendCoplayGame(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend) {
	return lpSteamFriends->GetFriendCoplayGame(*steamIDFriend);
}

// chat interface for games
// this allows in-game access to group (clan) chats from in the game
// the behavior is somewhat sophisticated, because the user may or may not be already in the group chat from outside the game or in the overlay
// use ActivateGameOverlayToUser( "chat", steamIDClan ) to open the in-game overlay version of the chat
DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_JoinClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return new SteamAPICall_t(lpSteamFriends->JoinClanChatRoom(*steamIDClan));
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_LeaveClanChatRoom(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->LeaveClanChatRoom(*steamIDClan);
}

DLL_FUNCTION(int32_t) BS_ISteamFriends_GetClanChatMemberCount(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan) {
	return lpSteamFriends->GetClanChatMemberCount(*steamIDClan);
}

DLL_FUNCTION(CSteamID*) BS_ISteamFriends_GetChatMemberByIndex(ISteamFriends* lpSteamFriends, CSteamID* steamIDClan, int32_t iUser) {
	return new CSteamID(lpSteamFriends->GetChatMemberByIndex(*steamIDClan, iUser));
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_SendClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, const char *pchText) {
	return lpSteamFriends->SendClanChatMessage(*steamIDClanChat, pchText);
}

DLL_FUNCTION(int32_t) BS_ISteamFriends_GetClanChatMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, int32_t iMessage, void* prgchText, int32_t cchTextMax, EChatEntryType* peChatEntryType, CSteamID* psteamidChatter) {
	return lpSteamFriends->GetClanChatMessage(*steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_IsClanChatAdmin(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat, CSteamID* steamIDUser) {
	return lpSteamFriends->IsClanChatAdmin(*steamIDClanChat, *steamIDUser);
}

// interact with the Steam (game overlay / desktop)
DLL_FUNCTION(uint32_t) BS_ISteamFriends_IsClanChatWindowOpenInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->IsClanChatWindowOpenInSteam(*steamIDClanChat);
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_OpenClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->OpenClanChatWindowInSteam(*steamIDClanChat);
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_CloseClanChatWindowInSteam(ISteamFriends* lpSteamFriends, CSteamID* steamIDClanChat) {
	return lpSteamFriends->CloseClanChatWindowInSteam(*steamIDClanChat);
}

// peer-to-peer chat interception
// this is so you can show P2P chats inline in the game
DLL_FUNCTION(uint32_t) BS_ISteamFriends_SetListenForFriendsMessages(ISteamFriends* lpSteamFriends, uint32_t bInterceptEnabled) {
	return lpSteamFriends->SetListenForFriendsMessages(bInterceptEnabled != 0);
}

DLL_FUNCTION(uint32_t) BS_ISteamFriends_ReplyToFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, const char* pchMsgToSend) {
	return lpSteamFriends->ReplyToFriendMessage(*steamIDFriend, pchMsgToSend);
}

DLL_FUNCTION(int32_t) BS_ISteamFriends_GetFriendMessage(ISteamFriends* lpSteamFriends, CSteamID* steamIDFriend, int32_t iMessageID, void* pvData, int32_t cubData, EChatEntryType* peChatEntryType) {
	return lpSteamFriends->GetFriendMessage(*steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
}

// following apis
DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_GetFollowerCount(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return new SteamAPICall_t(lpSteamFriends->GetFollowerCount(*steamID));
}

DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_IsFollowing(ISteamFriends* lpSteamFriends, CSteamID* steamID) {
	return new SteamAPICall_t(lpSteamFriends->IsFollowing(*steamID));
}

DLL_FUNCTION(SteamAPICall_t*) BS_ISteamFriends_EnumerateFollowingList(ISteamFriends* lpSteamFriends, uint32_t unStartIndex) {
	return new SteamAPICall_t(lpSteamFriends->EnumerateFollowingList(unStartIndex));
}
