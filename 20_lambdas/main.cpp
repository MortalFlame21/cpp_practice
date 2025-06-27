#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <functional>

void print(std::vector<int> v) {
	for (auto e : v) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}

int main(int argc, char* argv[]) {
	{
		std::vector v1{ 1, 2, 3, 4, 5, 6 };
		print(v1);
		auto gt{
			[](const auto& f, const auto& s) {
				return f > s;
			}
		};
		std::sort(v1.begin(), v1.end(), gt);
		print(v1);
	
		std::sort(v1.begin(), v1.end(), std::greater{});
		print(v1);
	
		std::random_device rd{};
		std::mt19937 mt{ rd() };
	
		std::shuffle(v1.begin(), v1.end(), mt);
		print(v1);
	
		std::sort(v1.begin(), v1.end(), [](const auto& f, const auto& s) { return f < s; });
		print(v1);
	}

	{
		std::string thing{ "grapes" };

		// test with = and &. big difference.
		auto print_fav_thing{
		  [=]() {
		    std::cout << "I like " << thing << '\n';
		  }
		};

		thing = "bananas with chocolate";

		print_fav_thing();
	}
}