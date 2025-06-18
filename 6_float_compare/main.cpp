#include <iostream>
#include <cmath>

// "close enough" value, elipson.
const double elipson_sm{ 1e-3 };
const double elipson_md{ 1e-6 };
const double elipson_lg{ 1e-9 };
const double elipson_xl{ 1e-12 };

bool float_comp_basic(double f1, double f2, double elipson) {
	return std::abs(f1 - f2) <= elipson;
}

bool float_comp_knuth(double f1, double f2, double elipson) {
	return (std::abs(f1 - f2) <= (std::max(std::abs(f1), std::abs(f2)) * elipson));
}

int main(int argc, char* argv[]) {
	const double f1{ 1.0001 };
	const double f2{ 1.00001 };
	const bool isSame{ float_comp_knuth(f1, f2, elipson_md) };
	std::cout << (isSame ? "They are both the same.\n" : "They are not the same.\n");
}

