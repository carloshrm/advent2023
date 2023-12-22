#pragma once

#include "Solution.h"

class Day14 : public Solution
{
private:
	enum DishSpots
	{
		Space,
		Ball,
		Rock
	};

	std::vector<std::vector<DishSpots>> map{};
	long long calculateLoad();
	void tiltNorth();
	void tiltSouth();
	void tiltEast();
	void tiltWest();
	void runCycle();

public:
	Day14();

	std::string partOne() override;
	std::string partTwo() override;
};

