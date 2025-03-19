
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
	return ;
}
