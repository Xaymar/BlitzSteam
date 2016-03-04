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

DLL_FUNCTION(ISteamHTTP*) BS_HTTP() {
	return SteamHTTP();
}

DLL_FUNCTION(ISteamHTTP*) BS_GameServerHTTP() {
	return SteamGameServerHTTP();
}

DLL_FUNCTION(HTTPRequestHandle) BS_ISteamHTTP_CreateHTTPRequest(ISteamHTTP* pThis, EHTTPMethod eHTTPRequestMethod, const char* cAbsoluteUrl) {
	return pThis->CreateHTTPRequest(eHTTPRequestMethod, cAbsoluteUrl);
}