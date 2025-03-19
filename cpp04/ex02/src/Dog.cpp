
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	this->_brain = new Brain("cats");
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& dog) : AAnimal(dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog.getType();
		this->_brain = new Brain(*dog._brain);
	}
	std::cout << "Dog copy assignement operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "Woeff" << std::endl;
	return ;
}

void	Dog::printBrain() const
{
	std::cout << "Dogs brain address: " << this->_brain << "\n";
	this->_brain->printIdeas();
	return ;
}