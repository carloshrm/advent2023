#include "Day5.h"
#include <sstream>
#include <future>

Day5::AlmanacRange Day5::extractRange(const std::string &input)
{
	std::stringstream ss(input);
	long long source, dest, range;
	ss >> dest >> source >> range;
	return AlmanacRange{ source, source + (range - 1), dest, dest + (range - 1) };
}

Day5::Day5() : Solution{ 5, false }
{
	std::stringstream seed_stream(input[0].substr(6, input[0].size()));
	long long val{ 0 };
	while (seed_stream >> val)
		seeds.push_back(val);

	for (size_t i{ 2 }; i < input.size(); i++)
	{
		if (input[i].find("map") != std::string::npos)
		{
			std::vector<AlmanacRange> new_map{};
			while (++i < input.size() && !input[i].empty())
			{
				new_map.push_back(extractRange(input[i]));
			}
			maps.push_back(new_map);
		}
	}
}

long long Day5::mapSeed(long long &seed_val)
{
	long long map_value{ seed_val };
	for (auto &list : maps)
	{
		for (auto &range : list)
		{
			if (range.src_start <= map_value && range.src_end >= map_value)
			{
				map_value = range.dst_start + (map_value - range.src_start);
				break;
			}
		}
	}
	return map_value;
}

int Day5::mapSeedRange(long long start, long long end)
{
	int lowest{ INT_MAX };
	while (start++ <= end)
	{
		auto mapped_location{ mapSeed(start) };
		if (mapped_location < lowest)
			lowest = mapped_location;
	}
	return lowest;
}

std::string Day5::partOne()
{
	int lowest_location{ INT_MAX };
	for (auto &seed : seeds)
	{
		auto mapped_location{ mapSeed(seed) };
		if (mapped_location < lowest_location)
			lowest_location = mapped_location;
	}
	return std::to_string(lowest_location);
}

std::string Day5::partTwo()
{
	std::vector<std::future<int>> threads{};
	for (size_t i{ 0 }; i < seeds.size(); i += 2)
	{
		long long first_seed{ seeds[i] };
		long long last_seed{ (seeds[i + 1] - 1) + first_seed };
		threads.push_back(std::async(&Day5::mapSeedRange, *this, first_seed, last_seed));
	}
	int lowest{ INT_MAX };
	for (auto &t : threads) lowest = std::min(lowest, t.get());
	return std::to_string(lowest);
}
