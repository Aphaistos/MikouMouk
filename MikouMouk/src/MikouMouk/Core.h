#pragma once

#ifdef  MK_PLATFORM_WINDOWS
	#ifdef MK_BUILD_DLL
		#define MIKOUMOUK_API __declspec(dllexport)
	#else
		#define MIKOUMOUK_API __declspec(dllimport)
	#endif
#else
	#error MikouMouk only suport Windows!
#endif

#ifdef MK_ENABLE_ASSERTS
	#define MK_ASSERT(x, ...) { if(!(x)) { MK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MK_CORE_ASSERT(x, ...) { if(!(x)) { MK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MK_ASSERT(x, ...)
	#define MK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)