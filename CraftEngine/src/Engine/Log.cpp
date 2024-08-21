#include "Log.h"
#include <iostream>

Craft::Log::Log(std::string name) {
	_name = name;
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Craft::Log::Log() {
	_name = "Generic Log";
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Craft::Log::~Log() {
}

void Craft::Log::Print(std::string text, const char* file, int line) {
	SetConsoleTextAttribute(_hConsole, (int)_selectedColor);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

void Craft::Log::Print_Log(std::string text, const char* file, int line) {
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::GREEN);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

void Craft::Log::Print_Info(std::string text, const char* file, int line) {
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::CYAN);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

void Craft::Log::Print_Error(std::string text, const char* file, int line) {
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::RED);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}