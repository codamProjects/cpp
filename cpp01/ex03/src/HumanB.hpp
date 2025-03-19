
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
public:
	HumanB(std::string const name);
	~HumanB();

	void	attack(void) const;
	void	setWeapon(Weapon weapon);

private:
	std::string	const _name;
	Weapon		*weapon;

	HumanB();
};

#endif
