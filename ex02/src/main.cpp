#include "Fixed.hpp"
#include <iostream>

int main(void) {
	{
		Fixed	a(5), b, c, d, e, f, g, h, i;

		std::cout << "\033[1;35ma is " << a << "\033[0m" << std::endl;

		b = a + a;
		std::cout << "\033[1;35mb is " << b << "\033[0m" << std::endl;

		c = a - a;
		std::cout << "\033[1;35mc is " << c << "\033[0m" << std::endl;

		d = a * a;
		std::cout << "\033[1;35md is " << d << "\033[0m" << std::endl;

		e = a / a;
		std::cout << "\033[1;35me is " << e << "\033[0m" << std::endl;

		f = a++;
		std::cout << "\033[1;35mf is " << f << "\033[0m" << std::endl;
		std::cout << "\033[1;35ma is " << a << "\033[0m" << std::endl;

		g = ++a;
		std::cout << "\033[1;35mg is " << g << "\033[0m" << std::endl;
		std::cout << "\033[1;35ma is " << a << "\033[0m" << std::endl;

		h = a--;
		std::cout << "\033[1;35mh is " << h << "\033[0m" << std::endl;
		std::cout << "\033[1;35ma is " << a << "\033[0m" << std::endl;

		i = --a;
		std::cout << "\033[1;35mi is " << i << "\033[0m" << std::endl;
		std::cout << "\033[1;35ma is " << a << "\033[0m" << std::endl;
	}
	{
		Fixed		a(10), b(20);
		const Fixed	c(30), d(40);

		std::cout << "\033[1;35mWhich is smaller, a or b?\033[0m" << std::endl;
		std::cout << Fixed::min(a, b) << std::endl;

		std::cout << "\033[1;35mWhich is greater, c or d?\033[0m" << std::endl;
		std::cout << Fixed::max(c, d) << std::endl;
	}
	{
		Fixed		a;
		const Fixed	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}

	return 0;
}
