;	BlitzSteam - Steam wrapper for Blitz
;	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
;
;	This program is free software: you can redistribute it and/or modify
;	it under the terms of the GNU Lesser General Public License as
;	published by the Free Software Foundation, either version 3 of the 
;	License, or (at your option) any later version.
;
;	This program is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;
;	You should have received a copy of the GNU Lesser General Public License
;	along with this program.  If not, see <http://www.gnu.org/licenses/>.

Include "../BlitzSteam.bb"

;----------------------------------------------------------------
;! Configuration
;----------------------------------------------------------------
Const APPID = 480 ; Test App / SpaceWar

Const FRAMERATE = 60
Const RESOLUTION_X = 1024
Const RESOLUTION_Y = 768
Const RESOLUTION_Z = 32
Const RESOLUTION_MODE = 2

;----------------------------------------------------------------
;! Init Code
;----------------------------------------------------------------
Global Timer = CreateTimer(FRAMERATE)

Global ServerListResponse_ServerResponded_p%:ServerListResponse_ServerResponded(0, 0)
Global ServerListResponse_RefreshComplete_p%:ServerListResponse_RefreshComplete(0, 0)

Graphics3D RESOLUTION_X, RESOLUTION_Y, RESOLUTION_Z, RESOLUTION_MODE
SetBuffer BackBuffer()

If Not BS_SteamAPI_Init() Then RuntimeError "Failed to initialize Steam!"

;----------------------------------------------------------------
;! Main Code
;----------------------------------------------------------------
Local Bank =CreateBank(1)
Local pRequestServersResponse = BS_ISteamMatchmakingServerListResponse_New(ServerListResponse_ServerResponded_p, 0, ServerListResponse_RefreshComplete_p)
Local hRequest = BS_ISteamMatchmakingServers_RequestInternetServerList(BS_SteamMatchmakingServers(), 480, Bank, 0, pRequestServersResponse)

While Not KeyHit(1)
	WaitTimer Timer
	BS_SteamAPI_RunCallbacks()
Wend

BS_ISteamMatchmakingServers_ReleaseRequest(BS_SteamMatchmakingServers(), hRequest)
BS_SteamAPI_Shutdown()

;----------------------------------------------------------------
;! Functions
;----------------------------------------------------------------
Function ServerListResponse_ServerResponded(hRequest%, iServer%)
	If (Not ServerListResponse_ServerResponded_p)
		ServerListResponse_ServerResponded_p = BP_GetFunctionPointer()
		Return
	EndIf
	Print iServer
End Function

Function ServerListResponse_RefreshComplete(hRequest%, eMatchMakingServerResponse%)
	If (Not ServerListResponse_RefreshComplete_p)
		ServerListResponse_RefreshComplete_p = BP_GetFunctionPointer()
		Return
	EndIf
	
	Select eMatchMakingServerResponse
		Case BS_EMatchMakingServerResponse_ServerResponded
			Print "Got Servers"
		Case BS_EMatchMakingServerResponse_ServerFailedToRespond
			Print "Server did not respond"
		Case BS_EMatchMakingServerResponse_NoServersListedOnMasterServer
			Print "No Servers listed for this game."
		Default
			Print "Unknown"
	End Select
End Function

;~IDEal Editor Parameters:
;~C#Blitz3D