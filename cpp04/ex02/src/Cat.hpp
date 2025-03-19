
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
public:
	Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat &cat);
	~Cat();

	void	makeSound() const override;
	void	printBrain() const override;

private:
	Brain *_brain;

};

#endif