
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#ifndef _ESPRESSOCOMMON_H_
#define _ESPRESSOCOMMON_H_

// Platform specific code
#if defined(_WIN32) && defined(_MSC_VER)
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>

// Header macros
#define ESPRESSO_API extern "C" __declspec(dllexport) JsErrorCode
#else 
#define CALLCONV
#define CALLINGCONVENTION
#define ESPRESSO_API extern "C" __declspec(dllexport) JsErrorCode
#define INCREMENT(x) __sync_fetch_and_add(&x, 1)
#define DECREMENT(x) __sync_fetch_and_add(&x, -1)
#endif

	/// <summary>
	///     An error code returned from a V8 hosting API.
	/// </summary>
typedef _Return_type_success_(return == 0) enum _JsErrorCode
{
	/// <summary>
	///     Success error code.
	/// </summary>
	JsNoError = 0,
} JsErrorCode;

#endif // _ESPRESSOCOMMON_H_