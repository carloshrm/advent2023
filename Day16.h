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

	static constexpr Vector2 Up{ 0, -1 };
	static constexpr Vector2 Down{ 0, 1 };
	static constexpr Vector2 Left{ -1, 0 };
	static constexpr Vector2 Right{ 1, 0 };

	static inline std::map<Vector2, Vector2> fw_mirror_logic{
		{Up, Right},
		{Left, Down},
		{Down, Left},
		{Right, Up}
	};

	static inline std::map<Vector2, Vector2> bw_mirror_logic{
		{Up, Left},
		{Left, Up},
		{Down, Right},
		{Right, Down}
	};

	long long runLight(int start_x, int start_y, const Vector2 &start_dir);

public:
	Day16();

	void setCurPos(short x, short y);

	std::string partOne() override;
	std::string partTwo() override;
};