#include "Vector2.h"

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
