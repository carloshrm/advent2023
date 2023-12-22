#include "Day14.h"

Day14::Day14() : Solution{ 14, false }
{
	for (auto &ln : input)
	{
		std::vector<DishSpots> line{};
		for (char c : ln)
			line.push_back(c == '.' ? Space : (c == 'O' ? Ball : Rock));

		map.push_back(line);
	}
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
