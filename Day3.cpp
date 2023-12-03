#include "Day3.h"

Day3::Day3() : Solution{ 3, false }
{
	schematic = std::vector<std::vector<PartNumber *>>(input.size());
	for (size_t i{ 0 }; i < input.size(); i++)
	{
		schematic[i] = std::vector<PartNumber *>(input[i].size(), nullptr);
		for (int j{ 0 }; j < input[i].size() - 1; j++)
		{
			if (std::isdigit(input[i][j]))
			{
				if (j - 1 >= 0 && schematic[i][j - 1] != nullptr)
					schematic[i][j] = schematic[i][j - 1];
				else
				{
					int k{ j };
					while (std::isdigit(input[i][k])) { k++; }
					schematic[i][j] = &(part_shelf.emplace_back(std::atoi(input[i].substr(j, k - j).data()), false));
				}
			}
		}
	}
}

int Day3::findSurroundingNumbers(size_t i, size_t j)
{
	int result{ 0 };
	for (int i_off{ -1 }; i_off <= 1; i_off++)
	{
		if (i + i_off < 0 || i + i_off >= input.size())
			continue;

		for (int j_off{ -1 }; j_off <= 1; j_off++)
		{
			if (j + j_off < 0 || j + j_off >= input[i + i_off].size())
				continue;

			if (std::isdigit(input[i + i_off][j + j_off]))
			{
				if (!schematic[i + i_off][j + j_off]->checked)
				{
					result += schematic[i + i_off][j + j_off]->number;
					schematic[i + i_off][j + j_off]->checked = true;
				}
			}

		}
	}
	return result;
}

int Day3::findRatio(size_t i, size_t j)
{
	std::vector<int> ratio_check{};
	for (int i_off{ -1 }; i_off <= 1; i_off++)
	{
		if (i + i_off < 0 || i + i_off >= input.size())
			continue;

		for (int j_off{ -1 }; j_off <= 1; j_off++)
		{
			if (j + j_off < 0 || j + j_off >= input[i + i_off].size())
				continue;

			if (std::isdigit(input[i + i_off][j + j_off]))
			{
				if (!schematic[i + i_off][j + j_off]->checked)
				{
					ratio_check.push_back(schematic[i + i_off][j + j_off]->number);
					schematic[i + i_off][j + j_off]->checked = true;
				}
			}

		}
	}
	if (ratio_check.size() != 2)
		return 0;
	else
		return (ratio_check[0] * ratio_check[1]);
}

std::string Day3::partOne()
{
	int sum{ 0 };
	for (size_t i{ 0 }; i < input.size(); i++)
	{
		for (size_t j{ 0 }; j < input[i].size(); j++)
		{
			if (input[i][j] != '.' && !std::isalnum(input[i][j]))
				sum += findSurroundingNumbers(i, j);
		}
	}
	return std::to_string(sum);
}

std::string Day3::partTwo()
{
	int ratio_sum{ 0 };
	for (size_t i{ 0 }; i < input.size(); i++)
	{
		for (size_t j{ 0 }; j < input[i].size(); j++)
		{
			if (input[i][j] == '*')
				ratio_sum += findRatio(i, j);
		}
	}
	return std::to_string(ratio_sum);
}
