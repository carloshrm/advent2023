#pragma once

#include "Solution.h"
#include <array>

class Day15 : public Solution
{
private:
	struct ElfLens
	{
		std::string label{};
		int focal_length{};
	};

	std::array<std::vector<ElfLens>, 256> box_map{};

	size_t runHash(std::string_view in);
	void addLens(const ElfLens &lens);
	void removeLens(const std::string_view label);
	long long calcFocusingPower();

public:
	Day15();

	std::string partOne() override;
	std::string partTwo() override;
};

