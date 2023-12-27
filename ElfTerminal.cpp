#include "ElfTerminal.h"

ElfTerminal::ElfTerminal()
{
	_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ElfTerminal::clear()
{
	system("CLS");
}

void ElfTerminal::setCursor(const short x, const short y)
{
	SetConsoleCursorPosition(_handle, { x, y });
}

void ElfTerminal::draw(const std::string_view msg, const int cc = 0, const int sleep = 0)
{
	if (sleep != 0)
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep));

	std::cout << "\033[" << cc << "m" << msg << "\033[m";
}