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
#include "SteamworksSDK/public/steam/isteamhtmlsurface.h"

DLL_FUNCTION(ISteamHTMLSurface*) BS_HTMLSurface() {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface=_BS_HTMLSurface@0")
	return SteamHTMLSurface();
}

// Must call init and shutdown when starting/ending use of the interface
DLL_FUNCTION(uint32_t) BS_HTMLSurface_Init(ISteamHTMLSurface* pSteamHTMLSurface) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_Init=_BS_HTMLSurface_Init@4")
	return pSteamHTMLSurface->Init();
}

DLL_FUNCTION(uint32_t) BS_HTMLSurface_Shutdown(ISteamHTMLSurface* pSteamHTMLSurface) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_Shutdown=_BS_HTMLSurface_Shutdown@4")
	return pSteamHTMLSurface->Shutdown();
}

// Create a browser object for display of a html page, when creation is complete the call handle
// will return a HTML_BrowserReady_t callback for the HHTMLBrowser of your new browser.
//   The user agent string is a substring to be added to the general user agent string so you can
// identify your client on web servers.
//   The userCSS string lets you apply a CSS style sheet to every displayed page, leave null if
// you do not require this functionality.
DLL_FUNCTION(SteamAPICall_t*) BS_HTMLSurface_CreateBrowser(ISteamHTMLSurface* pSteamHTMLSurface, const char* pchUserAgent, const char* pchUserCSS) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_CreateBrowser=_BS_HTMLSurface_CreateBrowser@12")
	return new SteamAPICall_t(pSteamHTMLSurface->CreateBrowser(pchUserAgent, pchUserCSS));
}

// Call this when you are done with a html surface, this lets us free the resources being used by it
DLL_FUNCTION(void) BS_HTMLSurface_RemoveBrowser(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_RemoveBrowser=_BS_HTMLSurface_RemoveBrowser@8")
	pSteamHTMLSurface->RemoveBrowser(unBrowserHandle);
}

// Navigate to this URL, results in a HTML_StartRequest_t as the request commences 
DLL_FUNCTION(void) BS_HTMLSurface_LoadURL(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchURL, const char* pchPostData) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_LoadURL=_BS_HTMLSurface_LoadURL@16")
	pSteamHTMLSurface->LoadURL(unBrowserHandle, pchURL, pchPostData);
}

// Tells the surface the size in pixels to display the surface
DLL_FUNCTION(void) BS_HTMLSurface_SetSize(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32_t unWidth, uint32_t unHeight) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetSize=_BS_HTMLSurface_SetSize@16")
	pSteamHTMLSurface->SetSize(unBrowserHandle, unWidth, unHeight);
}

// Stop the load of the current html page
DLL_FUNCTION(void) BS_HTMLSurface_StopLoad(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_StopLoad=_BS_HTMLSurface_StopLoad@8")
	pSteamHTMLSurface->StopLoad(unBrowserHandle);
}

// Reload (most likely from local cache) the current page
DLL_FUNCTION(void) BS_HTMLSurface_Reload(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_Reload=_BS_HTMLSurface_Reload@8")
	pSteamHTMLSurface->Reload(unBrowserHandle);
}

// navigate back in the page history
DLL_FUNCTION(void) BS_HTMLSurface_GoBack(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_GoBack=_BS_HTMLSurface_GoBack@8")
	pSteamHTMLSurface->GoBack(unBrowserHandle);
}

// navigate forward in the page history
DLL_FUNCTION(void) BS_HTMLSurface_GoForward(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_GoForward=_BS_HTMLSurface_GoForward@8")
	pSteamHTMLSurface->GoForward(unBrowserHandle);
}

// add this header to any url requests from this browser
DLL_FUNCTION(void) BS_HTMLSurface_AddHeader(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchKey, const char* pchValue) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_AddHeader=_BS_HTMLSurface_AddHeader@16")
	pSteamHTMLSurface->AddHeader(unBrowserHandle, pchKey, pchValue);
}

// run this javascript script in the currently loaded page
DLL_FUNCTION(void) BS_HTMLSurface_ExecuteJavascript(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchScript) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_ExecuteJavascript=_BS_HTMLSurface_ExecuteJavascript@12")
	pSteamHTMLSurface->ExecuteJavascript(unBrowserHandle, pchScript);
}

// Mouse click and mouse movement commands
DLL_FUNCTION(void) BS_HTMLSurface_MouseUp(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_MouseUp=_BS_HTMLSurface_MouseUp@12")
	pSteamHTMLSurface->MouseUp(unBrowserHandle, eMouseButton);
}

DLL_FUNCTION(void) BS_HTMLSurface_MouseDown(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_MouseDown=_BS_HTMLSurface_MouseDown@12")
	pSteamHTMLSurface->MouseDown(unBrowserHandle, eMouseButton);
}

DLL_FUNCTION(void) BS_HTMLSurface_MouseDoubleClick(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_MouseDoubleClick=_BS_HTMLSurface_MouseDoubleClick@12")
	pSteamHTMLSurface->MouseDoubleClick(unBrowserHandle, eMouseButton);
}

// x and y are relative to the HTML bounds
DLL_FUNCTION(void) BS_HTMLSurface_MouseMove(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int32_t x, int32_t y) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_MouseMove=_BS_HTMLSurface_MouseMove@16")
	pSteamHTMLSurface->MouseMove(unBrowserHandle, x, y);
}

// nDelta is pixels of scroll
DLL_FUNCTION(void) BS_HTMLSurface_MouseWheel(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int32_t nDelta) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_MouseWheel=_BS_HTMLSurface_MouseWheel@12")
	pSteamHTMLSurface->MouseWheel(unBrowserHandle, nDelta);
}

// keyboard interactions, native keycode is the virtual key code value from your OS
DLL_FUNCTION(void) BS_HTMLSurface_KeyDown(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_KeyDown=_BS_HTMLSurface_KeyDown@16")
	pSteamHTMLSurface->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

DLL_FUNCTION(void) BS_HTMLSurface_KeyUp(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_KeyUp=_BS_HTMLSurface_KeyUp@16")
	pSteamHTMLSurface->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

// cUnicodeChar is the unicode character point for this keypress (and potentially multiple chars per press)
DLL_FUNCTION(void) BS_HTMLSurface_KeyChar(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_KeyChar=_BS_HTMLSurface_KeyChar@16")
	pSteamHTMLSurface->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

// programmatically scroll this many pixels on the page
DLL_FUNCTION(void) BS_HTMLSurface_SetHorizontalScroll(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetHorizontalScroll=_BS_HTMLSurface_SetHorizontalScroll@12")
	pSteamHTMLSurface->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

DLL_FUNCTION(void) BS_HTMLSurface_SetVerticalScroll(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetVerticalScroll=_BS_HTMLSurface_SetVerticalScroll@12")
	pSteamHTMLSurface->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

// tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
DLL_FUNCTION(void) BS_HTMLSurface_SetKeyFocus(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetKeyFocus=_BS_HTMLSurface_SetKeyFocus@12")
	pSteamHTMLSurface->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
}

// open the current pages html code in the local editor of choice, used for debugging
DLL_FUNCTION(void) BS_HTMLSurface_ViewSource(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_ViewSource=_BS_HTMLSurface_ViewSource@8")
	pSteamHTMLSurface->ViewSource(unBrowserHandle);
}

// copy the currently selected text on the html page to the local clipboard
DLL_FUNCTION(void) BS_HTMLSurface_CopyToClipboard(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_CopyToClipboard=_BS_HTMLSurface_CopyToClipboard@8")
	pSteamHTMLSurface->CopyToClipboard(unBrowserHandle);
}

// paste from the local clipboard to the current html page
DLL_FUNCTION(void) BS_HTMLSurface_PasteFromClipboard(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_PasteFromClipboard=_BS_HTMLSurface_PasteFromClipboard@8")
	pSteamHTMLSurface->PasteFromClipboard(unBrowserHandle);
}

// find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
DLL_FUNCTION(void) BS_HTMLSurface_Find(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_Find=_BS_HTMLSurface_Find@20")
	pSteamHTMLSurface->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}

// cancel a currently running find
DLL_FUNCTION(void) BS_HTMLSurface_StopFind(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_StopFind=_BS_HTMLSurface_StopFind@8")
	pSteamHTMLSurface->StopFind(unBrowserHandle);
}

// return details about the link at position x,y on the current page
DLL_FUNCTION(void) BS_HTMLSurface_GetLinkAtPosition(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int x, int y) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_GetLinkAtPosition=_BS_HTMLSurface_GetLinkAtPosition@16")
	pSteamHTMLSurface->GetLinkAtPosition(unBrowserHandle, x, y);
}

// set a webcookie for the hostname in question
DLL_FUNCTION(void) BS_HTMLSurface_SetCookie(ISteamHTMLSurface* pSteamHTMLSurface, const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetCookie=_BS_HTMLSurface_SetCookie@32")
	pSteamHTMLSurface->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}

// Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
DLL_FUNCTION(void) BS_HTMLSurface_SetPageScaleFactor(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetPageScaleFactor=_BS_HTMLSurface_SetPageScaleFactor@20")
	pSteamHTMLSurface->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
}

// Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
// more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
// all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
// When background mode is disabled, any video or audio objects with that property will resume with ".play()".
DLL_FUNCTION(void) BS_HTMLSurface_SetBackgroundMode(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bBackgroundMode) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_SetBackgroundMode=_BS_HTMLSurface_SetBackgroundMode@12")
	pSteamHTMLSurface->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
}

// CALLBACKS
//
//  These set of functions are used as responses to callback requests
//

// You MUST call this in response to a HTML_StartRequest_t callback
//  Set bAllowed to true to allow this navigation, false to cancel it and stay 
// on the current page. You can use this feature to limit the valid pages
// allowed in your HTML surface.
DLL_FUNCTION(void) BS_HTMLSurface_AllowStartRequest(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bAllowed) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_AllowStartRequest=_BS_HTMLSurface_AllowStartRequest@12")
	pSteamHTMLSurface->AllowStartRequest(unBrowserHandle, bAllowed);
}

// You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
//  Set bResult to true for the OK option of a confirm, use false otherwise
DLL_FUNCTION(void) BS_HTMLSurface_JSDialogResponse(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bResult) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_JSDialogResponse=_BS_HTMLSurface_JSDialogResponse@12")
	pSteamHTMLSurface->JSDialogResponse(unBrowserHandle, bResult);
}

// You MUST call this in response to a HTML_FileOpenDialog_t callback
DLL_FUNCTION(void) BS_HTMLSurface_FileLoadDialogResponse(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles) {
#pragma comment(linker, "/EXPORT:BS_HTMLSurface_FileLoadDialogResponse=_BS_HTMLSurface_FileLoadDialogResponse@12")
	pSteamHTMLSurface->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
}