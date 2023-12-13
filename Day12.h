#pragma once

#include "Solution.h"

using ElfSpring = std::pair <std::string, std::vector<int>>;

class Day12 : public Solution
{
private:
	std::map<std::tuple<std::string, std::vector<int>, size_t>, long long> memo{};

	long long validateState(const std::string_view spring_state, const std::vector<int> &state_sum, const size_t check_i);

public:
	Day12();

	std::string partOne() override;
	std::string partTwo() override;
};