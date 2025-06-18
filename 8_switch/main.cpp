#include <iostream>

void switch_enum(int n) {
	enum Elements {
		FIRE,
		ICE,
		ROCK
	};

	const Elements element{static_cast<Elements>(n)};
	
	switch (element) {
	// ! do not indent as case labels do not define a new scope ! 
	case FIRE:
		std::cout << "Fire element. Will fall through with no break.\n";
		// [[fallthrough]] indicates an intentional fallthrough
		[[fallthrough]];
	case ICE:
		std::cout << "Ice element\n";
		break;
	case ROCK:
		std::cout << "Rock element\n";
		break;
	default:
		std::cout << "No element\n";
		break;
	}
}

void switch_char(char c) {
	switch (c) {
		// why does this not work
		//int a;
		//a = 1;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k': {
		// do not do this without it being block scoped! 
		int a{ 'a' };
		std::cout << c - a << "\n";
		break;
	}
	default:
		std::cout << c << "- was not part of label\n";
		break;
	}
}

int main(int argc, char* argv[]) {
	switch_enum(0);
	switch_char('z');
}