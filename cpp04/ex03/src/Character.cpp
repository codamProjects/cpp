
#include "Character.hpp"
#include <iostream>

Character::Character() : _name("NoName")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	// std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(const Character& src)
{
	*this = src;
	// std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != nullptr)
				delete this->_inventory[i];
			if (src._inventory[i] != nullptr)
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = nullptr;
		}
		this->copyBin(src._bin, src._binSize);
	}
	// std::cout << "Character copy assignment operator called" << std::endl;
	return (*this);
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	// std::cout << "Character constructor called" << std::endl;
	return ;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
	}
	if (this->_bin != nullptr)
	{
		for (unsigned int i = 0; i < this->_binSize; i++)
			delete this->_bin[i];
		delete [] this->_bin;
	}
	// std::cout << "Character destructor called" << std::endl;
	return ;
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	this->addToBin(m);
	return ;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx] != nullptr)
	{
		this->addToBin(this->_inventory[idx]);
		this->_inventory[idx] = nullptr;
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx] != nullptr)
		this->_inventory[idx]->use(target);
	return ;
}

void	Character::copyBin(AMateria** bin, unsigned int size)
{
	if (this->_bin != nullptr)
	{
		for (int i = 0; this->_bin[i] != nullptr; i++)
			delete this->_bin[i];
		delete [] this->_bin;
	}
	this->_bin = nullptr;
	this->_binSize = size;
	if (size <= 0)
		return ;
	this->_bin = new AMateria*[this->_binSize + 1];
	for (unsigned int i = 0; i < this->_binSize; i++)
		this->_bin[i] = bin[i]->clone();
	this->_bin[this->_binSize] = nullptr;
	return ;
}

void	Character::addToBin(AMateria* m)
{
	AMateria**	newBin;

	newBin = new AMateria*[this->_binSize + 2];
	for (unsigned int i = 0; i < _binSize; i++)
		newBin[i] = this->_bin[i];
	newBin[this->_binSize] = m;
	newBin[this->_binSize + 1] = nullptr;
	if (this->_bin != nullptr)
		delete [] this->_bin;
	this->_bin = newBin;
	this->_binSize++;
	return ;	
}
