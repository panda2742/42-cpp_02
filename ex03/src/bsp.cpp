#include "Point.hpp"

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
bool bsp(const Point a, const Point b, const Point c, const Point point) {
	/*
	First, we determine each dot product of each point with its
	associated edge and the point.
	 */
	Fixed	crossAP =
		(b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
	Fixed	crossBP =
		(c.x() - b.x()) * (point.y() - b.y()) - (c.y() - b.y()) * (point.x() - b.x());
	Fixed	crossCP =
		(a.x() - c.x()) * (point.y() - c.y()) - (a.y() - c.y()) * (point.x() - c.x());

	/*
	We show the content of each dot product result to check if everything is ok.
	*/
	std::cout << "\033[1;32mProd AP = " << crossAP << "\033[0m" << std::endl;
	std::cout << "\033[1;33mProd BP = " << crossBP << "\033[0m" << std::endl;
	std::cout << "\033[1;34mProd CP = " << crossCP << "\033[0m" << std::endl;

	/*
	First and last step, we interpret the result of each product and, we can
	conclude if the point is in/on the triangle based on those facts:
	- Only one product can be null (= 0), it means the dot is on the associated
	edge.
	- There cannot be a positive and a negative result. Each result should share
	the same sign.
	*/
	bool	hasNeg = (crossAP < 0) || (crossBP < 0) || (crossCP < 0);
	bool	hasPos = (crossAP > 0) || (crossBP > 0) || (crossCP > 0);

	/*
	Then we return the result here by filtering the two booleans result.
	*/
	return !(hasNeg && hasPos);
}

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
bool bcs(const Point a, const Point b, const Point c, const Point point) {
	/*
	In the comments below, a b c have been replaced by 1, 2, 3, and point does
	not have any alias; its coordinates stand for x and y.
	*/

	/*
	T is a matrix given by:

		(x1 - x3	x2 - x3)
	T = (y1 - y3	y2 - y3)
	*/
	const Fixed	Tmatrix[2][2] = {
		{ a.x() - c.x(), b.x() - c.x() },
		{ a.y() - c.y(), b.y() - c.y() }
	};
	/*
	The denominator is calculated based on the determinant of the T matrix,
	such as:

	det(T)	= ad - bc
			= (x1 - x3)(y2 - y3) - (x2 - x3)(y1 - y3)
	*/
	const Fixed	denom =
		Tmatrix[0][0] * Tmatrix[1][1] - Tmatrix[0][1] * Tmatrix[1][0];

	/*
	Then we calculate λ1, λ2 and λ3 based on:

			(y2 - y3)(x - x3) + (x3 - x2)(y - y3)
	λ1 =	-------------------------------------
							det(T)

			(y3 - y1)(x - x3) + (x1 - x3)(y - y3)
	λ2 =	-------------------------------------
							det(T)

	λ3 =	1 - λ1 - λ2

	Everything has been split to improve reading and evaluation.
	*/
	const Fixed	lambda1_0 = b.y() - c.y();
	const Fixed	lambda1_1 = point.x() - c.x();
	const Fixed	lambda1_2 = c.x() - b.x();
	const Fixed	lambda1_3 = point.y() - c.y();
	const Fixed	lambda1_4 = lambda1_0 * lambda1_1 + lambda1_2 * lambda1_3;
	const Fixed	lambda1 = lambda1_4 / denom;

	const Fixed	lambda2_0 = c.y() - a.y();
	const Fixed	lambda2_1 = point.x() - c.x();
	const Fixed	lambda2_2 = a.x() - c.x();
	const Fixed	lambda2_3 = point.y() - c.y();
	const Fixed	lambda2_4 = lambda2_0 * lambda2_1 + lambda2_2 * lambda2_3;
	const Fixed	lambda2 = lambda2_4 / denom;

	const Fixed	lambda3 = Fixed(1) - lambda1 - lambda2;

	std::cout << "\033[1;36md(T) = " << lambda1_0 << "\033[0m" << std::endl;

	/*
	We print everything here to be sure everything is ok.
	*/
	std::cout << "\033[1;31mλ1 0\033[0m = " << lambda1_0 << std::endl;
	std::cout << "\033[1;31mλ1 1\033[0m = " << lambda1_1 << std::endl;
	std::cout << "\033[1;31mλ1 2\033[0m = " << lambda1_2 << std::endl;
	std::cout << "\033[1;31mλ1 3\033[0m = " << lambda1_3 << std::endl;
	std::cout << "\033[1;31mλ1 4\033[0m = " << lambda1_4 << std::endl;
	std::cout << "\033[1;31mλ1 = " << lambda1 << "\033[0m" << std::endl;

	std::cout << "\033[1;32mλ2 0\033[0m = " << lambda2_0 << std::endl;
	std::cout << "\033[1;32mλ2 1\033[0m = " << lambda2_1 << std::endl;
	std::cout << "\033[1;32mλ2 2\033[0m = " << lambda2_2 << std::endl;
	std::cout << "\033[1;32mλ2 3\033[0m = " << lambda2_3 << std::endl;
	std::cout << "\033[1;32mλ2 4\033[0m = " << lambda2_4 << std::endl;
	std::cout << "\033[1;32mλ2 = " << lambda2 << "\033[0m" << std::endl;

	std::cout << "\033[1;33mλ3 = " << lambda3 << "\033[0m" << std::endl;

	/*
	Then we interprate the result by following this unbreakable rule:
	The point is in the ABC triangle if and only if every lambda result is
	superior or equal to 0.
	*/
	return lambda1 >= 0 && lambda2 >= 0 && lambda3 >= 0;
}
