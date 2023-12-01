#include "Solution.h"
#include <numeric>
#include <cstddef>
#include <string>


class Day1 : public Solution
{

public:
	Day1() : Solution{ 1, false }
	{
	}

	std::string partOne() const override
	{
		std::vector<int> calibration_values{};
		for (auto &ln : input)
		{
			char first = ' ';
			for (size_t i{ 0 }; first == ' '; i++)
			{
				if (std::isdigit(ln[i]))
					first = ln[i];
			}

			char last = ' ';
			for (size_t i{ ln.length() - 1 }; last == ' '; i--)
			{
				if (std::isdigit(ln[i]))
					last = ln[i];
			}

			calibration_values.push_back(((first - '0') * 10) + (last - '0'));
		}
		long long total{ std::accumulate(calibration_values.begin(), calibration_values.end(), 0) };
		return std::to_string(total);
	}

	std::string partTwo() const override
	{
		return "";
	}
};