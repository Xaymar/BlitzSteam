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

// Macros
//#define DLL_FUNCTION(type) extern "C" type __stdcall
#define DLL(type) extern "C" __declspec(dllexport) type __stdcall

// C/C++ Includes
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <inttypes.h>

// Steam
#include "SteamworksSDK/public/steam/steam_api.h"
#include "SteamworksSDK/public/steam/steam_gameserver.h"