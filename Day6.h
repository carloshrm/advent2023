#pragma once

#include "Solution.h"

class Day6 : public Solution
{
private:
	struct RaceInfo
	{
		long long time{ };
		long long distance{ };
	};

	std::vector<RaceInfo> races{};
	double calcNumWinnerValues(const RaceInfo &race);

public:
	Day6();

	std::string partOne() override;
	std::string partTwo() override;
};

