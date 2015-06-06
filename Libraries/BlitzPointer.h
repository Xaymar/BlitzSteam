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

typedef uint32_t(__cdecl *BlitzPointer_CallFunction0_t)(uint32_t);
typedef uint32_t(__cdecl *BlitzPointer_CallFunction1_t)(uint32_t, uint32_t);
typedef uint32_t(__cdecl *BlitzPointer_CallFunction2_t)(uint32_t, uint32_t, uint32_t);
typedef uint32_t(__cdecl *BlitzPointer_CallFunction3_t)(uint32_t, uint32_t, uint32_t, uint32_t);
typedef uint32_t(__cdecl *BlitzPointer_CallFunction4_t)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

extern BlitzPointer_CallFunction0_t BlitzPointer_CallFunction0;
extern BlitzPointer_CallFunction1_t BlitzPointer_CallFunction1;
extern BlitzPointer_CallFunction2_t BlitzPointer_CallFunction2;
extern BlitzPointer_CallFunction3_t BlitzPointer_CallFunction3;
extern BlitzPointer_CallFunction4_t BlitzPointer_CallFunction4;

void BlitzPointer_Initialize();