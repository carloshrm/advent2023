#pragma once

#include "Solution.h"
#include <map>

class Day8 : public Solution
{
private:
	struct DesertNode
	{
		std::string left{};
		std::string right{};
	};

	std::string instructions{};
	std::map<std::string, DesertNode> desert_map{ };

public:
	Day8();

	std::string partOne() override;
	std::string partTwo() override;
};

