
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << "\n";
	std::cout << (--a)++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "\n";
	std::cout << "a: " << a << " and b: " << b << "\n";
	std::cout << "max of a and b= " << Fixed::max(a, b) << std::endl;
	std::cout << "min of a and b= " << Fixed::min(a, b) << std::endl;
	std::cout << "max of a and 5= " << Fixed::max(a, 5) << std::endl;
	std::cout << "min of b and 0.01f= " << Fixed::min(b, 0.01f) << std::endl;
	std::cout << "\n";
	if (a < b)
		std::cout << "a is smaller then b\n";
	if (a > b)
		std::cout << "a is bigger then b\n";
	if (a == b)
		std::cout << "a is equal to b\n";
	if (a != b)
		std::cout << "a is not equal to b\n";
	if (a <= b)
		std::cout << "a is smaller then, or equal to b\n";
	if (a >= b)
		std::cout << "a is bigger then, or equal to b\n";
	std::cout << "\n";
	Fixed c(2.5f);
	Fixed d(10);
	std::cout << "c: " << c << " and d: " << d << "\n";
	std::cout << "c + d = " << c + d << "\n";
	std::cout << "c - d = " << c - d << "\n";
	std::cout << "c / d = " << c / d << "\n";
	std::cout << "c * d = " << c * d << "\n";
	return (0);
}

// int	main(void)
// {
// 	Fixed	a;
// 	Fixed const	b(Fixed(5.05f) * Fixed(2));
// 	Fixed const	c(Fixed(5.05f) / Fixed(0));
// 	Fixed const	d(Fixed(5.05f) + Fixed(2));
// 	Fixed const	e(Fixed(5.05f) - Fixed(2));

// 	std::cout << a << " vs " << a + Fixed(5.05f) << " vs " << Fixed(5.05f) << std::endl;
// 	std::cout << b << " vs " << b / Fixed(2) << " vs " << Fixed(5.05f) << std::endl;
// 	std::cout << c << " vs " << c * Fixed(2) << " vs " << Fixed(5.05f) << std::endl;
// 	std::cout << d << " vs " << d - Fixed(2) << " vs " << Fixed(5.05f) << std::endl;
// 	std::cout << e << " vs " << e + Fixed(2) << " vs " << Fixed(5.05f) << std::endl;

// 	return (0);
// }