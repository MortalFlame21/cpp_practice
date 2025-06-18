#include <iostream>

void print_2() {
	std::cout << "from dependent.cpp print_2()\n";
}

int add(int x, int y) {
	return x + y + 100;
}