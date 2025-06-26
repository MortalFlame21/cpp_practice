#include <iostream>
#include <array>

template<typename T, std::size_t N>
using square_2d = std::array<std::array<T, N>, N>;

template<typename T, std::size_t N>
using cube_3d = square_2d<std::array<T, N>, N>;

int main(int argv, char* argc[]) {
	square_2d<int, 3> table{{ 
		{1, 2, 3}, 
		{4, 5, 6}, 
		{7, 8, 9},
	}};
	square_2d<int, 10> mult_table{};

	for (auto& r : table) {
		for (auto& e : r) {
			std::cout << e << " ";
		}
		std::cout << "\n";
	}

	std::cout << table.at(2).size() << "\n";
}