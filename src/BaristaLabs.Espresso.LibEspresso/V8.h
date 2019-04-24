#pragma once

#include "EspressoCommon.h";

#include <v8.h>
#include <libplatform/libplatform.h>

extern "C"
{
	ESPRESSO_API Initialize(const char* directory_path);

	ESPRESSO_API Shutdown();
}