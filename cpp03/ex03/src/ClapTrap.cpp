
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << "ClapTrap copy constructor called for: " << this->_name << std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (this != &claptrap)
	{
		this->_name = claptrap._name;
		this->_hp = claptrap._hp;
		this->_ep = claptrap._ep;
		this->_ad = claptrap._ad;
	}
	std::cout << "ClapTrap copy assigment operator called for: " << this->_name << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string const& name) : _name(name)
{
	std::cout << "ClapTrap constructor called for: " << this->_name << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor called for:" << this->_name << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name;
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is damaged by ";
	std::cout << amount << " points" << std::endl;
	this->_hp -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name;
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << " repaired itself with " << amount << " points" << std::endl;
		this->_hp += amount;
		this->_ep -= 1;
	}
	else
	{
		std::cout << " tried to repair itself, but it doesnt have enough ";
		if (this->_ep <= 0 && this->_hp > 0)
			std::cout << "Energy Points." << std::endl;
		else if (this->_ep > 0 && this->_hp <= 0)
			std::cout << "Hit Points." << std::endl;
		else
			std::cout << "Hit Points and Energy Points." << std::endl;
	}
	return ;
}

void	ClapTrap::printStatus() const
{
	std::cout << "ClapTrap " << this->_name << " status: ";
	std::cout << "HitPoints=" << this->_hp;
	std::cout << " EnergiePoints=" << this->_ep;
	std::cout << " AttackDamage=" << this->_ad << std::endl;
	return ;
}

const std::string&	ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getAD() const
{
	return (this->_ad);
}

int	ClapTrap::getHP() const
{
	return (this->_hp);
}

int	ClapTrap::getEP() const
{
	return (this->_ep);
}
