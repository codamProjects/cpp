
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;

	if (argc < 2)
		harl.complain("");
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (i != 1)
				std::cout << "\n";
			harl.complain(argv[i]);
		}
	}
	return (0);
}
