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

BS_I#include "BlitzSteam.h"
#include "BlitzPointer.h"

#include <list>
#include <vector>
#include <map>

class BlitzCallback : public CCallbackBase {
	public:
	BlitzCallback(BP_BlitzFunction3_t pFunctionPointer);
	~BlitzCallback();

	virtual void Run(void *pvParam);
	virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall);
	virtual int GetCallbackSizeBytes();

	bool IsRegistered();
	bool IsGameServer();
	void SetGameServer(bool bIsGameServer);

	void Register(uint32_t iCallback);
	void Unregister();

	void RegisterResult(SteamAPICall_t hSteamAPICall, uint32_t iCallback);
	void UnregisterResult();

	private:
	BP_BlitzFunction3_t m_pFunctionPointer;
	uint32_t m_iCallback;
	SteamAPICall_t m_hSteamAPICall;
};

DLL_FUNCTION(BlitzCallback*) BS_Callback_Create(BP_BlitzFunction3_t pFunctionPointer);
DLL_FUNCTION(void) BS_Callback_Destroy(BlitzCallback* pCallback);

DLL_FUNCTION(int32_t) BS_Callback_IsRegistered(BlitzCallback* pCallback);
DLL_FUNCTION(int32_t) BS_Callback_IsGameServer(BlitzCallback* pCallback);
DLL_FUNCTION(int32_t) BS_Callback_SetGameServerFlag(BlitzCallback* pCallback, int32_t isGameServer);

DLL_FUNCTION(void) BS_Callback_Register(BlitzCallback* pCallback, uint32_t iCallback);
DLL_FUNCTION(void) BS_Callback_Unregister(BlitzCallback* pCallback);
DLL_FUNCTION(void) BS_Callback_RegisterResult(BlitzCallback* pCallback, SteamAPICall_t* pSteamAPICall, uint32_t iCallback);
DLL_FUNCTION(void) BS_Callback_UnregisterResult(BlitzCallback* pCallback);