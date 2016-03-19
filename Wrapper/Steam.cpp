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

//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam API setup & shutdown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

DLL(int32_t) BS_SteamAPI_Init() {
	return SteamAPI_Init();
}

DLL(void) BS_SteamAPI_Shutdown() {
	SteamAPI_Shutdown();
}

// checks if a local Steam client is running 
DLL(int32_t) BS_SteamAPI_IsSteamRunning() {
	return SteamAPI_IsSteamRunning();
}

// Detects if your executable was launched through the Steam client, and restarts your game through 
// the client if necessary. The Steam client will be started if it is not running.
//
// Returns: true if your executable was NOT launched through the Steam client. This function will
//          then start your application through the client. Your current process should exit.
//
//          false if your executable was started through the Steam client or a steam_appid.txt file
//          is present in your game's directory (for development). Your current process should continue.
//
// NOTE: This function should be used only if you are using CEG or not using Steam's DRM. Once applied
//       to your executable, Steam's DRM will handle restarting through Steam if necessary.
DLL(int32_t) BS_SteamAPI_RestartAppIfNecessary(uint32_t unOwnAppID) {
	return SteamAPI_RestartAppIfNecessary(unOwnAppID);
}

// crash dump recording functions
DLL(void) BS_SteamAPI_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID) {
	SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}

DLL(void) BS_SteamAPI_SetMiniDumpComment(const char* pchMsg) {
	SteamAPI_SetMiniDumpComment(pchMsg);
}

// Most Steam API functions allocate some amount of thread-local memory for
// parameter storage. The SteamAPI_ReleaseCurrentThreadMemory() function
// will free all API-related memory associated with the calling thread.
// This memory is also released automatically by SteamAPI_RunCallbacks(), so
// a single-threaded program does not need to explicitly call this function.
DLL(void) BS_SteamAPI_ReleaseCurrentThreadMemory() {
	return SteamAPI_ReleaseCurrentThreadMemory();
}

// -- Callbacks
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steam callback and call-result helpers
//
//	The following macros and classes are used to register your application for
//	callbacks and call-results, which are delivered in a predictable manner.
//
//	STEAM_CALLBACK macros are meant for use inside of a C++ class definition.
//	They map a Steam notification callback directly to a class member function
//	which is automatically prototyped as "void func( callback_type *pParam )".
//
//	CCallResult is used with specific Steam APIs that return "result handles".
//	The handle can be passed to a CCallResult object's Set function, along with
//	an object pointer and member-function pointer. The member function will
//	be executed once the results of the Steam API call are available.
//
//	CCallback and CCallbackManual classes can be used instead of STEAM_CALLBACK
//	macros if you require finer control over registration and unregistration.
//
//	Callbacks and call-results are queued automatically and are only
//	delivered/executed when your application calls SteamAPI_RunCallbacks().
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

// SteamAPI_RunCallbacks is safe to call from multiple threads simultaneously,
// but if you choose to do this, callback code may be executed on any thread.
DLL(void) BS_SteamAPI_RunCallbacks() {
	SteamAPI_RunCallbacks();
}