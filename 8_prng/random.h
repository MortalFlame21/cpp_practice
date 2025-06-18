// https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/

#pragma once

#include <chrono>
#include <random>

namespace Random {
	inline std::mt19937 generate() {
		std::random_device rd{};
		std::seed_seq seed_seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		return std::mt19937{ seed_seq };
	}

	inline std::mt19937 mt{ generate() };

	inline int get() {
		return mt();
	}

	inline int get(int l, int h) {
		return std::uniform_int_distribution{ l, h }(mt);
	}

	template<typename T>
	inline T get(T l, T h) {
		return std::uniform_int_distribution<T>{ l, h }(mt);
	}

	template<typename T, typename U, typename V>
	inline T get(U l, V h) {
		return get<T>(static_cast<T>(l), static_cast<T>(h));
	}
}


