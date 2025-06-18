#include <iostream>
//#include "external.cpp"
//#include "internal.cpp"
// ^- violates ODR 

// now has internal linkage, only in this file.
// will not violate the linked things
static auto g_c{ "main.cpp" };

// to use extern variable you must place a forward
// declaration
extern int g_x;
extern const int g_y;
extern const int g_z;
// ^ in this case extern means that a definition is
// somewhere else

int main(int argc, char* argv[]) {
	std::cout << g_c << "\n";
	std::cout << g_x << "\n";
	std::cout << g_y << "\n";
	std::cout << g_z << "\n";
}