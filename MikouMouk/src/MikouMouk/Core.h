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

#define BIT(x) (1 << x)