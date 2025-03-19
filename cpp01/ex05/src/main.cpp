
#include "Harl.hpp"
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
	std::string complaints[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};
	Harl harl;

	while (true)
	{
		int i = getRandomNumber(0, 5);
		if (i > 4)
			break ;
		std::cout << "Random complain level: '" << complaints[i] << "' gives output:\n\t";
		harl.complain(complaints[i]);
		std::cout << std::endl;
	}
	return (0);
}
