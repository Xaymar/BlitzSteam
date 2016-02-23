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

#include "BlitzCallback.h"

BlitzCallback::BlitzCallback(BP_Function3_t pFunctionPointer) {
	this->m_pFunctionPointer = pFunctionPointer;
}

BlitzCallback::~BlitzCallback() {
	this->Unregister();
	this->UnregisterResult();
}

int BlitzCallback::GetCallbackSizeBytes() {
	return sizeof(BlitzCallback);
}

void BlitzCallback::Run(void *pvParam) {
	if (this->m_hSteamAPICall != 0)
		this->m_hSteamAPICall = 0; // Caller unregisters for us.

	BP_CallFunction3(m_pFunctionPointer, reinterpret_cast<uint32_t>(pvParam), 0, 0);
}

void BlitzCallback::Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) {
	if (this->m_hSteamAPICall != 0)
		this->m_hSteamAPICall = 0; // Caller unregisters for us.

	BP_CallFunction3(m_pFunctionPointer, reinterpret_cast<uint32_t>(pvParam), (uint32_t)bIOFailure, (uint32_t)&hSteamAPICall);
}

bool BlitzCallback::IsRegistered() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsRegistered) != 0;
}

void BlitzCallback::Register(uint32_t iCallback) {
	if (!this->IsRegistered())
		SteamAPI_RegisterCallback(this, iCallback);
}

void BlitzCallback::Unregister() {
	if (this->IsRegistered())
		SteamAPI_UnregisterCallback(this);
}

void BlitzCallback::RegisterResult(SteamAPICall_t hSteamAPICall) {
	if (this->m_hSteamAPICall == 0) {
		SteamAPI_RegisterCallResult(this, hSteamAPICall);
		this->m_hSteamAPICall = hSteamAPICall;
	}
}

void BlitzCallback::UnregisterResult()
{
	if (this->m_hSteamAPICall != 0) {
		SteamAPI_UnregisterCallResult(this, this->m_hSteamAPICall);
		this->m_hSteamAPICall = 0;
	}
}

bool BlitzCallback::IsGameServer() {
	return (this->m_nCallbackFlags & this->k_ECallbackFlagsGameServer) != 0;
}

void BlitzCallback::SetGameServer(bool bIsGameServer) {
	this->m_nCallbackFlags &= ~k_ECallbackFlagsGameServer;
	if (bIsGameServer)
		this->m_nCallbackFlags |= k_ECallbackFlagsGameServer;
}

// DLL-Callables
DLL_FUNCTION(BlitzCallback*) BS_Callback_Create(BP_Function3_t pFunctionPointer) {
#pragma comment(linker, "/EXPORT:BS_Callback_Create=_BS_Callback_Create@4")
	return new BlitzCallback(pFunctionPointer);
}

DLL_FUNCTION(void) BS_Callback_Destroy(BlitzCallback* pCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_Destroy=_BS_Callback_Destroy@4")
	delete pCallback;
}

DLL_FUNCTION(int32_t) BS_Callback_IsRegistered(BlitzCallback* pCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_IsRegistered=_BS_Callback_IsRegistered@4")
	return pCallback->IsRegistered();
}

DLL_FUNCTION(int32_t) BS_Callback_IsGameServer(BlitzCallback* pCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_IsGameServer=_BS_Callback_IsGameServer@4")
	return pCallback->IsGameServer();
}

DLL_FUNCTION(int32_t) BS_Callback_SetGameServerFlag(BlitzCallback* pCallback, int32_t bIsGameServer) {
#pragma comment(linker, "/EXPORT:BS_Callback_SetGameServerFlag=_BS_Callback_SetGameServerFlag@8")
	bool isGameServer = pCallback->IsGameServer();
	pCallback->SetGameServer(!!bIsGameServer);
	return isGameServer;
}

DLL_FUNCTION(void) BS_Callback_Register(BlitzCallback* pCallback, uint32_t iCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_Register=_BS_Callback_Register@8")
	pCallback->Register(iCallback);
}

DLL_FUNCTION(void) BS_Callback_Unregister(BlitzCallback* pCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_Unregister=_BS_Callback_Unregister@4")
	pCallback->Unregister();
}

DLL_FUNCTION(void) BS_Callback_RegisterResult(BlitzCallback* pCallback, SteamAPICall_t* pSteamAPICall) {
#pragma comment(linker, "/EXPORT:BS_Callback_RegisterResult=_BS_Callback_RegisterResult@8")
	pCallback->RegisterResult(*pSteamAPICall);
}

DLL_FUNCTION(void) BS_Callback_UnregisterResult(BlitzCallback* pCallback) {
#pragma comment(linker, "/EXPORT:BS_Callback_UnregisterResult=_BS_Callback_UnregisterResult@4")
	pCallback->UnregisterResult();
}