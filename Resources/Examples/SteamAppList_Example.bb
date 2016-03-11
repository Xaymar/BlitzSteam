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

; SteamAppList stuff
Type SteamAppList
	Field AppId%
	Field Name$
	Field InstallDir$
	Field BuildId%
End Type
Global SteamAppList_Count%

Function SteamAppList_Fill()
	SteamAppList_Count = BS_ISteamAppList_GetNumInstalledApps(BS_SteamAppList())
	
	Local Buffer = CreateBank(4 * SteamAppList_Count)
	Local AppNameBuffer = CreateBank(1024)
	Local PathBuffer = CreateBank(260)
	
	Local AppIdCount = BS_ISteamAppList_GetInstalledApps(BS_SteamAppList(), Buffer, SteamAppList_Count)
	Delete Each SteamAppList
	For Index = 0 To AppIdCount - 1
		Local AppId = PeekInt(Buffer, Index*4)
		
		Local SAL.SteamAppList = New SteamAppList
		SAL\AppId = AppId
		Local AppNameLen = BS_ISteamAppList_GetAppName(BS_SteamAppList(), AppId, AppNameBuffer, 1024)
		SAL\Name = PeekCString(AppNameBuffer, 0, AppNameLen)
		Local PathLen = BS_ISteamAppList_GetAppInstallDir(BS_SteamAppList(), AppId, PathBuffer, 260)
		SAL\InstallDir = PeekCString(PathBuffer, 0, PathLen)
		SAL\BuildId = BS_ISteamAppList_GetAppBuildId(BS_SteamAppList(), AppId)
	Next
	
	FreeBank AppNameBuffer
	FreeBank PathBuffer
	FreeBank Buffer
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

SteamAppList_Fill()

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
	
	Text 0,15, "Installed Apps: " + SteamAppList_Count
	Local SAL.SteamAppList, Index = 0
	For SAL.SteamAppList = Each SteamAppList
		Index = Index + 1
		Text 0, 30 + Index* 15, RSet(SAL\AppId, 6) + "/" + RSet(SAL\BuildId, 8) + ": " + SAL\Name + " (Installed: '" + SAL\InstallDir + "')"
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