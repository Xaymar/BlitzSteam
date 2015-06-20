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

DLL_EXPORT uint32_t DLL_CALL BlitzSteamController_Init(ISteamController* lpSteamController, const char* pchAbsolutePathToControllerConfigVDF) {
	return lpSteamController->Init(pchAbsolutePathToControllerConfigVDF);
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_Init=_BlitzSteamController_Init@8")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamController_Shutdown(ISteamController* lpSteamController) {
	return lpSteamController->Shutdown();
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_Shutdown=_BlitzSteamController_Shutdown@4")

DLL_EXPORT void DLL_CALL BlitzSteamController_RunFrame(ISteamController* lpSteamController) {
	lpSteamController->RunFrame();
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_RunFrame=_BlitzSteamController_RunFrame@4")

DLL_EXPORT uint32_t DLL_CALL BlitzSteamController_GetControllerState(ISteamController* lpSteamController, uint32_t unControllerIndex, SteamControllerState_t *pState) {
	return lpSteamController->GetControllerState(unControllerIndex, pState);
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_GetControllerState=_BlitzSteamController_GetControllerState@12")

DLL_EXPORT void DLL_CALL BlitzSteamController_TriggerHapticPulse(ISteamController* lpSteamController, uint32_t unControllerIndex, ESteamControllerPad eTargetPad, uint32_t usDurationMicroSec) {
	lpSteamController->TriggerHapticPulse(unControllerIndex, eTargetPad, usDurationMicroSec);
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_TriggerHapticPulse=_BlitzSteamController_TriggerHapticPulse@16")

DLL_EXPORT void DLL_CALL BlitzSteamController_SetOverrideMode(ISteamController* lpSteamController, const char *pchMode) {
	lpSteamController->SetOverrideMode(pchMode);
}
#pragma comment(linker, "/EXPORT:BlitzSteamController_SetOverrideMode=_BlitzSteamController_SetOverrideMode@8")