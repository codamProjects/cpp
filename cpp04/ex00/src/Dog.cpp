
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		this->_type = dog.getType();
	std::cout << "Dog copy assignement operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "Woeff" << std::endl;
	return ;
}
