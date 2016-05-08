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

DLL(double_t*) BS_Double_New();
DLL(double_t*) BS_Double_Copy(double_t* pRight);
DLL(void) BS_Double_Destroy(double_t* pThis);

DLL(const char*) BS_Double_ToString(double_t* pThis);
DLL(double_t*) BS_Double_FromString(const char* pString);

DLL(double_t*) BS_Double_FromF(float_t fOther);
DLL(float_t) BS_Double_ToF(double_t* pThis);

DLL(double_t*) BS_Double_FromI(int32_t iOther);
DLL(int32_t) BS_Double_ToI(double_t* pThis);

DLL(double_t*) BS_Double_FromL(int64_t* pOther);
DLL(int64_t*) BS_Double_ToL(double_t* pThis);

DLL(int32_t) BS_Double_Compare(double_t* pThis, double_t* pOther);

DLL(double_t*) BS_Double_Set(double_t* pThis, double_t* pOther);
DLL(double_t*) BS_Double_Add(double_t* pThis, double_t* pOther);
DLL(double_t*) BS_Double_Sub(double_t* pThis, double_t* pOther);
DLL(double_t*) BS_Double_Div(double_t* pThis, double_t* pOther);
DLL(double_t*) BS_Double_Mul(double_t* pThis, double_t* pOther);
DLL(double_t*) BS_Double_Mod(double_t* pThis, double_t* pOther);

DLL(double_t*) BS_Double_SetF(double_t* pThis, float_t fOther);
DLL(double_t*) BS_Double_AddF(double_t* pThis, float_t fOther);
DLL(double_t*) BS_Double_SubF(double_t* pThis, float_t fOther);
DLL(double_t*) BS_Double_DivF(double_t* pThis, float_t fOther);
DLL(double_t*) BS_Double_MulF(double_t* pThis, float_t fOther);
DLL(double_t*) BS_Double_ModF(double_t* pThis, float_t fOther);
