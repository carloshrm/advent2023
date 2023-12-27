#include "Vector2.h"

Vector2 Vector2::operator +(const Vector2 &rhs) noexcept
{
	return Vector2{ first + rhs.first, second + rhs.second };
}

Vector2 &Vector2::operator+=(const Vector2 &rhs) noexcept
{
	first += rhs.first;
	second += rhs.second;
	return *this;
}

bool Vector2::operator<(const Vector2 &rhs) const noexcept
{
	if (this->first == rhs.first)
		return this->second < rhs.second;
	else
		return this->first < rhs.first;
}

bool Vector2::operator==(const Vector2 &v) const noexcept
{
	return v.first == first && v.second == second;
}

constexpr const Vector2 Vector2::Up{ 0, -1 };
constexpr const Vector2 Vector2::Down{ 0, 1 };
constexpr const Vector2 Vector2::Left{ -1, 0 };
constexpr const Vector2 Vector2::Right{ 1, 0 };