
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog &dog);
	~Dog();

	void	makeSound() const override;
	void	printBrain() const override;

private:
	Brain *_brain;

};

#endif