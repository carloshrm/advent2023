#pragma once

struct Vector2
{
	int first{};
	int second{};

	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Left;
	static const Vector2 Right;
	
	Vector2 operator +(const Vector2 &rhs) noexcept;
	Vector2 &operator +=(const Vector2 &rhs) noexcept;
	bool operator <(const Vector2 &rhs) const noexcept;
	bool operator ==(const Vector2 &v) const noexcept;
};
