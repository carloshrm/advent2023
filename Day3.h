#pragma once

#include "Solution.h"
#include <list>

class Day3 : public Solution
{
private:
	struct PartNumber
	{
		int number{ 0 };
		bool checked{ true };
	};

	std::vector<std::vector<PartNumber *>> schematic;
	std::list<PartNumber> part_shelf{};
	int findSurroundingNumbers(size_t i, size_t j);
	int findRatio(size_t i, size_t j);
	void resetState();

public:

	Day3();

	std::string partOne() override;
	std::string partTwo() override;
};

