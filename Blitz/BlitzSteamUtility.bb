;	BlitzSteam - Steam wrapper for Blitz.
;	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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
;	along with this program.  If not, see <http:;www.gnu.org/licenses/>.

;----------------------------------------------------------------
; -- Constants
;----------------------------------------------------------------
Const BSU_NAME_LENGTH					= 4096
Const BSU_INSTALLDIR_LENGTH				= 4096
Const BSU_APPID_COUNT					= 4096
Const BSU_INSTALLEDDEPOTS_COUNT			= 4096

;----------------------------------------------------------------
; -- Globals
;----------------------------------------------------------------
Global BSUInitialized = False
Global BSUIsSteamRunning% = False
; -- Interfaces
Global BSUAppList%, BSUApps%, BSUClient%, BSUController%
Global BSUFriends%, BSUHTTP%, BSUHTMLSurface%, BSUInventory%
Global BSUMatchmaking%, BSUMatchmakingServers%, BSUMusic%
Global BSUMusicRemote%, BSUNetworking%, BSURemoteStorage%
Global BSUScreenshots%, BSUUGC%, BSUUnifiedMessages%, BSUUser%
Global BSUUserStats%, BSUUtils%, BSUVideo%

;----------------------------------------------------------------
; -- Types
;----------------------------------------------------------------
Type BSU_App
	Field AppId%
	Field Name$
	Field InstallDir$
End Type

Type BSU_DLC
	Field AppId%
	Field Available%
	Field Name$
End Type

Type BSU_Depot
	Field DepotId%
End Type

Type BSU_Friend
	Field SteamID_L, SteamID_R
	
	Field Name$
	Field NickName$
	
	Field Index%
	Field Relationship%
	Field State%
	Field SteamLevel%
End Type

;----------------------------------------------------------------
; -- Globals
;----------------------------------------------------------------
Global BSU_AppCount
Global BSU_DLCCount
Global BSU_DepotCount
Global BSU_FriendCount

;----------------------------------------------------------------
; -- Functions
;----------------------------------------------------------------
; -- Utility
; Writes a C-String value to a Bank.
; Returns amount of bytes written.
Function BSU_PokeCString%(Bank%, Pos%, Value$)
	If Bank Then
		Local BankSz = BankSize(Bank)
		
		If Pos < 0 Then Pos = 0
		If Pos >= BankSz Then Pos = BankSz - 1
		
		Local ValuePos, ValueLen = Len(Value)
		For ValuePos = 1 To ValueLen
			; Don't write over the edge, we still need space for the 0-byte
			If (Pos + ValuePos) >= (BankSz - 1) Then Exit
			
			PokeByte Bank, Pos + ValuePos, Asc(Mid(Value, ValuePos, 1))
		Next
		PokeByte Bank, Pos + ValuePos, 0
		Return ValuePos
	EndIf
End Function

; Reads a C-String value from a Bank.
; Returns read C-String
Function BSU_PeekCString$(Bank%, Pos%)
	If Bank Then
		Local BankSz = BankSize(Bank)
		
		If Pos < 0 Then Pos = 0
		If Pos >= BankSz Then Pos = BankSz - 1
		
		Local OutStr$, OutLen = (BankSz - Pos)
		Local BankPos
		For BankPos = 0 To OutLen
			If (Pos + BankPos) >= BankSz Then Exit
			
			Local Value = PeekByte(Bank, Pos + BankPos)
			
			If Value = 0 Then
				Exit
			Else
				OutStr=OutStr+Chr(Value)
			EndIf
		Next
		Return OutStr
	EndIf
End Function

; -- Steam
Function BSU_Init()
	BSUIsSteamRunning = BlitzSteam_IsSteamRunning()
	If BSUIsSteamRunning Then
		BlitzSteam_Init()
		
		BSUAppList				= BlitzSteamAppList()
		BSUApps					= BlitzSteamApps()
		BSUClient				= BlitzSteamClient()
		BSUController			= BlitzSteamController()
		BSUFriends				= BlitzSteamFriends()
		BSUHTTP					= BlitzSteamHTTP()
		BSUHTMLSurface			= BlitzSteamHTMLSurface()
		BSUInventory			= BlitzSteamInventory()
		BSUMatchmaking			= BlitzSteamMatchmaking()
		BSUMatchmakingServers	= BlitzSteamMatchmakingServers()
		BSUMusic				= BlitzSteamMusic()
		BSUMusicRemote			= BlitzSteamMusicRemote()
		BSUNetworking			= BlitzSteamNetworking()
		BSURemoteStorage		= BlitzSteamRemoteStorage()
		BSUScreenshots			= BlitzSteamScreenshots()
		BSUUGC					= BlitzSteamUGC()
		BSUUnifiedMessages		= BlitzSteamUnifiedMessages()
		BSUUser					= BlitzSteamUser()
		BSUUserStats			= BlitzSteamUserStats()
		BSUUtils				= BlitzSteamUtils()
		BSUVideo				= BlitzSteamVideo()
		
		BSUInitialized = True
	EndIf
End Function

Function BSU_Shutdown()
	If BSUIsSteamRunning
		BlitzSteam_Shutdown()
		BSUAppList=0
		BSUApps=0
		BSUClient=0
		BSUController=0
		BSUFriends=0
		BSUHTTP=0
		BSUHTMLSurface=0
		BSUInitialized=0
		BSUMatchmaking=0
		BSUMatchmakingServers=0
		BSUMusic=0
		BSUMusicRemote=0
		BSUNetworking=0
		BSURemoteStorage=0
		BSUScreenshots=0
		BSUUGC=0
		BSUUnifiedMessages=0
		BSUUser=0
		BSUUserStats=0
		BSUUtils=0
		BSUVideo=0
		
		BSUInitialized = False
	EndIf
End Function

; -- SteamAppList
Function BSUAppList_GetInstalledApps(BankAppIdsStorage=0, BankAppNameStorage=0, BankAppInstallDirStorage=0)
	Local BankAppIds, BankAppIdsSz = BSU_APPID_COUNT
	Local BankAppName, BankAppNameSz = BSU_NAME_LENGTH
	Local BankAppInstallDir, BankAppInstallDirSz = BSU_INSTALLDIR_LENGTH
	Local AppCount%, InstalledApp.BSU_App
	
	If BSUInitialized Then
		; Clear Installed App List
		Delete Each BSU_App
		
		; Early-Exit to not waste time.
		If BlitzSteamAppList_GetNumInstalledApps(BSUApps) = 0 Then Return
		
		If BankAppIdsStorage = 0
			; Create Temporary storage for AppIds.
			BankAppIds = CreateBank(BankAppIdsSz * 4)
		Else
			; Reuse existing Bank.
			BankAppIds = BankAppIdsStorage
			BankAppIdsSz = Floor(BankSize(BankAppIds) / 4)
		EndIf
		
		; Request installed apps from Steam.
		BSU_AppCount = BlitzSteamAppList_GetInstalledApps(BSUAppList, BankAppIds, BankAppIdsSz)
		
		; We don't need to do this if we don't actually have any apps returned.
		If BSU_AppCount > 0 Then
			If BankAppNameStorage = 0 Then
				; Create temporary storage for name.
				BankAppName = CreateBank(BankAppNameSz)
			Else
				BankAppName = BankAppNameStorage
				BankAppNameSz = BankSize(BankAppName)
			EndIf
			If BankAppInstallDirStorage = 0 Then
				; Create temporary storage for installdir.
				BankAppInstallDir = CreateBank(BankAppInstallDirSz)
			Else
				BankAppInstallDir = BankAppInstallDirStorage
				BankAppInstallDirSz = BankSize(BankAppInstallDir)
			EndIf
			
			; Index all apps.
			Local AppIndex
			For AppIndex = 0 To BSU_AppCount - 1
				InstalledApp.BSU_App = New BSU_App
				InstalledApp\AppId = PeekInt(BankAppIds, AppIndex * 4)
				InstalledApp\Name = BSUAppList_GetAppName(InstalledApp\AppId, BankAppName)
				InstalledApp\InstallDir = BSUAppList_GetInstallDir(InstalledApp\AppId, BankAppInstallDir)
			Next
			
			; Free temporary storage for name and installdir.
			If BankAppInstallDirStorage = 0 Then FreeBank BankAppInstallDir
			If BankAppNameStorage = 0 FreeBank BankAppName
		EndIf
		
		; Free temporary storage for AppIds.
		If BankAppIdsStorage = 0 FreeBank BankAppIds
	EndIf
End Function

Function BSUAppList_GetAppName$(AppID%, BankStorage=0)
	Local Bank, BankSz = BSU_NAME_LENGTH
	Local AppName$
	
	If BSUInitialized Then
		If BankStorage = 0 Then
			; Create temporary storage.
			Bank = CreateBank(BankSz)
		Else
			; Reuse existing Bank.
			Bank = BankStorage
			BankSz = BankSize(Bank)
		EndIf
		
		; Request App name from Steam.
		BlitzSteamAppList_GetAppName(BSUAppList, AppID, Bank, BankSz)
		
		; Read returned C-String from Bank.
		AppName$ = BSU_PeekCString(Bank, 0)
		
		; Free temporary storage.
		If BankStorage = 0 Then FreeBank Bank
	EndIf
	
	; Return name read.
	Return AppName
End Function

Function BSUAppList_GetInstallDir$(AppID%, BankStorage=0)
	Local Bank, BankSz = BSU_INSTALLDIR_LENGTH
	Local AppInstallDir$
	
	If BSUInitialized Then
		If BankStorage = 0 Then
			; Create temporary storage.
			Bank = CreateBank(BankSz)
		Else
			; Reuse existing Bank.
			Bank = BankStorage
			BankSz = BankSize(Bank)
		EndIf
		
		; Request App name from Steam.
		BlitzSteamAppList_GetAppInstallDir(BSUAppList, AppID, Bank, BankSz)
		
		; Read returned C-String from Bank.
		AppInstallDir$ = BSU_PeekCString(Bank, 0)
		
		; Free temporary storage.
		If BankStorage = 0 Then FreeBank Bank
	EndIf
	
	; Return name read.
	Return AppInstallDir
End Function

; -- SteamApps
Function BSUApps_GetDLCData(BankAppIdStorage=0, BankAvailableStorage=0, BankNameStorage=0)
	Local BankAppId%, BankAvailable%
	Local BankName%, BankNameSz% = BSU_NAME_LENGTH
	Local DLCCount% = 0
	
	If BSUInitialized Then
		Delete Each BSU_DLC
		
		BSU_DLCCount = BlitzSteamApps_GetDLCCount(BSUApps)
		If BSU_DLCCount > 0
			If BankAppIdStorage = 0 Then
				; Create temporary storage for AppId.
				BankAppId = CreateBank(4)
			Else
				; Reuse existing storage.
				BankAppId = BankAppIdStorage
			EndIf
			
			If BankAvailableStorage = 0 Then
				; Create temporary storage for Availability.
				BankAvailable = CreateBank(4)
			Else
				; Reuse existing storage.
				BankAvailable = BankAvailableStorage
			EndIf
			
			If BankNameStorage = 0 Then
				; Create temporary storage for Availability.
				BankName = CreateBank(BankNameSz)
			Else
				; Reuse existing storage.
				BankName = BankNameStorage
				BankNameSz = BankSize(BankName)
			EndIf
			
			Local DLCIndex%
			For DLCIndex = 0 To BSU_DLCCount - 1
				BSUApps_GetDLCDataByIndex(DLCIndex, BankAppId, BankAvailable, BankName)
			Next
			
			; Free temporary storages.
			If BankNameStorage = 0 Then FreeBank BankName
			If BankAvailableStorage = 0 Then FreeBank BankAvailable
			If BankAppIdStorage = 0 Then FreeBank BankAppId
		EndIf
	EndIf
End Function

Function BSUApps_GetDLCDataByIndex.BSU_DLC(iDLC%, BankAppIdStorage=0, BankAvailableStorage=0, BankNameStorage=0)
	Local BankAppId%, BankAvailable%
	Local BankName%, BankNameSz% = BSU_NAME_LENGTH
	Local DLC.BSU_DLC
	
	If BSUInitialized Then
		If BankAppIdStorage = 0 Then
			; Create temporary storage for AppId.
			BankAppId = CreateBank(4)
		Else
			; Reuse existing storage.
			BankAppId = BankAppIdStorage
		EndIf
		
		If BankAvailableStorage = 0 Then
			; Create temporary storage for Availability.
			BankAvailable = CreateBank(4)
		Else
			; Reuse existing storage.
			BankAvailable = BankAvailableStorage
		EndIf
		
		If BankNameStorage = 0 Then
			; Create temporary storage for Availability.
			BankName = CreateBank(BankNameSz)
		Else
			; Reuse existing storage.
			BankName = BankNameStorage
			BankNameSz = BankSize(BankName)
		EndIf
		
		; Request DLC Data from Steam.
		If BlitzSteamApps_GetDLCDataByIndex(BSUApps, iDLC, BankAppId, BankAvailable, BankName, BankNameSz)
			; Create a result DLC object.
			DLC.BSU_DLC = New BSU_DLC
			DLC\AppId = PeekInt(BankAppId, 0)
			DLC\Available = PeekInt(BankAvailable, 0)
			DLC\Name = BSU_PeekCString(BankName, 0)
		EndIf
		
		; Free temporary storages.
		If BankNameStorage = 0 Then FreeBank BankName
		If BankAvailableStorage = 0 Then FreeBank BankAvailable
		If BankAppIdStorage = 0 Then FreeBank BankAppId
	EndIf
	
	; Return the result.
	Return DLC
End Function

Function BSUApps_GetCurrentBetaName$(BankNameStorage=0)
	Local BankName, BankNameSz = BSU_NAME_LENGTH
	Local BetaName$ = ""
	
	If BSUInitialized Then
		If BankNameStorage = 0 Then
			; Create temporary storage for name.
			BankName = CreateBank(BankNameSz)
		Else
			; Reuse existing storage.
			BankName = BankNameStorage
			BankNameSz = BankSize(BankName)
		EndIf
		
		; Request beta name from Steam.
		BlitzSteamApps_GetCurrentBetaName(BSUApps, BankName, BankNameSz)
		
		; Read returned name.
		BetaName = BSU_PeekCString(BankName, 0)
		
		; Free temporary storage.
		If BankNameStorage = 0 Then FreeBank BankName
	EndIf
	
	; Return the result.
	Return BetaName
End Function

Function BSUApps_GetInstalledDepots(nAppID%, BankDepotStorage=0)
	Local BankDepot, BankDepotSz = BSU_INSTALLEDDEPOTS_COUNT
	Local DepotCount
	
	If BSUInitialized Then
		Delete Each BSU_Depot
		
		If BankDepotStorage = 0 Then
			; Create temporary storage.
			BankDepot = CreateBank(BankDepotSz * 4)
		Else
			; Reuse existing storage.
			BankDepot = BankDepotStorage
			BankDepotSz = BankSize(BankDepot) / 4
		EndIf
		
		; Request depots from Steam.
		BSU_DepotCount = BlitzSteamApps_GetInstalledDepots(BSUApps, nAppID, BankDepot, BankDepotSz)
		
		; Read returned depots into objects.
		Local DepotIndex
		For DepotIndex = 0 To BSU_DepotCount - 1
			Local Depot.BSU_Depot = New BSU_Depot
			Depot\DepotId = PeekInt(BankDepot, DepotIndex * 4)
		Next
		
		; Free temporary storage.
		If BankDepotStorage = 0 Then FreeBank BankDepot
	EndIf
End Function

Function BSUApps_GetAppInstallDir$(nAppID%, BankInstallDirStorage=0)
	Local BankInstallDir, BankInstallDirSz = BSU_INSTALLDIR_LENGTH
	Local InstallDir$
	
	If BSUInitialized Then
		If BankInstallDirStorage = 0 Then
			; Create temporary storage.
			BankInstallDir = CreateBank(BankInstallDirSz)
		Else
			; Reuse existing storage.
			BankInstallDir = BankInstallDirStorage
			BankInstallDirSz = BankSize(BankInstallDir)
		EndIf
		
		; Request install dir from Steam.
		Local InstallDirLen% = BlitzSteamApps_GetAppInstallDir(BSUApps, nAppID, BankInstallDir, BankInstallDirSz)
		
		; Read returned value.
		InstallDir = BSU_PeekCString(BankInstallDir, 0)
		
		; Free temporary storage.
		If BankInstallDirStorage = 0 Then FreeBank BankInstallDir
	EndIf
	
	Return InstallDir$
End Function

Function BSUApps_GetDLCDownloadProgress#(nAppID%)
	Local Progress# = 1.0
	If BSUInitialized
		; Create temporary storage.
		Local i64_Downloaded, i64_Total
		i64_Downloaded	= BlitzSteamInt64_New()
		i64_Total		= BlitzSteamInt64_New()
		
		; Request download progress from Steam.
		If BlitzSteamApps_GetDlcDownloadProgressEx(BSUApps, nAppID, i64_Downloaded, i64_Total) Then
			Local dDownloaded, dTotal
			dDownloaded = BlitzSteamInt64_ToDouble(i64_Downloaded)
			dTotal = BlitzSteamInt64_ToDouble(i64_Total)
			
			BlitzSteamDouble_DivP dDownloaded, dTotal
			Progress = BlitzSteamDouble_ToFloat(dDownloaded)
			
			BlitzSteamDouble_Destroy dDownloaded
			BlitzSteamDouble_Destroy dTotal
		EndIf
		
		; Free temporary storage.
		BlitzSteamInt64_Destroy i64_Downloaded
		BlitzSteamInt64_Destroy i64_Total
	EndIf
	Return Progress
End Function

; -- SteamFriends
Function BSUFriends_GetFriends(iFriendFlags=BLITZSTEAM_EFriendFlags_All)
	If BSUInitialized Then
		Delete Each BSU_Friend
		
		BSU_FriendCount = BlitzSteamFriends_GetFriendCount(BSUFriends, iFriendFlags)
		If BSU_FriendCount > 0 Then
			Local FriendIndex
			For FriendIndex = 0 To BSU_FriendCount - 1
				Local CSteamID = BlitzSteamFriends_GetFriendByIndex(BSUFriends, FriendIndex, iFriendFlags)
				Local Friend.BSU_Friend = New BSU_Friend
				
				; Store a 'native' version of the SteamID
				Local SteamID64 = BlitzSteamCSteamID_ConvertToUInt64(CSteamID)
				Friend\SteamID_L = BlitzSteamInt64_ValueL(SteamID64)
				Friend\SteamID_R = BlitzSteamInt64_ValueR(SteamID64)
				BlitzSteamInt64_Destroy(SteamID64)
				
				; Names
				Friend\Name = BlitzSteamFriends_GetFriendPersonaName(BSUFriends, CSteamID)
				Friend\NickName = BlitzSteamFriends_GetPlayerNickname(BSUFriends, CSteamID)
				
				; Other Stuff
				Friend\Index = FriendIndex
				Friend\Relationship = BlitzSteamFriends_GetFriendRelationship(BSUFriends, CSteamID)
				Friend\State = BlitzSteamFriends_GetFriendPersonaState(BSUFriends, CSteamID)
				Friend\SteamLevel = BlitzSteamFriends_GetFriendSteamLevel(BSUFriends, CSteamID)
				
				BlitzSteamCSteamID_Destroy(CSteamID)
			Next
		EndIf
	EndIf
End Function

;~IDEal Editor Parameters:
;~F#52#67#80#9F#BD#FA#116#133#163#195#1B1#1D0#1EB
;~C#Blitz3D