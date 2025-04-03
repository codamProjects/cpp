
#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char *argv[]) {
	try {
		if (argc != 2)
			throw (std::runtime_error("program takes (only) one argument"));
		RPN rpn;
		rpn.processInput(argv[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);	
}