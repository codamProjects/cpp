
#include "ScalarConverter.hpp"

int main(int ac, char *av[]) {
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			ScalarConverter::convert(av[i]);
			std::cout << BLUE << "------------" << RESET << std::endl;
		}
	}
	else
		std::cout << RED << "provide arguments or run ./test.sh" << RESET << std::endl;
	return (0);
}