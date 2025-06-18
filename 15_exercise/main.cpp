#include <iostream>
#include <string>

class Monster {
public:
	enum class Type {
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		maxMonsterTypes,
	};

private:
	Type type{};
	std::string name{ "???" };
	std::string roar{ "???" };
	int hit_points{};
};

int main(int argc, char* argv[]) {

}