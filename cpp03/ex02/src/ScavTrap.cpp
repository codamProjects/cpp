
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	*this = scavtrap;
	std::cout << "ScavTrap copy constructor called for: " << this->_name << std::endl;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (this != &scavtrap)
	{
		this->_name = scavtrap._name;
		this->_hp = scavtrap._hp;
		this->_ep = scavtrap._ep;
		this->_ad = scavtrap._ad;
	}
	std::cout << "ScavTrap copy assigment operator called for: " << this->_name << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap constructor called for: " << this->_name << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor called for: " << this->_name << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->_name;
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << " attacks " << target << ", causing ";
		std::cout << this->_ad <<  " points of damage" << std::endl;
		this->_ep -= 1;
	}
	else
	{
		std::cout << " tried to attack " << target << ", but it doesnt have enough ";
		if (this->_ep <= 0 && this->_hp > 0)
			std::cout << "Energy Points" << std::endl;
		else if (this->_ep > 0 && this->_hp <= 0)
			std::cout << "Hit Points" << std::endl;
		else
			std::cout << "Hit Points and Energy Points" << std::endl;
	}
	return ; 
}
