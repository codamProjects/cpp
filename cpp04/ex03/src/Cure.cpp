
#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	*this = src;
	// std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure& Cure::operator=(const Cure& src)
{
	//type wil be 'cure', so no need to copy the type
	(void)src;
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
	return ;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}