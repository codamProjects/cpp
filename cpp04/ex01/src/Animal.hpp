
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& animal);
	Animal& operator=(const Animal &animal);
	Animal(const std::string& type);
	virtual ~Animal();

	virtual void		makeSound() const;
	virtual void		printBrain() const;
	const std::string&	getType() const;
	void				setType(std::string type);

protected:
	std::string	_type;

};

#endif