#include <string>
#include "Solution.h"

Solution::Solution(int day, bool example)
{
	std::string line{ };
	std::ifstream file(std::format("day{}{}.txt", day, (example ? "_e" : "")));
	while (std::getline(file, line))
		input.push_back(line);
}