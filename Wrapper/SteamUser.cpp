#include "dllmain.h"

DLL_EXPORT void* BlitzSteam_ISteamUser_GetSteamID(void* lpSteamUser) {
	return (void*)&(((ISteamUser*)lpSteamUser)->GetSteamID());
}

//DLL_EXPORT void* BlitzSteam_ISteamUser_