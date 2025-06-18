#include <iostream>

// structs and classes have undefined rule sets.
template<typename T>
struct Pair {
	T first{};
	T second{};

	void print() const {
		std::cout << "Pair: (" << first << ", " << second << ").";
	}

	bool isEqual() const {
		return first == second;
	}
};

int main(int argc, char* argv[]) {
	Pair<int> p{ 1, 2 };
	p.print();
	std::cout << "\n" << (p.isEqual() ? "Same" : "Not Same");
}


