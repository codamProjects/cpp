
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& brain);
	Brain& operator=(const Brain& brain);
	Brain(const std::string& word);
	~Brain();

	const std::string	*getIdeas() const;
	void				printIdeas() const;

private:
	std::string	_ideas[100];
};

#endif