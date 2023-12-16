#include "Day13.h"
#include <iostream>

Day13::Day13() : Solution{ 13, true }
{
	ElfValley new_valley{};
	for (auto &l : input)
	{
		if (l.empty())
		{
			valleys.push_back(new_valley);
			new_valley = ElfValley();
		}
		else
			new_valley.push_back(l);
	}
	if (!new_valley.empty())
		valleys.push_back(new_valley);
}

ElfValley Day13::rotateValley(const ElfValley &v)
{
	ElfValley rotated{};
	for (size_t y{ 0 }; y < v.front().size(); y++)
	{
		std::string h_line{};
		for (size_t x{ 0 }; x < v.size(); x++)
		{
			h_line += v[x][y];
		}
		rotated.push_back(h_line);
	}
	return rotated;
}

void Day13::findReflectionPoints(const std::string_view line, std::map<size_t, int> &points)
{
	int left{ 0 };
	int right{ 0 };
	for (size_t i{ 0 }; i < line.size() - 1; i++)
	{
		left = i;
		right = left + 1;
		int inner_offset{ 0 };
		while (line[left - inner_offset] == line[right + inner_offset])
		{
			inner_offset++;
			if (left - inner_offset < 0 || right + inner_offset >= line.size())
			{
				points[i]++;
				break;
			}
		}
	}
}

size_t Day13::findMirrorPos(const ElfValley &valley)
{
	std::map<size_t, int> reflection_pts{};
	for (size_t i{ 0 }; i < valley.size(); i++)
	{
		findReflectionPoints(valley[i], reflection_pts);
	}
	auto point = std::max_element(reflection_pts.begin(), reflection_pts.end(),
		[](const auto &a, const auto &b) { return a.second < b.second; });

	if (point == reflection_pts.end() || point->second != valley.size())
		return std::string::npos;
	else
		return point->first;
}

size_t Day13::findMirrorWithSmudge(const ElfValley &valley)
{
	std::map<size_t, int> reflection_pts{};
	for (size_t i{ 0 }; i < valley.size(); i++)
	{
		findReflectionPoints(valley[i], reflection_pts);
	}
	std::map<size_t, int> sec_pts{};
	auto rotated{ rotateValley(valley) };
	for (size_t i{ 0 }; i < rotated.size(); i++)
	{
		findReflectionPoints(rotated[i], sec_pts);
	}
	return 0;
}

std::string Day13::partOne()
{
	long long result{ 0 };
	for (auto &v : valleys)
	{
		size_t point{ findMirrorPos(v) };
		if (point == std::string::npos)
			point = (findMirrorPos(rotateValley(v)) + 1) * 100;
		else
			point += 1;

		result += point;
	}
	return std::to_string(result);
}

std::string Day13::partTwo()
{
	long long result{ 0 };
	for (auto &v : valleys)
	{
		size_t point{ findMirrorWithSmudge(v) };

		result += point;
	}
	return std::to_string(result);
}
