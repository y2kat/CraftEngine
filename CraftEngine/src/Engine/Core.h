#pragma once

#ifdef CRAFT_PLATFORM_WINDOWS
	#ifdef CRAFT_BUILD_DLL
		#define CRAFT_API __declspec(dllexport) //identificador para saber q chow
	#else
		#define CRAFT_API __declspec(dllimport)
	#endif

#else
	#error Only support windows
#endif
