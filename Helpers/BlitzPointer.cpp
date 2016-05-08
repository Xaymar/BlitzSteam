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

#include "BlitzPointer.h"

DLL(intptr_t) BS_BlitzPointer_GetReturnAddress() {
	intptr_t BasePointer, ReturnAddress;

	__asm { //ASM. Do touch if suicidal.
		mov BasePointer, ebp;		// Store current BasePointer
	}

	// Blitz uses X86 Call-Near (E8) instructions to call its own functions.
	// We can simply deduce the Return Address like this because of that.
	//-- Parent_EBP = *EBP
	//-- Parent_RP = Parent_EBP + 16
	ReturnAddress = *(intptr_t*)((*(intptr_t*)BasePointer) + 16);

	return ReturnAddress;
}

DLL(intptr_t) BS_BlitzPointer_GetFunctionPointer() {
	intptr_t BasePointer, ReturnAddress, FunctionPointer;

	__asm { //ASM. Do touch if suicidal.
		mov BasePointer, ebp;		// Store current BasePointer
	}

	// Blitz uses X86 Call-Near (E8) instructions to call its own functions.
	// We can simply deduce the Return Address like this because of that.
	//-- Parent_EBP = *EBP
	//-- Parent_RP = Parent_EBP + 16
	ReturnAddress = *(intptr_t*)((*(intptr_t*)BasePointer) + 16);

	// And since it's a Call-Near, the call is offset to the return address.
	FunctionPointer = ReturnAddress + *(intptr_t*)(ReturnAddress - 4);

	return FunctionPointer;
}
