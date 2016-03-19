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

#pragma once
#include "BlitzSteamInternal.h"

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
DLL(CSteamID*) BS_CSteamID_New();
DLL(CSteamID*) BS_CSteamID_Copy(CSteamID* pOther);
DLL(void) BS_CSteamID_Destroy(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Constructor
// Input  : unAccountID -	32-bit account ID
//			eUniverse -		Universe this account belongs to
//			eAccountType -	Type of account
//-----------------------------------------------------------------------------
DLL(CSteamID*) BS_CSteamID_New_IdUniverseType(AccountID_t iAccountId, EUniverse eUniverse, EAccountType eAccountType);

//-----------------------------------------------------------------------------
// Purpose: Constructor
// Input  : unAccountID -	32-bit account ID
//			unAccountInstance - instance 
//			eUniverse -		Universe this account belongs to
//			eAccountType -	Type of account
//-----------------------------------------------------------------------------
DLL(CSteamID*) BS_CSteamID_New_IdInstanceUniverseType(AccountID_t iAccountId, uint32_t iInstance, EUniverse eUniverse, EAccountType eAccountType);

//-----------------------------------------------------------------------------
// Purpose: Constructor
// Input  : ulSteamID -		64-bit representation of a Steam ID
// Note:	Will not accept a uint32 or int32 as input, as that is a probable mistake.
//			See the stubbed out overloads in the private: section for more info.
//-----------------------------------------------------------------------------
DLL(CSteamID*) BS_CSteamID_FromL(int64_t* pOther);
DLL(int64_t*) BS_CSteamID_ToL(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Sets parameters for steam ID
// Input  : unAccountID -	32-bit account ID
//			eUniverse -		Universe this account belongs to
//			eAccountType -	Type of account
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_Set(CSteamID* pThis, AccountID_t iAccountID, EUniverse eUniverse, EAccountType eAccountType);

//-----------------------------------------------------------------------------
// Purpose: Sets parameters for steam ID
// Input  : unAccountID -	32-bit account ID
//			eUniverse -		Universe this account belongs to
//			eAccountType -	Type of account
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_InstancedSet(CSteamID* pThis, AccountID_t iAccountId, uint32_t iInstance, EUniverse eUniverse, EAccountType eAccountType);

//-----------------------------------------------------------------------------
// Purpose: Initializes a steam ID from its 52 bit parts and universe/type
// Input  : ulIdentifier - 52 bits of goodness
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_FullSet(CSteamID* pThis, int64_t* plIdentifier, EUniverse eUniverse, EAccountType eAccountType);

//-----------------------------------------------------------------------------
// Purpose: Initializes a steam ID from its 64-bit representation
// Input  : ulSteamID -		64-bit representation of a Steam ID
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_SetFromLong(CSteamID* pThis, int64_t* plSteamID);

//-----------------------------------------------------------------------------
// Purpose: Clear all fields, leaving an invalid ID.
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_Clear(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Converts the static parts of a steam ID to a 64-bit representation.
//			For multiseat accounts, all instances of that account will have the
//			same static account key, so they can be grouped together by the static
//			account key.
// Output : 64-bit static account key
//-----------------------------------------------------------------------------
DLL(int64_t*) BS_CSteamID_GetStaticAccountKey(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: create an anonymous game server login to be filled in by the AM
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_CreateBlankAnonLogon(CSteamID* pThis, EUniverse eUniverse);

//-----------------------------------------------------------------------------
// Purpose: create an anonymous game server login to be filled in by the AM
//-----------------------------------------------------------------------------
DLL(void) BS_CSteamID_CreateBlankAnonUserLogon(CSteamID* pThis, EUniverse eUniverse);

//-----------------------------------------------------------------------------
// Purpose: Is this an anonymous game server login that will be filled in?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsBlankAnonAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a game server account id?  (Either persistent or anonymous)
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsGameServerAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a persistent (not anonymous) game server account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsPersistentGameServerAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this an anonymous game server account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsAnonGameServerAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a content server account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsContentServerAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a clan account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsClanAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a chat account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsChatAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a Lobby?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsLobby(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this an individual user account id?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsIndividualAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this an anonymous account?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsAnonAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this an anonymous user account? ( used to create an account or reset a password )
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsAnonUserAccount(CSteamID* pThis);

//-----------------------------------------------------------------------------
// Purpose: Is this a faked up Steam ID for a PSN friend account?
//-----------------------------------------------------------------------------
DLL(int32_t) BS_CSteamID_IsConsoleUserAccount(CSteamID* pThis);

// simple accessors
DLL(void) BS_CSteamID_SetAccountID(CSteamID* pThis, AccountID_t iAccountId);
DLL(AccountID_t) BS_CSteamID_GetAccountID(CSteamID* pThis);

DLL(void) BS_CSteamID_SetAccountInstance(CSteamID* pThis, uint32_t iInstance);
DLL(void) BS_CSteamID_ClearIndividualInstance(CSteamID* pThis);
DLL(int32_t) BS_CSteamID_HasNoIndividualInstance(CSteamID* pThis);
DLL(uint32_t) BS_CSteamID_GetAccountInstance(CSteamID* pThis);

DLL(EAccountType) BS_CSteamID_GetEAccountType(CSteamID* pThis);

DLL(void) BS_CSteamID_SetEUniverse(CSteamID* pThis, EUniverse eUniverse);
DLL(EUniverse) BS_CSteamID_GetEUniverse(CSteamID* pThis);

DLL(int32_t) BS_CSteamID_Compare(CSteamID* pThis, CSteamID* pOther);