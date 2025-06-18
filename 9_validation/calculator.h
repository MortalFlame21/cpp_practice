#pragma once 
#include <iostream>

void ignoreLine() {
	// ignore everything till \n
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasExtraCharacters() {
	return !std::cin.eof() && std::cin.peek() != '\n';
}

int askInteger() {
	int integer{};
	while(true) {
		std::cout << "Enter a integer: ";
		std::cin >> integer;

		// fail state
		// std::cin has bool conversion
		if (!std::cin && std::cin.eof()) {
			std::exit(0);
		}
		// ^v3 if in fail state and ran into EOF
		// shut that shi down

		if (!std::cin) {
			// add custom error msg here
			std::cin.clear();
			ignoreLine();
			continue;
		}
		// ^ v2. if in fail state clear it up
		// and enter normal state.

		if (hasExtraCharacters()) {
			ignoreLine();
		}
		// ^ simple v1, ignore extra characters
		// which could f up the program

		if (std::cin) {
			return integer;
		}
	};
}


// generic input things
template <typename T>
T askInput() {
	T value{};
	while(true) {
		std::cout << "Enter a value: ";
		std::cin >> value;

		// fail state
		// std::cin has bool conversion
		if (!std::cin && std::cin.eof()) {
			std::exit(0);
		}
		// ^v3 if in fail state and ran into EOF
		// shut that shi down

		if (!std::cin) {
			// add custom error msg here
			std::cin.clear();
			ignoreLine();
			continue;
		}
		// ^ v2. if in fail state clear it up
		// and enter normal state.

		if (hasExtraCharacters()) {
			ignoreLine();
		}
		// ^ simple v1, ignore extra characters
		// which could f up the program

		if (std::cin) {
			return value;
		}
	};
}

int calculate(int a, char b, int c) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return a;
	}

}

// simple program that asks user for int, char, int.
void calculator() {
	auto a{ askInteger() };
	auto b{ askInput<char>() };
	auto c{ askInteger() };
	auto d{ calculate(a, b, c)};
	std::cout << a << " " << b << " " << c << " = " << d << "\n";
}
