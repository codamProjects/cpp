
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_list[i] = nullptr;
	// std::cout << "MateriaSource default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_list[i] != nullptr)
				delete this->_list[i];
			if (src._list[i] != nullptr)
				this->_list[i] = src._list[i]->clone();
			else
				this->_list[i] = nullptr;
		}
	}
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i] != nullptr)
			delete this->_list[i];
	}
	// std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i] == nullptr)
		{
			this->_list[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_list[i] != nullptr && this->_list[i]->getType() == type)
			return (this->_list[i]->clone());
	}
	return (0);
}
