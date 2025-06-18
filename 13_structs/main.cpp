#include <iostream>

struct Vector {
	double x{};
	double y{};
};

std::ostream& operator<<(std::ostream& o, Vector& v) {
	return o << "(" << v.x << ", " << v.y << ")";
}

int main(int argc, char* argv[]) {
	Vector v{ 3.14 };
	// std::cout << v;

	// testing
	operator<<(std::cout, v); // lol it works like this
}