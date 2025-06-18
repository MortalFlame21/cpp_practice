// 7.4

#include <iostream>

// non const global variables have external linkage
const int g_a{ 69420 };
constexpr auto g_b{ "we global baby !" };
int g_x;

void increase_gblx() {
	g_x++;
}

void print_gbla() {
	std::cout << "g_a " << g_a << "\n";
}

void print_gblb() {
	std::cout << "g_b " << g_b << "\n";
}

void print_gblx() {
	std::cout << "g_x " << g_x << "\n";
}

int main(int argc, char* argv[]) {
	print_gblx();
	print_gbla();
	increase_gblx();
	g_x++;
	print_gblx();
	print_gblb();
	g_x += 4;
	print_gblx();
	print_gblb();
}