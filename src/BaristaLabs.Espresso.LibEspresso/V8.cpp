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

#include "EspressoCommon.h"
#include "libplatform/libplatform.h"

static std::unique_ptr<v8::Platform> s_platform = nullptr;

ESPRESSO_API Initialize(const char* directory_path)
{
	// Initialize V8.
	v8::V8::InitializeICUDefaultLocation(directory_path);
	v8::V8::InitializeExternalStartupData(directory_path);
	if (s_platform == nullptr) {
		s_platform = v8::platform::NewDefaultPlatform(0);
	}
	v8::V8::InitializePlatform(s_platform.get());
	v8::V8::Initialize();

	return JsNoError;
}

ESPRESSO_API Shutdown() {
	v8::V8::Dispose();
	v8::V8::ShutdownPlatform();
	s_platform.release();
	s_platform = nullptr;
	return JsNoError;
}
