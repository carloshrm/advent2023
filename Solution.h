#pragma once

#include <string>
#include <vector>
#include <format>
#include <fstream>

class Solution
{
protected:
	std::vector<std::string> input{};
	Solution(int day, bool example);

public:
	virtual std::string partOne() = 0;
	virtual std::string partTwo() = 0;
};