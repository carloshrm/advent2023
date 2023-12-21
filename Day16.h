#pragma once

#include "Solution.h"
#include <queue>
#include <map>
#include <iostream>
#include <Windows.h>

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

	struct Vector2
	{
		int first{};
		int second{};

		Vector2 &operator +=(const Vector2 &rhs) noexcept
		{
			first += rhs.first;
			second += rhs.second;
			return *this;
		}

		bool operator <(const Vector2 &rhs) const noexcept
		{
			if (this->first == rhs.first)
				return this->second < rhs.second;
			else
				return this->first < rhs.first;
		}

		bool operator ==(const Vector2 &v) const noexcept
		{
			return v.first == first && v.second == second;
		}
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
	HANDLE handle;

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

	std::vector<std::vector<Vector2>> tracker{};

public:
	Day16();

	void setCurPos(short x, short y);

	std::string partOne() override;
	std::string partTwo() override;
};