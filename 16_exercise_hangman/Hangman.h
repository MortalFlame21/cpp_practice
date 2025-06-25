#pragma once

#include <vector>
#include <array>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace std::string_view_literals;

namespace Hangman {
	inline constexpr std::array g_word_vec { 
		"mystery"sv, "broccoli"sv, "account"sv, 
		"almost"sv, "spaghetti"sv, "opinion"sv, 
		"beautiful"sv, "distance"sv, "luggage"sv,
		"fortnite"sv, "banana"sv, "unemployment"sv,
		"aaaaa"sv, "zzaaaattt"sv, "pqpqpq"sv
	};
	void main();
	std::string_view pick_random_word();
}

class Game {
public:
	void run();

private:
	const std::string_view m_word{ Hangman::pick_random_word() };
    std::string m_guess_word{ std::string(m_word.size(), '_') };  
	int m_heath{ 3 };
	std::unordered_map<char, char> m_letter_guesses{};

	void display_stats();
	bool valid_guess(char guess);
	void handle_guess(char guess);
	bool has_been_guessed(char guess);
	void check_guess_in_word(char guess);
	void add_guess(char guess);
	void reveal_guess(char guess);
	int get_letter_index(char letter);
	std::string display_prev_guesses();
	int get_health();
	bool has_won();
	bool has_lost();
};

class GameError {
public:
	static bool invalid_input();
	static void clear_input();
	static void reset_input();
	static void ignore_input();
	static void handle_invalid_input();
	static bool has_extra_input();
};
