
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	const Animal* pets[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			pets[i] = new Dog();
		else
			pets[i] = new Cat();
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i += 2)
	{
		std::cout << pets[i]->getType() << "-sound: ";
		pets[i]->makeSound();
		pets[i]->printBrain();
		std::cout << "\n";
		std::cout << pets[i + 1]->getType() << "-sound: ";
		pets[i + 1]->makeSound();
		pets[i + 1]->printBrain();
		std::cout << "\n";
	}
	for (int i = 0; i < 4; i++)
		delete pets[i];

	std::cout << "\n";
	Dog *dog = new Dog();
	dog->setType("dog1");
	std::cout << "\n";
	Dog dog2 = *dog;
	dog2.setType("dog2");
	std::cout << "\n";
	Dog dog3(*dog);
	dog3.setType("dog3");
	std::cout << "\n";

	std::cout << dog->getType() << " address: " << dog << "\n";
	dog->printBrain();
	std::cout << "\n" << dog2.getType() << " address: " << &dog2 << "\n";
	dog2.printBrain();
	std::cout << "\n" << dog3.getType() << " address: " << &dog3 << "\n";
	dog3.printBrain();
	std::cout << "\n";

	delete dog;

	return (0);
}