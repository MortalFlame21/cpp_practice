#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cassert>
#include <numeric>

namespace Player {
	enum Items {
		HEALTH_POTION,
		TORCHES,
		ARROWS,
		MAX_ITEMS,
	};

	std::vector num_items{ 1, 5, 10 };

	std::string_view item_str(Items item) {
		switch (item) {
		case HEALTH_POTION:
			return "health potion";
		case TORCHES:
			return "torches";
		case ARROWS:
			return "arrows";
		default:
			return "unknown item";
		}
	}

	void view_total_items() {
		for (size_t i{}; i < num_items.size(); ++i) {
			std::cout << "You have " << num_items.at(i) << " " << item_str(static_cast<Items>(i)) << "\n";
		}

		int sum = std::accumulate(Player::num_items.begin(), Player::num_items.end(), 0);
		std::cout << "You have " << sum << " total items\n";
	}
}

int main(int argc, char* argv[]) {
	assert(Player::num_items.size() == Player::MAX_ITEMS);

	Player::view_total_items();

}