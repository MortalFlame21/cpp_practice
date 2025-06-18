#include <iostream>

int main(int argc, char* argv[]) {
	int x{ 9999 };
	int y{ 9999 };
	int z{ 9999 };

	int* x_ptr{ &x };
	// unitialised a wild pointer
	int* wild_ptr;
	// null pointer
	int* null_ptr{};

	// reference to a pointer
	// int*& ref_ptr{ x_ptr };

	std::cout << "1 - x_ptr: " << x_ptr << "\n";
	// will not work
	// std::cout << "1 - wild_ptr" << wild_ptr << "\n";
	// cannot dereference this too
	std::cout << "1 - null_ptr: " << null_ptr << "\n\n";

	(*x_ptr)++;
	wild_ptr = &y;
	null_ptr = &z;

	std::cout << "2 - x_ptr (addr, val): " << x_ptr << " " << *x_ptr << "\n";
	std::cout << "2 - wild_ptr (addr, val): " << wild_ptr << " " << *wild_ptr << "\n";
	std::cout << "2 - null_ptr (addr, val): " << null_ptr << " " << *null_ptr << "\n\n";

	*wild_ptr = (*x_ptr)++;
	*null_ptr = 9998;

	std::cout << "3 - x_ptr (addr, val): " << x_ptr << " " << *x_ptr << "\n";
	std::cout << "3 - wild_ptr (addr, val): " << wild_ptr << " " << *wild_ptr <<"\n";
	std::cout << "3 - null_ptr (addr, val): " << null_ptr << " " << *null_ptr <<"\n\n";

	constexpr int a{ 10 };
	const int b{ 10 };
	
	// similar behaviour to lvalue reference to const
	const int* const_ptr{ &a };
	// this means we cannot change the address of
	// the const int pointer
	const int* const const_addr_ptr{ &b };
	// const_addr_ptr = a; // <- not possible
	
	std::cout << "const_ptr (addr, val): " << const_ptr << " " << *const_ptr << "\n";
	std::cout << "const_addr_ptr (addr, val): " << const_addr_ptr << " " << *const_addr_ptr << "\n";

	const_ptr = &b;

	std::cout << "const_ptr (addr, val): " << const_ptr << " " << *const_ptr << "\n";
}