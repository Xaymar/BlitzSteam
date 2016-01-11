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

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_New() {
	return new CSteamID();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_New=_BS_CSteamID_New@0")

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromID(uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(unAccountID, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_FromID=_BS_CSteamID_FromID@12")

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromIDInstance(uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType) {
	return new CSteamID(unAccountID, unInstance, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_FromIDInstance=_BS_CSteamID_FromIDInstance@16")

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromSteamID(uint64_t* ulSteamID) {
	return new CSteamID(*ulSteamID);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_FromSteamID=_BS_CSteamID_FromSteamID@4")

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_Copy(CSteamID* pSteamID) {
	return new CSteamID(*pSteamID);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_Copy=_BS_CSteamID_Copy@4")

DLL_EXPORT void DLL_CALL BS_CSteamID_Destroy(CSteamID* pSteamID) {
	delete pSteamID;
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_Destroy=_BS_CSteamID_Destroy@4")

DLL_EXPORT void DLL_CALL BS_CSteamID_Set(CSteamID* pSteamID, uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->Set(unAccountID, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_Set=_BS_CSteamID_Set@16")

DLL_EXPORT void DLL_CALL BS_CSteamID_InstancedSet(CSteamID* pSteamID, uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->InstancedSet(unAccountID, unInstance, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_InstancedSet=_BS_CSteamID_InstancedSet@20")

DLL_EXPORT void DLL_CALL BS_CSteamID_FullSet(CSteamID* pSteamID, uint64_t* ulIdentifier, EUniverse eUniverse, EAccountType eAccountType) {
	pSteamID->FullSet(*ulIdentifier, eUniverse, eAccountType);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_FullSet=_BS_CSteamID_FullSet@16")

DLL_EXPORT void DLL_CALL BS_CSteamID_SetFromUInt64(CSteamID* pSteamID, uint64_t* ulSteamID) {
	pSteamID->SetFromUint64(*ulSteamID);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_SetFromUInt64=_BS_CSteamID_SetFromUInt64@8")

DLL_EXPORT void DLL_CALL BS_CSteamID_Clear(CSteamID* pSteamID) {
	pSteamID->Clear();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_Clear=_BS_CSteamID_Clear@4")

DLL_EXPORT uint64_t* DLL_CALL BS_CSteamID_ConvertToUInt64(CSteamID* pSteamID) {
	uint64_t* val = new uint64_t;
	*val = pSteamID->ConvertToUint64();
	return val;
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ConvertToUInt64=_BS_CSteamID_ConvertToUInt64@4")

DLL_EXPORT uint64_t* DLL_CALL BS_CSteamID_GetStaticAccountKey(CSteamID* pSteamID) {
	uint64_t* val = new uint64_t;
	*val = pSteamID->GetStaticAccountKey();
	return val;
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GetStaticAccountKey=_BS_CSteamID_GetStaticAccountKey@4")

DLL_EXPORT void DLL_CALL BS_CSteamID_CreateBlankAnonLogon(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->CreateBlankAnonLogon(eUniverse);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_CreateBlankAnonLogon=_BS_CSteamID_CreateBlankAnonLogon@8")

DLL_EXPORT void DLL_CALL BS_CSteamID_CreateBlankAnonUserLogon(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->CreateBlankAnonUserLogon(eUniverse);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_CreateBlankAnonUserLogon=_BS_CSteamID_CreateBlankAnonUserLogon@8")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_BlankAnonAccount(CSteamID* pSteamID) {
	return pSteamID->BBlankAnonAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_BlankAnonAccount=_BS_CSteamID_BlankAnonAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_GameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GameServerAccount=_BS_CSteamID_GameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_PersistentGameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BPersistentGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_PersistentGameServerAccount=_BS_CSteamID_PersistentGameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonGameServerAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonGameServerAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_AnonGameServerAccount=_BS_CSteamID_AnonGameServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ContentServerAccount(CSteamID* pSteamID) {
	return pSteamID->BContentServerAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ContentServerAccount=_BS_CSteamID_ContentServerAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ClanAccount(CSteamID* pSteamID) {
	return pSteamID->BClanAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ClanAccount=_BS_CSteamID_ClanAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ChatAccount(CSteamID* pSteamID) {
	return pSteamID->BChatAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ChatAccount=_BS_CSteamID_ChatAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IsLobby(CSteamID* pSteamID) {
	return pSteamID->IsLobby();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_IsLobby=_BS_CSteamID_IsLobby@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IndividualAccount(CSteamID* pSteamID) {
	return pSteamID->BIndividualAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_IndividualAccount=_BS_CSteamID_IndividualAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_AnonAccount=_BS_CSteamID_AnonAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonUserAccount(CSteamID* pSteamID) {
	return pSteamID->BAnonUserAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_AnonUserAccount=_BS_CSteamID_AnonUserAccount@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ConsoleUserAccount(CSteamID* pSteamID) {
	return pSteamID->BConsoleUserAccount();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ConsoleUserAccount=_BS_CSteamID_ConsoleUserAccount@4")

DLL_EXPORT void DLL_CALL BS_CSteamID_SetAccountID(CSteamID* pSteamID, AccountID_t unAccountID) {
	pSteamID->SetAccountID(unAccountID);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_SetAccountID=_BS_CSteamID_SetAccountID@8")

DLL_EXPORT void DLL_CALL BS_CSteamID_SetAccountInstance(CSteamID* pSteamID, uint32_t unInstance) {
	pSteamID->SetAccountInstance(unInstance);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_SetAccountInstance=_BS_CSteamID_SetAccountInstance@8")

DLL_EXPORT void DLL_CALL BS_CSteamID_ClearIndividualInstance(CSteamID* pSteamID) {
	pSteamID->ClearIndividualInstance();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_ClearIndividualInstance=_BS_CSteamID_ClearIndividualInstance@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_HasNoIndividualInstance(CSteamID* pSteamID) {
	return pSteamID->HasNoIndividualInstance();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_HasNoIndividualInstance=_BS_CSteamID_HasNoIndividualInstance@4")

DLL_EXPORT AccountID_t DLL_CALL BS_CSteamID_GetAccountID(CSteamID* pSteamID) {
	return pSteamID->GetAccountID();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GetAccountID=_BS_CSteamID_GetAccountID@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_GetAccountInstance(CSteamID* pSteamID) {
	return pSteamID->GetUnAccountInstance();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GetAccountInstance=_BS_CSteamID_GetAccountInstance@4")

DLL_EXPORT EAccountType DLL_CALL BS_CSteamID_GetEAccountType(CSteamID* pSteamID) {
	return pSteamID->GetEAccountType();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GetEAccountType=_BS_CSteamID_GetEAccountType@4")

DLL_EXPORT EUniverse DLL_CALL BS_CSteamID_GetEUniverse(CSteamID* pSteamID) {
	return pSteamID->GetEUniverse();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_GetEUniverse=_BS_CSteamID_GetEUniverse@4")

DLL_EXPORT void DLL_CALL BS_CSteamID_SetEUniverse(CSteamID* pSteamID, EUniverse eUniverse) {
	pSteamID->SetEUniverse(eUniverse);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_SetEUniverse=_BS_CSteamID_SetEUniverse@8")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IsValid(CSteamID* pSteamID) {
	return pSteamID->IsValid();
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_IsValid=_BS_CSteamID_IsValid@4")

DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_Compare(CSteamID* pSteamID, CSteamID* pSteamIDOther) {
	return (pSteamID == pSteamIDOther ? 1 : 0) + (pSteamID < pSteamIDOther ? 2 : 0) + (pSteamID > pSteamIDOther ? 4 : 0);
}
#pragma comment(linker, "/EXPORT:BS_CSteamID_Compare=_BS_CSteamID_Compare@8")
