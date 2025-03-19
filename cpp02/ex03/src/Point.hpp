
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point &point);
	Point	&operator=(const Point &point);
	Point(const float x, const float y);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed _x;
	Fixed _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif