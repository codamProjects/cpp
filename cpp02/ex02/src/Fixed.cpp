
#include "Fixed.hpp"

//constructors:
Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "default constr called\n";
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "copy constr called\n";
	*this = fixed;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "copy assigment opperator called\n";
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num)
{
	// std::cout << "int constr called\n";
	this->setRawBits(num << this->_fractionBits);
	return ;
}

Fixed::Fixed(const float num)
{
	// std::cout << "float constr called\n";
	this->setRawBits(roundf(num * (1 << this->_fractionBits)));
	return ;
}

//destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
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

//comparison operators:
bool Fixed::operator==(Fixed const& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator>(Fixed const& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const& rhs) const
{
	return (!(*this == rhs));
}

bool Fixed::operator>=(Fixed const& rhs) const
{
	return (*this > rhs || *this == rhs);
}

bool Fixed::operator<=(Fixed const& rhs) const
{
	return (*this < rhs || *this == rhs);
}

//arithmetic operators:
Fixed	Fixed::operator+(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//in/de-crement functions:
Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue += 1;
	return (*this);	
}

Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue -= 1;
	return (*this);	
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_fixedPointValue += 1;
	return (temp);
}
	
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_fixedPointValue -= 1;
	return (temp);
}

//min/max functions:
Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return ((f1 > f2) ? f1 : f2);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return ((f1 < f2) ? f1 : f2);
}

//general function:
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}