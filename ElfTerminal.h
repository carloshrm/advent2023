#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

class ElfTerminal
{
private:
	HANDLE _handle;

public:
	ElfTerminal();

	void clear();
	void setCursor(const short x, const short y);
	void draw(const std::string_view msg, const int cc, const int sleep);
};

