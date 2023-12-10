#include "Day6.h"
#include "ElfHelper.h"
#include <cmath>

Day6::Day6() : Solution{ 6, false }
{
	auto time_info{ ElfHelper::parseDigits<int>(5, input[0].length(), input[0]) };
	auto dist_info{ ElfHelper::parseDigits<int>(9, input[1].length(), input[1]) };
	for (size_t i = 0; i < time_info.size(); i++)
		races.push_back(RaceInfo{ .time = time_info[i], .distance = dist_info[i] });
}

double Day6::calcNumWinnerValues(const RaceInfo &race)
{
	double disc{ (std::pow(race.time, 2) - (4 * (race.distance + 1))) };
	double fst_root{ std::ceil((-race.time + std::sqrt(disc)) / -2) };
	double sec_root{ std::floor((-race.time - std::sqrt(disc)) / -2) };
	return std::abs(fst_root - sec_root) + 1;
}

std::string Day6::partOne()
{
	int result{ 1 };
	for (auto &race : races)
		result *= calcNumWinnerValues(race);

	return std::to_string(result);
}

std::string Day6::partTwo()
{
	std::string big_time{ input[0] }, big_dist{ input[1] };
	std::erase(big_time, ' ');
	std::erase(big_dist, ' ');
	auto time{ std::atoll(big_time.substr(5, big_time.length()).data()) };
	auto dist{ std::atoll(big_dist.substr(9, big_dist.length()).data()) };
	return std::to_string(calcNumWinnerValues(RaceInfo{ time, dist }));
}
