#include <iostream>
#include <string_view>

namespace Game {
	enum Flag {
		optimised,
		dlss,
	};
}

namespace Player {
	enum Flag {
		health,
		speed,
	};

	enum class Gun {
		assault_rifle,
		shotgun,
	};

	enum class Melee {
		fist,
		sword,
	};

}

constexpr std::string_view returnFlag(Player::Flag flag) {
	switch (flag) {
	case Player::Flag::health:
		return "Health";
	case Player::Flag::speed:
		return "Speed";
	default:
		return "No Flag";
	}
}

std::ostream& operator<<(std::ostream& o, Player::Flag f) {
	return o << returnFlag(f);
}

int main() {
	Game::Flag game_flags{ Game::Flag::optimised };
	Player::Flag player_flags{ static_cast<Player::Flag>(0) };
	std::cout << player_flags << "\n";

	// can compare cause this is a *unscoped enumeration*
	if (game_flags == player_flags) {
		std::cout << "game_flags == player_flags";
	}

	auto gun{ Player::Gun::shotgun };
	auto melee{ Player::Melee::sword };

	// cannot do
	// constexpr bool isSame{ melee == gun };
}
