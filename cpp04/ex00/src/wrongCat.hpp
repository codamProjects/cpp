
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "wrongAnimal.hpp"

class wrongCat: public wrongAnimal
{
public:
	wrongCat();
	wrongCat(const wrongCat& wrongcat);
	wrongCat& operator=(const wrongCat &wrongcat);
	~wrongCat();

	void	makeSound() const;
};

#endif