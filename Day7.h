#pragma once

#include "Solution.h"
#include <array>
#include <map>

class Day7 : public Solution
{
private:
	enum HandRank
	{
		High_card = -6,
		One_pair,
		Two_pair,
		Three_of_a_kind,
		Full_house,
		Four_of_a_kind,
		Five_of_a_kind,
		No_Rank
	};

	struct CamelHand
	{
		HandRank rank{ No_Rank };
		std::array<char, 5> cards{};
		int bid{};

		CamelHand()
		{
		}

		CamelHand(const CamelHand &camel_hand)
			: rank{ No_Rank }
			, cards{ camel_hand.cards }
			, bid{ camel_hand.bid }
		{
		}

		void setRank(std::vector<int> groups)
		{
			if (groups[0] == 5)
				rank = Five_of_a_kind;
			else if (groups[0] == 4)
				rank = Four_of_a_kind;
			else if (groups[0] == 3)
			{
				if (groups[1] == 2)
					rank = Full_house;
				else
					rank = Three_of_a_kind;
			}
			else if (groups[0] == 2)
			{
				if (groups[1] == 2)
					rank = Two_pair;
				else
					rank = One_pair;
			}
			else
				rank = High_card;
		}
	};


	const std::map<char, int> suit_val{
		{ 'A', 1 }, { 'K', 2 }, { 'Q', 3 }, { 'J', 4 },
		{ 'T', 5 }, { '9', 6 }, { '8', 7 }, { '7', 8 },
		{ '6', 9 }, { '5', 10 }, { '4', 11 }, { '3', 12 },
		{ '2', 13 } };

	const std::map<char, int> pt2_suit_val{
		{ 'A', 1 }, { 'K', 2 }, { 'Q', 3 }, { 'T', 4 },
		{ '9', 5 }, { '8', 6 }, { '7', 7 }, { '6', 8 },
		{ '5', 9 }, { '4', 10 }, { '3', 11 }, { '2', 12 },
		{ 'J', 13 }, };

	bool with_joker{ false };
	std::vector<CamelHand> camel_cards{};

	bool compareHands(CamelHand &first, CamelHand &second);
	HandRank getRank(CamelHand &target);
	std::vector<int> getGroups(const CamelHand &target);

public:
	Day7();

	std::string partOne() override;
	std::string partTwo() override;
};

