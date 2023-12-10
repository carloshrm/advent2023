#pragma once

#include "Solution.h"

class Day2 : public Solution
{

private:
	struct Game
	{
		int red{ 0 };
		int green{ 0 };
		int blue{ 0 };
	};

	std::vector<std::vector<Game>> records;

	int calcGamePower(const std::vector<Day2::Game> &pulls);
	Game parseGame(const size_t prev_split_idx, const size_t game_split_idx, std::string_view ln);
	bool auditGame(const std::vector<Game> &pulls);
	void setupRecords();

public:
	Day2();

	std::string partOne() override;
	std::string partTwo() override;
};