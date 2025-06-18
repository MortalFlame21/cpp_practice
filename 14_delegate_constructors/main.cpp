#include <iostream>
#include <string>
#include <string_view>

class Ball {
public:
	// Ball();
	// Ball(std::string color);
	// Ball(double radius);
	// Ball(std::string color, double radius);
	// can reduce to 2 constructors through
	// Ball::Ball(double radius)
	// Ball::Ball(std::string color, double radius)

	Ball(double radius);
	Ball(std::string_view color, double radius);

	const std::string& get_color();
	double get_radius();

	void print();
protected:

private:
	std::string m_color{ "Black" };
	double		m_radius{ 10.0 };
};

// Ball::Ball(double radius)
Ball::Ball(double radius)
	: Ball{ "Black", radius }
{
}

// this handles
// Ball::Ball()
// Ball::Ball(std::string_view color)
// Ball::Ball(std::string_view color, double radius)
Ball::Ball(std::string_view color = "Black", double radius = 10.0)
	: m_color{ color }, m_radius{ radius }
{
	print();
}

const std::string& Ball::get_color() {
	return m_color;
}

double Ball::get_radius() {
	return m_radius;
}

void Ball::print() {
	std::cout << "Ball(" << get_color() << ", " << get_radius() << ")\n";
}

int main(int argc, char* argv[]) {
	Ball default_ball{};
	Ball blue_balls{ "Blue" };
	Ball ball_21{ 21 };
	Ball blue_balls_21{ "Blue", 21 };
}

