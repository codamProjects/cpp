
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &fixed);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator==(Fixed const& rhs) const;
	bool	operator>(Fixed const& rhs) const;
	bool	operator<(Fixed const& rhs) const;
	bool	operator>=(Fixed const& rhs) const;
	bool	operator<=(Fixed const& rhs) const;
	bool	operator!=(Fixed const& rhs) const;

	Fixed	operator+(Fixed const& rhs) const;
	Fixed	operator-(Fixed const& rhs) const;
	Fixed	operator*(Fixed const& rhs) const;
	Fixed	operator/(Fixed const& rhs) const;

	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed&	max(Fixed& f1, Fixed& f2);
	static Fixed&	min(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);

private:
	int					_fixedPointValue;
	static const int	_fractionBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif