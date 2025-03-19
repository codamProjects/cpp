
#include "Zombie.hpp"
#include <random>

static int	getRandomNumber(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return (distribution(gen));
}

int	main(void)
{
	Zombie		*zombies;
	std::string	name;
	int			n;

	name = "Donald";
	n = getRandomNumber(1, 10);
	zombies = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}