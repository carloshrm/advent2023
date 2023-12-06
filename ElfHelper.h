#pragma once

#include <vector>
#include <string>
#include <sstream>

class ElfHelper
{
public:
	template <typename T>
		requires std::is_arithmetic<T>::value
	static inline std::vector<T> parseDigits(const size_t start, const size_t len, const std::string &input)
	{
		std::stringstream ss(input.substr(start, len));
		std::vector<T> numbers{};
		T n{};
		while (ss >> n)
			numbers.push_back(n);

		return numbers;
	}
};