#pragma once

#include "Solution.h"

class Day1 : public Solution
{
private:
	static inline const std::vector<std::string> number_names{
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	size_t getFirstDigitPosition(std::string_view ln);
	size_t getLastDigitPosition(std::string_view ln);
	int findSpelledNumber(std::string_view slice);

public:
	Day1();

	std::string partOne() override;
	std::string partTwo() override;
};