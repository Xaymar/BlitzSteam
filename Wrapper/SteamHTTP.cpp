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

//-----------------------------------------------------------------------------
// Purpose: interface to http client
//-----------------------------------------------------------------------------
DLL_FUNCTION(ISteamHTTP*) BS_HTTP() {
	return SteamHTTP();
}

DLL_FUNCTION(ISteamHTTP*) BS_GameServerHTTP() {
	return SteamGameServerHTTP();
}

// Initializes a new HTTP request, returning a handle to use in further operations on it.  Requires
// the method (GET or POST) and the absolute URL for the request.  Both http and https are supported,
// so this string must start with http:// or https:// and should look like http://store.steampowered.com/app/250/ 
// or such.
DLL_FUNCTION(HTTPRequestHandle) BS_ISteamHTTP_CreateHTTPRequest(ISteamHTTP* pThis, EHTTPMethod eHTTPRequestMethod, const char* cAbsoluteUrl) {
	return pThis->CreateHTTPRequest(eHTTPRequestMethod, cAbsoluteUrl);
}

// Set a context value for the request, which will be returned in the HTTPRequestCompleted_t callback after
// sending the request.  This is just so the caller can easily keep track of which callbacks go with which request data.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestContextValue(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint64_t* plContextValue) {
	return pThis->SetHTTPRequestContextValue(hRequest, *plContextValue);
}

// Set a timeout in seconds for the HTTP request, must be called prior to sending the request.  Default
// timeout is 60 seconds if you don't call this.  Returns false if the handle is invalid, or the request
// has already been sent.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPNetworkActivityTimeout(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint32 unTimeoutSeconds) {
	return pThis->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
}

// Set a request header value for the request, must be called prior to sending the request.  Will 
// return false if the handle is invalid or the request is already sent.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestHeaderValue(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue) {
	return pThis->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
}

// Set a GET or POST parameter value on the request, which is set will depend on the EHTTPMethod specified
// when creating the request.  Must be called prior to sending the request.  Will return false if the 
// handle is invalid or the request is already sent.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestGetOrPostParameter(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue) {
	return pThis->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
}

// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
// asynchronous response via callback.
//
// Note: If the user is in offline mode in Steam, then this will add a only-if-cached cache-control 
// header and only do a local cache lookup rather than sending any actual remote request.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SendHTTPRequest(ISteamHTTP* pThis, HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle) {
	return pThis->SendHTTPRequest(hRequest, pCallHandle);
}

// Sends the HTTP request, will return false on a bad handle, otherwise use SteamCallHandle to wait on
// asynchronous response via callback for completion, and listen for HTTPRequestHeadersReceived_t and 
// HTTPRequestDataReceived_t callbacks while streaming.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SendHTTPRequestAndStreamResponse(ISteamHTTP* pThis, HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle) {
	return pThis->SendHTTPRequestAndStreamResponse(hRequest, pCallHandle);
}

// Defers a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the tail of the queue.  Returns false on invalid handle, or if the request is not yet sent.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_DeferHTTPRequest(ISteamHTTP* pThis, HTTPRequestHandle hRequest) {
	return pThis->DeferHTTPRequest(hRequest);
}

// Prioritizes a request you have sent, the actual HTTP client code may have many requests queued, and this will move
// the specified request to the head of the queue.  Returns false on invalid handle, or if the request is not yet sent.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_PrioritizeHTTPRequest(ISteamHTTP* pThis, HTTPRequestHandle hRequest) {
	return pThis->PrioritizeHTTPRequest(hRequest);
}

// Checks if a response header is present in a HTTP response given a handle from HTTPRequestCompleted_t, also 
// returns the size of the header value if present so the caller and allocate a correctly sized buffer for
// GetHTTPResponseHeaderValue.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPResponseHeaderSize(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize) {
	return pThis->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, unResponseHeaderSize);
}

// Gets header values from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the
// header is not present or if your buffer is too small to contain it's value.  You should first call 
// BGetHTTPResponseHeaderSize to check for the presence of the header and to find out the size buffer needed.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPResponseHeaderValue(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize) {
	return pThis->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
}

// Gets the size of the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPResponseBodySize(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint32 *unBodySize) {
	return pThis->GetHTTPResponseBodySize(hRequest, unBodySize);
}

// Gets the body data from a HTTP response given a handle from HTTPRequestCompleted_t, will return false if the 
// handle is invalid or is to a streaming response, or if the provided buffer is not the correct size.  Use BGetHTTPResponseBodySize first to find out
// the correct buffer size to use.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPResponseBodyData(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize) {
	return pThis->GetHTTPResponseBodyData(hRequest, pBodyDataBuffer, unBufferSize);
}

// Gets the body data from a streaming HTTP response given a handle from HTTPRequestDataReceived_t. Will return false if the 
// handle is invalid or is to a non-streaming response (meaning it wasn't sent with SendHTTPRequestAndStreamResponse), or if the buffer size and offset 
// do not match the size and offset sent in HTTPRequestDataReceived_t.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPStreamingResponseBodyData(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint32 cOffset, uint8 *pBodyDataBuffer, uint32 unBufferSize) {
	return pThis->GetHTTPStreamingResponseBodyData(hRequest, cOffset, pBodyDataBuffer, unBufferSize);
}

// Releases an HTTP response handle, should always be called to free resources after receiving a HTTPRequestCompleted_t
// callback and finishing using the response.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_ReleaseHTTPRequest(ISteamHTTP* pThis, HTTPRequestHandle hRequest) {
	return pThis->ReleaseHTTPRequest(hRequest);
}

// Gets progress on downloading the body for the request.  This will be zero unless a response header has already been
// received which included a content-length field.  For responses that contain no content-length it will report
// zero for the duration of the request as the size is unknown until the connection closes.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPDownloadProgressPct(ISteamHTTP* pThis, HTTPRequestHandle hRequest, float *pflPercentOut) {
	return pThis->GetHTTPDownloadProgressPct(hRequest, pflPercentOut);
}

// Sets the body for an HTTP Post request.  Will fail and return false on a GET request, and will fail if POST params
// have already been set for the request.  Setting this raw body makes it the only contents for the post, the pchContentType
// parameter will set the content-type header for the request so the server may know how to interpret the body.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestRawPostBody(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBody, uint32 unBodyLen) {
	return pThis->SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen);
}

// Creates a cookie container handle which you must later free with ReleaseCookieContainer().  If bAllowResponsesToModify=true
// than any response to your requests using this cookie container may add new cookies which may be transmitted with
// future requests.  If bAllowResponsesToModify=false than only cookies you explicitly set will be sent.  This API is just for
// during process lifetime, after steam restarts no cookies are persisted and you have no way to access the cookie container across
// repeat executions of your process.
DLL_FUNCTION(HTTPCookieContainerHandle) BS_ISteamHTTP_CreateCookieContainer(ISteamHTTP* pThis, bool bAllowResponsesToModify) {
	return pThis->CreateCookieContainer(bAllowResponsesToModify);
}

// Release a cookie container you are finished using, freeing it's memory
DLL_FUNCTION(int32_t) BS_ISteamHTTP_ReleaseCookieContainer(ISteamHTTP* pThis, HTTPCookieContainerHandle hCookieContainer) {
	return pThis->ReleaseCookieContainer(hCookieContainer);
}

// Adds a cookie to the specified cookie container that will be used with future requests.
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetCookie(ISteamHTTP* pThis, HTTPCookieContainerHandle hCookieContainer, const char *pchHost, const char *pchUrl, const char *pchCookie) {
	return pThis->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
}

// Set the cookie container to use for a HTTP request
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestCookieContainer(ISteamHTTP* pThis, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer) {
	return pThis->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
}

// Set the extra user agent info for a request, this doesn't clobber the normal user agent, it just adds the extra info on the end
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestUserAgentInfo(ISteamHTTP* pThis, HTTPRequestHandle hRequest, const char *pchUserAgentInfo) {
	return pThis->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
}

// Set that https request should require verified SSL certificate via machines certificate trust store
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(ISteamHTTP* pThis, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate) {
	return pThis->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
}

// Set an absolute timeout on the HTTP request, this is just a total time timeout different than the network activity timeout
// which can bump everytime we get more data
DLL_FUNCTION(int32_t) BS_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(ISteamHTTP* pThis, HTTPRequestHandle hRequest, uint32 unMilliseconds) {
	return pThis->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
}

// Check if the reason the request failed was because we timed it out (rather than some harder failure)
DLL_FUNCTION(int32_t) BS_ISteamHTTP_GetHTTPRequestWasTimedOut(ISteamHTTP* pThis, HTTPRequestHandle hRequest, bool *pbWasTimedOut) {
	return pThis->GetHTTPRequestWasTimedOut(hRequest, pbWasTimedOut);
}