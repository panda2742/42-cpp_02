#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/**
 * The Binary Space Partitioning recursively subdivides a Euclidian space
 * into two convex shapes.
 * Test whether or not the point is in or on the ABC triangle by regarding on
 * which side of each triangle edge.
 * 
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to evaluate.
 * @return True if the point is on or in the triangle.
 */
bool bsp(const Point a, const Point b, const Point c, const Point point);

/**
 * A barycentric coordinate system is a coordinate system in which the location
 * of a poiunt is specified by reference to a simplex.
 * Apply the calculus of this system to determine if the point is in or on the
 * ABC triangle by regarding on the values of the calculated lambdas based on
 * the denominator.
 * 
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to evaluate.
 * @return True if the point is on or in the triangle.
 */
bool bcs(const Point a, const Point b, const Point c, const Point point);

int main(void) {
	const Point	a(Fixed(3.8f), Fixed(6.31f));
	const Point	b(Fixed(2.18f), Fixed(2.75f));
	const Point	c(Fixed(5.84f), Fixed(3.45f));
	const Point	point(Fixed(4.62f), Fixed(5.16f));

	const bool	bspRes = bsp(a, b, c, point);
	const bool	bcsRes = bcs(a, b, c, point);

	std::cout << "\033[1;33m===== BSP METHOD =====\033[0m " << std::endl;
	std::cout << "\033[1;36mBased on those parameters, the point\033[0m ";
	if (bspRes)
		std::cout << "\033[1;32mIS\033[0m ";
	else
		std::cout << "\033[1;31mIS NOT\033[0m ";
	std::cout << "\033[1;36min the triangle.\033[0m" << std::endl;

	std::cout << "\033[1;33m===== BCS METHOD =====\033[0m " << std::endl;
	std::cout << "\033[1;36mBased on those parameters, the point\033[0m ";
	if (bcsRes)
		std::cout << "\033[1;32mIS\033[0m ";
	else
		std::cout << "\033[1;31mIS NOT\033[0m ";
	std::cout << "\033[1;36min the triangle.\033[0m" << std::endl;

	return 0;
}
