#include "Day12.h"
#include "ElfHelper.h"
#include <iostream>

Day12::Day12() : Solution{ 12, false }
{
}

long long Day12::validateState(const std::string_view spring_state, const std::vector<int> &state_sum, const size_t sum_i)
{
	if (spring_state.empty())
	{
		if (sum_i == state_sum.size())
			return 1;
		else
			return 0;
	}
	if (memo.contains(std::make_tuple(std::string(spring_state), state_sum, sum_i)))
		return memo[std::make_tuple(std::string(spring_state), state_sum, sum_i)];

	long long result{ 0 };
	if (spring_state[0] == '.')
		result = validateState(spring_state.substr(1, spring_state.size()), state_sum, sum_i);
	else if (spring_state[0] == '?')
	{
		std::string damaged_option(spring_state);
		damaged_option[0] = '#';
		std::string normal_option(spring_state);
		normal_option[0] = '.';
		result = validateState(damaged_option, state_sum, sum_i) + validateState(normal_option, state_sum, sum_i);
	}
	else if (spring_state[0] == '#')
	{
		if (sum_i >= state_sum.size() || spring_state.size() <= state_sum[sum_i] - 1)
			return 0;

		int n{ 0 };
		size_t j{ 0 };
		while (j < state_sum[sum_i])
		{
			if (spring_state[j] != '.')
				n++;
			j++;
		}
		if (n == state_sum[sum_i])
		{
			if (spring_state.size() == n)
			{
				if (sum_i == state_sum.size() - 1)
					return 1;
				else
					return 0;
			}
			else if (spring_state[state_sum[sum_i]] == '.')
				result = validateState(spring_state.substr(n, spring_state.size()), state_sum, sum_i + 1);
			else if (spring_state[state_sum[sum_i]] == '?')
				result = validateState(spring_state.substr(n + 1, spring_state.size()), state_sum, sum_i + 1);
			else
				return 0;
		}
		else
			return 0;
	}
	memo[std::make_tuple(std::string(spring_state), state_sum, sum_i)] = result;
	return result;
}

std::string Day12::partOne()
{
	std::vector<ElfSpring> hot_springs{};
	for (auto &ln : input)
	{
		const size_t div{ ln.find(' ') };
		hot_springs.push_back(ElfSpring{ ln.substr(0, div), ElfHelper::parseDigits<int>(div + 1, ln.length(), ln, ',') });
	}

	int sum{ 0 };
	for (auto &hs : hot_springs)
	{
		sum += validateState(hs.first, hs.second, 0);
	}
	return std::to_string(sum);
}

std::string Day12::partTwo()
{
	std::vector<ElfSpring> hot_springs{};

	for (auto &ln : input)
	{
		const size_t div{ ln.find(' ') };
		std::string springs{
			ln.substr(0, div) + "?" +
			ln.substr(0, div) + "?" +
			ln.substr(0, div) + "?" +
			ln.substr(0, div) + "?" +
			ln.substr(0, div)
		};

		auto parsed_digits{ ElfHelper::parseDigits<int>(div + 1, ln.length(), ln, ',') };
		std::vector<int> numbers{};
		for (size_t i{ 0 }; i < 5; i++)
		{
			for (int n : parsed_digits)
				numbers.push_back(n);
		}
		hot_springs.push_back(ElfSpring{ springs,numbers });
	}

	long long sum{ 0 };
	for (auto &hs : hot_springs)
	{
		sum += validateState(hs.first, hs.second, 0);
	}
	return std::to_string(sum);
}
