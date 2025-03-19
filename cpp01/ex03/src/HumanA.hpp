
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
public:
	HumanA(std::string const name, Weapon &weapon);
	~HumanA();

	void	attack(void) const;

private:
	std::string	const _name;
	Weapon		&weapon;

	HumanA();
};

#endif
