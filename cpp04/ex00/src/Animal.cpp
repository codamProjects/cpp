
#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal default constructor called for: " << this->getType() << std::endl;
	return ;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
	std::cout << "Animal copy constructor called for: " << this->getType() << std::endl;
	return ;
}

Animal&	Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->_type = animal.getType();
	std::cout << "Animal copy assignement operator called for: " << this->getType() << std::endl;
	return (*this);
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal constructor called for: " << this->getType() << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for: " << this->getType() << std::endl;
	return ;
}

const std::string& Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Unknown sound" << std::endl;
	return ;
}