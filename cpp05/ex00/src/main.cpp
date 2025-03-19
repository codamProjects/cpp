
#include "../includes/Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat dwight;
		std::cout << dwight << std::endl;
		std::cout << "increment with 1" << std::endl;
		dwight.incrementGrade();
		std::cout << dwight << std::endl;
		std::cout << "increment with 74" << std::endl;
		dwight.incrementGrade(74);
		std::cout << dwight << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "--------\n";
	try {
		Bureaucrat jim(10, "Jim");
		std::cout << jim << std::endl;
		std::cout << "decrement with 10" << std::endl;
		jim.decrementGrade(10);
		std::cout << jim << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "--------\n";
	try {
		Bureaucrat HIGH(151);
		std::cout << HIGH << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "--------\n";;
	try {
		Bureaucrat LOW(0);
		std::cout << LOW << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}