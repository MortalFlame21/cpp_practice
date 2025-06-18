#include <iostream> 
#include <cmath>

class Point2d {
public:
	Point2d() = default;
	Point2d(double x, double y);
	double get_x() const;
	double get_y() const;
	void print() const;
	double distance_to(const Point2d& p) const;
private:
	double m_x{};
	double m_y{};
};

Point2d::Point2d(double x, double y)
	: m_x{ x }, m_y{ y }
{

}

double Point2d::get_x() const {
	return m_x;
}

double Point2d::get_y() const {
	return m_y;
}

void Point2d::print() const {
	std::cout << "(" << m_x << ", " << m_y << ")\n";
}

double Point2d::distance_to(const Point2d& p) const {
	// no need for Point2d::get_{x, y} because they are part of the class type.
	return std::sqrt(std::pow(m_x - p.m_x, 2.0) + std::pow(m_y - p.m_y, 2.0));
}

int main(int argc, char* argv[]) {
	Point2d p1{};
	Point2d p2{ 3.0, 4.0 };

	p1.print();
	p2.print();

	std::cout << "p1 -> p2: " << p1.distance_to(p2) << "\n";
	std::cout << "p1 <- p2: " << p2.distance_to(p1) << "\n";
}