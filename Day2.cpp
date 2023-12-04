#include "Day2.h"
#include <string>
#include <array>
#include <charconv>

Day2::Day2() : Solution{ 2, false }
{
	records.reserve(input.size() + 1);
	setupRecords();
}

void Day2::setupRecords()
{
	for (std::string_view ln : input)
	{
		std::vector<Game> parsed_games{ };
		size_t prev_split_idx{ ln.find(':') + 2 };
		size_t game_split_idx;
		do
		{
			game_split_idx = ln.find(';', prev_split_idx);
			if (game_split_idx == std::string::npos)
				game_split_idx = ln.length();

			parsed_games.push_back(parseGame(prev_split_idx, game_split_idx, ln));
			prev_split_idx = game_split_idx + 2;
		} while (game_split_idx != ln.length());
		records.push_back(parsed_games);
	}
}

Day2::Game Day2::parseGame(const size_t &prev_split_idx, const size_t &game_split_idx, std::string_view &ln)
{
	Game new_game{};

	size_t prev_part{ prev_split_idx };
	size_t data_part{ 0 };
	for (size_t i = prev_split_idx; i <= game_split_idx; i++)
	{
		if (i == game_split_idx || ln[i] == ',')
		{
			int num{ 0 };

			std::from_chars(ln.data() + prev_part, ln.data() + prev_part + 3, num);
			switch (ln[i - 1])
			{
			case 'd':
				new_game.red = num;
				break;
			case 'n':
				new_game.green = num;
				break;
			case 'e':
				new_game.blue = num;
				break;
			default:
				break;
			}
			prev_part = (i + 2);
		}
	}
	return new_game;
}

bool Day2::auditGame(const std::vector<Day2::Game> &pulls)
{
	constexpr Day2::Game totals{ .red = 12, .green = 13, .blue = 14 };
	for (auto &pull : pulls)
	{
		if (pull.red > totals.red || pull.green > totals.green || pull.blue > totals.blue)
			return false;
	}
	return true;
}

int Day2::calcGamePower(const std::vector<Day2::Game> &pulls)
{
	Day2::Game max{};
	for (auto &pull : pulls)
	{
		max.red = std::max(pull.red, max.red);
		max.green = std::max(pull.green, max.green);
		max.blue = std::max(pull.blue, max.blue);
	}
	return (max.red * max.green * max.blue);
}

std::string Day2::partOne()
{
	int possible_games{ 0 };
	for (int i{ 0 }; i < records.size(); i++)
	{
		if (auditGame(records.at(i)))
			possible_games += (i + 1);
	}
	return std::to_string(possible_games);
}

std::string Day2::partTwo()
{
	int total_power{ 0 };
	for (int i{ 0 }; i < records.size(); i++)
	{
		total_power += calcGamePower(records.at(i));
	}
	return std::to_string(total_power);
}