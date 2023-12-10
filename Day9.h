#pragma once

#include "Solution.h"

class Day9 : public Solution
{
private:
	std::vector<std::vector<int>> history{};

	std::vector<int> calcSequence(const std::vector<int> &source);
	long long calcNextVal(const std::vector<std::vector<int>> &sequences);

public:
	Day9();

	std::string partOne() override;
	std::string partTwo() override;
};

