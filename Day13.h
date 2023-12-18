#pragma once

#include "Solution.h"

class Day13 : public Solution
{
private:
	struct ElfValley
	{
		std::vector<std::string> layout{};
		size_t first_mirror{ std::string::npos };
		bool rotated_mirror{ false };
	};

	std::vector<ElfValley> valleys{};

	std::vector<size_t> findReflectionPoints(const std::string_view line);
	size_t findMirrorPos(const ElfValley &valley, const bool with_smudge);
	size_t searchSmudge(const ElfValley &valley);
	ElfValley rotateValley(const ElfValley &v);

public:
	Day13();

	std::string partOne() override;
	std::string partTwo() override;
};

