
#include "wrongAnimal.hpp"

wrongAnimal::wrongAnimal() : _type("Unknown")
{
	std::cout << "wrongAnimal default constructor called for: " << this->getType() << std::endl;
	return ;
}

wrongAnimal::wrongAnimal(const wrongAnimal& wronganimal)
{
	*this = wronganimal;
	std::cout << "wrongAnimal copy constructor called for: " << this->getType() << std::endl;
	return ;
}

wrongAnimal&	wrongAnimal::operator=(const wrongAnimal &wronganimal)
{
	if (this != &wronganimal)
		this->_type = wronganimal.getType();
	std::cout << "wrong Animal copy assignement operator called for: " << this->getType() << std::endl;
	return (*this);
}

wrongAnimal::wrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "wrongAnimal constructor called for: " << this->getType() << std::endl;
	return ;
}

wrongAnimal::~wrongAnimal()
{
	std::cout << "wrongAnimal destructor called for: " << this->getType() << std::endl;
	return ;
}

const std::string&	wrongAnimal::getType() const
{
	return (this->_type);
}

void	wrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
	return ;
}