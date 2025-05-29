#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Fixed xFixed, const Fixed yFixed) : _x(xFixed), _y(yFixed) {
	std::cout << "Fixed constructor called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point(void) {
	std::cout << "Destructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;

	return *this;
}

const Fixed& Point::x(void) const {
	return _x;
}

const Fixed& Point::y(void) const {
	return _y;
}
