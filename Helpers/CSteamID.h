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

#include "dllmain.h"

DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_New();
DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromID(uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromIDInstance(uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_FromSteamID(uint64_t* ulSteamID);
DLL_EXPORT CSteamID* DLL_CALL BS_CSteamID_Copy(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_Destroy(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_Set(CSteamID* pSteamID, uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BS_CSteamID_InstancedSet(CSteamID* pSteamID, uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BS_CSteamID_FullSet(CSteamID* pSteamID, uint64_t* ulIdentifier, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BS_CSteamID_SetFromUInt64(CSteamID* pSteamID, uint64_t* ulSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_Clear(CSteamID* pSteamID);
DLL_EXPORT uint64_t* DLL_CALL BS_CSteamID_ConvertToUInt64(CSteamID* pSteamID);
DLL_EXPORT uint64_t* DLL_CALL BS_CSteamID_GetStaticAccountKey(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_CreateBlankAnonLogon(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT void DLL_CALL BS_CSteamID_CreateBlankAnonUserLogon(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_BlankAnonAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_GameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_PersistentGameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonGameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ContentServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ClanAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ChatAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IsLobby(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IndividualAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_AnonUserAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_ConsoleUserAccount(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_SetAccountID(CSteamID* pSteamID, AccountID_t unAccountID);
DLL_EXPORT void DLL_CALL BS_CSteamID_SetAccountInstance(CSteamID* pSteamID, uint32_t unInstance);
DLL_EXPORT void DLL_CALL BS_CSteamID_ClearIndividualInstance(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_HasNoIndividualInstance(CSteamID* pSteamID);
DLL_EXPORT AccountID_t DLL_CALL BS_CSteamID_GetAccountID(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_GetAccountInstance(CSteamID* pSteamID);
DLL_EXPORT EAccountType DLL_CALL BS_CSteamID_GetEAccountType(CSteamID* pSteamID);
DLL_EXPORT EUniverse DLL_CALL BS_CSteamID_GetEUniverse(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BS_CSteamID_SetEUniverse(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_IsValid(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BS_CSteamID_Compare(CSteamID* pSteamID, CSteamID* pSteamIDOther);