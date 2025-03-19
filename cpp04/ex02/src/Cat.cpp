
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	this->_brain = new Brain("dogs");
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& cat) : AAnimal(cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->_type = cat.getType();
		this->_brain = new Brain(*cat._brain);
	}
	std::cout << "Cat copy assignement operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "Miauw" << std::endl;
	return ;
}

void	Cat::printBrain() const
{
	std::cout << "Cats brain address: " << this->_brain << "\n";
	this->_brain->printIdeas();
	return ;
}