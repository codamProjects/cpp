
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal& aanimal);
	AAnimal& operator=(const AAnimal &aanimal);
	AAnimal(const std::string& type);
	virtual ~AAnimal();

	virtual void		makeSound() const = 0;
	virtual void		printBrain() const = 0;
	const std::string&	getType() const;
	void				setType(std::string type);

protected:
	std::string	_type;

};

#endif