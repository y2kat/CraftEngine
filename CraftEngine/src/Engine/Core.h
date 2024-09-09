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

#ifdef CRAFT_ENABLE_ASSERTS
	#define CRAFT_ASSERT(x, ...) {if(!(x)){ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define CRAFT_CORE_ASSERT(x, ...) {if(!(x)){ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define CRAFT_ASSERT(x, ...)
	#define CRAFT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
