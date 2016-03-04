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

#include "CSteamID.h"

DLL_FUNCTION(CSteamID*) BS_CSteamID_New() {
	return new CSteamID();
}

DLL_FUNCTION(CSteamID*) BS_CSteamID_Copy(CSteamID* pOther) {
	return new CSteamID(*pOther);
}

DLL_FUNCTION(void) BS_CSteamID_Destroy(CSteamID* pThis) {
	delete pThis;
}

DLL_FUNCTION(CSteamID*) BS_CSteamID_New_IdUniverseType(AccountID_t iAccountId, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(iAccountId, eUniverse, eAccountType);
}

DLL_FUNCTION(CSteamID*) BS_CSteamID_New_IdInstanceUniverseType(AccountID_t iAccountId, uint32_t iInstance, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(iAccountId, iInstance, eUniverse, eAccountType);
}

DLL_FUNCTION(CSteamID*) BS_CSteamID_FromL(int64_t* pOther) {
	return new CSteamID((uint64_t)*pOther);
}

DLL_FUNCTION(int64_t*) BS_CSteamID_ToL(CSteamID* pThis) {
	return new int64_t(pThis->ConvertToUint64());
}

DLL_FUNCTION(void) BS_CSteamID_Set(CSteamID* pThis, AccountID_t iAccountID, EUniverse eUniverse, EAccountType eAccountType) {
	pThis->Set(iAccountID, eUniverse, eAccountType);
}

DLL_FUNCTION(void) BS_CSteamID_InstancedSet(CSteamID* pThis, AccountID_t iAccountId, uint32_t iInstance, EUniverse eUniverse, EAccountType eAccountType) {
	pThis->InstancedSet(iAccountId, iInstance, eUniverse, eAccountType);
}

DLL_FUNCTION(void) BS_CSteamID_FullSet(CSteamID* pThis, int64_t* plIdentifier, EUniverse eUniverse, EAccountType eAccountType) {
	pThis->FullSet(*plIdentifier, eUniverse, eAccountType);
}

DLL_FUNCTION(void) BS_CSteamID_SetFromLong(CSteamID* pThis, int64_t* plSteamID) {
	pThis->SetFromUint64(*plSteamID);
}

DLL_FUNCTION(void) BS_CSteamID_Clear(CSteamID* pThis) {
	pThis->Clear();
}

DLL_FUNCTION(int64_t*) BS_CSteamID_GetStaticAccountKey(CSteamID* pThis) {
	return new int64_t(pThis->GetStaticAccountKey());
}

DLL_FUNCTION(void) BS_CSteamID_CreateBlankAnonLogon(CSteamID* pThis, EUniverse eUniverse) {
	pThis->CreateBlankAnonLogon(eUniverse);
}

DLL_FUNCTION(void) BS_CSteamID_CreateBlankAnonUserLogon(CSteamID* pThis, EUniverse eUniverse) {
	pThis->CreateBlankAnonUserLogon(eUniverse);
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsBlankAnonAccount(CSteamID* pThis) {
	return pThis->BBlankAnonAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsGameServerAccount(CSteamID* pThis) {
	return pThis->BGameServerAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsPersistentGameServerAccount(CSteamID* pThis) {
	return pThis->BPersistentGameServerAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsAnonGameServerAccount(CSteamID* pThis) {
	return pThis->BAnonGameServerAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsContentServerAccount(CSteamID* pThis) {
	return pThis->BContentServerAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsClanAccount(CSteamID* pThis) {
	return pThis->BClanAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsChatAccount(CSteamID* pThis) {
	return pThis->BChatAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsLobby(CSteamID* pThis) {
	return pThis->IsLobby();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsIndividualAccount(CSteamID* pThis) {
	return pThis->BIndividualAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsAnonAccount(CSteamID* pThis) {
	return pThis->BAnonAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsAnonUserAccount(CSteamID* pThis) {
	return pThis->BAnonUserAccount();
}

DLL_FUNCTION(int32_t) BS_CSteamID_IsConsoleUserAccount(CSteamID* pThis) {
	return pThis->BConsoleUserAccount();
}

DLL_FUNCTION(void) BS_CSteamID_SetAccountID(CSteamID* pThis, AccountID_t iAccountId) {
	pThis->SetAccountID(iAccountId);
}

DLL_FUNCTION(AccountID_t) BS_CSteamID_GetAccountID(CSteamID* pThis) {
	return pThis->GetAccountID();
}

DLL_FUNCTION(void) BS_CSteamID_SetAccountInstance(CSteamID* pThis, uint32_t iInstance) {
	pThis->SetAccountInstance(iInstance);
}

DLL_FUNCTION(void) BS_CSteamID_ClearIndividualInstance(CSteamID* pThis) {
	pThis->ClearIndividualInstance();
}

DLL_FUNCTION(int32_t) BS_CSteamID_HasNoIndividualInstance(CSteamID* pThis) {
	return pThis->HasNoIndividualInstance();
}

DLL_FUNCTION(uint32_t) BS_CSteamID_GetAccountInstance(CSteamID* pThis) {
	return pThis->GetUnAccountInstance();
}

DLL_FUNCTION(EAccountType) BS_CSteamID_GetEAccountType(CSteamID* pThis) {
	return pThis->GetEAccountType();
}

DLL_FUNCTION(void) BS_CSteamID_SetEUniverse(CSteamID* pThis, EUniverse eUniverse) {
	pThis->SetEUniverse(eUniverse);
}

DLL_FUNCTION(EUniverse) BS_CSteamID_GetEUniverse(CSteamID* pThis) {
	return pThis->GetEUniverse();
}

DLL_FUNCTION(int32_t) BS_CSteamID_Compare(CSteamID* pThis, CSteamID* pOther) {
	return /* It can either be Equal (0) or Smaller or Greater. Easy to check. */
		   /* Greater */
		(*pThis > *pOther ? 1 : 0) +
		/* Smaller */
		(*pThis < *pOther ? -1 : 0);
}