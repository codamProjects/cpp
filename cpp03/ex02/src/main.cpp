
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap jane("Jane");
	FragTrap john("John");

	john.printStatus();
	jane.printStatus();
	john.attack(jane.getName());
	jane.takeDamage(john.getAD());
	john.printStatus();
	jane.printStatus();

	FragTrap copyJohn(john);
	copyJohn.printStatus();

	copyJohn = jane;
	copyJohn.printStatus();
	while (john.getHP() > 0 && john.getEP() > 0 && jane.getHP() > 0 && jane.getEP() > 0)
	{
		jane.attack(john.getName());
		john.takeDamage(jane.getAD());
	}
	jane.attack(john.getName());
	john.takeDamage(jane.getAD());
	john.beRepaired(john.getAD());
	jane.highFivesGuys();
	jane.printStatus();
	john.highFivesGuys();
	john.printStatus();
	copyJohn.highFivesGuys();
	copyJohn.printStatus();
	return (0);
}