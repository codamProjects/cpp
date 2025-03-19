
#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("NoType")
{
	// std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria& src)
{
	*this = src;
	// std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}
	
AMateria&	AMateria::operator=(const AMateria& src)
{
	if (this != &src)
		this->_type = src._type;
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	// std::cout << "AMateria constructor called" << std::endl;
	return ;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
	return ;
}

std::string const&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "I dont know what to do to " << target.getName() << std::endl;
	return ;
}