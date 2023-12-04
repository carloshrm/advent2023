#pragma once
#include "Solution.h"
#include <set>

class Day4 : public Solution
{
	struct CardInfo
	{
		std::set<int> winning_numbers{};
		std::set<int> drawn_numbers{};
	};

	std::vector<CardInfo> elf_cards{};
	std::set<int> getNumbers(size_t start, size_t end, std::string &info);
		
public:

	Day4();

	std::string partOne() override;
	std::string partTwo() override;
};

