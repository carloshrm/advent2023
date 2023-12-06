#pragma once

#include "Solution.h"

class Day5 : public Solution
{
private:
	struct AlmanacRange
	{
		long long src_start;
		long long src_end;
		long long dst_start;
		long long dst_end;
	};

	std::vector<long long> seeds{};
	std::vector<std::vector<AlmanacRange>> maps{};

	AlmanacRange extractRange(const std::string &input);
	long long mapSeed(long long &seed_val);
	int mapSeedRange(long long start, long long end);

public:
	Day5();

	std::string partOne() override;
	std::string partTwo() override;
};

