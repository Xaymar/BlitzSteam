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

// STL Exceptions
#include <exception>
#include <stdexcept>

// Memory Management
#include <memory>

// Platform specific: Windows
#include <windows.h>

// Macros
#define DLL_EXPORT extern "C" //__declspec(dllexport)
#define DLL_METHOD extern "C"
#define DLL_CALL __stdcall

// Steam
#include "SteamworksSDK/public/steam/steam_api.h"