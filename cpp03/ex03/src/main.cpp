
#include "DiamondTrap.hpp"

// int	main(void)
// {
// 	DiamondTrap test2("test2");
// 	DiamondTrap test(test2);

// 	test.whoAmI();
// 	test.printStatus();
// 	test.FragTrap::printStatus();
// 	test.ScavTrap::printStatus();
// 	test.ClapTrap::printStatus();
// 	return 0;
// }

int	main(void)
{
	DiamondTrap jane("Jane");
	DiamondTrap john("John");

	john.printStatus();
	jane.printStatus();
	john.attack(jane.getName());
	jane.takeDamage(john.getAD());
	john.printStatus();
	jane.printStatus();

	DiamondTrap copyJohn(john);
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
	jane.FragTrap::highFivesGuys();
	jane.printStatus();
	john.whoAmI();
	john.printStatus();
	copyJohn.ScavTrap::guardGate();
	copyJohn.printStatus();
	return (0);
}