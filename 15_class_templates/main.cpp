#include <iostream>

template <typename T>
class Pair {
public:
	Pair() = default;
	Pair(T first, T second);
	
	T get_first() { return m_first; }
	T get_second() { return m_second; }

	void print();
private:
	T m_first{};
	T m_second{};
};

// need lines 14, 15 as this was a template
template <typename T>
Pair<T>::Pair(T first, T second)
	: m_first{ first }, m_second{ second }
{

}

// templates should be in the same file
template <typename T>
void Pair<T>::print() {
std::cout << "<T>(" << get_first() << ", " << get_second() << ")\n";
}

void Pair<int>::print() {
	std::cout << "<int>(" << get_first() << ", " << get_second() << ")\n";
}

int main(int argc, char* argv[]) {
	Pair<int> p1{ 1, 2 };
	p1.print();

	Pair<double> p2{ 1.0, 2.0};
	p2.print();
}