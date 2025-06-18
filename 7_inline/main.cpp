#include <iostream>
#include "math.h"

// with one of the pi() functions having
// inline, it would not violate ODR.
inline auto pi() {
	return 3.14;
}

int main(int argc, char* argv[]) {
	std::cout << pi() << "\n";
	std::cout << Math::Constants::pi << "\n";
	std::cout << Math::Constants::euler << "\n";
}