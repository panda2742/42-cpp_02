#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * Represents a fixed-point number.
 */
class Fixed {
	public:
	/**
	 * Initialize the fixed-point number instance and set its value to 0.
	 */
	Fixed(void);
	/**
	 * Initialize the fixed-point number instance and set its value to the
	 * number passed in parameters.
	 * 
	 * @param value The value used for the class initialization.
	 */
	Fixed(const int value);
	/**
	 * Initialize the fixed-point number instance and take a floating-point
	 * number as a parameter. Converts the floating-point number into a
	 * fixed-point number.
	 * 
	 * @param floatingValue The value used for the class initialization.
	 */
	Fixed(const float floatingValue);
	/**
	 * A copy constructor.
	 * 
	 * @param other The other instance to copy into the new one.
	 */
	Fixed(const Fixed& other);
	/**
	 * A destructor.
	 */
	~Fixed(void);

	/**
	 * A copy assignment operator overload.
	 * 
	 * @param other The other instance to assign to the class instance.
	 */
	Fixed& operator=(const Fixed &other);

	/**
	 * Convert the fixed-point number into a floating-point number and return
	 * it.
	 * 
	 * @return The generated floating-point value.
	 */
	float toFloat(void) const;

	/**
	 * Convert the fixed-point number into a integer and return it.
	 * 
	 * @return The generated integer value.
	 */
	int toInt(void) const;

	/**
	 * Return the raw value of the fixed-point number.
	 * 
	 * @return The raw value of the fixed-point number.
	 */
	int getRawBits(void) const;

	/**
	 * Set the raw value of the fixed-point number.
	 * 
	 * @param raw The raw value to set.
	 */
	void setRawBits(const int raw);

	private:
	/**
	 * The number of fractional bits. Its value is set for every instance of
	 * the class.
	 */
	static const int _fractionalBits;

	/**
	 * The raw value of the fixed-point number.
	 */
	int	_value;
};

/**
 * An insertion operator overload. Display the content of the fixed-point
 * number as a floating-point number.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif /* FIXED_HPP */
