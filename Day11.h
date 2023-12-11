#pragma once

#include "Solution.h"

using GalaxyPos = std::pair<size_t, size_t>;

class Day11 : public Solution
{
private:
	std::vector<size_t> horizontal_exp_idx{};
	std::vector<size_t> vertical_exp_idx{};

	long long calcManhattanDistance(const GalaxyPos &a, const GalaxyPos &b);
	std::vector<GalaxyPos> makeGalaxies(const long long &expansion_size);
public:
	Day11();

	std::string partOne() override;
	std::string partTwo() override;
};