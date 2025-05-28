#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * Represents a fixed-point number.
 */
class Fixed {
	public:
	/**
	 * Takes two references of Fixed-point number as parameters and returns a
	 * reference to the smallest one.
	 * 
	 * @param f1 The first Fixed instance.
	 * @param f2 The second Fixed instance.
	 * @return A reference to the smallest one.
	 */
	static Fixed& min(Fixed& f1, Fixed& f2);
	/**
	 * Takes two references of constant Fixed-point number as parameters and
	 * returns a reference to the smallest one.
	 * 
	 * @param f1 The first Fixed instance.
	 * @param f2 The second Fixed instance.
	 * @return A reference to the smallest one.
	 */
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	/**
	 * Takes two references of Fixed-point number as parameters and returns a
	 * reference to the greatest one.
	 * 
	 * @param f1 The first Fixed instance.
	 * @param f2 The second Fixed instance.
	 * @return A reference to the greatest one.
	 */
	static Fixed& max(Fixed& f1, Fixed& f2);
	/**
	 * Takes two references of constant Fixed-point number as parameters and
	 * returns a reference to the greatest one.
	 * 
	 * @param f1 The first Fixed instance.
	 * @param f2 The second Fixed instance.
	 * @return A reference to the greatest one.
	 */
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

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
	 * @return A reference to this instance.
	 */
	Fixed& operator=(const Fixed &other);
	/**
	 * An equality comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator==(const Fixed& other) const;
	/**
	 * An inequality comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator!=(const Fixed& other) const;
	/**
	 * An inferior comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator<(const Fixed& other) const;
	/**
	 * A superior comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator>(const Fixed& other) const;
	/**
	 * An inferior or equal comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator<=(const Fixed& other) const;
	/**
	 * A superior or equal comparison operator overload.
	 * 
	 * @param other The other instance to compare with the class instance.
	 * @return Either true or false if the comparison is true.
	 */
	bool operator>=(const Fixed& other) const;
	/**
	 * The addition operator.
	 * 
	 * @param other The other instance to add to the class instance.
	 * @return A new Fixed instance containing the result value.
	 */
	Fixed operator+(const Fixed& other) const;
	/**
	 * The substraction operator.
	 * 
	 * @param other The other instance to add to the class instance.
	 * @return A new Fixed instance containing the result value.
	 */
	Fixed operator-(const Fixed& other) const;
	/**
	 * The multiplication operator.
	 * 
	 * @param other The other instance to add to the class instance.
	 * @return A new Fixed instance containing the result value.
	 */
	Fixed operator*(const Fixed& other) const;
	/**
	 * The division operator.
	 * 
	 * @param other The other instance to add to the class instance.
	 * @return A new Fixed instance containing the result value.
	 */
	Fixed operator/(const Fixed& other) const;
	/**
	 * The pre-increment operator.
	 * 
	 * @return The Fixed instance containing the result value.
	 */
	Fixed& operator++(void);
	/**
	 * The post-increment operator.
	 * 
	 * @return A temporary Fixed instance containing the old value.
	 */
	Fixed operator++(int);
	/**
	 * The pre-decrement operator.
	 * 
	 * @return The Fixed instance containing the result value.
	 */
	Fixed& operator--(void);
	/**
	 * The post-decrement operator.
	 * 
	 * @return A temporary Fixed instance containing the old value.
	 */
	Fixed operator--(int);

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
