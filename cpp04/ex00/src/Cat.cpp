
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat &cat)
{
	if (this != &cat)
		this->_type = cat.getType();
	std::cout << "Cat copy assignement operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "Miauw" << std::endl;
	return ;
}