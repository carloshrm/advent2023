#include "Day8.h"
#include <numeric>

Day8::Day8() : Solution{ 8, false }
{
	instructions = input[0];
	for (size_t i{ 2 }; i < input.size(); i++)
	{
		desert_map.emplace(input[i].substr(0, 3), DesertNode{ input[i].substr(7, 3), input[i].substr(12, 3) });
	}
}

std::string Day8::partOne()
{
	std::string starting_point{ "AAA" };
	std::string *current_node = &starting_point;
	int steps{ 1 };
	auto i = instructions.begin();
	while (*current_node != "ZZZ")
	{
		if (i == instructions.end())
			i = instructions.begin();

		current_node = (*i) == 'L' ?
			&(desert_map.at(*current_node).left) :
			&(desert_map.at(*current_node).right);

		steps++;
		i++;
	}
	return std::to_string(steps);
}

std::string Day8::partTwo()
{
	std::vector<const std::string *> current_nodes{};
	for (auto &[k, v] : desert_map)
	{
		if (k[2] == 'A')
			current_nodes.push_back(&k);
	}

	long long steps{ 0 };
	for (auto &n : current_nodes)
	{
		auto i = instructions.begin();
		int current_steps{ 0 };
		while ((*n)[2] != 'Z')
		{
			if (i == instructions.end())
				i = instructions.begin();

			n = (*i) == 'L' ?
				&desert_map.at(*n).left :
				&desert_map.at(*n).right;

			current_steps++;
			i++;
		}
		steps = steps == 0 ? current_steps : std::lcm(steps, current_steps);
	}
	return std::to_string(steps);
}
