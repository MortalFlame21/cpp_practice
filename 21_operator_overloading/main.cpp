#include <iostream>
#include <cassert>
#include <sstream>

class Vec2d {
public:
	Vec2d() = default;
	Vec2d(double x, double y) : m_x{ x }, m_y{ y } {};
	
	// need friend because operator<< is not a member function
	friend std::ostream& operator<<(std::ostream& out, const Vec2d& v) {
		return out << "(" << v.m_x << ", " << v.m_y << ")";
	}

	friend std::istream& operator>>(std::istream& in, Vec2d& v) {
		// in relation to *transactional operations*
		double x{}; double y{};
		std::cout << "Enter x, y for vector: ";
		v = (in >> x >> y) ? Vec2d{x, y} : v;
		return in;
	}
	
	// unary operator overloading
	Vec2d& operator-() {
		m_x = -m_x; m_y = -m_y;
		return *this;
	}

	Vec2d& operator+() {
		return *this;
	}

	// pre increment and decrement
	Vec2d& operator--() {
		--m_x; --m_y;
		return *this;
	}

	Vec2d& operator++() {
		++m_x; ++m_y;
		return *this;
	}

	// post increment and decrement
	Vec2d operator--(int) {
		Vec2d tmp{ *this };
		--(*this);
		return tmp;
	}

	Vec2d operator++(int) {
		Vec2d tmp{ *this };
		++(*this);
		return tmp;
	}

	// comparision operator overloading
	bool operator==(const Vec2d& o) {
		return (m_x == o.m_x) && (m_y == o.m_y);
	}

	bool operator!=(const Vec2d& o) {
		return !(*this == o);
	}

	// overloading casts
	// best to mark as explicit
	explicit operator std::string() const {
		std::stringstream ss;
		ss << "(" << m_x << ", " << m_y << ")";
		return ss.str();
	}

	// assignment overloading vs copy constructor
	Vec2d(const Vec2d& v) 
		: m_x { v.m_x }, m_y { v.m_y } 
	{
		std::cout << "copy constructor called\n";
	}

	Vec2d& operator=(const Vec2d& o) {
		std::cout << "operator= called\n";
		m_x = o.m_x;
		m_y = o.m_y;
		return *this;
	}
private:
	double m_x{};
	double m_y{};
};

int main(int argc, char* argv[]) {
	Vec2d v1{ 1, 2 };
	std::cout << v1 << "\n";

	Vec2d v2{ 2, 4 };
	// std::cin >> v2;
	std::cout << -v2 << "\n";

	Vec2d v3{ v2 };
	std::cout << (v2 == v3 ? "same" : "not same") << "\n";
	std::cout << (v2 != v1 ? "not same" : "same") << "\n";

	std::cout << v3++ << "\n";
	std::cout << ++v3 << "\n";
	assert((v3 == Vec2d{0, -2} && "Not the same. Check operator++."));

	auto v_str{ static_cast<std::string>(v1) };
	std::cout << v_str << "\n";
	
	v1 = v2;
	std::cout << v1 << "\n";
	v1 = v1;
	std::cout << v1 << "\n";
}