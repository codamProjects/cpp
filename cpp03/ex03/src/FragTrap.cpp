
#include "FragTrap.hpp"

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap)
{
	*this = fragtrap;
	std::cout << "FragTrap copy constructor called for: " << this->_name << std::endl;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		this->_name = fragtrap._name;
		this->_hp = fragtrap._hp;
		this->_ep = fragtrap._ep;
		this->_ad = fragtrap._ad;
	}
	std::cout << "FragTrap copy assigment operator called for: " << this->_name << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap constructor called for: " << this->_name << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for: " << this->_name << std::endl;
	return;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " asks for a HIGH FIVE!" << std::endl;
	return ;
}
