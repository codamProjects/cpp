
#include "wrongCat.hpp"

wrongCat::wrongCat() : wrongAnimal("wrongCat")
{
	std::cout << "wrongCat default constructor called" << std::endl;
	return ;
}

wrongCat::wrongCat(const wrongCat& wrongcat) : wrongAnimal(wrongcat)
{
	std::cout << "wrongCat copy constructor called" << std::endl;
	return ;
}

wrongCat& wrongCat::operator=(const wrongCat &wrongcat)
{
	if (this != &wrongcat)
		this->_type = wrongcat.getType();
	std::cout << "wrongCat copy assignement operator called" << std::endl;
	return (*this);
}

wrongCat::~wrongCat()
{
	std::cout << "wrongCat destructor called" << std::endl;
	return ;
}

void	wrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
	return ;
}