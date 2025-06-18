#include <iostream>

namespace bb {
	int subtract(int x, int y) {
		return x - y;
	}
	void print_difference(int x, int y) {
		std::cout << x << " - " << y << " = " << subtract(x, y) << ".\n";
	}
}

int main(int argc, char* argv[]) {
	{
		namespace Swag = bb;
		Swag::print_difference(1, 2);
	}
	bb::print_difference(1, 2);
}