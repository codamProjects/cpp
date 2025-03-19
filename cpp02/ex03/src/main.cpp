
#include "Point.hpp"

int	main(void)
{
	//inside
	Point const a(3, 5);
	Point const b(1, 1);
	Point const c(4, 1);
	Point const point(2.5f, 3.5f);

	//outside
	// Point const a(3, 5);
	// Point const b(1, 1);
	// Point const c(4, 1);
	// Point const point(6, 2);

	// //on line
	// Point const a(4, 1);
	// Point const b(1, 1);
	// Point const c(2.5f, 3.5f);
	// Point const point(c);

	//floats only
	// Point const a(2.75f, 4.5f);
	// Point const b(4.25, 1.75f);
	// Point const c(1.5f, 1.25f);
	// Point const point(2.5f, 2.5f); //inside
	//Point const	point(5.1f, 5.1f); //outside
	//Point const point(3.5f, 1); //on the line

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point is not inside the triangle\n";
	return (0);
}