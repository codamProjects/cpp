
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("")
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << "ClapTrap copy constructor called for: " << this->getName() << std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (this != &claptrap)
	{
		this->_name = claptrap.getName();
		this->_hp = claptrap.getHP();
		this->_ep = claptrap.getEP();
		this->_ad = claptrap.getAD();
	}
	std::cout << "ClapTrap copy assigment operator called for: " << this->getName() << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string const& name) : _name(name)
{
	std::cout << "ClapTrap constructor called for: " << this->getName() << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor called for:" << this->getName() << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->getName();
	if (this->getEP() > 0 && this->getHP() > 0)
	{
		std::cout << " attacks " << target << ", causing ";
		std::cout << this->getAD() <<  " points of damage" << std::endl;
		this->_ep -= 1;
	}
	else
	{
		std::cout << " tried to attack " << target << ", but it doesnt have enough ";
		if (this->getEP() <= 0 && this->getHP() > 0)
			std::cout << "Energy Points" << std::endl;
		else if (this->getEP() > 0 && this->getHP() <= 0)
			std::cout << "Hit Points" << std::endl;
		else
			std::cout << "Hit Points and Energy Points" << std::endl;
	}
	return ; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " is damaged by ";
	std::cout << amount << " points" << std::endl;
	this->_hp -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName();
	if (this->getEP() > 0 && this->getHP() > 0)
	{
		std::cout << " repaired itself with " << amount << " points" << std::endl;
		this->_hp += amount;
		this->_ep -= 1;
	}
	else
	{
		std::cout << " tried to repair itself, but it doesnt have enough ";
		if (this->getEP() <= 0 && this->getHP() > 0)
			std::cout << "Energy Points." << std::endl;
		else if (this->getEP() > 0 && this->getHP() <= 0)
			std::cout << "Hit Points." << std::endl;
		else
			std::cout << "Hit Points and Energy Points." << std::endl;
	}
	return ;
}

void	ClapTrap::printStatus() const
{
	std::cout << "ClapTrap " << this->getName() << " status: ";
	std::cout << "HitPoints=" << this->getHP();
	std::cout << " EnergiePoints=" << this->getEP();
	std::cout << " AttackDamage=" << this->getAD() << std::endl;
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
