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

#include "Memory.h"

DLL_FUNCTION(void*) BS_Memory_Alloc(uint32_t iSize) {
#pragma comment(linker, "/EXPORT:BS_Memory_Alloc=_BS_Memory_Alloc@4")
	return malloc(iSize);
}

DLL_FUNCTION(void*) BS_Memory_ReAlloc(void* pMemory, uint32_t iNewSize) {
#pragma comment(linker, "/EXPORT:BS_Memory_ReAlloc=_BS_Memory_ReAlloc@8")
	return realloc(pMemory, iNewSize);
}

DLL_FUNCTION(void) BS_Memory_Free(void* pMemory) {
#pragma comment(linker, "/EXPORT:BS_Memory_Free=_BS_Memory_Free@4")
	free(pMemory);
}

DLL_FUNCTION(uint8_t) BS_Memory_PeekByte(void* pMemory, uint32_t offset) {
#pragma comment(linker, "/EXPORT:BS_Memory_PeekByte=_BS_Memory_PeekByte@8")
	return *(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL_FUNCTION(uint16_t) BS_Memory_PeekShort(void* pMemory, uint32_t offset) {
#pragma comment(linker, "/EXPORT:BS_Memory_PeekShort=_BS_Memory_PeekShort@8")
	return *(uint16_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL_FUNCTION(uint32_t) BS_Memory_PeekInt(void* pMemory, uint32_t offset) {
#pragma comment(linker, "/EXPORT:BS_Memory_PeekInt=_BS_Memory_PeekInt@8")
	return *(uint32_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL_FUNCTION(float_t) BS_Memory_PeekFloat(void* pMemory, uint32_t offset) {
#pragma comment(linker, "/EXPORT:BS_Memory_PeekFloat=_BS_Memory_PeekFloat@8")
	return *(float_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL_FUNCTION(void) BS_Memory_PokeByte(void* pMemory, uint32_t offset, uint8_t value) {
#pragma comment(linker, "/EXPORT:BS_Memory_PokeByte=_BS_Memory_PokeByte@12")
	*((reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL_FUNCTION(void) BS_Memory_PokeShort(void* pMemory, uint32_t offset, uint16_t value) {
#pragma comment(linker, "/EXPORT:BS_Memory_PokeShort=_BS_Memory_PokeShort@12")
	*(reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL_FUNCTION(void) BS_Memory_PokeInt(void* pMemory, uint32_t offset, uint32_t value) {
#pragma comment(linker, "/EXPORT:BS_Memory_PokeInt=_BS_Memory_PokeInt@12")
	*(reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL_FUNCTION(void) BS_Memory_PokeFloat(void* pMemory, uint32_t offset, float_t value) {
#pragma comment(linker, "/EXPORT:BS_Memory_PokeFloat=_BS_Memory_PokeFloat@12")
	*(reinterpret_cast<float_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}