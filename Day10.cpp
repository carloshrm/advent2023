#include "Day10.h"
#include <iostream>
#include <queue>
#include <Windows.h>
#include <thread>
#include <chrono>

Day10::Day10() : Solution{ 10, false }
{
	step_counter = std::vector<std::vector<int>>(input.size(), std::vector<int>(input.front().size(), -1));
	for (int i{ 0 }; i < input.size(); i++)
	{
		for (int j{ 0 }; j < input[i].size(); j++)
		{
			if (input[i][j] == 'S')
			{
				bool n = false, s = false, e = false, w = false;

				n = (i - 1 >= 0
					&& (input[i - 1][j] == '|' || input[i - 1][j] == '7' || input[i - 1][j] == 'F'));

				s = (i + 1 < input.size()
					&& (input[i + 1][j] == '|' || input[i + 1][j] == 'L' || input[i + 1][j] == 'J'));

				w = (j - 1 >= 0
					&& (input[i][j - 1] == '-' || input[i][j - 1] == 'L' || input[i][j - 1] == 'F'));

				e = (j + 1 < input[i].size()
					&& (input[i][j + 1] == '-' || input[i][j + 1] == '7' || input[i][j + 1] == 'J'));

				if (n)
				{
					if (s)
						input[i][j] = '|';
					else if (e)
						input[i][j] = 'L';
					else
						input[i][j] = 'J';
				}
				else if (s)
				{
					if (e)
						input[i][j] = 'F';
					else
						input[i][j] = '7';
				}
				else
				{
					input[i][j] = '-';
				}
				start_pipe = ElfPipe{ i, j };
				break;
			}
		}
	}
}

constexpr std::vector<Day10::Direction> Day10::getMoveDir(const char pipe_shape)
{
	std::vector<Direction> next{};

	if (pipe_shape == '|' || pipe_shape == 'L' || pipe_shape == 'J')
		next.push_back(North);

	if (pipe_shape == '|' || pipe_shape == '7' || pipe_shape == 'F')
		next.push_back(South);

	if (pipe_shape == '-' || pipe_shape == 'L' || pipe_shape == 'F')
		next.push_back(East);

	if (pipe_shape == '-' || pipe_shape == '7' || pipe_shape == 'J')
		next.push_back(West);

	return next;
}

std::string Day10::partOne()
{
	std::queue<ElfPipe> bfs{};
	bfs.push(start_pipe);
	step_counter[start_pipe.first][start_pipe.second]++;
	int steps{ 0 };

	while (!bfs.empty())
	{
		ElfPipe current_pipe{ bfs.front() };
		bfs.pop();
		if (pipe_history.contains(current_pipe))
			continue;

		pipe_history.insert(current_pipe);
		steps = step_counter[current_pipe.first][current_pipe.second];
		for (auto &dir : getMoveDir(input[current_pipe.first][current_pipe.second]))
		{
			ElfPipe next_dir{ move_dir[dir].first + current_pipe.first, move_dir[dir].second + current_pipe.second };
			if (next_dir == start_pipe)
				continue;

			bfs.push(next_dir);
			step_counter[next_dir.first][next_dir.second] = steps + 1;
		}
	}
	return std::to_string(steps);
}

std::string Day10::partTwo()
{
	int tile_count{ 0 };
	for (size_t i{ 0 }; i < step_counter.size(); i++)
	{
		size_t left_edge{ 0 };
		size_t right_edge{ step_counter[i].size() - 1 };

		while (left_edge != right_edge && step_counter[i][left_edge] == -1) { left_edge++; }
		while (right_edge != left_edge && step_counter[i][right_edge] == -1) { right_edge--; }

		bool inside{ false };
		for (size_t j{ left_edge }; j <= right_edge; j++)
		{
			if (step_counter[i][j] != -1 && input[i][j] != '-')
			{
				if (input[i][j] == '|' || input[i][j] == 'L' || input[i][j] == 'J')
					inside = !inside;
			}

			if (inside && (input[i][j] == '.' || !pipe_history.contains(ElfPipe{ i, j })))
				tile_count++;
		}
	}
	return std::to_string(tile_count);
}
