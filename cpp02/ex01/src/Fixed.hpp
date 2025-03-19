
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

private:
	int					_fixedPointValue;
	static const int	_fractionBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif