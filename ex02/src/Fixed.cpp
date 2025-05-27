#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float floatingValue) {
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(floatingValue * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_value = other._value;

	return *this;
}

bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _value != other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;
}

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed	res;

	res._value = _value + other._value;

	return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed	res;

	res._value = _value - other._value;

	return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed		res;

	long long	tmp = static_cast<long long>(_value) * static_cast<long long>(other._value);
	res._value = static_cast<int>(tmp >> _fractionalBits);

	return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed		res;

	long long	tmp = (static_cast<long long>(_value) << _fractionalBits / other._value);
	res._value = static_cast<int>(tmp);

	return res;
}

float Fixed::toFloat(void) const {
	float	nb;

	nb = static_cast<float>(_value) / (1 << _fractionalBits);

	return nb;
}

int Fixed::toInt(void) const {
	int	nb;

	nb = _value >> _fractionalBits;

	return nb;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return _value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

const int Fixed::_fractionalBits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();

	return os;
}
