#pragma once
#include "Engine/Core.h"

#include "craftpch.h"
#include <format>
#include <windows.h>

namespace Craft {
	class CRAFT_API Log {
		enum class ConsoleColor {
			BLUE = 9,
			GREEN = 10,
			CYAN = 11,
			RED = 12,
			MAGENTA = 13,
			YELLOW = 14,
			WHITE = 15,
		};
	public:
		Log(std::string name);
		Log();
		~Log();

		void Print(std::string text, const char* file, int line);
		void Print_Log(std::string text, const char* file, int line);
		void Print_Info(std::string text, const char* file, int line);
		void Print_Error(std::string text, const char* file, int line);

	private:
		std::string _name;
		HANDLE _hConsole;
		ConsoleColor _selectedColor = ConsoleColor::GREEN;
	};
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define LOG(x) log->Print(x, __FILENAME__, __LINE__);
#define LOG_TEST(...) log -> Print(std::format(__VA_ARGS__), __FILENAME__, __LINE__);

#define PRINT_LOG(...) log->Print_Log(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define PRINT_INFO(...) log->Print_Info(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define PRINT_ERROR(...) log->Print_Error(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
