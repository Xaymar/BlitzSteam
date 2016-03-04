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

DLL_FUNCTION(double_t*) BS_Double_New() {
	return new double_t;
}
DLL_FUNCTION(double_t*) BS_Double_Copy(double_t* pOther) {
	return new double_t(*pOther);
}
DLL_FUNCTION(void) BS_Double_Destroy(double_t* pThis) {
	delete pThis;
}

char* BS_Double_Buffer = new char[32];
DLL_FUNCTION(const char*) BS_Double_ToString(double_t* pThis) {
	std::stringstream myStream;
	myStream << (*pThis);

	const char* myBuffer = myStream.str().c_str();
	strcpy_s(BS_Double_Buffer, 32, myBuffer);
	return BS_Double_Buffer;
}
DLL_FUNCTION(double_t*) BS_Double_FromString(const char* pString) {
	double_t* pThis = new double_t;
	std::stringstream myStream = std::stringstream(pString);
	myStream >> *pThis;
	return pThis;
}

DLL_FUNCTION(double_t*) BS_Double_FromF(float_t fOther) {
	return new double_t(fOther);
}
DLL_FUNCTION(float_t) BS_Double_ToF(double_t* pThis) {
	return (float_t)*pThis;
}

DLL_FUNCTION(double_t*) BS_Double_FromI(int32_t iOther) {
	return new double_t(iOther);
}
DLL_FUNCTION(int32_t) BS_Double_ToI(double_t* pThis) {
	return (int32_t)*pThis;
}

DLL_FUNCTION(double_t*) BS_Double_FromL(int64_t* pOther) {
	return new double_t((double_t)*pOther);
}
DLL_FUNCTION(int64_t*) BS_Double_ToL(double_t* pThis) {
	return new int64_t((int64_t)*pThis);
}

DLL_FUNCTION(int32_t) BS_Double_Compare(double_t* pThis, double_t* pOther) {
	return /* It can either be Equal (0) or Smaller or Greater. Easy to check. */
		   /* Greater */
		(*pThis > *pOther ? 1 : 0) +
		/* Smaller */
		(*pThis < *pOther ? -1 : 0);
}

DLL_FUNCTION(double_t*) BS_Double_Set(double_t* pThis, double_t* pOther) {
	*pThis = *pOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_Add(double_t* pThis, double_t* pOther) {
	*pThis += *pOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_Sub(double_t* pThis, double_t* pOther) {
	*pThis -= *pOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_Div(double_t* pThis, double_t* pOther) {
	*pThis /= *pOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_Mul(double_t* pThis, double_t* pOther) {
	*pThis *= *pOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_Mod(double_t* pThis, double_t* pOther) {
	*pThis = fmod(*pThis, *pOther);
	return pThis;
}

DLL_FUNCTION(double_t*) BS_Double_SetF(double_t* pThis, float_t fOther) {
	*pThis = fOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_AddF(double_t* pThis, float_t fOther) {
	*pThis += fOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_SubF(double_t* pThis, float_t fOther) {
	*pThis -= fOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_DivF(double_t* pThis, float_t fOther) {
	*pThis /= fOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_MulF(double_t* pThis, float_t fOther) {
	*pThis *= fOther;
	return pThis;
}
DLL_FUNCTION(double_t*) BS_Double_ModF(double_t* pThis, float_t fOther) {
	*pThis = fmod(*pThis, fOther);
	return pThis;
}