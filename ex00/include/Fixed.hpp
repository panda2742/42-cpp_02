#ifndef FIXED_POINT_HPP
# define FIXED_POINT_HPP

class Fixed {
	public:
	// Constructors & Destructors
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);

	// Operators
	Fixed& operator=(const Fixed &other);

	// Getters
	int getRawBits(void) const;

	// Setters
	void setRawBits(const int raw);

	private:
	// Static attributes
	static const int _fractionalBits;

	// Attributes
	int	_fixedValue;
};

#endif