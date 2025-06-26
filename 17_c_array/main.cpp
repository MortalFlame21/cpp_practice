#include <iostream>
#include <iterator>

int main(int argc, char* argv[]) {
	// can't be 0 length
	// char arr[]{};
	
	int arr1[5]{};
	int arr2[]{ 2, 3, 5, 7, 11 };

	std::cout << std::size(arr1) << "\n";
	std::cout << std::size(arr2) << "\n";

	auto decay_arr2{ arr2 };

	std::cout << arr1 << "\n";
	std::cout << arr2 << "\n";
	std::cout << decay_arr2 << "\n";

	std::cout << "arr2 == &arr2[0] =" << std::boolalpha << (arr2 == &arr2[0]) << "\n";

	char c_str1[3]{ "ab" };
	// purposely omit the '\0'
	c_str1[2] = 'c';
	const char* c_str2{ "bro" };

	std::cout << c_str1 << "\n";
	std::cout << c_str2 << "\n";

	// interprets as char*, thus it prints until '\0'!
	char char_val{ 'Q' };
    std::cout << &char_val << "\n";

	int int_val{ 21 };
    std::cout << &int_val << "\n";
}