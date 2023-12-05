#pragma once
#include "Solution.h"
#include <set>

class Day4 : public Solution
{
private:
	struct ElfCard
	{
		std::set<int> winning_numbers{};
		std::set<int> drawn_numbers{};
	};

	struct CardScore
	{
		int id;
		int score;
	};

	std::vector<ElfCard> elf_cards{};
	std::vector<CardScore> card_scores{};
	std::set<int> getNumbers(size_t start, size_t end, std::string &info);
	void getBonusCards(const std::vector<CardScore> &hand, std::vector<CardScore> &prizes);
		
public:
	Day4();

	std::string partOne() override;
	std::string partTwo() override;
};

