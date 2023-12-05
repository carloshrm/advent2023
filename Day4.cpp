#include "Day4.h"
#include <regex>
#include <queue>

Day4::Day4() : Solution{ 4, false }
{
	for (auto &ln : input)
	{
		size_t start{ ln.find(':') };
		size_t split{ ln.find('|') };
		elf_cards.push_back(ElfCard{ getNumbers(start, split, ln), getNumbers(split + 1, ln.length(), ln) });
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
	int total_score{ 0 };
	int id{ 1 };
	for (auto &card : elf_cards)
	{
		int points{ 0 };
		for (int winning : card.winning_numbers)
		{
			if (card.drawn_numbers.find(winning) != card.drawn_numbers.end())
				points++;
		}
		card_scores.push_back(CardScore{ id++, points });
		total_score += std::pow(2, points - 1);
	}
	return std::to_string(total_score);
}

void Day4::getBonusCards(const std::vector<CardScore> &hand, std::vector<CardScore> &prizes)
{
	for (auto card : hand)
	{
		int prize_id{ card.score };
		while (prize_id-- > 0)
			prizes.push_back(card_scores.at(card.id + prize_id));
	}
}

std::string Day4::partTwo()
{
	long long collection_size{ static_cast<int>(elf_cards.size()) };

	std::vector<CardScore> prev_hand{ };
	for (auto &c : card_scores)
		prev_hand.push_back(c);

	std::vector<CardScore> bonus_cards{ };
	while (!prev_hand.empty())
	{
		bonus_cards.clear();
		getBonusCards(prev_hand, bonus_cards);

		collection_size += bonus_cards.size();
		prev_hand = bonus_cards;
	}
	return std::to_string(collection_size);
}
