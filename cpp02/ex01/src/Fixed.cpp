
#include "Fixed.hpp"

//constructors:
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num)
{
	std::cout << "int constructor called\n";
	this->setRawBits(num << this->_fractionBits);
	return ;
}

Fixed::Fixed(const float num)
{
	std::cout << "float constructor called\n";
	this->setRawBits(roundf(num * (1 << this->_fractionBits)));
	return ;
}

//destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
	return ;
}

//member functions:
int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (this->getRawBits() / static_cast<float>(1 << this->_fractionBits));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionBits);
}

//general function:
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}