#include <iostream>
#include <vector>
#include <utility>

int main(int argc, char* argv[]) {
	// uses initialiser list
	std::vector<int> v1{ 10 };
	std::cout << v1.at(0) << "\n";
	
	// fills array of 10 elements
	std::vector<int> v2(10);
	std::cout << v2.at(0) << "\n";

	// Class template argument deduction, CTAD, is possible ^C++17
	std::vector v_ctad{ 12 };
	std::vector v{ 12, 69 };
}