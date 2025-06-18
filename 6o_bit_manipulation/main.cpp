#include <iostream>
#include <cstdint>
#include <bitset>

[[maybe_unused]] constexpr uint8_t mask0{ 0b0000'0001 };
[[maybe_unused]] constexpr uint8_t mask1{ 0b0000'0010 };
[[maybe_unused]] constexpr uint8_t mask2{ 0b0000'0100 };
[[maybe_unused]] constexpr uint8_t mask3{ 0b0000'1000 };
[[maybe_unused]] constexpr uint8_t mask4{ 0b0001'0000 };
[[maybe_unused]] constexpr uint8_t mask5{ 0b0010'0000 };
[[maybe_unused]] constexpr uint8_t mask6{ 0b0100'0000 };
[[maybe_unused]] constexpr uint8_t mask7{ 0b1000'0000 };

int main(int argc, char* argv[]) {
	uint8_t byte{ 0b0000'0000 | mask0 | mask1 | mask7 };
	std::bitset<8> byte_bits{ byte };
	byte_bits >>= 2;
	std::cout << byte_bits << "\n";
} 