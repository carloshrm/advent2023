#pragma once

#include "Solution.h"

using ElfSpring = std::pair < std::string, std::vector<int>>;

class Day12 : public Solution
{
private:
	std::vector<ElfSpring> hot_springs{};
	int validateState(const std::string_view spring_state, const std::vector<int> &state_check, const size_t check_i);
public:
	Day12();

	std::string partOne() override;
	std::string partTwo() override;
};