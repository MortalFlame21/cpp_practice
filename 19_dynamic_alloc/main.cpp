#include <iostream>

int main(int argc, char* argv[]) {
	{
		int* ptr_heap_1{ new int };
		// can also use (5). direct initialisation. 
		// this is uniform initialisation.
		int* ptr_heap_2{ new int {5} };

		std::cout << ptr_heap_1 << "\n";
		std::cout << ptr_heap_2 << "\n";

		std::cout << *ptr_heap_1 << "\n";
		std::cout << *ptr_heap_2 << "\n\n";

		delete ptr_heap_1;
		ptr_heap_1 = nullptr;
		delete ptr_heap_2;
		ptr_heap_2 = nullptr;
	}

	{
		int* ptr_heap_arr_1{ new int[0] { } };
		int* ptr_heap_arr_2{ new int[2] {1, 2}  };
		
		std::cout << *ptr_heap_arr_1 << "\n";
		std::cout << *ptr_heap_arr_2 << "\n\n";

		delete[] ptr_heap_arr_1;
		ptr_heap_arr_1 = nullptr;
		delete[] ptr_heap_arr_2;
		ptr_heap_arr_2 = nullptr;
	} 
	
	{
		constexpr int row_size{ 3 };
		constexpr int col_size{ 3 };
		int** ptr_heap_2d{ new int*[row_size] };
		for (int i{}; i < row_size; ++i)
			ptr_heap_2d[i] = new int[col_size] { i + 1, i + 2, i + 3 };

		for (int i{}; i < row_size; ++i) {
			for (int j{}; j < col_size; ++j) {
				std::cout << ptr_heap_2d[i][j] << ", ";
			}
			std::cout << "\n";
		}

		for (int i{}; i < row_size; ++i)
			delete[] ptr_heap_2d[i];
		delete[] ptr_heap_2d;
	} 
}