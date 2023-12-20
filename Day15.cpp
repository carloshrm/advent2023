#include "Day15.h"
#include <sstream>

Day15::Day15() : Solution{ 15, false }
{
}

void Day15::addLens(const ElfLens &new_lens)
{
	auto &current_box{ box_map[runHash(new_lens.label)] };
	for (auto &in_lens : current_box)
	{
		if (in_lens.label == new_lens.label)
		{
			in_lens.focal_length = new_lens.focal_length;
			return;
		}
	}
	current_box.push_back(new_lens);
}

void Day15::removeLens(const std::string_view label)
{
	auto &current_box{ box_map[runHash(label)] };
	std::erase_if(current_box, [label](auto &lens) { return lens.label == label; });
}

long long Day15::calcFocusingPower()
{
	long long total{ 0 };
	for (size_t box{ 0 }; box < box_map.size(); box++)
	{
		for (size_t slot{ 0 }; slot < box_map[box].size(); slot++)
		{
			total += (box + 1) * (slot + 1) * box_map[box][slot].focal_length;
		}
	}
	return total;
}

size_t Day15::runHash(std::string_view in)
{
	size_t hash_value{ 0 };
	for (size_t i = 0; i < in.size(); i++)
	{
		hash_value += in[i];
		hash_value *= 17;
		hash_value %= 256;
	}
	return hash_value;
}

std::string Day15::partOne()
{
	long long result{ 0 };
	std::istringstream ss(input.front());
	std::string sequence;
	while (std::getline(ss, sequence, ','))
	{
		result += runHash(sequence);
	}
	return std::to_string(result);
}

std::string Day15::partTwo()
{
	long long result{ 0 };
	std::istringstream ss(input.front());
	std::string sequence;
	while (std::getline(ss, sequence, ','))
	{
		for (size_t i{ 2 }; i < sequence.size(); i++)
		{
			if (sequence[i] == '-')
				removeLens(sequence.substr(0, i));
			else if (sequence[i] == '=')
				addLens(ElfLens{ sequence.substr(0, i), std::atoi(sequence.substr(i + 1, 1).data()) });
		}
	}

	return std::to_string(calcFocusingPower());
}
