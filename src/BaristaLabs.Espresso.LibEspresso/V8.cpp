#pragma once

#include "pch.h"
#include "V8.h"
/// \mainpage V8 Hosting API Reference
///
/// V8 is Chromium's JavaScript engine. It is an integral part of Chrome but can
/// also be hosted independently by other applications. This reference describes the APIs available
/// to applications to host V8.
///
/// This file contains the common API set shared among all V8 releases. 

/// \file
/// \brief The base V8 hosting API.
///
/// This file contains a flat C API layer. This is the API exported by LibEspresso.dll.
#include <v8.h>

#include "EspressoCommon.h";
#include "libplatform/libplatform.h"

std::unique_ptr<v8::Platform> platform = nullptr;

ESPRESSO_API Initialize(const char* directory_path)
{

	// Initialize V8.
	v8::V8::InitializeICUDefaultLocation(directory_path);
	v8::V8::InitializeExternalStartupData(directory_path);
	if (platform == nullptr) {
		platform = v8::platform::NewDefaultPlatform(0);
	}
	v8::V8::InitializePlatform(platform.get());
	v8::V8::Initialize();

	return JsNoError;
}

ESPRESSO_API Shutdown() {
	v8::V8::Dispose();
	v8::V8::ShutdownPlatform();
	platform = nullptr;
	return JsNoError;
}
