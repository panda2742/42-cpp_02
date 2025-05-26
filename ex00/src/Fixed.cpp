#include "Fixed.hpp"
#include <iostream>

// PUBLIC ===================
// Constructors & Destructors
Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedValue = other.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return *this;
}

// Getters
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedValue;
}

// Setters
void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedValue = raw;
}

// PRIVATE =========
// Static attributes
const int Fixed::_fractionalBits = 8;
