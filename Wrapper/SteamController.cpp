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

//-----------------------------------------------------------------------------
// Purpose: Native Steam controller support API
//-----------------------------------------------------------------------------
DLL(ISteamController*) BS_SteamController() {
	return SteamController();
}

// Init and Shutdown must be called when starting/ending use of this interface
DLL(int32_t) BS_ISteamController_Init(ISteamController* lpSteamController) {
	return lpSteamController->Init();
}

// Init and Shutdown must be called when starting/ending use of this interface
DLL(int32_t) BS_ISteamController_Shutdown(ISteamController* lpSteamController) {
	return lpSteamController->Shutdown();
}

// Pump callback/callresult events
// Note: SteamAPI_RunCallbacks will do this for you, so you should never need to call this directly.
DLL(void) BS_ISteamController_RunFrame(ISteamController* lpSteamController) {
	lpSteamController->RunFrame();
}

// Enumerate currently connected controllers
// handlesOut should point to a STEAM_CONTROLLER_MAX_COUNT sized array of ControllerHandle_t handles
// Returns the number of handles written to handlesOut
DLL(int32_t) BS_ISteamController_GetConnectedControllers(ISteamController* lpSteamController, ControllerHandle_t* pHandlesOut) {
	return lpSteamController->GetConnectedControllers(pHandlesOut);
}

ControllerHandle_t* pControllerHandles = new ControllerHandle_t[STEAM_CONTROLLER_MAX_COUNT];
DLL(int32_t) BS_ISteamController_GetConnectedControllersSimple(ISteamController* lpSteamController) {
	return lpSteamController->GetConnectedControllers(pControllerHandles);
}

DLL(ControllerHandle_t*) BS_ISteamController_GetConnectedControllersSimple_Index(uint32_t index) {
	if (index >= STEAM_CONTROLLER_MAX_COUNT)
		index = STEAM_CONTROLLER_MAX_COUNT - 1;
	return &(pControllerHandles[index]);
}

// Invokes the Steam overlay and brings up the binding screen
// Returns false is overlay is disabled / unavailable, or the user is not in Big Picture mode
DLL(int32_t) BS_ISteamController_ShowBindingPanel(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle) {
	return lpSteamController->ShowBindingPanel(*pControllerHandle);
}

// ACTION SETS
// Lookup the handle for an Action Set. Best to do this once on startup, and store the handles for all future API calls.
DLL(ControllerActionSetHandle_t*) BS_ISteamController_GetActionSetHandle(ISteamController* lpSteamController, const char* pszActionSetName) {
	return new ControllerActionSetHandle_t(lpSteamController->GetActionSetHandle(pszActionSetName));
}

// Reconfigure the controller to use the specified action set (ie 'Menu', 'Walk' or 'Drive')
// This is cheap, and can be safely called repeatedly. It's often easier to repeatedly call it in
// your state loops, instead of trying to place it in all of your state transitions.
DLL(void) BS_ISteamController_ActivateActionSet(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle) {
	lpSteamController->ActivateActionSet(*pControllerHandle, *pActionSetHandle);
}

DLL(ControllerActionSetHandle_t*) BS_ISteamController_GetCurrentActionSet(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle) {
	return new ControllerActionSetHandle_t(lpSteamController->GetCurrentActionSet(*pControllerHandle));
}

// Lookup the handle for a digital action. Best to do this once on startup, and store the handles for all future API calls.
DLL(ControllerDigitalActionHandle_t*) BS_ISteamController_GetDigitalActionHandle(ISteamController* lpSteamController, const char* pszActionName) {
	return new ControllerDigitalActionHandle_t(lpSteamController->GetDigitalActionHandle(pszActionName));
}

// Returns the current state of the supplied digital game action
DLL(ControllerDigitalActionData_t*) BS_ISteamController_GetDigitalActionData(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerDigitalActionHandle_t* pDigitalActionHandle) {
	return &lpSteamController->GetDigitalActionData(*pControllerHandle, *pDigitalActionHandle);
}

// Get the origin(s) for a digital action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
DLL(int32_t) BS_ISteamController_GetDigitalActionOrigins(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle, ControllerDigitalActionHandle_t* pDigitalActionHandle, EControllerActionOrigin *pEControllerActionOrigin) {
	return lpSteamController->GetDigitalActionOrigins(*pControllerHandle, *pActionSetHandle, *pDigitalActionHandle, pEControllerActionOrigin);
}

// Lookup the handle for an analog action. Best to do this once on startup, and store the handles for all future API calls.
DLL(ControllerAnalogActionHandle_t*) BS_ISteamController_GetAnalogActionHandle(ISteamController* lpSteamController, const char *pszActionName) {
	return new ControllerAnalogActionHandle_t(lpSteamController->GetAnalogActionHandle(pszActionName));
}

// Returns the current state of these supplied analog game action
DLL(ControllerAnalogActionData_t*) BS_ISteamController_GetAnalogActionData(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle) {
	return &lpSteamController->GetAnalogActionData(*pControllerHandle, *pAnalogActionHandle);
}

// Get the origin(s) for an analog action within an action set. Returns the number of origins supplied in originsOut. Use this to display the appropriate on-screen prompt for the action.
// originsOut should point to a STEAM_CONTROLLER_MAX_ORIGINS sized array of EControllerActionOrigin handles
DLL(int32_t) BS_ISteamController_GetAnalogActionOrigins(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerActionSetHandle_t* pActionSetHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle, EControllerActionOrigin *pEControllerActionOrigin) {
	return lpSteamController->GetAnalogActionOrigins(*pControllerHandle, *pActionSetHandle, *pAnalogActionHandle, pEControllerActionOrigin);
}

DLL(void) BS_ISteamController_StopAnalogActionMomentum(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ControllerAnalogActionHandle_t* pAnalogActionHandle) {
	lpSteamController->StopAnalogActionMomentum(*pControllerHandle, *pAnalogActionHandle);
}

// Trigger a haptic pulse on a controller
DLL(void) BS_ISteamController_TriggerHapticPulse(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ESteamControllerPad eTargetPad, uint32_t usDurationMicroSec) {
	lpSteamController->TriggerHapticPulse(*pControllerHandle, eTargetPad, (uint16_t)usDurationMicroSec);
}

DLL(void) BS_ISteamController_TriggerRepeatedHapticPulse(ISteamController* lpSteamController, ControllerHandle_t* pControllerHandle, ESteamControllerPad eTargetPad, uint32_t usDurationMicroSec, uint32_t usOffMicroSec, uint32_t unRepeat, uint32_t nFlags) {
	lpSteamController->TriggerRepeatedHapticPulse(*pControllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
}
