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

DLL_FUNCTION(ISteamHTMLSurface*) BS_SteamHTMLSurface() {
	return SteamHTMLSurface();
}

// Must call init and shutdown when starting/ending use of the interface
DLL_FUNCTION(uint32_t) BS_SteamHTMLSurface_Init(ISteamHTMLSurface* pSteamHTMLSurface) {
	return pSteamHTMLSurface->Init();
}

DLL_FUNCTION(uint32_t) BS_SteamHTMLSurface_Shutdown(ISteamHTMLSurface* pSteamHTMLSurface) {
	return pSteamHTMLSurface->Shutdown();
}

// Create a browser object for display of a html page, when creation is complete the call handle
// will return a HTML_BrowserReady_t callback for the HHTMLBrowser of your new browser.
//   The user agent string is a substring to be added to the general user agent string so you can
// identify your client on web servers.
//   The userCSS string lets you apply a CSS style sheet to every displayed page, leave null if
// you do not require this functionality.
DLL_FUNCTION(SteamAPICall_t*) BS_SteamHTMLSurface_CreateBrowser(ISteamHTMLSurface* pSteamHTMLSurface, const char* pchUserAgent, const char* pchUserCSS) {
	return new SteamAPICall_t(pSteamHTMLSurface->CreateBrowser(pchUserAgent, pchUserCSS));
}

// Call this when you are done with a html surface, this lets us free the resources being used by it
DLL_FUNCTION(void) BS_SteamHTMLSurface_RemoveBrowser(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->RemoveBrowser(unBrowserHandle);
}

// Navigate to this URL, results in a HTML_StartRequest_t as the request commences 
DLL_FUNCTION(void) BS_SteamHTMLSurface_LoadURL(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchURL, const char* pchPostData) {
	pSteamHTMLSurface->LoadURL(unBrowserHandle, pchURL, pchPostData);
}

// Tells the surface the size in pixels to display the surface
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetSize(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32_t unWidth, uint32_t unHeight) {
	pSteamHTMLSurface->SetSize(unBrowserHandle, unWidth, unHeight);
}

// Stop the load of the current html page
DLL_FUNCTION(void) BS_SteamHTMLSurface_StopLoad(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->StopLoad(unBrowserHandle);
}

// Reload (most likely from local cache) the current page
DLL_FUNCTION(void) BS_SteamHTMLSurface_Reload(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->Reload(unBrowserHandle);
}

// navigate back in the page history
DLL_FUNCTION(void) BS_SteamHTMLSurface_GoBack(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->GoBack(unBrowserHandle);
}

// navigate forward in the page history
DLL_FUNCTION(void) BS_SteamHTMLSurface_GoForward(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->GoForward(unBrowserHandle);
}

// add this header to any url requests from this browser
DLL_FUNCTION(void) BS_SteamHTMLSurface_AddHeader(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchKey, const char* pchValue) {
	pSteamHTMLSurface->AddHeader(unBrowserHandle, pchKey, pchValue);
}

// run this javascript script in the currently loaded page
DLL_FUNCTION(void) BS_SteamHTMLSurface_ExecuteJavascript(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char* pchScript) {
	pSteamHTMLSurface->ExecuteJavascript(unBrowserHandle, pchScript);
}

// Mouse click and mouse movement commands
DLL_FUNCTION(void) BS_SteamHTMLSurface_MouseUp(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
	pSteamHTMLSurface->MouseUp(unBrowserHandle, eMouseButton);
}

DLL_FUNCTION(void) BS_SteamHTMLSurface_MouseDown(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
	pSteamHTMLSurface->MouseDown(unBrowserHandle, eMouseButton);
}

DLL_FUNCTION(void) BS_SteamHTMLSurface_MouseDoubleClick(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton) {
	pSteamHTMLSurface->MouseDoubleClick(unBrowserHandle, eMouseButton);
}

// x and y are relative to the HTML bounds
DLL_FUNCTION(void) BS_SteamHTMLSurface_MouseMove(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int32_t x, int32_t y) {
	pSteamHTMLSurface->MouseMove(unBrowserHandle, x, y);
}

// nDelta is pixels of scroll
DLL_FUNCTION(void) BS_SteamHTMLSurface_MouseWheel(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int32_t nDelta) {
	pSteamHTMLSurface->MouseWheel(unBrowserHandle, nDelta);
}

// keyboard interactions, native keycode is the virtual key code value from your OS
DLL_FUNCTION(void) BS_SteamHTMLSurface_KeyDown(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
	pSteamHTMLSurface->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

DLL_FUNCTION(void) BS_SteamHTMLSurface_KeyUp(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
	pSteamHTMLSurface->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}

// cUnicodeChar is the unicode character point for this keypress (and potentially multiple chars per press)
DLL_FUNCTION(void) BS_SteamHTMLSurface_KeyChar(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers) {
	pSteamHTMLSurface->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}

// programmatically scroll this many pixels on the page
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetHorizontalScroll(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll) {
	pSteamHTMLSurface->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

DLL_FUNCTION(void) BS_SteamHTMLSurface_SetVerticalScroll(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll) {
	pSteamHTMLSurface->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
}

// tell the html control if it has key focus currently, controls showing the I-beam cursor in text controls amongst other things
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetKeyFocus(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus) {
	pSteamHTMLSurface->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
}

// open the current pages html code in the local editor of choice, used for debugging
DLL_FUNCTION(void) BS_SteamHTMLSurface_ViewSource(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->ViewSource(unBrowserHandle);
}

// copy the currently selected text on the html page to the local clipboard
DLL_FUNCTION(void) BS_SteamHTMLSurface_CopyToClipboard(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->CopyToClipboard(unBrowserHandle);
}

// paste from the local clipboard to the current html page
DLL_FUNCTION(void) BS_SteamHTMLSurface_PasteFromClipboard(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->PasteFromClipboard(unBrowserHandle);
}

// find this string in the browser, if bCurrentlyInFind is true then instead cycle to the next matching element
DLL_FUNCTION(void) BS_SteamHTMLSurface_Find(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse) {
	pSteamHTMLSurface->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}

// cancel a currently running find
DLL_FUNCTION(void) BS_SteamHTMLSurface_StopFind(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle) {
	pSteamHTMLSurface->StopFind(unBrowserHandle);
}

// return details about the link at position x,y on the current page
DLL_FUNCTION(void) BS_SteamHTMLSurface_GetLinkAtPosition(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, int x, int y) {
	pSteamHTMLSurface->GetLinkAtPosition(unBrowserHandle, x, y);
}

// set a webcookie for the hostname in question
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetCookie(ISteamHTMLSurface* pSteamHTMLSurface, const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly) {
	pSteamHTMLSurface->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}

// Zoom the current page by flZoom ( from 0.0 to 2.0, so to zoom to 120% use 1.2 ), zooming around point X,Y in the page (use 0,0 if you don't care)
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetPageScaleFactor(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY) {
	pSteamHTMLSurface->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
}

// Enable/disable low-resource background mode, where javascript and repaint timers are throttled, resources are
// more aggressively purged from memory, and audio/video elements are paused. When background mode is enabled,
// all HTML5 video and audio objects will execute ".pause()" and gain the property "._steam_background_paused = 1".
// When background mode is disabled, any video or audio objects with that property will resume with ".play()".
DLL_FUNCTION(void) BS_SteamHTMLSurface_SetBackgroundMode(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bBackgroundMode) {
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
DLL_FUNCTION(void) BS_SteamHTMLSurface_AllowStartRequest(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bAllowed) {
	pSteamHTMLSurface->AllowStartRequest(unBrowserHandle, bAllowed);
}

// You MUST call this in response to a HTML_JSAlert_t or HTML_JSConfirm_t callback
//  Set bResult to true for the OK option of a confirm, use false otherwise
DLL_FUNCTION(void) BS_SteamHTMLSurface_JSDialogResponse(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, bool bResult) {
	pSteamHTMLSurface->JSDialogResponse(unBrowserHandle, bResult);
}

// You MUST call this in response to a HTML_FileOpenDialog_t callback
DLL_FUNCTION(void) BS_SteamHTMLSurface_FileLoadDialogResponse(ISteamHTMLSurface* pSteamHTMLSurface, HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles) {
	pSteamHTMLSurface->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
}