#include <iostream>
#include <string>
#include <string_view>

std::string_view get_sv(std::string_view str) {
	std::string str_{ str };
	std::string_view str__{ str_ };
	return str__;
}

int main(int argc, char* argv[]) {
	std::string_view str{};
	{
		std::string s{ "nested and will clean up before std::string_view" };
		str = s;
	}
	// undefined behaviour
	std::cout << str << "\n";

	str = get_sv("undefined behaviour, std::string_view outlives:" 
				 "std::string object");
	std::cout << str << "\n";

	std::string_view c_str_kinda[3] = {"c", "style", "string"};

	for (int i{}; auto w : c_str_kinda) {
		std::cout << w << (++i < 3 ? " " : "\n");
	}

	std::string_view concat_str{
		"concat "
		"through multiple by "
		"adjacent string literals "
		"lines pretty neat"
	};
	std::cout << concat_str << "\n";
}