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

#include "BlitzSteam.h"

DLL_FUNCTION(ISteamController*) BS_Controller() {
#pragma comment(linker, "/EXPORT:BS_Controller=_BS_Controller@0")
	return SteamController();
}

// Init and Shutdown must be called when starting/ending use of this interface
DLL_FUNCTION(uint32_t) BS_Controller_Init(ISteamController* lpSteamController) {
#pragma comment(linker, "/EXPORT:BS_Controller_Init=_BS_Controller_Init@4")
	return lpSteamController->Init();
}

// Init and Shutdown must be called when starting/ending use of this interface
DLL_FUNCTION(uint32_t) BS_Controller_Shutdown(ISteamController* lpSteamController) {
#pragma comment(linker, "/EXPORT:BS_Controller_Shutdown=_BS_Controller_Shutdown@4")
	return lpSteamController->Shutdown();
}

// Pump callback/callresult events
// Note: SteamAPI_RunCallbacks will do this for you, so you should never need to call this directly.
DLL_FUNCTION(void) BS_Controller_RunFrame(ISteamController* lpSteamController) {
#pragma comment(linker, "/EXPORT:BS_Controller_RunFrame=_BS_Controller_RunFrame@4")
	lpSteamController->RunFrame();
}

// Enumerate currently connected controllers
// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
// Returns the number of handles written to handlesOut
DLL_FUNCTION(uint32_t) BS_Controller_GetConnectedControllers(ISteamController* lpSteamController, ControllerHandle_t* pHandlesOut) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetConnectedControllers=_BS_Controller_GetConnectedControllers@8")
	return lpSteamController->GetConnectedControllers(pHandlesOut);
}

ControllerHandle_t* pControllerHandles = new ControllerHandle_t[STEAM_CONTROLLER_MAX_COUNT];
DLL_FUNCTION(uint32_t) BS_Controller_GetConnectedControllersSimple(ISteamController* lpSteamController) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetConnectedControllersSimple=_BS_Controller_GetConnectedControllersSimple@4")
	return lpSteamController->GetConnectedControllers(pControllerHandles);
}

DLL_FUNCTION(ControllerHandle_t*) BS_Controller_GetConnectedControllersSimple_Index(uint32_t index) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetConnectedControllersSimple_Index=_BS_Controller_GetConnectedControllersSimple_Index@4")
	if (index >= STEAM_CONTROLLER_MAX_COUNT)
		index = STEAM_CONTROLLER_MAX_COUNT - 1;
	return &(pControllerHandles[index]);
}

// Invokes the Steam overlay and brings up the binding screen
// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
DLL_FUNCTION(uint32_t) BS_Controller_ShowBindingPanel(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_ShowBindingPanel=_BS_Controller_ShowBindingPanel@8")
	return lpSteamController->ShowBindingPanel(*pControllerHandle);
}

// ACTION SETS
// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
DLL_FUNCTION(ControllerActionSetHandle_t*) BS_Controller_GetActionSetHandle(ISteamController* lpSteamController, const char* pszActionSetName) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetActionSetHandle=_BS_Controller_GetActionSetHandle@8")
	return new ControllerActionSetHandle_t(lpSteamController->GetActionSetHandle(pszActionSetName));
}

// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
// your state loops, instead of trying to place it in all of your state transitions.
DLL_FUNCTION(void) BS_Controller_ActivateActionSet(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_ActivateActionSet=_BS_Controller_ActivateActionSet@12")
	lpSteamController->ActivateActionSet(*pControllerHandle, *pActionSetHandle);
}

DLL_FUNCTION(ControllerActionSetHandle_t*) BS_Controller_GetCurrentActionSet(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetCurrentActionSet=_BS_Controller_GetCurrentActionSet@8")
	return new ControllerActionSetHandle_t(lpSteamController->GetCurrentActionSet(*pControllerHandle));
}

// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
DLL_FUNCTION(ControllerDigitalActionHandle_t*) BS_Controller_GetDigitalActionHandle(ISteamController* lpSteamController, const char* pszActionName) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionHandle=_BS_Controller_GetDigitalActionHandle@8")
	return new ControllerDigitalActionHandle_t(lpSteamController->GetDigitalActionHandle(pszActionName));
}

// Returns the current state of the supplied digital game action
DLL_FUNCTION(ControllerDigitalActionData_t*) BS_Controller_GetDigitalActionData(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerDigitalActionHandle_t* pDigitalActionHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionData=_BS_Controller_GetDigitalActionData@12")
	return &lpSteamController->GetDigitalActionData(*pControllerHandle, *pDigitalActionHandle);
}

// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
DLL_FUNCTION(int32_t) BS_Controller_GetDigitalActionOrigins(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle, ControllerDigitalActionHandle_t* pDigitalActionHandle, EControllerActionOrigin *pEControllerActionOrigin) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionOrigins=_BS_Controller_GetDigitalActionOrigins@20")
	return lpSteamController->GetDigitalActionOrigins(*pControllerHandle, *pActionSetHandle, *pDigitalActionHandle, pEControllerActionOrigin);
}

// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
DLL_FUNCTION(ControllerAnalogActionHandle_t*) BS_Controller_GetAnalogActionHandle(ISteamController* lpSteamController, const char *pszActionName) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionOrigins=_BS_Controller_GetDigitalActionOrigins@20")
	return new ControllerAnalogActionHandle_t(lpSteamController->GetAnalogActionHandle(pszActionName));
	//BlitzSteam: Cleanup using BS_Helper_DeleteLongLong
}

// Returns the current state of these supplied analog game action
DLL_FUNCTION(ControllerAnalogActionData_t*) BS_Controller_GetAnalogActionData(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionOrigins=_BS_Controller_GetDigitalActionOrigins@20")
	return &lpSteamController->GetAnalogActionData(*pControllerHandle, *pAnalogActionHandle);
}

// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
DLL_FUNCTION(uint32_t) BS_Controller_GetAnalogActionOrigins(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle, EControllerActionOrigin *pEControllerActionOrigin) {
#pragma comment(linker, "/EXPORT:BS_Controller_GetDigitalActionOrigins=_BS_Controller_GetDigitalActionOrigins@20")
	return lpSteamController->GetAnalogActionOrigins(*pControllerHandle, *pActionSetHandle, *pAnalogActionHandle, pEControllerActionOrigin);
}

DLL_FUNCTION(void) BS_Controller_StopAnalogActionMomentum(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle) {
#pragma comment(linker, "/EXPORT:BS_Controller_StopAnalogActionMomentum=_BS_Controller_StopAnalogActionMomentum@12")
	lpSteamController->StopAnalogActionMomentum(*pControllerHandle, *pAnalogActionHandle);
}

// Trigger a haptic pulse on a controller
DLL_FUNCTION(void) BS_Controller_TriggerHapticPulse(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ESteamControllerPad eTargetPad, uint32_t usDurationMicroSec) {
#pragma comment(linker, "/EXPORT:BS_Controller_TriggerHapticPulse=_BS_Controller_TriggerHapticPulse@16")
	lpSteamController->TriggerHapticPulse(*pControllerHandle, eTargetPad, (uint16_t)usDurationMicroSec);
}

DLL_FUNCTION(void) BS_Controller_TriggerRepeatedHapticPulse(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ESteamControllerPad eTargetPad, uint32_t usDurationMicroSec, uint32_t usOffMicroSec, uint32_t unRepeat, uint32_t nFlags) {
#pragma comment(linker, "/EXPORT:BS_Controller_TriggerRepeatedHapticPulse=_BS_Controller_TriggerRepeatedHapticPulse@28")
	lpSteamController->TriggerRepeatedHapticPulse(*pControllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
}