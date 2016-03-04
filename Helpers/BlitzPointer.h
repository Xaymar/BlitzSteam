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

BS_I
// Types of Blitz Functions.
typedef int32_t(__stdcall *BP_BlitzFunction0_t)();
typedef int32_t(__stdcall *BP_BlitzFunction1_t)(int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction2_t)(int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction3_t)(int32_t, int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction4_t)(int32_t, int32_t, int32_t, int32_t);
typedef int32_t(__stdcall *BP_BlitzFunction5_t)(int32_t, int32_t, int32_t, int32_t, int32_t);

#define BP_CallFunction0(ptr)						(reinterpret_cast<BP_BlitzFunction0_t>(ptr))()
#define BP_CallFunction1(ptr, p1)					(reinterpret_cast<BP_BlitzFunction1_t>(ptr))(p1)
#define BP_CallFunction2(ptr, p1, p2)				(reinterpret_cast<BP_BlitzFunction2_t>(ptr))(p1, p2)
#define BP_CallFunction3(ptr, p1, p2, p3)			(reinterpret_cast<BP_BlitzFunction3_t>(ptr))(p1, p2, p3)
#define BP_CallFunction4(ptr, p1, p2, p3, p4)		(reinterpret_cast<BP_BlitzFunction4_t>(ptr))(p1, p2, p3, p4)
#define BP_CallFunction5(ptr, p1, p2, p3, p4, p5)	(reinterpret_cast<BP_BlitzFunction5_t>(ptr))(p1, p2, p3, p4, p5)