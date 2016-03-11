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
	char* output = new char[strlen(pchFormat) * 4];
	time_t t = unTime;
	struct tm *tm = localtime(&t);
	strftime(output, sizeof(output), pchFormat, tm);
	delete tm;
	return output;
}

DLL_FUNCTION(void) BS_Helper_CopyMemoryIntMangle(void* pSource, void* pDest, int32_t iMangling,
												 uint32_t iSourceW, uint32_t iSourceH, uint32_t iDestW, uint32_t iDestH,
												 uint32_t iAreaX, uint32_t iAreaY, uint32_t iAreaW, uint32_t iAreaH) {
	int8_t iMangleByte0 = static_cast<int8_t>((iMangling & 0xFF));
	int8_t iMangleByte1 = static_cast<int8_t>((iMangling & 0xFF00) >> 8);
	int8_t iMangleByte2 = static_cast<int8_t>((iMangling & 0xFF0000) >> 16);
	int8_t iMangleByte3 = static_cast<int8_t>((iMangling & 0xFF000000) >> 24);

	if (pSource > pDest) {
		// Start at beginning
		for (uint32_t iY = iAreaY; iY < (iAreaY + iAreaH); iY++) {
			// Only do this once per loop
			for (uint32_t iX = iAreaX; iX < (iAreaX + iAreaW); iX++) {
				// Could technically optimize the following into single instructions, but this is fast enough for now.
				uint32_t* pSourceOff = reinterpret_cast<uint32_t*>(pSource) + ((iSourceW * iY) + iX);
				uint32_t* pDestOff = reinterpret_cast<uint32_t*>(pDest) + ((iDestW * iY) + iX);

				// Allow Mangling using just a single integer and checking on the fly if it's positive or negative to branch out to the correct shift.
				*pDestOff =
					(iMangleByte0 > 0 ?
					 (*pSourceOff & 0xFF) >> iMangleByte0 :
					 (*pSourceOff & 0xFF) << -iMangleByte0)
					+ (iMangleByte1 > 0 ?
					 (*pSourceOff & 0xFF00) >> iMangleByte1 :
					 (*pSourceOff & 0xFF00) << -iMangleByte1) 
					+ (iMangleByte2 > 0 ?
					 (*pSourceOff & 0xFF0000) >> iMangleByte2 :
					 (*pSourceOff & 0xFF0000) << -iMangleByte2)
					+ (iMangleByte3 > 0 ?
					 (*pSourceOff & 0xFF000000) >> iMangleByte3 :
					 (*pSourceOff & 0xFF000000) << -iMangleByte3);
			}
		}
	} else {
		//ToDo, mirror the above. Instead of adding we subtract.
		//// Start at end

		//for (uint32_t iY = y + h; iY >= y; iY--) {
		//	pSourceOff = reinterpret_cast<uint32_t*>(pSource) + ((tw * iY) + x);
		//	pDestOff = reinterpret_cast<uint32_t*>(pDest) + ((tw * iY) + x);

		//	for (uint32_t iX = x + w; iX >= x; iX--) {
		//		*pDestOff =
		//			(iMangleByte0 > 0 ?
		//			 (*pSourceOff & 0xFF) >> iMangleByte0 :
		//			 (*pSourceOff & 0xFF) << -iMangleByte0)
		//			+ (iMangleByte1 > 0 ?
		//			   (*pSourceOff & 0xFF00) >> iMangleByte1 :
		//			   (*pSourceOff & 0xFF00) << -iMangleByte1)
		//			+ (iMangleByte2 > 0 ?
		//			   (*pSourceOff & 0xFF0000) >> iMangleByte2 :
		//			   (*pSourceOff & 0xFF0000) << -iMangleByte2)
		//			+ (iMangleByte3 > 0 ?
		//			   (*pSourceOff & 0xFF000000) >> iMangleByte3 :
		//			   (*pSourceOff & 0xFF000000) << -iMangleByte3);

		//		// Above is some mangling magic i learned in some source code. Allows you to define a byte bit shift using a single integer.
		//		pSourceOff -= 1;
		//		pDestOff -= 1;
		//	}
		//}
	}
}