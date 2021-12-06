#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MikouMouk {
	class MIKOUMOUK_API Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MK_CORE_TRACE(...) ::MikouMouk::Log::getCoreLogger()->trace(__VA_ARGS__)
#define MK_CORE_INFO(...)  ::MikouMouk::Log::getCoreLogger()->info(__VA_ARGS__)
#define MK_CORE_WARN(...)  ::MikouMouk::Log::getCoreLogger()->warn(__VA_ARGS__)
#define MK_CORE_ERROR(...) ::MikouMouk::Log::getCoreLogger()->error(__VA_ARGS__)
#define MK_CORE_FATAL(...) ::MikouMouk::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MK_TRACE(...) ::MikouMouk::Log::getClientLogger()->trace(__VA_ARGS__)
#define MK_INFO(...)  ::MikouMouk::Log::getClientLogger()->info(__VA_ARGS__)
#define MK_WARN(...)  ::MikouMouk::Log::getClientLogger()->warn(__VA_ARGS__)
#define MK_ERROR(...) ::MikouMouk::Log::getClientLogger()->error(__VA_ARGS__)
#define MK_FATAL(...) ::MikouMouk::Log::getClientLogger()->fatal(__VA_ARGS__)