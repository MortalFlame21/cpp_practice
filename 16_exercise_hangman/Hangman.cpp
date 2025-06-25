#include <iostream>
#include <random>
#include <sstream>
#include <algorithm>

#include "Hangman.h"

namespace Hangman {
	void main() {
		std::cout << "Welcome to hangman in C++!\n\n";
		Game hangman{};
		hangman.run();
	}

	std::string_view pick_random_word() {
		std::random_device rd{};
		std::seed_seq sq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		std::mt19937 mt(sq); 
		std::uniform_int_distribution domain{ 0, static_cast<int>(g_word_vec.size() - 1) };
		return g_word_vec.at(domain(mt));
	}
}

void Game::run() {
	while (true) {
		display_stats();

		char g{};
		std::cout << "Enter your next guess\n> ";
		std::cin >> g;

		if (GameError::invalid_input()) {
			GameError::handle_invalid_input();
			continue;
		}

		if (GameError::has_extra_input()) {
			GameError::ignore_input();
		}
		
		handle_guess(g);

		if (has_won()) {
			std::cout << "GG. You win! Nice job find the word was \"" << m_word << "\".\n";
			return;
		}
		if (has_lost()) {
			std::cout << "GG. You lose. The word was \"" << m_word << "\".\n";
			return; 
		}

		std::cout << "\n";
	}
}

void Game::display_stats() {
	std::cout << "The word \"" << m_guess_word << "\".\n"
		<< "Previous guesses:\n" << display_prev_guesses() << "\n";
}

bool Game::valid_guess(char guess) {
	return std::isalpha(guess);
}

void Game::handle_guess(char guess) {
	if (!valid_guess(guess)) {
		std::cout << "'" << guess << "'" << " is invalid! A-z only!\n";
	}
	else if (has_been_guessed(guess)) {
		std::cout << "'" << guess << "'" << " has been guessed! Try again!\n";
	}
	else {
		check_guess_in_word(guess);
	}

}

bool Game::has_been_guessed(char guess) {
	return m_letter_guesses.find(guess) != m_letter_guesses.end();
}

void Game::check_guess_in_word(char guess) {
	if (m_word.find(guess) == std::string::npos) {
		std::cout << "L, '" << guess << "' is not in the word.\n";
		--m_heath;
	}
	else {
		std::cout << "W, '" << guess << "' is in the word.\n";
	}

	add_guess(guess);
	reveal_guess(guess);
}

void Game::add_guess(char guess) {
	m_letter_guesses[guess] = true;
}

void Game::reveal_guess(char guess) {
	for (int i{};; i != std::string::npos) {
		i = m_word.find(guess, i);
		if (i == std::string::npos) return;
		m_guess_word.at(i++) = guess;
	}
}

int Game::get_letter_index(char letter) {
	return (std::tolower(letter) - 'a') % 26;
}

std::string Game::display_prev_guesses() {
	if (m_letter_guesses.size() == 0) return "- none\n";

	std::stringstream ss{};
	for (auto [g, b] : m_letter_guesses) ss << "- '" << g << "'\n";
	return ss.str();
}

int Game::get_health() {
	return m_heath;
}

bool Game::has_won() {
	return m_guess_word == m_word;
}

bool Game::has_lost() {
	return get_health() == 0;
}

bool GameError::invalid_input() {
	return !std::cin;
}

void GameError::reset_input() {
	clear_input();
	ignore_input();
}

void GameError::clear_input() {
	std::cin.clear();
}

void GameError::ignore_input() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool GameError::has_extra_input() {
	return (!std::cin.eof() || std::cin.peek() != '\n');
}

void GameError::handle_invalid_input() {
	reset_input();
	std::cout << "Invalid guess! Input must be A-z.\n";
}
