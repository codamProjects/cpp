
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Ban nothing";
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << "Brain copy constructor called" << std::endl;
	return ;
}

Brain&	Brain::operator=(const Brain &brain)
{
	const std::string *buf;

	if (this != &brain)
	{
		buf = brain.getIdeas();
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = buf[i];
	}
	std::cout << "Brain copy assignement operator called" << std::endl;
	return (*this);
}

Brain::Brain(const std::string& word)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Ban " +  word;
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

const std::string	*Brain::getIdeas() const
{
	return (this->_ideas);
}

void	Brain::printIdeas() const
{
	std::cout << "First idea: ";
	std::cout << this->_ideas[0] << "\n";
	std::cout << "Last idea: ";
	std::cout << this->_ideas[99] << std::endl;
	return;
}