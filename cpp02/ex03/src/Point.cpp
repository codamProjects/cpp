
#include "Point.hpp"

//construcotrs:
Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const Point &point)
{
	*this = point;
	return ;
}

Point	&Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->_x = point.getX();
		this->_y = point.getY();
	}
	return (*this);
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	return ;
}

//destructor
Point::~Point()
{
	return ;
}

//member functions
Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
