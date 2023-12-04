#include "Day4.h"
#include <regex>

Day4::Day4() : Solution{ 4, false }
{

	for (auto &ln : input)
	{
		size_t start{ ln.find(':') };
		size_t split{ ln.find('|') };
		elf_cards.push_back(CardInfo{ getNumbers(start, split, ln), getNumbers(split + 1, ln.length(), ln)});
	}
}

std::set<int> Day4::getNumbers(size_t start, size_t len, std::string &info)
{
	const std::regex match_template("(\\d+)");

	std::set<int> numbers_found{ };
	std::sregex_token_iterator search(info.begin() + start, info.begin() + len, match_template);
	while (search != std::sregex_token_iterator())
	{
		numbers_found.insert(std::atoi((*search).str().data()));
		search++;
	}
	return numbers_found;
}

std::string Day4::partOne()
{
	int score{ 0 };
	for (auto &card : elf_cards)
	{
		int points{ -1 };
		for (int winning : card.winning_numbers)
		{
			if (card.drawn_numbers.find(winning) != card.drawn_numbers.end())
				points++;
		}
		score += std::pow(2, points);
	}
	return std::to_string(score);
}

std::string Day4::partTwo()
{
	return std::to_string(1);
}
