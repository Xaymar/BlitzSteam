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

DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_New();
DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromID(uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromIDInstance(uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_FromSteamID(uint64_t* ulSteamID);
DLL_EXPORT CSteamID* DLL_CALL BlitzSteamCSteamID_Copy(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Destroy(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Set(CSteamID* pSteamID, uint32_t unAccountID, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_InstancedSet(CSteamID* pSteamID, uint32_t unAccountID, uint32_t unInstance, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_FullSet(CSteamID* pSteamID, uint64_t* ulIdentifier, EUniverse eUniverse, EAccountType eAccountType);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetFromUInt64(CSteamID* pSteamID, uint64_t* ulSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_Clear(CSteamID* pSteamID);
DLL_EXPORT uint64_t* DLL_CALL BlitzSteamCSteamID_ConvertToUInt64(CSteamID* pSteamID);
DLL_EXPORT uint64_t* DLL_CALL BlitzSteamCSteamID_GetStaticAccountKey(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_CreateBlankAnonLogon(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_CreateBlankAnonUserLogon(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_BlankAnonAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_GameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_PersistentGameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonGameServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ContentServerAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ClanAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ChatAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IsLobby(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IndividualAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_AnonUserAccount(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_ConsoleUserAccount(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetAccountID(CSteamID* pSteamID, AccountID_t unAccountID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetAccountInstance(CSteamID* pSteamID, uint32_t unInstance);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_ClearIndividualInstance(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_HasNoIndividualInstance(CSteamID* pSteamID);
DLL_EXPORT AccountID_t DLL_CALL BlitzSteamCSteamID_GetAccountID(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_GetAccountInstance(CSteamID* pSteamID);
DLL_EXPORT EAccountType DLL_CALL BlitzSteamCSteamID_GetEAccountType(CSteamID* pSteamID);
DLL_EXPORT EUniverse DLL_CALL BlitzSteamCSteamID_GetEUniverse(CSteamID* pSteamID);
DLL_EXPORT void DLL_CALL BlitzSteamCSteamID_SetEUniverse(CSteamID* pSteamID, EUniverse eUniverse);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_IsValid(CSteamID* pSteamID);
DLL_EXPORT uint32_t DLL_CALL BlitzSteamCSteamID_Compare(CSteamID* pSteamID, CSteamID* pSteamIDOther);