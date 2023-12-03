#include "Solution.h"
#include "Day1.h"
#include <numeric>
#include <cstddef>
#include <string>
#include <algorithm>

Day1::Day1() : Solution{ 1, false }
{
}

size_t Day1::getFirstDigitPosition(std::string_view ln)
{
	for (size_t i{ 0 }; i < ln.length(); i++)
	{
		if (std::isdigit(ln[i]))
			return i;
	}
	return 0;
}

size_t Day1::getLastDigitPosition(std::string_view ln)
{
	for (size_t i{ ln.length() - 1 }; i >= 0 && i != SIZE_MAX; i--)
	{
		if (std::isdigit(ln[i]))
			return i;
	}
	return 0;
}

int Day1::findSpelledNumber(std::string_view slice)
{
	if (slice.length() < 3)
		return 0;

	size_t num_pos{ 0 };
	for (size_t i{ 0 }; i < number_names.size(); i++)
	{
		num_pos = slice.find(number_names[i]);
		if (num_pos != std::string::npos)
			return (int)(i + 1);
	}
	return 0;
}

std::string Day1::partOne()
{
	std::vector<int> calibration_values{};
	for (std::string_view ln : input)
	{
		char first{ ln[getFirstDigitPosition(ln)] };
		char last{ ln[getLastDigitPosition(ln)] };

		calibration_values.push_back(((first - '0') * 10) + (last - '0'));
	}
	int total{ std::accumulate(calibration_values.begin(), calibration_values.end(), 0) };
	return std::to_string(total);
}

std::string Day1::partTwo()
{
	std::vector<int> calibration_values{};
	for (std::string_view ln : input)
	{
		int current_number{ 0 };

		size_t idx_first{ getFirstDigitPosition(ln) };
		size_t idx_before_first{ 0 };
		int num_before_first{ 0 };
		if (idx_first >= 3)
		{
			while (idx_before_first + 3 <= idx_first && num_before_first == 0)
			{
				num_before_first = findSpelledNumber(ln.substr(idx_before_first, 5));
				idx_before_first += 1;
			}
		}
		current_number += (num_before_first == 0 ? (ln[idx_first] - '0') : num_before_first) * 10;

		size_t idx_last{ getLastDigitPosition(ln) };
		size_t idx_after_last{ ln.length() - 3 };
		int num_after_last{ 0 };
		if (ln.length() - idx_last >= 3)
		{
			while (idx_after_last > idx_last && num_after_last == 0)
			{
				num_after_last = findSpelledNumber(ln.substr(idx_after_last, 5));
				idx_after_last -= 1;
			}
		}
		current_number += num_after_last == 0 ? (ln[idx_last] - '0') : num_after_last;
		calibration_values.push_back(current_number);
	}
	int total{ std::accumulate(calibration_values.begin(), calibration_values.end(), 0) };
	return std::to_string(total);
}
