#include "dllmain.h"



// Callbacks
DLL_EXPORT void SteamClient_SetWarningMessageHook(ISteamClient* lpSteamClient, SteamAPIWarningMessageHook_t pFunction) {
	lpSteamClient->SetWarningMessageHook(pFunction);
}

DLL_EXPORT void SteamClient_Set_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CPostAPIResultInProcess(fpFunction);
}

DLL_EXPORT void SteamClient_Remove_SteamAPI_CPostAPIResultInProcess(ISteamClient* lpSteamClient, SteamAPI_PostAPIResultInProcess_t fpFunction) {
	lpSteamClient->Remove_SteamAPI_CPostAPIResultInProcess(fpFunction);
}

DLL_EXPORT void SteamClient_Set_SteamAPI_CCheckCallbackRegisteredInProcess(ISteamClient* lpSteamClient, SteamAPI_CheckCallbackRegistered_t fpFunction) {
	lpSteamClient->Set_SteamAPI_CCheckCallbackRegisteredInProcess(fpFunction);
}