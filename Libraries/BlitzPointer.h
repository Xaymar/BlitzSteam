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