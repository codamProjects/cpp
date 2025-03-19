
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap jane("Jane");
	ScavTrap john("John");

	john.printStatus();
	jane.printStatus();
	john.attack(jane.getName());
	jane.takeDamage(john.getAD());
	john.printStatus();
	jane.printStatus();

	ScavTrap copyJohn(john);
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
	jane.guardGate();
	jane.printStatus();
	john.guardGate();
	john.printStatus();
	copyJohn.guardGate();
	copyJohn.printStatus();
	return (0);
}