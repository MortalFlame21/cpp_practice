#include <iostream>
#include <string>
#include <string_view>
#include <cstdarg>

void print_ints(int count, ...) {
	std::va_list list{};
	va_start(list, count);

	for (int i{}; i < count; ++i) {
		// va args must be same
		std::cout << va_arg(list, int) << " ";
	}
	std::cout << "\n";

	va_end(list);
}

int main(int argc, char* argv[]) {
	print_ints(3, 6, 7, 4);
	print_ints(2, 6, 7, 4);
}
