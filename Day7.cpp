#include "Day7.h"
#include <sstream>
#include <algorithm>

Day7::Day7() : Solution{ 7, true }
{
	for (auto &ln : input)
	{
		CamelHand new_hand{};
		for (size_t i{ 0 }; i < ln.length(); i++)
		{
			if (ln[i] != ' ')
				new_hand.cards[i] = ln[i];
			else
			{
				new_hand.bid = std::atoi(ln.substr(i + 1, ln.length()).data());
				break;
			}
		}
		camel_cards.push_back(new_hand);
	}
}

bool Day7::compareHands(CamelHand &first, CamelHand &second)
{
	HandRank fst_rank{ getRank(first) };
	HandRank sec_rank{ getRank(second) };
	if (fst_rank == sec_rank)
	{
		for (size_t i{ 0 }; i < 5; i++)
		{
			if (first.cards[i] != second.cards[i])
				return suit_val.at(first.cards[i]) > suit_val.at(second.cards[i]);
		}
		return true;
	}
	else
		return fst_rank < sec_rank;
}

Day7::HandRank Day7::getRank(CamelHand &target)
{
	if (target.rank == No_Rank)
		target.setRank(getGroups(target));

	return target.rank;
}

std::vector<int> Day7::getGroups(const CamelHand &target)
{
	std::map<char, int> groups{};
	for (auto &c : target.cards)
	{
		if (groups.find(c) == groups.end())
			groups[c] = 1;
		else
			groups[c]++;
	}
	std::vector<int> results{};
	for (auto &[k, v] : groups)
	{
		if (!results.empty() && results.back() < v)
			results.insert(results.begin(), v);
		else
			results.push_back(v);
	}
	return results;
}

std::string Day7::partOne()
{
	std::sort(camel_cards.begin(), camel_cards.end(),
		[this](Day7::CamelHand &a, Day7::CamelHand &b)
		{
			return this->compareHands(a, b);
		});

	long long result{ 0 };
	for (size_t i{ 0 }; i < camel_cards.size(); i++)
	{
		result += (i + 1) * camel_cards[i].bid;
	}
	return std::to_string(result);
}

std::string Day7::partTwo()
{
	return std::string();
}
