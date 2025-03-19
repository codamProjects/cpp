
#include "Animal.hpp"

AAnimal::AAnimal() : _type("Unknown")
{
	std::cout << "AAnimal default constructor called for: " << this->getType() << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& aanimal)
{
	*this = aanimal;
	std::cout << "AAnimal copy constructor called for: " << this->getType() << std::endl;
	return ;
}

AAnimal&	AAnimal::operator=(const AAnimal &aanimal)
{
	if (this != &aanimal)
		this->_type = aanimal.getType();
	std::cout << "AAnimal copy assignement operator called for: " << this->getType() << std::endl;
	return (*this);
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
	std::cout << "AAnimal constructor called for: " << this->getType() << std::endl;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called for: " << this->getType() << std::endl;
	return ;
}

const std::string& AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
	return ;
}
