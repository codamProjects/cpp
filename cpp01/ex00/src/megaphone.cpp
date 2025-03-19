
#include <iostream>

int	main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << " ";
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)(toupper(argv[i][j]));
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return 0;
}
