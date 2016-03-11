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

; Initialize Steam before your next call to Graphics.
If BS_SteamAPI_Init() = False Then
	RuntimeError "Steam: Failed to initialize!"
EndIf

Const FPS = 30
Const FPS_MULT# = 1.0 / FPS

; Demo Scene
Graphics3D 1024, 768, 32, 2
SetBuffer BackBuffer()

Local demoTimer = CreateTimer(FPS)
Local demoRoot = CreatePivot()
Local demoCameraRoot = CreatePivot(demoRoot)
Local demoCamera = CreateCamera(demoCameraRoot)
MoveEntity demoCamera, 0, 0, -10
Local demoCube = CreateCube(demoRoot)

; SteamApps Stuff
Type SteamAppsDLC
	Field Id%
	Field Available%
	Field Name$
End Type
Global SteamAppsDLC_Count

Function SteamAppsDLC_Fill()
	Local IdBuffer = CreateBank(4)
	Local AvailableBuffer = CreateBank(4)
	Local NameBuffer = CreateBank(1024)
	
	SteamAppsDLC_Count = BS_ISteamApps_GetDLCCount(BS_SteamApps())
	Delete Each SteamAppsDLC
	For Index = 0 To SteamAppsDLC_Count - 1
		If BS_ISteamApps_GetDLCDataByIndex(BS_SteamApps(), Index, IdBuffer, AvailableBuffer, NameBuffer, 1024)
			Local SAD.SteamAppsDLC = New SteamAppsDLC
			SAD\Id = PeekInt(IdBuffer, 0)
			SAD\Available = PeekInt(AvailableBuffer, 0)
			SAD\Name = PeekCString(NameBuffer, 0, 1024)
		Else
			SteamAppsDLC_Count = SteamAppsDLC_Count - 1
		EndIf
	Next
	
	FreeBank NameBuffer
	FreeBank AvailableBuffer
	FreeBank IdBuffer
End Function

Type SteamAppsDepots
	Field DepotId
End Type
Global SteamAppsDepots_Count

Function SteamAppsDepots_Fill()
	Local DepotsBuffer
	; Exercise: Do this one yourself with the above Type. It's not that hard.
End Function

Function PeekCString$(Bank, Offset=0, Length=-1)
	Local Out$ = "", Pos = Offset
	While Abs(Length) > 0
		Length = Length - 1
		
		Local by = PeekByte(Bank, Pos)
		If by = 0 Then
			Length = 0
		Else
			Out = Out + Chr(by)
		EndIf
		
		Pos = Pos + 1
	Wend
	Return Out
End Function

Local BetaBuffer = CreateBank(1024)
BS_ISteamApps_GetCurrentBetaName(BS_SteamApps(), BetaBuffer, 1024)
Local Beta$ = PeekCString(BetaBuffer, 0, 1024)
FreeBank BetaBuffer

Local AppInstallDir$, AppInstallDirBuffer = CreateBank(260)
BS_ISteamApps_GetAppInstallDir(BS_SteamApps(), 480, AppInstallDirBuffer, 260)
AppInstallDir = PeekCString(AppInstallDirBuffer, 0, 260)
FreeBank AppInstallDirBuffer

Local llOwner = BS_ISteamApps_GetAppOwner(BS_SteamApps())
Local OwnerId$ = "[U:" + BS_CSteamID_GetAccountInstance(llOwner) + ":" + BS_CSteamID_GetAccountID(llOwner) + "] STEAM_" + (BS_CSteamID_GetEAccountType(llOwner) - 1) + ":" + (BS_CSteamID_GetEUniverse(llOwner) - 1) + ":" + (BS_CSteamID_GetAccountID(llOwner) / 2)
BS_CSteamID_Destroy llOwner

; Main Loop
Local EndGame = False
Repeat
	Cls
	
	;! Update
	; End on Escape
	EndGame = KeyHit(1)
	
	TurnEntity demoCube, 1 * FPS_MULT, 3 * FPS_MULT, 2.332 * FPS_MULT
	
	;! Render 3D
	RenderWorld
	
	;! Render 2D
	Text 0, 0, "Escape to Quit"
	
	Text 0, 30, "Is Subscribed? " + BS_ISteamApps_IsSubscribed(BS_SteamApps())
	Text 0, 45, "Is Low Violence? " + BS_ISteamApps_IsLowViolence(BS_SteamApps())
	Text 0, 60, "Is Cybercafe? " + BS_ISteamApps_IsCybercafe(BS_SteamApps())
	Text 0, 75, "Is VAC Banned? " + BS_ISteamApps_IsVACBanned(BS_SteamApps())
	Text 0, 90, "Current Game Language: " + BS_ISteamApps_GetCurrentGameLanguage(BS_SteamApps())
	Text 0,105, "Available Game Languages: " + BS_ISteamApps_GetAvailableGameLanguages(BS_SteamApps())
	Text 0,120, "Is Subscribed App (480)? " + BS_ISteamApps_IsSubscribedApp(BS_SteamApps(), 480)
	Text 0,135, "Is DLC (323180) Installed? " + BS_ISteamApps_IsDlcInstalled(BS_SteamApps(), 323180) ; Portal 2 Soundtrack DLC
	Text 0,150, "Earliest Purchase Unix Time (480): " + BS_ISteamApps_GetEarliestPurchaseUnixTime(BS_SteamApps(), 480)
	Text 0,165, "Is Subscribed from Free Weekend? " + BS_ISteamApps_IsSubscribedFromFreeWeekend(BS_SteamApps())
	Text 0,180, "DLC Count: " + BS_ISteamApps_GetDLCCount(BS_SteamApps())
	Text 0,195, "Current Beta Name: " + Beta
	Text 0,210, "App Install Dir: " + AppInstallDir$
	Text 0,225, "Is App Installed (480): " + BS_ISteamApps_IsAppInstalled(BS_SteamApps(), 480)
	Text 0,240, "App Owner Id: " + OwnerId
	Text 0,255, "App Built Id: " + BS_ISteamApps_GetAppBuildId(BS_SteamApps())
	
	; BS_ISteamApps_GetLanchQueryParam$(BS_SteamApps(), pchKey$)
	;	// Returns the associated launch param if the game is run via steam://run/<appid>//?param1=value1;param2=value2;param3=value3 etc.
	;	// Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
	;	// Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
	;	// but it is advised that you not param names beginning with an underscore for your own features.
	
	; BS_ISteamApps_MarkContentCorrupt signals steam that game files are corrupt or missing. Forces a validation after quit and before next start.
	
	; How To Use: BS_ISteamApps_RequestProofOfPurchaseKey(BS_SteamApps(), nAppId)
	;	// Request cd-key for yourself or owned DLC. If you are interested in this
	;	// data then make sure you provide us with a list of valid keys to be distributed
	;	// to users when they purchase the game, before the game ships.
	;	// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
	;	// the key is available (which may be immediately).
	; Example (Spacewar) does not have CD-Keys.
	
	Text 512, 0, "DLCs: " + SteamAppsDLC_Count
	Local Index = 0, SAD.SteamAppsDLC
	For SAD = Each SteamAppsDLC
		Text 512, 15 + Index * 15, SAD\Id + "(" + SAD\Available + "): " + SAD\Name
		; You could install DLCs from the app itself, BS_ISteamApps_InstallDLC, BS_ISteamApps_UninstallDLC
		; BS_ISteamApps_GetDlcDownloadProgress allows you to check the progress, BlitzUtility's LongLong stuff is useful here.
		
		Index = Index + 1
	Next
	
	;! Update Window
	Flip 0
	WaitTimer(demoTimer)
Until EndGame = True

; Shut down Steam as the last action of your program.
BS_SteamAPI_Shutdown()
End
;~IDEal Editor Parameters:
;~C#Blitz3D