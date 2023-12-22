#include "Day16.h"
#include <algorithm>

Day16::Day16() : Solution{ 16, false }
{
}


long long Day16::runLight(int start_x, int start_y, const Vector2 &start_dir)
{
	std::vector<std::vector<Vector2>> tracker(input.size(), std::vector<Vector2>(input.front().size(), { -2, -2 }));

	std::queue<LightBeam> active_lights{};
	active_lights.push(LightBeam{ { start_x, start_y }, start_dir });
	while (!active_lights.empty())
	{
		LightBeam current_beam{ active_lights.front() };
		active_lights.pop();

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
	return charged;
}

std::string Day16::partOne()
{
	return std::to_string(runLight(0, 0, Right));
}

std::string Day16::partTwo()
{
	long long max{ 0 };
	for (int i{ 0 }; i < input.size(); i++)
	{
		auto top{ runLight(i, 0, Down) };
		auto bot{ runLight(i, input.size() - 1, Up)};

		auto left{ runLight(0, i, Right) };
		auto right{ runLight(input.size() - 1, i, Left) };
		max = std::max<long long>({ top, bot, left, right, max });
	}
	return std::to_string(max);
}
