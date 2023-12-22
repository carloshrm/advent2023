#pragma once

struct Vector2
{
	int first{};
	int second{};

	Vector2 &operator +=(const Vector2 &rhs) noexcept;
	bool operator <(const Vector2 &rhs) const noexcept;
	bool operator ==(const Vector2 &v) const noexcept;
};