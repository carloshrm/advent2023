#include "Day16.h"
#include <chrono>
#include <thread>

Day16::Day16() : Solution{ 16, false }
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	for (auto &l : input)
		std::cout << l << '\n';

	tracker =
		std::vector<std::vector<Vector2>>(
			input.size(), std::vector<Vector2>(
				input.front().size(),
				{ -2, -2 }
			)
		);
}

void Day16::setCurPos(short x, short y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

std::string Day16::partOne()
{
	int a = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::queue<LightBeam> active_lights{};
	active_lights.push(LightBeam{ { 0, 0 }, Right });
	while (!active_lights.empty())
	{
		LightBeam current_beam{ active_lights.front() };
		active_lights.pop();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		setCurPos(current_beam.pos.first, current_beam.pos.second);
		std::cout << "\033[104m.\033[m";

		if (tracker[current_beam.pos.second][current_beam.pos.first] == current_beam.dir)
			continue;
		tracker[current_beam.pos.second][current_beam.pos.first] = current_beam.dir;

		auto pos_tile{ input[current_beam.pos.second][current_beam.pos.first] };
		switch (pos_tile)
		{
		case Vert_Splitter:
			if (current_beam.dir == Left || current_beam.dir == Right)
			{
				current_beam.dir = Up;
				active_lights.push(LightBeam{ current_beam.pos, Down });
			}
			break;
		case Horiz_Splitter:
			if (current_beam.dir == Up || current_beam.dir == Down)
			{
				current_beam.dir = Left;
				active_lights.push(LightBeam{ current_beam.pos, Right });
			}
			break;
		case Forwards_Mirror:
			current_beam.dir = fw_mirror_logic[current_beam.dir];
			break;
		case Backwards_Mirror:
			current_beam.dir = bw_mirror_logic[current_beam.dir];
			break;
		default:
			break;
		}

		current_beam.pos += current_beam.dir;
		if (current_beam.pos.first < 0 ||
			current_beam.pos.first >= input.front().size() ||
			current_beam.pos.second < 0 ||
			current_beam.pos.second >= input.size())
			continue;
		else
			active_lights.push(current_beam);
	}

	long long charged{};
	for (auto &l : tracker)
	{
		for (auto &tile : l)
		{
			if (tile.first != -2 && tile.second != -2)
				charged++;
		}
	}
	std::cin >> a;
	setCurPos(0, input.size() + 1);
	return std::to_string(charged);
}

std::string Day16::partTwo()
{
	return std::string();
}
