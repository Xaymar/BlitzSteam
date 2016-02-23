Include "BlitzSteam.bb"

;----------------------------------------------------------------
;! Steam Stuff
;----------------------------------------------------------------

; SteamClient: WarningMessageHook
Global Steam_WarningMessageHook_Callback = 0
Function Steam_WarningMessageHook(bIsWarning%, pchMessageBuffer%)
	If Steam_WarningMessageHook_Callback = 0 Then
		Steam_WarningMessageHook_Callback = BP_GetFunctionPointer()
		Return
	EndIf
	
	; Read Message from buffer
	Local msg$ = ""
	If bIsWarning = 1 Then
		msg = "[Warning]"
	Else
		msg = "[Info]"
	EndIf
	msg = msg + PeekMemoryStringC(pchMessageBuffer)
	
	DebugLog "[Steam]" + msg$
End Function:Steam_WarningMessageHook(0, 0)
Function PeekMemoryStringC(Memory%, Length%=-1)
	Local Ptr = Memory
	Local iChar = 0, tiChar = 0
	Local sOut$ = ""
	
	Repeat
		tiChar = PeekMemoryByte(Ptr)
		
		; Advance memory, decrease Length
		Ptr = Ptr + 1
		Length = Length - 1
		
		If (tiChar = 0) Then
			Length = 0
		Else
			sOut = sOut + Chr(tiChar)
		EndIf
	Until Length = 0
	
	Return sOut
End Function

;----------------------------------------------------------------
;! Blitz Browser Wrapper (Image based)
;----------------------------------------------------------------
Type Browser
	Field Id%
	
	Field ImageHandle%, ImageSize[2]
	
	; Internal Steam
	Field z_llSteamAPICall%
End Type

Global Browser_HTMLSurface_BrowserReady_p = 0, Browser_HTMLSurface_BrowserReady_c = 0
Function Browser_HTMLSurface_BrowserReady(pvParam%, bIOFailure, llSteamAPICall)
	If (Browser_HTMLSurface_BrowserReady_p = 0) Then
		Browser_HTMLSurface_BrowserReady_p = BP_GetFunctionPointer()
		Browser_HTMLSurface_BrowserReady_c = BS_Callback_Create(Browser_HTMLSurface_BrowserReady_p)
		Return 
	EndIf
	
	DebugLog "HTMLSurface_BrowserReady"
	
	Local Browser.Browser = Browser_FindBySteamAPICall(llSteamAPICall)
	Browser\Id = PeekMemoryInt(pvParam)
	Browser_LoadURL(Browser, "http://google.com/")
	Browser_SetSize(Browser, Browser\ImageSize[0], Browser\ImageSize[1])
	
	; Cleanup
	BS_Helper_DeleteLong(Browser\z_llSteamAPICall):Browser\z_llSteamAPICall = 0
	BS_Callback_UnregisterResult Browser_HTMLSurface_BrowserReady_c ; Caller does this too.
End Function:Browser_HTMLSurface_BrowserReady(0, 0, 0)

Global Browser_HTMLSurface_NeedsPaint_p = 0, Browser_HTMLSurface_NeedsPaint_c = 0
Function Browser_HTMLSurface_NeedsPaint(pvParam%)
	If (Browser_HTMLSurface_NeedsPaint_p = 0) Then
		Browser_HTMLSurface_NeedsPaint_p = BP_GetFunctionPointer()
		Browser_HTMLSurface_NeedsPaint_c = BS_Callback_Create(Browser_HTMLSurface_NeedsPaint_p)
		Return 
	EndIf
	
	DebugLog "HTMLSurface_NeedsPaint"
	
	Local Browser.Browser = Browser_FindById(PeekMemoryInt(pvParam))
	
	; Paint logic
	;CALLBACK_MEMBER(0, HHTMLBrowser, unBrowserHandle) // the browser that needs the paint
	;CALLBACK_MEMBER(1, const char *, pBGRA ) // a pointer to the B8G8R8A8 data for this surface, valid until SteamAPI_RunCallbacks is next called
	;CALLBACK_MEMBER(2, uint32, unWide) // the total width of the pBGRA texture
	;CALLBACK_MEMBER(3, uint32, unTall) // the total height of the pBGRA texture
	;CALLBACK_MEMBER(4, uint32, unUpdateX) // the offset in X for the damage rect for this update
	;CALLBACK_MEMBER(5, uint32, unUpdateY) // the offset in Y for the damage rect for this update
	;CALLBACK_MEMBER(6, uint32, unUpdateWide) // the width of the damage rect for this update
	;CALLBACK_MEMBER(7, uint32, unUpdateTall) // the height of the damage rect for this update
	;CALLBACK_MEMBER(8, uint32, unScrollX) // the page scroll the browser was at when this texture was rendered
	;CALLBACK_MEMBER(9, uint32, unScrollY) // the page scroll the browser was at when this texture was rendered
	;CALLBACK_MEMBER(10, float, flPageScale) // the page scale factor on this page when rendered
	;CALLBACK_MEMBER(11, uint32, unPageSerial) // incremented on each new page load, you can use this to reject draws while navigating to new pages
	
End Function:Browser_HTMLSurface_NeedsPaint(0)

Global Browser_HTMLSurface_StartRequest_p = 0, Browser_HTMLSurface_StartRequest_c = 0
Function Browser_HTMLSurface_StartRequest(pvParam%)
	If (Browser_HTMLSurface_StartRequest_p = 0) Then
		Browser_HTMLSurface_StartRequest_p = BP_GetFunctionPointer()
		Browser_HTMLSurface_StartRequest_c = BS_Callback_Create(Browser_HTMLSurface_StartRequest_p)
		Return 
	EndIf
	
	DebugLog "HTMLSurface_StartRequest"
	
	; Default to allow all requests. (Why not? For an Example, this is good enough.)
	BS_HTMLSurface_AllowStartRequest BS_HTMLSurface(), PeekMemoryInt(pvParam), True
End Function:Browser_HTMLSurface_StartRequest(0)


Function Browser_Create.Browser(Width%, Height, UserAgent$="BlitzSteam", UserCSS$="")
	DebugLog "[Browser::Create] Creating with UserAgent '"+UserAgent+"' and CSS '"+UserCSS+"'."
	
	; Register Callbacks (Can do this in an Init function too)
	BS_Callback_Register Browser_HTMLSurface_BrowserReady_c, BS_HTMLSurface_BrowserReady
	BS_Callback_Register Browser_HTMLSurface_NeedsPaint_c, BS_HTMLSurface_NeedsPaint
	BS_Callback_Register Browser_HTMLSurface_StartRequest_c, BS_HTMLSurface_StartRequest
	
	; Create Browser Object
	Local Browser.Browser = New Browser
	Browser\z_llSteamAPICall = BS_HTMLSurface_CreateBrowser(BS_HTMLSurface(), UserAgent, UserCSS)
	Browser\ImageSize[0] = Width
	Browser\ImageSize[1] = Height
	
	; Register CallResult
	BS_Callback_RegisterResult Browser_HTMLSurface_BrowserReady_c, Browser\z_llSteamAPICall 
	
	Return Browser
End Function

Function Browser_IsReady(Browser.Browser)
	If Browser = Null Then Return False
	
	DebugLog "[Browser::IsReady] Checking if '"+Browser\Id+"'/'"+Browser\z_llSteamAPICall+"' is ready."
	
	Return (Browser\Id <> 0)
End Function

Function Browser_FindById.Browser(Id%)
	If Id = 0 Then Return Null ; 0 is not a valid Browser Handle.
	
	DebugLog "[Browser::FindById] Finding by Id '"+Id+"."
	
	Local Browser.Browser
	For Browser = Each Browser
		If Browser\Id = Id Then Return Browser
	Next
	
	Return Null
End Function

Function Browser_FindBySteamAPICall.Browser(llSteamAPICall%)
	If llSteamAPICall = 0 Then Return Null ; 0 is not a valid SteamAPICall.
	
	DebugLog "[Browser::FindBySteamAPICall] Finding by SteamAPICall '"+llSteamAPICall+"."
	
	Local Browser.Browser
	For Browser = Each Browser
		If Browser\z_llSteamAPICall = llSteamAPICall Then Return Browser
	Next
	
	Return Null
End Function

Function Browser_Destroy.Browser(Browser.Browser)
	If Browser = Null Then Return Null
	
	DebugLog "[Browser::Destroy] Destroying '"+Browser\Id+"'."
	
	BS_HTMLSurface_RemoveBrowser BS_HTMLSurface(), Browser\Id
	Delete Browser:Return Null
End Function

Function Browser_SetSize(Browser.Browser, Width%, Height%)
	If Browser = Null Then Return
	
	DebugLog "[Browser::SetSize] Resizing '"+Browser\Id+"' to "+Width+"x"+Height+"."
	
	; Free old Image
	If (Browser\ImageHandle <> 0) Then
		FreeImage(Browser\ImageHandle)
	EndIf
	
	; Create new Image
	Browser\ImageHandle = CreateImage(Width%, Height%)
	Browser\ImageSize[0] = Width
	Browser\ImageSize[1] = Height
	
	BS_HTMLSurface_SetSize BS_HTMLSurface(), Browser\Id, Width, Height
End Function

Function Browser_GetHandle(Browser.Browser)
	Return Browser\ImageHandle
End Function

Function Browser_LoadURL(Browser.Browser, URL$, PostData$="")
	If Browser = Null Then Return
	
	DebugLog "[Browser::SetSize] Browser '"+Browser\Id+"' is loading URL '"+URL+"'."
	
	BS_HTMLSurface_LoadURL BS_HTMLSurface(), Browser\Id, URL, PostData
End Function

;----------------------------------------------------------------
;! Example Code
;----------------------------------------------------------------
If BS_Steam_Init() = 0 Then RuntimeError "Steam failed to initialize."

; Steam: Hooks, Callbacks, CallResults
BS_Client_SetWarningMessageHook BS_Client(), Steam_WarningMessageHook_Callback

; Steam: HTMLSurface API
If BS_HTMLSurface() = 0 Then RuntimeError "Steam: HTMLSurface API is not available."
If BS_HTMLSurface_Init(BS_HTMLSurface()) = 0 Then RuntimeError "Steam: HTMLSurface API did not want to be initialized?!"
BS_HTMLSurface_SetSize BS_HTMLSurface(), 0, GraphicsWidth(), GraphicsHeight()

; Scene Setup
Graphics3D 1024, 768, 32, 2:SetBuffer BackBuffer()

; Create a Browser
Local myBrowser.Browser = Browser_Create(512, 512)

While Not Browser_IsReady(myBrowser)
	BS_Steam_RunCallbacks()
	Delay 100
Wend

While Not KeyHit(1)
	Cls
	
	; Steam: Run any Callbacks
	; Q: Why before RenderWorld/Flip?
	; A: If we did any changes, having them available before Rendering helps responsiveness.
	;    A one-frame Delay is noticeable, even to people claiming the eye only sees 30 fps.
	;    Please read a Biology book if you are one of those, it doesn't work like that.
	BS_Steam_RunCallbacks()
	
	RenderWorld
	
	DrawImage Browser_GetHandle(myBrowser), 0, 0, 0
	
	Flip
Wend

; Destroy existing Browser
myBrowser = Browser_Destroy(myBrowser)

; Steam: HTMLSurface API
BS_HTMLSurface_Shutdown(BS_HTMLSurface())

EndGraphics
End

;~IDEal Editor Parameters:
;~F#8#19#3C#50
;~C#Blitz3D