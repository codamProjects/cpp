
#include "Dog.hpp"
#include "Cat.hpp"
#include "wrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const wrongAnimal *wrongA = new wrongAnimal();
	const wrongAnimal *wrongC = new wrongCat();
	std::cout << wrongA->getType() << std::endl;
	std::cout << wrongC->getType() << std::endl;
	wrongA->makeSound();
	wrongC->makeSound();
	delete wrongA;
	delete wrongC;
	return (0);
}