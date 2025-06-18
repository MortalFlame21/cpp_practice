#include <iostream>

class Vector3d;

class Point3d {
public:
	Point3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const {
		std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);
private:
	double m_x{};
	double m_y{};
	double m_z{};
};

class Vector3d {
public:
	Vector3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const {
		std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}
	
private:
	double m_x{};
	double m_y{};
	double m_z{};

	// A friend class
	// friend class Point3d;
	// Vector3d must see the full definition of Point3d to make it a friend
	// member function.
	friend void Point3d::moveByVector(const Vector3d& v);
};

// move outside definition because Point3d does not know about Vector3d
void Point3d::moveByVector(const Vector3d& v) {
	m_x += v.m_x;
	m_y += v.m_x;
	m_z += v.m_z;
}

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}