
#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	*this = src;
	// std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice& Ice::operator=(const Ice& src)
{
	//type wil be 'ice', so no need to copy the type
	(void)src;
	// std::cout << "Ice copy assignment operator called" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
	return ;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots a ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}