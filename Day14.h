#pragma once

#include "Solution.h"
#include <Windows.h>

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
	void setCurPos(short x, short y);
	void drawSymbol(char s);
	HANDLE handle;
	void draw();

	std::string partOne() override;
	std::string partTwo() override;
};

