#include "Day9.h"
#include "ElfHelper.h"
#include <iostream>

Day9::Day9() : Solution{ 9, false }
{
	std::for_each(input.begin(), input.end(),
		[this](auto &ln)
		{
			history.push_back(ElfHelper::parseDigits<int>(0, ln.length(), ln));
		});
}

std::vector<int> Day9::calcSequence(const std::vector<int> &source)
{
	std::vector<int> new_sequence{};
	if (source.size() == 1)
		new_sequence.push_back(0);
	else
	{
		for (size_t i{ 1 }; i < source.size(); i++)
		{
			new_sequence.push_back(source[i] - source[i - 1]);
		}
	}
	return new_sequence;
}

long long Day9::calcNextVal(const std::vector<std::vector<int>> &sequences)
{
	long long next_val{ 0 };
	for (auto i{ sequences.rbegin() }; i != sequences.rend(); i++)
	{
		next_val += (*i).back();
	}
	return next_val;
}

std::string Day9::partOne()
{
	long long result{ 0 };
	for (auto &entry : history)
	{
		std::vector<std::vector<int>> sequences{ entry };
		auto current_sequence = &sequences.back();
		while (!std::all_of((*current_sequence).begin(), (*current_sequence).end(), [](int n) { return n == 0; }))
		{
			sequences.push_back(calcSequence(*current_sequence));
			current_sequence = &sequences.back();
		}
		result += calcNextVal(sequences);
	}
	return std::to_string(result);
}

std::string Day9::partTwo()
{
	long long result{ 0 };
	for (auto &entry : history)
	{
		std::vector<std::vector<int>> sequences{ entry };
		std::reverse(sequences.back().begin(), sequences.back().end());
		auto current_sequence = &sequences.back();
		while (!std::all_of((*current_sequence).begin(), (*current_sequence).end(), [](int n) { return n == 0; }))
		{
			sequences.push_back(calcSequence(*current_sequence));
			current_sequence = &sequences.back();
		}
		result += calcNextVal(sequences);
	}
	return std::to_string(result);
}
