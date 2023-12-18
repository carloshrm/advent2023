#include "Day13.h"
#include <iostream>

Day13::Day13() : Solution{ 13, false }
{
	std::vector<std::string> layout{};
	for (auto &l : input)
	{
		if (l.empty())
		{
			valleys.push_back(ElfValley{ layout });
			layout.clear();
		}
		else
			layout.push_back(l);
	}
	if (!layout.empty())
		valleys.push_back(ElfValley{ layout });
}

Day13::ElfValley Day13::rotateValley(const ElfValley &v)
{
	std::vector<std::string> rotated{};
	for (size_t y{ 0 }; y < v.layout.front().size(); y++)
	{
		std::string h_line{};
		for (size_t x{ 0 }; x < v.layout.size(); x++)
		{
			h_line += v.layout[x][y];
		}
		rotated.push_back(h_line);
	}
	return ElfValley{ rotated, v.rotated_mirror ? v.first_mirror : std::string::npos, v.rotated_mirror };
}

std::vector<size_t> Day13::findReflectionPoints(const std::string_view line)
{
	std::vector<size_t> local_points{};
	int left{ 0 }, right{ 0 };
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
				local_points.push_back(i);
				break;
			}
		}
	}
	return local_points;
}

size_t Day13::findMirrorPos(const ElfValley &valley, const bool with_smudge = false)
{
	std::map<size_t, int> count{};
	for (size_t i{ 0 }; i < valley.layout.size(); i++)
	{
		for (auto &pt : findReflectionPoints(valley.layout[i]))
			count[pt]++;
	}
	for (auto &[pt, ln] : count)
	{
		if (ln == valley.layout.size())
		{
			if (!with_smudge || (with_smudge && valley.first_mirror != pt))
				return pt;
		}
	}
	return std::string::npos;
}

size_t Day13::searchSmudge(const ElfValley &valley)
{
	ElfValley temp{ valley };
	for (size_t i{ 0 }; i < temp.layout.size(); i++)
	{
		std::string prev_line{ temp.layout[i] };
		for (size_t j{ 0 }; j < temp.layout[i].size(); j++)
		{
			temp.layout[i] = prev_line;
			temp.layout[i][j] = (temp.layout[i][j] == '.' ? '#' : '.');
			size_t point = findMirrorPos(temp, true);
			if (point != std::string::npos)
				return point;
		}
		temp.layout[i] = prev_line;
	}
	return std::string::npos;
}

std::string Day13::partOne()
{
	long long result{ 0 };
	for (auto &v : valleys)
	{
		auto point{ findMirrorPos(v) };
		if (point == std::string::npos)
		{
			point = findMirrorPos(rotateValley(v));
			if (point != std::string::npos)
				result += (point + 1) * 100;
			v.rotated_mirror = true;
		}
		else
			result += point + 1;

		v.first_mirror = point;
	}
	return std::to_string(result);
}

std::string Day13::partTwo()
{
	long long result{ 0 };
	for (auto v : valleys)
	{
		size_t point{ findMirrorPos(v, true) };
		if (point == std::string::npos)
			point = searchSmudge(v);

		if (point == std::string::npos)
		{
			ElfValley rotated{ rotateValley(v) };
			point = findMirrorPos(rotated, true);
			if (point == std::string::npos)
				point = searchSmudge(rotated);

			result += (point + 1) * 100;
		}
		else
			result += point + 1;
	}
	return std::to_string(result);
}
