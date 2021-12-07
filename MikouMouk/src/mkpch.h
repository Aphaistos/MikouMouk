#pragma once

#include <memory>
#include <utility>
#include <functional>
// #include "spdlog/sinks/stdout_color_sinks.h"

#include <string>
#include <sstream>
#include <vector>

#include "MikouMouk/Log.h"

#ifdef MK_PLATFORM_WINDOWS
	#include <Windows.h>
#endif