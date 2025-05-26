#include "Fixed.hpp"
#include <iostream>

// PUBLIC ===================
// Constructors & Destructors
Fixed::Fixed() : _numberValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_numberValue = other.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_numberValue = other.getRawBits();
	}
	return *this;
}

// Getters
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _numberValue;
}

// Setters
void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_numberValue = raw;
}

// PRIVATE =========
// Static attributes
const int Fixed::_fractionalBits = 8;
