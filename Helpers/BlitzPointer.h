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

DLL(intptr_t) BS_BlitzPointer_GetReturnAddress();
DLL(intptr_t) BS_BlitzPointer_GetFunctionPointer();

// Types of Blitz Functions.
typedef int32_t(__stdcall *BP_BlitzFunction0_t)();
typedef int32_t(__stdcall *BP_BlitzFunction1_t)(int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction2_t)(int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction3_t)(int32_t, int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction4_t)(int32_t, int32_t, int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction5_t)(int32_t, int32_t, int32_t, int32_t, int32_t);

#define BP_CallFunction0(ptr)						(ptr)()
#define BP_CallFunction1(ptr, p1)					(ptr)(p1)
#define BP_CallFunction2(ptr, p1, p2)				(ptr)(p1, p2)
#define BP_CallFunction3(ptr, p1, p2, p3)			(ptr)(p1, p2, p3)
#define BP_CallFunction4(ptr, p1, p2, p3, p4)		(ptr)(p1, p2, p3, p4)
#define BP_CallFunction5(ptr, p1, p2, p3, p4, p5)	(ptr)(p1, p2, p3, p4, p5)