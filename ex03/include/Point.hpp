#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/**
 * Represent a point in a bidimensional plan.
 */
class Point {
	public:
	/**
	 * Initialize the Point and set its values x and y both to 0.
	 */
	Point(void);
	/**
	 * Initialize the Point and set its coordinates to the two const Fixed
	 * instance values passed in parameters.
	 * 
	 * @param xFixed The Fixed for the x coordinate.
	 * @param yFixed The Fixed for the y coordinate.
	 */
	Point(const Fixed xFixed, const Fixed yFixed);
	/**
	 * A copy constructor.
	 * 
	 * @param other The other instance to copy into the new one.
	 */
	Point(const Point& other);
	/**
	 * A destructor.
	 */
	~Point(void);

	/**
	 * A copy assignment operator overload.
	 * 
	 * @param other The other instance to assign to the class instance.
	 * @return A reference to this instance.
	 */
	Point& operator=(const Point &other);

	private:
	/**
	 * The x coordinate of the point.
	 */
	const Fixed	_x;
	/**
	 * The y coordinate of the point.
	 */
	const Fixed	_y;
};

#endif /* POINT_HPP */