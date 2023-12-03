#pragma once

#include "Solution.h"
#include <string>
#include <vector>
#include <tuple>

class Day2 : public Solution
{
	struct Game
	{
		int red{ 0 };
		int green{ 0 };
		int blue{ 0 };
	};

private:
	std::vector<std::vector<Game>> records;
	void setupRecords();
	Game parseGame(const size_t &prev_split_idx, const size_t &game_split_idx, std::string_view &ln);
	bool auditGame(const std::vector<Game> &pulls);
	int calcGamePower(const std::vector<Day2::Game> &pulls);

public:
	Day2();

	std::string partOne() override;
	std::string partTwo() override;
};