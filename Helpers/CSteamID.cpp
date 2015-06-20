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

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_New() {
	return new CSteamID();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_New=_BlitzSteamCSteamID_New@0")

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromID(uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(unAccountID, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_FromID=_BlitzSteamCSteamID_FromID@12")

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromIDInstance(uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(unAccountID, unInstance, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_FromIDInstance=_BlitzSteamCSteamID_FromIDInstance@16")

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromSteamID(uint64_t* ulSteamID) {
	return new CSteamID(*ulSteamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_FromSteamID=_BlitzSteamCSteamID_FromSteamID@4")

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_Copy(CSteamID* pSteamID) {
	return new CSteamID(*pSteamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_Copy=_BlitzSteamCSteamID_Copy@4")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Destroy(CSteamID* pSteamID) {
	delete pSteamID;
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_Destroy=_BlitzSteamCSteamID_Destroy@4")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Set(CSteamID* pSteamID, uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->Set(unAccountID, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_Set=_BlitzSteamCSteamID_Set@16")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_InstancedSet(CSteamID* pSteamID, uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->InstancedSet(unAccountID, unInstance, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_InstancedSet=_BlitzSteamCSteamID_InstancedSet@20")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_FullSet(CSteamID* pSteamID, uint64_t* ulIdentifier, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->FullSet(*ulIdentifier, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_FullSet=_BlitzSteamCSteamID_FullSet@16")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetFromUInt64(CSteamID* pSteamID, uint64_t* ulSteamID) {
	pSteamID->SetFromUint64(*ulSteamID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_SetFromUInt64=_BlitzSteamCSteamID_SetFromUInt64@8")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Clear(CSteamID* pSteamID) {
	pSteamID->Clear();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_Clear=_BlitzSteamCSteamID_Clear@4")

DLL_EXPORT uint64_t* DLL_CALL BlitzSteamCSteamID_ConvertToUInt64(CSteamID* pSteamID) {
	uint64_t* val = new uint64_t;
	*val = pSteamID->ConvertToUint64();
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ConvertToUInt64=_BlitzSteamCSteamID_ConvertToUInt64@4")

DLL_EXPORT uint64_t* DLL_CALL BlitzSteamCSteamID_GetStaticAccountKey(CSteamID* pSteamID) {
	uint64_t* val = new uint64_t;
	*val = pSteamID->GetStaticAccountKey();
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GetStaticAccountKey=_BlitzSteamCSteamID_GetStaticAccountKey@4")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_CreateBlankAnonLogon(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->CreateBlankAnonLogon(eUniverse);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_CreateBlankAnonLogon=_BlitzSteamCSteamID_CreateBlankAnonLogon@8")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_CreateBlankAnonUserLogon(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->CreateBlankAnonUserLogon(eUniverse);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_CreateBlankAnonUserLogon=_BlitzSteamCSteamID_CreateBlankAnonUserLogon@8")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_BlankAnonAccount(CSteamID* pSteamID) {
	return pSteamID->BBlankAnonAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_BlankAnonAccount=_BlitzSteamCSteamID_BlankAnonAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_GameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GameServerAccount=_BlitzSteamCSteamID_GameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_PersistentGameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BPersistentGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_PersistentGameServerAccount=_BlitzSteamCSteamID_PersistentGameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonGameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_AnonGameServerAccount=_BlitzSteamCSteamID_AnonGameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ContentServerAccount(CSteamID* pSteamID) {
	return pSteamID->BContentServerAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ContentServerAccount=_BlitzSteamCSteamID_ContentServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ClanAccount(CSteamID* pSteamID) {
	return pSteamID->BClanAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ClanAccount=_BlitzSteamCSteamID_ClanAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ChatAccount(CSteamID* pSteamID) {
	return pSteamID->BChatAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ChatAccount=_BlitzSteamCSteamID_ChatAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IsLobby(CSteamID* pSteamID) {
	return pSteamID->IsLobby();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_IsLobby=_BlitzSteamCSteamID_IsLobby@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IndividualAccount(CSteamID* pSteamID) {
	return pSteamID->BIndividualAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_IndividualAccount=_BlitzSteamCSteamID_IndividualAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_AnonAccount=_BlitzSteamCSteamID_AnonAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonUserAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonUserAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_AnonUserAccount=_BlitzSteamCSteamID_AnonUserAccount@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ConsoleUserAccount(CSteamID* pSteamID) {
	return pSteamID->BConsoleUserAccount();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ConsoleUserAccount=_BlitzSteamCSteamID_ConsoleUserAccount@4")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetAccountID(CSteamID* pSteamID, AccountID_t unAccountID) {
	pSteamID->SetAccountID(unAccountID);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_SetAccountID=_BlitzSteamCSteamID_SetAccountID@8")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetAccountInstance(CSteamID* pSteamID, uint32_t unInstance) {
	pSteamID->SetAccountInstance(unInstance);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_SetAccountInstance=_BlitzSteamCSteamID_SetAccountInstance@8")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_ClearIndividualInstance(CSteamID* pSteamID) {
	pSteamID->ClearIndividualInstance();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_ClearIndividualInstance=_BlitzSteamCSteamID_ClearIndividualInstance@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_HasNoIndividualInstance(CSteamID* pSteamID) {
	return pSteamID->HasNoIndividualInstance();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_HasNoIndividualInstance=_BlitzSteamCSteamID_HasNoIndividualInstance@4")

DLL_EXPORT AccountID_t DLL_CALL BlitzSteamCSteamID_GetAccountID(CSteamID* pSteamID) {
	return pSteamID->GetAccountID();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GetAccountID=_BlitzSteamCSteamID_GetAccountID@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_GetAccountInstance(CSteamID* pSteamID) {
	return pSteamID->GetUnAccountInstance();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GetAccountInstance=_BlitzSteamCSteamID_GetAccountInstance@4")

DLL_EXPORT EAccountType DLL_CALL BlitzSteamCSteamID_GetEAccountType(CSteamID* pSteamID) {
	return pSteamID->GetEAccountType();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GetEAccountType=_BlitzSteamCSteamID_GetEAccountType@4")

DLL_EXPORT EUniverse DLL_CALL BlitzSteamCSteamID_GetEUniverse(CSteamID* pSteamID) {
	return pSteamID->GetEUniverse();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_GetEUniverse=_BlitzSteamCSteamID_GetEUniverse@4")

DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetEUniverse(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->SetEUniverse(eUniverse);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_SetEUniverse=_BlitzSteamCSteamID_SetEUniverse@8")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IsValid(CSteamID* pSteamID) {
	return pSteamID->IsValid();
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_IsValid=_BlitzSteamCSteamID_IsValid@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_Compare(CSteamID* pSteamID, CSteamID* pSteamIDOther) {
	return (pSteamID == pSteamIDOther ? 1 : 0) + (pSteamID < pSteamIDOther ? 2 : 0) + (pSteamID > pSteamIDOther ? 4 : 0);
}
#pragma comment(linker, "/EXPORT:BlitzSteamCSteamID_Compare=_BlitzSteamCSteamID_Compare@8")
