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

#include "Helper.h"

DLL_FUNCTION(const char*) BS_Helper_FormatUnixTime(uint32_t unTime, const char* pchFormat) {
#pragma comment(linker, "/EXPORT:BS_Helper_FormatUnixTime=_BS_Helper_FormatUnixTime@8")
	char* output = new char[strlen(pchFormat) * 4];
	time_t t = unTime;
	struct tm *tm = localtime(&t);
	strftime(output, sizeof(output), pchFormat, tm);
	delete tm;
	return output;
}

DLL_FUNCTION(void) BS_Helper_DeleteLong(uint64_t* pLong) {
#pragma comment(linker, "/EXPORT:BS_Helper_DeleteLong=_BS_Helper_DeleteLong@4")
	delete pLong;
}

DLL_FUNCTION(double_t*) BS_Helper_CreateDouble(float_t value) {
#pragma comment(linker, "/EXPORT:BS_Helper_CreateDouble=_BS_Helper_CreateDouble@4")
	return new double_t(value);
}

DLL_FUNCTION(void) BS_Helper_DeleteDouble(double_t* pDouble) {
#pragma comment(linker, "/EXPORT:BS_Helper_DeleteDouble=_BS_Helper_DeleteDouble@4")
	delete pDouble;
}