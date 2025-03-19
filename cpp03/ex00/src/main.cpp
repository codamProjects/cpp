
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap jane("Jane");
	ClapTrap john("John");

	john.printStatus();
	jane.printStatus();
	john.attack(jane.getName());
	jane.takeDamage(john.getAD());
	john.printStatus();
	jane.printStatus();

	ClapTrap copyJohn(john);
	copyJohn.printStatus();

	copyJohn = jane;
	copyJohn.printStatus();
	while (jane.getEP() > 0)
	{
		jane.attack(john.getName());
		john.takeDamage(jane.getAD());
	}
	jane.attack(john.getName());
	jane.printStatus();
	john.printStatus();
	copyJohn.printStatus();
	return (0);
}