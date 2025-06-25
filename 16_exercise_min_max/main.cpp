#include <iostream>
#include <vector>
#include <utility>

template<typename T>
std::pair<T, T> get_min_max_index_pairs(std::vector<T> v);

std::vector<int> get_user_vec();

int main(int argc, char* argv[]) {
	std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
	std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };	

	auto p1 = get_min_max_index_pairs(v1);
	auto p2 = get_min_max_index_pairs(v2);
	auto p3 = get_min_max_index_pairs(get_user_vec());

	std::cout << "(" << p1.first << ", " << p1.second << ")\n";
	std::cout << "(" << p2.first << ", " << p2.second << ")\n";
	std::cout << "(" << p3.first << ", " << p3.second << ")\n";

}

template<typename T>
std::pair<T, T> get_min_max_index_pairs(std::vector<T> v) {
	size_t min{};
	size_t max{};
	for (size_t i{}; i < v.size(); ++i) {
		if (v.at(i) < v.at(min)) min = i;
		if (v.at(i) > v.at(max)) max = i;
	}
	return { min, max };
}

std::vector<int> get_user_vec() {
	std::cout << "Enter your own int values:\n";
	std::vector<int> v{};

	while (true) {
		int n{};
		std::cout << "> ";
		std::cin >> n;

		if (n == -1) {
			return v;
		}

		if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

		v.push_back(n);
	}
}