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
#include <sstream>

DLL(int64_t*) BS_Long_New();
DLL(int64_t*) BS_Long_Copy(int64_t* pRight);
DLL(void) BS_Long_Destroy(int64_t* pThis);

DLL(const char*) BS_Long_ToString(int64_t* pThis);
DLL(int64_t*) BS_Long_FromString(const char* pString);

DLL(int64_t*) BS_Long_FromI(int32_t iRight);
DLL(int64_t*) BS_Long_FromII(int32_t iLeft, int32_t iRight);
DLL(int32_t) BS_Long_ToI(int64_t* pThis, int32_t iShift);
DLL(int32_t) BS_Long_ToIH(int64_t* pThis);
DLL(int32_t) BS_Long_ToIL(int64_t* pThis);

DLL(int64_t*) BS_Long_FromF(float_t fOther);
DLL(float_t) BS_Long_ToF(int64_t* pThis);

DLL(int64_t*) BS_Long_FromD(double_t* pOther);
DLL(double_t*) BS_Long_ToD(int64_t* pThis);

DLL(int32_t) BS_Long_Compare(int64_t* pThis, int64_t* pOther);

DLL(int64_t*) BS_Long_Set(int64_t* pThis, int64_t* pOther);
DLL(int64_t*) BS_Long_Add(int64_t* pThis, int64_t* pOther);
DLL(int64_t*) BS_Long_Sub(int64_t* pThis, int64_t* pOther);
DLL(int64_t*) BS_Long_Div(int64_t* pThis, int64_t* pOther);
DLL(int64_t*) BS_Long_Mul(int64_t* pThis, int64_t* pOther);
DLL(int64_t*) BS_Long_Mod(int64_t* pThis, int64_t* pOther);

DLL(int64_t*) BS_Long_SetI(int64_t* pThis, int32_t iRight);
DLL(int64_t*) BS_Long_AddI(int64_t* pThis, int32_t iRight);
DLL(int64_t*) BS_Long_SubI(int64_t* pThis, int32_t iRight);
DLL(int64_t*) BS_Long_DivI(int64_t* pThis, int32_t iRight);
DLL(int64_t*) BS_Long_MulI(int64_t* pThis, int32_t iRight);
DLL(int64_t*) BS_Long_ModI(int64_t* pThis, int32_t iRight);

DLL(int64_t*) BS_Long_SetII(int64_t* pThis, int32_t iLeft, int32_t iRight);
DLL(int64_t*) BS_Long_AddII(int64_t* pThis, int32_t iLeft, int32_t iRight);
DLL(int64_t*) BS_Long_SubII(int64_t* pThis, int32_t iLeft, int32_t iRight);
DLL(int64_t*) BS_Long_DivII(int64_t* pThis, int32_t iLeft, int32_t iRight);
DLL(int64_t*) BS_Long_MulII(int64_t* pThis, int32_t iLeft, int32_t iRight);
DLL(int64_t*) BS_Long_ModII(int64_t* pThis, int32_t iLeft, int32_t iRight);

DLL(int64_t*) BS_Long_Shift(int64_t* pThis, int32_t iShift);