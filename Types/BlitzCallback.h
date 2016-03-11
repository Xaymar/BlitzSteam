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
#include "../Helpers/BlitzPointer.h"

#include <list>
#include <vector>
#include <map>

class BlitzCallback : public CCallbackBase {
	// Static Parts
	public:
	/// Initializes the CallbackSizes list for future use.
	static void Initialize();
	static std::map<int32_t, size_t> Sizes;

	// Class Parts
	public:
	// Constructor
	BlitzCallback(BP_BlitzFunction3_t pFunctionPointer);
	// Destructor
	~BlitzCallback();

	// Run
	virtual void Run(void *pvParam);
	virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall);

	// Callback Size
	virtual int GetCallbackSizeBytes();

	// Accessors
	void SetCallback(int32_t iCallback);
	int32_t GetCallback();

	void SetFunction(BP_BlitzFunction3_t pFunction);
	BP_BlitzFunction3_t GetFunction();
	
	bool IsRegistered();
	void SetRegistered(bool bIsRegistered);

	bool IsGameServer();
	void SetGameServer(bool bIsGameServer);

	// Registration in Steam
	/// Register as Callback
	void Register(uint32_t iCallback);
	void Unregister();

	/// Register as CallResult
	void RegisterResult(SteamAPICall_t hSteamAPICall, uint32_t iCallback);
	void UnregisterResult();

	private:
	/// Function to Call
	BP_BlitzFunction3_t m_pFunctionPointer;

	/// Assigned SteamAPICall
	SteamAPICall_t m_hSteamAPICall;
};

//-----------------------------------------------------------------------------
// C-Callables
//-----------------------------------------------------------------------------
DLL_FUNCTION(BlitzCallback*) BS_Callback_New(BP_BlitzFunction3_t pFunctionPointer);
DLL_FUNCTION(void) BS_Callback_Destroy(BlitzCallback* pCallback);

DLL_FUNCTION(int32_t) BS_Callback_GetCallbackSizeBytes(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_SetCallback(BlitzCallback* pCallback, int32_t iCallback);
DLL_FUNCTION(int32_t) BS_Callback_GetCallback(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_SetFunction(BlitzCallback* pCallback, BP_BlitzFunction3_t pFunction);
DLL_FUNCTION(BP_BlitzFunction3_t) BS_Callback_GetFunction(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_SetRegistered(BlitzCallback* pCallback, int32_t bIsRegistered);
DLL_FUNCTION(int32_t) BS_Callback_IsRegistered(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_SetGameServer(BlitzCallback* pCallback, int32_t bIsGameServer);
DLL_FUNCTION(int32_t) BS_Callback_IsGameServer(BlitzCallback* pCallback);

DLL_FUNCTION(void) BS_Callback_Register(BlitzCallback* pCallback, uint32_t iCallback);
DLL_FUNCTION(void) BS_Callback_Unregister(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_RegisterResult(BlitzCallback* pCallback, SteamAPICall_t* pSteamAPICall, uint32_t iCallback);
DLL_FUNCTION(void) BS_Callback_UnregisterResult(BlitzCallback* pCallback);