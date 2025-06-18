#pragma once

#include "Point3d.h"

class Vector3d {
public:
	Vector3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{

	}

	void print() const;
private:
	double m_x{};
	double m_y{};
	double m_z{};

	friend void Point3d::moveByVector(const Vector3d& v);
};

