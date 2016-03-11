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
	
	;! Update Window
	Flip 0
	WaitTimer(demoTimer)
Until EndGame = True

; Shut down Steam as the last action of your program.
BS_SteamAPI_Shutdown()
End
;~IDEal Editor Parameters:
;~C#Blitz3D