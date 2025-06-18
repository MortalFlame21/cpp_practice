#include <iostream> 
#include <random>
#include <chrono>
#include "random.h"

int main(int argc, char* argv[]) {
	// have ability to generate 32-bit integers, or use std::mt19937_64 for 64-bit.
	// we are using a changing seed, time.
	// std::mt19937 mt{ static_cast<std::mt19937::result_type>(
	// 	std::chrono::steady_clock::now().time_since_epoch().count()
	// ) };
	// or use std::random_device
	// std::mt19937 mt{ std::random_device{}() };
	// or create a seed sequence which distributes the 0/1s in the seed
	// basically it takes, the vector of rd and creates a random seed
	std::random_device rd{};
	// recommened to do 8 calls to rd
	std::seed_seq seed_seq{ rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ seed_seq };

	// uniform distribution is a random number distribution that produces outputs 
	// between two numbers [l, u] with *equal probability*.
	// in this case [1, 6]
	std::uniform_int_distribution domain{ 1, 10000 };

	for (int count{ 1 }; count <= 40; ++count) {
		std::cout << domain(mt) << "\t" << ((count % 5 == 0) ? "\n" : "");
	}
	
	std::cout << "\nRandom::mt()\n";
	std::cout << Random::mt() << "\n";
	std::cout << Random::mt() << "\n";

	std::cout << "\nRandom::get()\n";
	std::cout << Random::get() << "\n";
	std::cout << Random::get() << "\n";
	std::cout << Random::get() << "\n";
	std::cout << Random::get() << "\n";

	std::cout << "\nRandom::get<T>(T, T)\n";
	std::cout << Random::get(1, 100) << "\n";
	std::cout << Random::get(1, 100000) << "\n";
	std::cout << Random::get(-100, -1) << "\n";

	std::cout << "\nRandom::get<T>(U, V)\n";
	// only on integral types
	// std::cout << Random::get<double>(0, 1) << "\n";
	// std::cout << Random::get<double>(0, 100) << "\n";
	std::cout << Random::get<uint32_t>(100, 1000) << "\n";
}