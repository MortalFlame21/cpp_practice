#include <iostream>
#include <string>

class Monster {
public:
	enum Type {
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MaxMonsterTypes,
	};

	Monster(Type type, std::string name, std::string roar, int hit_points);

	std::string getTypeString() const;
	void print() const;
private:
	Type m_type{};
	std::string m_name{ "???" };
	std::string m_roar{ "???" };
	int m_hit_points{};
};

Monster::Monster(Type type, std::string name, std::string roar, int hit_points) :
	m_type{ type }, m_name{ name }, m_roar{ roar }, m_hit_points{ hit_points }
{
	
}

std::string Monster::getTypeString() const {
	switch (m_type) {
	case Dragon:
		return "Dragon";
		break;
	case Goblin:
		return "Goblin";
		break;
	case Ogre:
		return "Ogre";
		break;
	case Orc:
		return "Orc";
		break;
	case Skeleton:
		return "Skeleton";
		break;
	case Troll:
		return "Troll";
		break;
	case Vampire:
		return "Vampire";
		break;
	case Zombie:
		return "Zombie";
		break;
	default:
		return "UnknownType";
		break;
	}
}

void Monster::print() const {
	std::cout << m_name << " the " << getTypeString();
	if (m_hit_points > 0.0) {

		std::cout << " has " << m_hit_points << " hit points and says " << m_roar << ".\n";
	} 
	else {
		std::cout << " is dead.\n";
	}
}

namespace MonsterGenerator {
	Monster generate() {
		return Monster{ Monster::Skeleton, "Bones", "*rattle*", 4 };
	}
}

int main(int argc, char* argv[]) {
	Monster skeleton{ Monster::Skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::Vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

	Monster m{ MonsterGenerator::generate() };
	m.print();
}
