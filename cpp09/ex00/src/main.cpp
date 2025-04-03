
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	try {
		if (argc != 2)
			throw (std::runtime_error("invalid amount of arguments"));
		readInput(argv[1]);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
