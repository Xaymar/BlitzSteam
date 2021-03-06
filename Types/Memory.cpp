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

DLL(void*) BS_Memory_Alloc(uint32_t iSize) {
	return malloc(iSize);
}

DLL(void*) BS_Memory_ReAlloc(void* pMemory, uint32_t iNewSize) {
	return realloc(pMemory, iNewSize);
}

DLL(void) BS_Memory_Free(void* pMemory) {
	free(pMemory);
}

DLL(void) BS_Memory_PokeByte(void* pMemory, uint32_t offset, int8_t value) {
	*((reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL(int32_t) BS_Memory_PeekByte(void* pMemory, uint32_t offset) {
	return *(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL(void) BS_Memory_PokeShort(void* pMemory, uint32_t offset, int16_t value) {
	*(reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL(int32_t) BS_Memory_PeekShort(void* pMemory, uint32_t offset) {
	return *(int16_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL(void) BS_Memory_PokeInt(void* pMemory, uint32_t offset, int32_t value) {
	*(reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL(int32_t) BS_Memory_PeekInt(void* pMemory, uint32_t offset) {
	return *(int32_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL(void) BS_Memory_PokeFloat(void* pMemory, uint32_t offset, float_t value) {
	*(reinterpret_cast<float_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = value;
}

DLL(float_t) BS_Memory_PeekFloat(void* pMemory, uint32_t offset) {
	return *(float_t*)(reinterpret_cast<uint8_t*>(pMemory) + offset);
}

DLL(void) BS_Memory_PokeLong(void* pMemory, uint32_t offset, int64_t* value) {
	*(reinterpret_cast<int64_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = *value;
}

DLL(int64_t*) BS_Memory_PeekLong(void* pMemory, uint32_t offset) {
	return new int64_t(*(reinterpret_cast<int64_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)));
}

DLL(void) BS_Memory_PokeDouble(void* pMemory, uint32_t offset, double_t* value) {
	*(reinterpret_cast<double_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)) = *value;
}

DLL(double_t*) BS_Memory_PeekDouble(void* pMemory, uint32_t offset) {
	return new double_t(*(reinterpret_cast<double_t*>(reinterpret_cast<uint8_t*>(pMemory) + offset)));
}
