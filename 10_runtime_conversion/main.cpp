#include <iostream>
#include <cstdint>

void narrow_conversion(uint32_t n) {
	std::cout << n << "\n";
}

int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;

	// explicit conversion
	std::cout << static_cast<uint32_t>(n) << "\n";

	narrow_conversion(n);
}
