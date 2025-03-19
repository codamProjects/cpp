
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	//Weapon club = Weapon("Stick");
	{
		Weapon club = Weapon("Sword");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Toothpick");
		bob.attack();
	}
	{
		Weapon club = Weapon("Knife");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Pen");
		jim.attack();
	}
	return (0);
}
