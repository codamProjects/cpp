
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	*this = diamondtrap;
	std::cout << "DiamondTrap copy constructor called for: " << this->_name << std::endl;
	return ;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	if (this != &diamondtrap)
	{
		this->_name = diamondtrap._name;
		this->ClapTrap::_name = diamondtrap._name + "_clap_trap";
		this->_hp = diamondtrap._hp;
		this->_ep = diamondtrap._ep;
		this->_ad = diamondtrap._ad;
	}
	std::cout << "DiamondTrap copy assigment operator called for: " << this->_name << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hp = this->_FThp;
	this->_ep = this->_STep;
	this->_ad = this->_FTad;
	std::cout << "DiamondTrap constructor called for: " << this->_name << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for: " << this->_name << std::endl;
	return;
}

const std::string&	DiamondTrap::getName() const
{
	return (this->_name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name=" << this->_name;
	std::cout << " ClapTrap name=" << this->ClapTrap::_name << std::endl;
	return ;
}
