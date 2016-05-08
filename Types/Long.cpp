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

#include "Long.h"

DLL(int64_t*) BS_Long_New() {
	return new int64_t;
}
DLL(int64_t*) BS_Long_Copy(int64_t* pOther) {
	return new int64_t(*pOther);
}
DLL(void) BS_Long_Destroy(int64_t* pThis) {
	delete pThis;
}

char* BS_Long_Buffer = new char[32];
DLL(const char*) BS_Long_ToString(int64_t* pThis) {
	std::stringstream myStream;
	myStream << (*pThis);

	const char* myBuffer = myStream.str().c_str();
	strcpy_s(BS_Long_Buffer, 32, myBuffer);
	return BS_Long_Buffer;
}
DLL(int64_t*) BS_Long_FromString(const char* pString) {
	int64_t* pThis = new int64_t;
	std::stringstream myStream = std::stringstream(pString);
	myStream >> *pThis;
	return pThis;
}

DLL(int64_t*) BS_Long_FromI(int32_t iRight) {
	return new int64_t(iRight);
}
DLL(int64_t*) BS_Long_FromII(int32_t iLeft, int32_t iRight) {
	return new int64_t(((int64_t)(iLeft) << 32) + iRight);
}
DLL(int32_t) BS_Long_ToI(int64_t* pThis, int32_t iShift) {
	if (iShift >= 0)
		return (int32_t)(*pThis >> iShift);
	else
		return (int32_t)(*pThis << -iShift);
}
DLL(int32_t) BS_Long_ToIH(int64_t* pThis) {
	return (int32_t)(*pThis >> 32);
}
DLL(int32_t) BS_Long_ToIL(int64_t* pThis) {
	return (int32_t)*pThis;
}

DLL(int64_t*) BS_Long_FromF(float_t fOther) {
	return new int64_t((int64_t)fOther);
}
DLL(float_t) BS_Long_ToF(int64_t* pThis) {
	return (float_t)*pThis;
}

DLL(int64_t*) BS_Long_FromD(double_t* pOther) {
	return new int64_t((int64_t)*pOther);
}
DLL(double_t*) BS_Long_ToD(int64_t* pThis) {
	return new double_t((double_t)*pThis);
}

DLL(int32_t) BS_Long_Compare(int64_t* pThis, int64_t* pOther) {
	if ((pThis == nullptr) || (pOther == nullptr))
		return -1;

	return /* It can either be Equal (0) or Smaller or Greater. Easy to check. */
		/* Greater */
		(*pThis > *pOther ? 1 : 0) +
		/* Smaller */
		(*pThis < *pOther ? -1 : 0);
}

DLL(int64_t*) BS_Long_Set(int64_t* pThis, int64_t* pOther) {
	*pThis = *pOther;
	return pThis;
}
DLL(int64_t*) BS_Long_Add(int64_t* pThis, int64_t* pOther) {
	*pThis += *pOther;
	return pThis;
}
DLL(int64_t*) BS_Long_Sub(int64_t* pThis, int64_t* pOther) {
	*pThis -= *pOther;
	return pThis;
}
DLL(int64_t*) BS_Long_Div(int64_t* pThis, int64_t* pOther) {
	*pThis /= *pOther;
	return pThis;
}
DLL(int64_t*) BS_Long_Mul(int64_t* pThis, int64_t* pOther) {
	*pThis *= *pOther;
	return pThis;
}
DLL(int64_t*) BS_Long_Mod(int64_t* pThis, int64_t* pOther) {
	*pThis %= *pOther;
	return pThis;
}

DLL(int64_t*) BS_Long_SetI(int64_t* pThis, int32_t iRight) {
	*pThis = iRight;
	return pThis;
}
DLL(int64_t*) BS_Long_AddI(int64_t* pThis, int32_t iRight) {
	*pThis += iRight;
	return pThis;
}
DLL(int64_t*) BS_Long_SubI(int64_t* pThis, int32_t iRight) {
	*pThis -= iRight;
	return pThis;
}
DLL(int64_t*) BS_Long_DivI(int64_t* pThis, int32_t iRight) {
	*pThis /= iRight;
	return pThis;
}
DLL(int64_t*) BS_Long_MulI(int64_t* pThis, int32_t iRight) {
	*pThis *= iRight;
	return pThis;
}
DLL(int64_t*) BS_Long_ModI(int64_t* pThis, int32_t iRight) {
	*pThis %= iRight;
	return pThis;
}

DLL(int64_t*) BS_Long_SetII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis = (((int64_t)iLeft << 32) + iRight);
	return pThis;
}
DLL(int64_t*) BS_Long_AddII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis += (((int64_t)iLeft << 32) + iRight);
	return pThis;
}
DLL(int64_t*) BS_Long_SubII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis -= (((int64_t)iLeft << 32) + iRight);
	return pThis;
}
DLL(int64_t*) BS_Long_DivII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis /= (((int64_t)iLeft << 32) + iRight);
	return pThis;
}
DLL(int64_t*) BS_Long_MulII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis *= (((int64_t)iLeft << 32) + iRight);
	return pThis;
}
DLL(int64_t*) BS_Long_ModII(int64_t* pThis, int32_t iLeft, int32_t iRight) {
	*pThis %= (((int64_t)iLeft << 32) + iRight);
	return pThis;
}

DLL(int64_t*) BS_Long_Shift(int64_t* pThis, int32_t iRight) {
	if (iRight >= 0)
		*pThis >>= iRight;
	else
		*pThis <<= -iRight;
	return pThis;
}