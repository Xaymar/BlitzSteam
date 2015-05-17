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