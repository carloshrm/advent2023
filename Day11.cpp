#include "Day11.h"

Day11::Day11() : Solution{ 11, false }
{
	for (size_t i{ 0 }; i < input.size(); i++)
	{
		if (std::all_of(input[i].begin(), input[i].end(), [](char c) { return c == '.'; }))
			horizontal_exp_idx.push_back(i);
	}

	for (size_t i{ 0 }; i < input.front().size(); i++)
	{
		bool found_galaxy{ false };
		for (size_t j{ 0 }; j < input.size(); j++)
		{
			if (input[j][i] == '#')
			{
				found_galaxy = true;
				break;
			}
		}
		if (!found_galaxy)
			vertical_exp_idx.push_back(i);
	}
}

long long Day11::calcManhattanDistance(const GalaxyPos &a, const GalaxyPos &b)
{
	return std::abs((long long)a.first - (long long)b.first) + std::abs((long long)a.second - (long long)b.second);
}

std::vector<GalaxyPos> Day11::makeGalaxies(const long long &expansion_size)
{
	std::vector<GalaxyPos> galaxies{};
	for (size_t i{ 0 }; i < input.size(); i++)
	{
		for (size_t j{ 0 }; j < input[i].size(); j++)
		{
			if (input[i][j] == '#')
			{
				int e_i{ 0 };
				for (auto &v : horizontal_exp_idx)
				{
					if (v <= i)
						e_i++;
				}

				int e_j{ 0 };
				for (auto &v : vertical_exp_idx)
				{
					if (v <= j)
						e_j++;
				}

				galaxies.push_back(GalaxyPos{ i + (e_i * expansion_size), j + (e_j * expansion_size) });
			}
		}
	}
	return galaxies;
}

std::string Day11::partOne()
{
	auto galaxies{ makeGalaxies(1) };
	int sum{ 0 };
	for (size_t i{ 0 }; i < galaxies.size(); i++)
	{
		for (size_t j{ i }; j < galaxies.size(); j++)
		{
			sum += calcManhattanDistance(galaxies[i], galaxies[j]);
		}
	}
	return std::to_string(sum);
}

std::string Day11::partTwo()
{
	auto galaxies{ makeGalaxies(1000000 - 1) };
	long long sum{ 0 };
	for (size_t i{ 0 }; i < galaxies.size(); i++)
	{
		for (size_t j{ i }; j < galaxies.size(); j++)
		{
			sum += calcManhattanDistance(galaxies[i], galaxies[j]);
		}
	}
	return std::to_string(sum);
}
