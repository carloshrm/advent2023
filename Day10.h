#pragma once

#include "Solution.h"
#include <set>

using ElfPipe = std::pair<size_t, size_t>;

class Day10 : public Solution
{
private:
	enum Direction { North, South, East, West };

	std::map< Direction, std::pair<size_t, size_t>> move_dir{
		{North, {-1, 0}},
		{South, {1, 0}},
		{East, {0, 1}},
		{West, {0, -1}}
	};

	ElfPipe start_pipe;
	std::set<ElfPipe> pipe_history{};
	std::vector<std::vector<int>> step_counter;

	constexpr std::vector<Direction> getMoveDir(const char pipe_shape);

public:
	Day10();


	std::string partOne() override;
	std::string partTwo() override;
};

