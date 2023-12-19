#include "Day14.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <format>

Day14::Day14() : Solution{ 14, false }
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto &ln : input)
	{
		std::vector<DishSpots> line{};
		for (char c : ln)
			line.push_back(c == '.' ? Space : (c == 'O' ? Ball : Rock));

		map.push_back(line);
	}
}

void Day14::setCurPos(short x, short y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

void Day14::drawSymbol(char s)
{
	int col{ (s == Ball ? 92 : s == Space ? 0 : 1) };
	std::cout << std::format("\033[{}m{} \033[m", col, (s == Ball ? 'O' : s == Space ? ' ' : '#'));
}

void Day14::draw()
{
	std::string show{};
	for (auto &l : map)
	{
		for (auto &s : l)
		{
			int col{ (s == Ball ? 92 : s == Space ? 0 : 1) };
			show += std::format("\033[{}m{} \033[m", col, (s == Ball ? 'O' : s == Space ? ' ' : '#'));
		}
		show += '\n';
	}
	system("CLS");
	std::cout << show;
}

long long Day14::calculateLoad()
{
	long long result{ 0 };
	for (size_t i{ 0 }; i < map.size(); i++)
	{
		for (size_t j{ 0 }; j < map[i].size(); j++)
		{
			if (map[i][j] == Ball)
				result += (map.size() - i);
		}
	}
	return result;
}

void Day14::tiltNorth()
{
	for (int i{ 0 }; i < map.size(); i++)
	{
		for (int j{ 0 }; j < map[i].size(); j++)
		{
			if (map[i][j] == Ball)
			{
				int step{ i };
				while (step > 0 && map[step - 1][j] == Space)
				{
					step--;
				}
				if (step != i)
				{
					setCurPos(j * 2, step);
					drawSymbol(map[i][j]);
					setCurPos(j * 2, i);
					std::cout << ' ';

					map[step][j] = map[i][j];
					map[i][j] = Space;
				}
			}
		}
	}
}

void Day14::tiltSouth()
{
	for (int i{ static_cast<int>(map.size() - 1) }; i >= 0; i--)
	{
		for (int j{ 0 }; j < map[i].size(); j++)
		{
			if (map[i][j] == Ball)
			{
				int step{ i };
				while (step < (map.size() - 1) && map[step + 1][j] == Space)
				{
					step++;
				}
				if (step != i)
				{
					setCurPos(j * 2, step);
					drawSymbol(map[i][j]);
					setCurPos(j * 2, i);
					std::cout << ' ';

					map[step][j] = map[i][j];
					map[i][j] = Space;
				}
			}
		}
	}
}

void Day14::tiltEast()
{
	for (int i{ 0 }; i < map.size(); i++)
	{
		for (int j{ static_cast<int>(map[i].size() - 1) }; j >= 0; j--)
		{
			if (map[i][j] == Ball)
			{
				int step{ j };
				while (step < (map[i].size() - 1) && map[i][step + 1] == Space)
				{
					step++;
				}
				if (step != j)
				{
					setCurPos(step * 2, i);
					drawSymbol(map[i][j]);
					setCurPos(j * 2, i);
					std::cout << ' ';

					map[i][step] = map[i][j];
					map[i][j] = Space;
				}
			}
		}
	}
}

void Day14::tiltWest()
{
	for (int i{ 0 }; i < map.size(); i++)
	{
		for (int j{ 0 }; j < map[i].size(); j++)
		{
			if (map[i][j] == Ball)
			{
				int step{ j };
				while (step > 0 && map[i][step - 1] == Space)
				{
					step--;
				}
				if (step != j)
				{
					setCurPos(step * 2, i);
					drawSymbol(map[i][j]);
					setCurPos(j * 2, i);
					std::cout << ' ';

					map[i][step] = map[i][j];
					map[i][j] = Space;
				}
			}
		}
	}
}

void Day14::runCycle()
{
	tiltNorth();
	tiltWest();
	tiltSouth();
	tiltEast();
}

std::string Day14::partOne()
{
	//tiltNorth();
	return std::to_string(calculateLoad());
}

std::string Day14::partTwo()
{
	for (size_t i = 0; i < 1000; i++)
	{
		runCycle();
	}
	return std::to_string(calculateLoad());
}
