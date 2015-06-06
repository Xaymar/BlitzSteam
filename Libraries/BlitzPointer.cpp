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

#pragma once
#include "BlitzPointer.h"

BlitzPointer_CallFunction0_t BlitzPointer_CallFunction0 = 0;
BlitzPointer_CallFunction1_t BlitzPointer_CallFunction1 = 0;
BlitzPointer_CallFunction2_t BlitzPointer_CallFunction2 = 0;
BlitzPointer_CallFunction3_t BlitzPointer_CallFunction3 = 0;
BlitzPointer_CallFunction4_t BlitzPointer_CallFunction4 = 0;
HMODULE hmBlitzPointerDLL;

void BlitzPointer_Initialize() {
	hmBlitzPointerDLL = LoadLibrary(TEXT("BlitzPointer.dll"));
	if (hmBlitzPointerDLL != nullptr) {
		BlitzPointer_CallFunction0 = (BlitzPointer_CallFunction0_t)GetProcAddress(hmBlitzPointerDLL, "BlitzPointer_CallFunction0");
		BlitzPointer_CallFunction1 = (BlitzPointer_CallFunction1_t)GetProcAddress(hmBlitzPointerDLL, "BlitzPointer_CallFunction1");
		BlitzPointer_CallFunction2 = (BlitzPointer_CallFunction2_t)GetProcAddress(hmBlitzPointerDLL, "BlitzPointer_CallFunction2");
		BlitzPointer_CallFunction3 = (BlitzPointer_CallFunction3_t)GetProcAddress(hmBlitzPointerDLL, "BlitzPointer_CallFunction3");
		BlitzPointer_CallFunction4 = (BlitzPointer_CallFunction4_t)GetProcAddress(hmBlitzPointerDLL, "BlitzPointer_CallFunction4");

		if (BlitzPointer_CallFunction0 == nullptr
			|| BlitzPointer_CallFunction1 == nullptr
			|| BlitzPointer_CallFunction2 == nullptr
			|| BlitzPointer_CallFunction3 == nullptr
			|| BlitzPointer_CallFunction4 == nullptr) {
			MessageBox(0, ERROR_TEXT_001, ERROR_TITLE_001, 0);
		}
	} else {
		MessageBox(0, ERROR_TEXT_001, ERROR_TITLE_001, 0);
	}
}