// STL Exceptions
#include <exception>
#include <stdexcept>

// Memory Management
#include <memory>

// Platform specific: Windows
#include <windows.h>

// Macros
#define DLL_EXPORT extern "C" //__declspec(dllexport)

// Steam
#include "steam/steam_api.h"

// Error Messages
#define ERROR_TITLE_001	TEXT("Error 001")
#define ERROR_TEXT_001	TEXT("E001: Could not load 'BlitzPointer.dll'.")
#define ERROR_TITLE_002 TEXT("Error 002")
#define ERROR_TEXT_002	TEXT("E002: Unable to find one or multiple function addresses in 'BlitzPointer.dll'.")