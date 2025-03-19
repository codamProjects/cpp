
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack(void) const
{
	if (weapon)
	{
		std::cout << _name << " attacks with their ";
		std::cout << weapon->getType() << std::endl;
	}
	else
		std::cout << "Help, I(" << _name << ") dont have a weapon!" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
	return ;
}
