#pragma once

#include "Solution.h"

using ElfValley = std::vector<std::string>;

class Day13 : public Solution
{
private:
	std::vector<ElfValley> valleys{};

	void findReflectionPoints(const std::string_view line, std::map<size_t, int> &points);
	size_t findMirrorPos(const ElfValley &valley);
	size_t findMirrorWithSmudge(const ElfValley &valley);
	ElfValley rotateValley(const ElfValley &v);

public:
	Day13();

	std::string partOne() override;
	std::string partTwo() override;
};

