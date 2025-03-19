
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

void	Weapon::setType(std::string const type)
{
	this->_type = type;
	return ;
}

std::string const&	Weapon::getType(void) const
{
	return(_type);
}