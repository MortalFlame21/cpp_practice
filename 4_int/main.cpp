#include <iostream>
#include <cstdint>

int main(int argc, char* argv[]) {
	// Either use std:: namespace or not. I will not.

	uint8_t likeChar{};
	uint16_t likeInt{};

	std::cout << "Enter a character: ";
	std::cin >> likeChar;

	// Would output likeChar to be a char
	std::cout << "likeChar == " << likeChar << "\n";
	std::cout << "likeChar (uint16) == " << static_cast<uint16_t>(likeChar) << "\n";

	std::cout << "Enter a negative number: ";
	std::cin >> likeInt;

	std::cout << "likeInt == " << likeInt;
	std::cout << ". 0 <= likeInt <= " << UINT16_MAX << " (UINT16_MAX)\n";
}