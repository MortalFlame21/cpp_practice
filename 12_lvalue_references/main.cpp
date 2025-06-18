#include <iostream>
#include <string>

void printAddr(std::string val, std::string& ref) {
	std::cout << "val: " << &val << "\n";
	std::cout << "ref: " << &ref << "\n";
	std::cout << "val == ref: " << (&val == &ref) << "\n";
}

int main(int argc, char* argv[]) {
	int a{ 100 };
	// int& is a lvalue reference type.
	int& ref_a{ a };

	ref_a = 999;

	std::cout << "a: " << a << "\n";
	std::cout << "ref_a: " << ref_a << "\n";

	// experiment, this is a rvalue reference type.
	// NOT a reference to a reference.
	int&& b{ 100 };
	std::cout << "b: " << b << "\n";

	// lvalue reference to const can refer to rvalues
	// a temp object is created and initialised with the rvalue
	// ^ this above can be tricky to identify when referring
	// const through different type.
	const int& c{ 1000 };
	const int& d = 1000;

	std::cout << "c: " << c << "\n";
	std::cout << "d: " << d << "\n";

	std::string s{ "hello" };
	std::cout << "s:   " << &s << "\n";
	printAddr(s, s);
}