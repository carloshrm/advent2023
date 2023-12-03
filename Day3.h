#pragma once

#include "Solution.h"
#include <list>

class Day3 : public Solution
{
	struct PartNumber
	{
		int number{ 0 };
		bool checked{ true };
	};

public:
	std::vector<std::vector<PartNumber *>> schematic;
	std::list<PartNumber> part_shelf{};
	int findSurroundingNumbers(size_t i, size_t j);

	Day3();

	std::string partOne() override;
	std::string partTwo() override;
};

