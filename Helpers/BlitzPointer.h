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

typedef void*(__stdcall *BP_Function0_t)();
typedef void*(__stdcall *BP_Function1_t)(uint32_t);
typedef void*(__stdcall *BP_Function2_t)(uint32_t, uint32_t);
typedef void*(__stdcall *BP_Function3_t)(uint32_t, uint32_t, uint32_t);
typedef void*(__stdcall *BP_Function4_t)(uint32_t, uint32_t, uint32_t, uint32_t);

#define BP_CallFunction0(ptr) ((BP_Function0_t)ptr)()
#define BP_CallFunction1(ptr, p1) ((BP_Function1_t)ptr)(p1)
#define BP_CallFunction2(ptr, p1, p2) ((BP_Function2_t)ptr)(p1, p2)
#define BP_CallFunction3(ptr, p1, p2, p3) ((BP_Function3_t)ptr)(p1, p2, p3)
#define BP_CallFunction4(ptr, p1, p2, p3, p4) ((BP_Function4_t)ptr)(p1, p2, p3, p4)