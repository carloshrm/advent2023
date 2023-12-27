#pragma once

#include "Vector2.h"
#include "Solution.h"
#include <queue>
#include <map>

class Day16 : public Solution
{
private:
	enum GridTile
	{
		Horiz_Splitter = '-',
		Vert_Splitter = '|',
		Forwards_Mirror = '/',
		Backwards_Mirror = '\\',
		Space = '.'
	};

	struct LightBeam
	{
		Vector2 pos{};
		Vector2 dir{};

		bool step(int x_edge, int y_edge)
		{
			pos.first += dir.first;
			pos.second += dir.second;
			return !(pos.first < 0 || pos.first >= x_edge ||
				pos.second < 0 || pos.second >= y_edge);
		}
	};

	static inline std::map<Vector2, Vector2> fw_mirror_logic{
		{Vector2::Up, Vector2::Right},
		{Vector2::Left, Vector2::Down},
		{Vector2::Down, Vector2::Left},
		{Vector2::Right, Vector2::Up}
	};

	static inline std::map<Vector2, Vector2> bw_mirror_logic{
		{Vector2::Up, Vector2::Left},
		{Vector2::Left, Vector2::Up},
		{Vector2::Down, Vector2::Right},
		{Vector2::Right, Vector2::Down}
	};

	long long runLight(int start_x, int start_y, const Vector2 &start_dir);

public:
	Day16();

	std::string partOne() override;
	std::string partTwo() override;
};