#ifndef FIXED_POINT_HPP
# define FIXED_POINT_HPP

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

#endif /* FIXED_HPP */