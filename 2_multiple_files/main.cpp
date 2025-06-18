#include <iostream>

int add(int x, int y);

void print_1() {
	std::cout << "from main.cpp print_1()\n";
}

int main(int argc, char* argv[]) {
	print_1();
	std::cout << add(1, 2) << "\n";
}