
#include "Point.hpp"

static Fixed	getCrossProduct(Point const i, Point const j, Point const k)
{
	return ((j.getX() - i.getX()) * (k.getY() - i.getY()) - (k.getX() - i.getX()) * (j.getY() - i.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossProduct1 = getCrossProduct(a, b, point);
	Fixed	crossProduct2 = getCrossProduct(b, c, point);
	Fixed	crossProduct3 = getCrossProduct(c, a, point);

	if (crossProduct1 > 0 && crossProduct2 > 0 && crossProduct3 > 0)
		return (1);
	if (crossProduct1 < 0 && crossProduct2 < 0 && crossProduct3 < 0)
		return (1);
	return (0);
}