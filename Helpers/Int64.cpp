//	BlitzSteam - Steam wrapper for Blitz.
//	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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

#include "dllmain.h"
#include <string>
#include <sstream>

#pragma region Construction & Destruction
DLL_EXPORT int64_t* BlitzSteamInt64_New() {
	return new int64_t;
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_New=_BlitzSteamInt64_New@0")

DLL_EXPORT int64_t* BlitzSteamInt64_Copy(int64_t* other) {
	int64_t* pthis = new int64_t;
	*pthis = *other;
	return pthis;
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_Copy=_BlitzSteamInt64_Copy@4")

DLL_EXPORT void BlitzSteamInt64_Destroy(int64_t* pthis) {
	delete pthis;
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_Destroy=_BlitzSteamInt64_Destroy@4")
#pragma endregion Construction & Destruction

#pragma region Math
DLL_EXPORT void BlitzSteamInt64_SetP(int64_t* pthis, int64_t* other) { *pthis = *other; }
DLL_EXPORT void BlitzSteamInt64_SetV(int64_t* pthis, uint32_t left, uint32_t right) { *pthis = ((int64_t)left << 32) + right; }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SetP=_BlitzSteamInt64_SetP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SetV=_BlitzSteamInt64_SetV@12")

DLL_EXPORT void BlitzSteamInt64_AddP(int64_t* pthis, int64_t* other) { *pthis += *other; }
DLL_EXPORT void BlitzSteamInt64_AddV(int64_t* pthis, uint32_t left, uint32_t right) { *pthis += ((int64_t)left << 32) + right; }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_AddP=_BlitzSteamInt64_AddP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_AddV=_BlitzSteamInt64_AddV@12")

DLL_EXPORT void BlitzSteamInt64_SubP(int64_t* pthis, int64_t* other) { *pthis -= *other; }
DLL_EXPORT void BlitzSteamInt64_SubV(int64_t* pthis, uint32_t left, uint32_t right) { *pthis -= ((int64_t)left << 32) + right; }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SubP=_BlitzSteamInt64_SubP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SubV=_BlitzSteamInt64_SubV@12")

DLL_EXPORT void BlitzSteamInt64_MulP(int64_t* pthis, int64_t* other) { *pthis *= *other; }
DLL_EXPORT void BlitzSteamInt64_MulV(int64_t* pthis, uint32_t left, uint32_t right) { *pthis *= ((int64_t)left << 32) + right; }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_MulP=_BlitzSteamInt64_MulP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_MulV=_BlitzSteamInt64_MulV@12")

DLL_EXPORT void BlitzSteamInt64_DivP(int64_t* pthis, int64_t* other) { *pthis *= *other; }
DLL_EXPORT void BlitzSteamInt64_DivV(int64_t* pthis, uint32_t left, uint32_t right) { *pthis *= ((int64_t)left << 32) + right; }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_DivP=_BlitzSteamInt64_DivP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_DivV=_BlitzSteamInt64_DivV@12")
#pragma endregion Math

#pragma region Comparison
DLL_EXPORT uint32_t BlitzSteamInt64_EqualsP(int64_t* pthis, int64_t* other) { return (*pthis == *other); }
DLL_EXPORT uint32_t BlitzSteamInt64_EqualsV(int64_t* pthis, uint32_t left, uint32_t right) { return (*pthis == ((int64_t)left << 32) + right); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_EqualsP=_BlitzSteamInt64_EqualsP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_EqualsV=_BlitzSteamInt64_EqualsV@12")

DLL_EXPORT uint32_t BlitzSteamInt64_GEqualsP(int64_t* pthis, int64_t* other) { return (*pthis >= *other); }
DLL_EXPORT uint32_t BlitzSteamInt64_GEqualsV(int64_t* pthis, uint32_t left, uint32_t right) { return (*pthis >= ((int64_t)left << 32) + right); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_GEqualsP=_BlitzSteamInt64_GEqualsP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_GEqualsV=_BlitzSteamInt64_GEqualsV@12")

DLL_EXPORT uint32_t BlitzSteamInt64_SEqualsP(int64_t* pthis, int64_t* other) { return (*pthis <= *other); }
DLL_EXPORT uint32_t BlitzSteamInt64_SEqualsV(int64_t* pthis, uint32_t left, uint32_t right) { return (*pthis <= ((int64_t)left << 32) + right); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SEqualsP=_BlitzSteamInt64_SEqualsP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SEqualsV=_BlitzSteamInt64_SEqualsV@12")

DLL_EXPORT uint32_t BlitzSteamInt64_GreaterP(int64_t* pthis, int64_t* other) { return (*pthis > *other); }
DLL_EXPORT uint32_t BlitzSteamInt64_GreaterV(int64_t* pthis, uint32_t left, uint32_t right) { return (*pthis > ((int64_t)left << 32) + right); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_GreaterP=_BlitzSteamInt64_GreaterP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_GreaterV=_BlitzSteamInt64_GreaterV@12")

DLL_EXPORT uint32_t BlitzSteamInt64_SmallerP(int64_t* pthis, int64_t* other) { return (*pthis < *other); }
DLL_EXPORT uint32_t BlitzSteamInt64_SmallerV(int64_t* pthis, uint32_t left, uint32_t right) { return (*pthis < ((int64_t)left << 32) + right); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SmallerP=_BlitzSteamInt64_SmallerP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_SmallerV=_BlitzSteamInt64_SmallerV@12")
#pragma endregion Comparison

#pragma region Conversion
DLL_EXPORT const char* BlitzSteamInt64_ToString(int64_t* pthis) {
	std::stringstream stream;
	stream << *pthis;
	return stream.str().c_str();
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_ToString=_BlitzSteamInt64_ToString@4")

// Int64 -> Int32
DLL_EXPORT int32_t BlitzSteamInt64_ValueL(int64_t* pthis) { return (int32_t)((*pthis) >> 32); }
DLL_EXPORT int32_t BlitzSteamInt64_ValueR(int64_t* pthis) { return (int32_t)((*pthis) && 0xFFFFFFFF); }
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_ValueL=_BlitzSteamInt64_ValueL@4")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_ValueR=_BlitzSteamInt64_ValueR@4")

// Int64 <-> Float
DLL_EXPORT float BlitzSteamInt64_ToFloat(int64_t* pthis) { return (float)*pthis; }
DLL_EXPORT int64_t* BlitzSteamInt64_FromFloat(float_t other) {
	int64_t val = (int64_t)other;
	return BlitzSteamInt64_Copy(&val);
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_ToFloat=_BlitzSteamInt64_ToFloat@4")
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_FromFloat=_BlitzSteamInt64_FromFloat@4")

// Int64 -> Double
DLL_EXPORT double_t* BlitzSteamInt64_ToDouble(int64_t* pthis) {
	double_t* val = new double_t;
	*val = (double_t)*pthis;
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamInt64_ToDouble=_BlitzSteamInt64_ToDouble@4")
#pragma endregion Conversion
