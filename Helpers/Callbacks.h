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
#include "BlitzSteam.h"

class BS_Callback : CCallbackBase {
	public:
	void* bbRunFunction;
	virtual void Run(void *pvParam);
	virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall);
	virtual int GetCallbackSizeBytes();
};

DLL_FUNCTION(BS_Callback*) BS_Callback_Create(uint32_t fpFunctionPointer);
DLL_FUNCTION(void) BS_Callback_Destroy(BS_Callback* lpCallback);