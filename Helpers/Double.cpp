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
DLL_EXPORT double_t* BlitzSteamDouble_New() {
	return new double_t;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_New=_BlitzSteamDouble_New@0")

DLL_EXPORT double_t* BlitzSteamDouble_Copy(double_t* other) {
	double_t* pthis = new double_t;
	*pthis = *other;
	return pthis;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_Copy=_BlitzSteamDouble_Copy@4")

DLL_EXPORT void BlitzSteamDouble_Delete(double_t* pthis) {
	delete pthis;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_Delete=_BlitzSteamDouble_Delete@4")
#pragma endregion Construction & Destruction

#pragma region Math
DLL_EXPORT void BlitzSteamDouble_SetP(double_t* pthis, double_t* other) { *pthis = *other; }
DLL_EXPORT void BlitzSteamDouble_SetF(double_t* pthis, float_t other) { *pthis = other; }
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_SetP=_BlitzSteamDouble_SetP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_SetF=_BlitzSteamDouble_SetF@8")

DLL_EXPORT void BlitzSteamDouble_AddP(double_t* pthis, double_t* other) { *pthis += *other; }
DLL_EXPORT void BlitzSteamDouble_AddF(double_t* pthis, float_t other) { *pthis += other; }
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_AddP=_BlitzSteamDouble_AddP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_AddF=_BlitzSteamDouble_AddF@8")

DLL_EXPORT void BlitzSteamDouble_SubP(double_t* pthis, double_t* other) { *pthis -= *other; }
DLL_EXPORT void BlitzSteamDouble_SubF(double_t* pthis, float_t other) { *pthis -= other; }
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_SubP=_BlitzSteamDouble_SubP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_SubF=_BlitzSteamDouble_SubF@8")

DLL_EXPORT void BlitzSteamDouble_MulP(double_t* pthis, double_t* other) { *pthis *= *other; }
DLL_EXPORT void BlitzSteamDouble_MulF(double_t* pthis, float_t other) { *pthis *= other; }
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_MulP=_BlitzSteamDouble_MulP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_MulF=_BlitzSteamDouble_MulF@8")

DLL_EXPORT void BlitzSteamDouble_DivP(double_t* pthis, double_t* other) { *pthis /= *other; }
DLL_EXPORT void BlitzSteamDouble_DivF(double_t* pthis, float_t other) { *pthis /= other; }
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_DivP=_BlitzSteamDouble_DivP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_DivF=_BlitzSteamDouble_DivF@8")
#pragma endregion Math

#pragma region Comparison
DLL_EXPORT uint32_t BlitzSteamDouble_CompareP(double_t* pthis, double_t* other) {
	return (*pthis == *other ? 1 : 0) + (*pthis < *other ? 2 : 0) + (*pthis > *other ? 4 : 0);
}
DLL_EXPORT uint32_t BlitzSteamDouble_CompareF(double_t* pthis, float_t other) {
	return (*pthis == other ? 1 : 0) + (*pthis < other ? 2 : 0) + (*pthis > other ? 4 : 0);
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_CompareP=_BlitzSteamDouble_CompareP@8")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_CompareF=_BlitzSteamDouble_CompareF@8")
#pragma endregion Comparison

#pragma region Conversion
DLL_EXPORT const char* BlitzSteamDouble_ToString(double_t* pthis) {
	std::stringstream stream;
	stream << *pthis;
	return stream.str().c_str();
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_ToString=_BlitzSteamDouble_ToString@4")

// Double <-> Float
DLL_EXPORT float_t BlitzSteamDouble_ToFloat(double_t* pthis) { return (float_t)*pthis; }
DLL_EXPORT double_t* BlitzSteamDouble_FromFloat(float_t other) {
	double_t* val = new double_t;
	*val = (double_t)other;
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_ToFloat=_BlitzSteamDouble_ToFloat@4")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_FromFloat=_BlitzSteamDouble_FromFloat@4")

// Double <-> Int32
DLL_EXPORT int32_t BlitzSteamDouble_ToInt32(double_t* pthis) { return (int32_t)*pthis; }
DLL_EXPORT double_t* BlitzSteamDouble_FromInt32(int32_t other) {
	double_t* val = new double_t;
	*val = (double_t)other;
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_ToInt32=_BlitzSteamDouble_ToInt32@4")
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_FromInt32=_BlitzSteamDouble_FromInt32@4")

// Double -> Int64
DLL_EXPORT int64_t* BlitzSteamDouble_ToInt64(double_t* pthis) {
	int64_t* val = new int64_t;
	*val = (int64_t)*pthis;
	return val;
}
#pragma comment(linker, "/EXPORT:BlitzSteamDouble_ToInt64=_BlitzSteamDouble_ToInt64@4")
#pragma endregion Conversion
