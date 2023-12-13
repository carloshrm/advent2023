#pragma once

#include <vector>
#include <string>
#include <sstream>

class ElfHelper
{
public:
	template <typename T>
		requires std::is_arithmetic<T>::value
	static inline std::vector<T> parseDigits(const size_t start, const size_t len, const std::string &input, const char token = ' ')
	{
		std::string parsed_input{ input.substr(start, len) };
		if (token != ' ')
		{
			for (size_t i{ 0 }; i < parsed_input.size(); i++)
				if (parsed_input[i] == token)
					parsed_input[i] = ' ';
		}

		std::stringstream ss(parsed_input);
		std::vector<T> numbers{};
		T n{};
		while (ss >> n)
			numbers.push_back(n);

		return numbers;
	}
};