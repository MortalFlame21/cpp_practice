#include <iostream>

// global variables are static
// this however has internal linkage.
int n{};

int staticIncrement() {
	// variable n now has static duration.
	// variable n is also a static local variable.
	static int n{};
	return n++;
}

int main(int argc, char* argv[]) {
	std::cout << staticIncrement() << "\n";
	std::cout << staticIncrement() << "\n";
	std::cout << staticIncrement() << "\n";
	std::cout << staticIncrement() << "\n";
	std::cout << n++ << "\n";
}