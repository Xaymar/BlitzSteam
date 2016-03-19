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
#include <stdlib.h>


DLL(void*) BS_Memory_Alloc(uint32_t iSize);
DLL(void*) BS_Memory_ReAlloc(void* pMemory, uint32_t iNewSize);
DLL(void) BS_Memory_Free(void* pMemory);

DLL(void) BS_Memory_PokeByte(void* pMemory, uint32_t offset, int8_t value);
DLL(int32_t) BS_Memory_PeekByte(void* pMemory, uint32_t offset);

DLL(void) BS_Memory_PokeShort(void* pMemory, uint32_t offset, int16_t value);
DLL(int32_t) BS_Memory_PeekShort(void* pMemory, uint32_t offset);

DLL(void) BS_Memory_PokeInt(void* pMemory, uint32_t offset, int32_t value);
DLL(int32_t) BS_Memory_PeekInt(void* pMemory, uint32_t offset);

DLL(void) BS_Memory_PokeFloat(void* pMemory, uint32_t offset, float_t value);
DLL(float_t) BS_Memory_PeekFloat(void* pMemory, uint32_t offset);

DLL(void) BS_Memory_PokeLong(void* pMemory, uint32_t offset, int64_t* value);
DLL(int64_t*) BS_Memory_PeekLong(void* pMemory, uint32_t offset);

DLL(void) BS_Memory_PokeDouble(void* pMemory, uint32_t offset, double_t* value);
DLL(double_t*) BS_Memory_PeekDouble(void* pMemory, uint32_t offset);
