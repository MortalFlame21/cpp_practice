#include <iostream>
#include <array>
#include <string_view>

struct Item {
	std::string_view name;
	int gold;
};

template<typename T, std::size_t N>
void printArray(const std::array<T, N>& a) {
	std::cout << "The array (";
	for (const auto& e : a) {
		std::cout << e;
		if (e != a.back()) std::cout << ", ";
	}
	std::cout << ") has length " << N << "\n";
}

template<typename T, std::size_t N>
void printItemsArray(const std::array<T, N>& a) {
	for (const auto& e : a) {
		std::cout << e.name << " costs " << e.gold << " gold\n";
	}
}

int main(int argc, char* argv[]) {
	constexpr std::array arr1{ 1, 4, 9, 16 };
	printArray(arr1);

	constexpr std::array arr2{ 'h', 'e', 'l', 'l', 'o' };
	printArray(arr2);

	// brace elision allows for CTAD
	constexpr std::array<Item, 4>  arr3{{
		{"sword", 5}, {"dagger", 3},
		{"club", 2}, {"spear", 7}
	}};
	printItemsArray(arr3);
}