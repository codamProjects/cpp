
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A nameless Zombie has been created" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie '"<< _name << "' is destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}

void	Zombie::setName(std::string const name)
{
	this->_name = name;
	return ;
}
