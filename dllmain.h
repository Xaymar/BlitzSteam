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

// STL Exceptions
#include <exception>
#include <stdexcept>

// Memory Management
#include <memory>

// Platform specific: Windows
#include <windows.h>

// Macros
#define DLL_EXPORT extern "C" //__declspec(dllexport)

// Steam
#include "steam/steam_api.h"

// Error Messages
#define ERROR_TITLE_001	TEXT("Error 001")
#define ERROR_TEXT_001	TEXT("E001: Could not load 'BlitzPointer.dll'.")
#define ERROR_TITLE_002 TEXT("Error 002")
#define ERROR_TEXT_002	TEXT("E002: Unable to find one or multiple function addresses in 'BlitzPointer.dll'.")