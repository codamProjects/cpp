
#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string const& literal) {
	Types	literalType(literal);

	switch (literalType.getType()) {
		case CHAR:
			std::cout << "Input: " << YELLOW << literal << RESET << " = ";
			std::cout << GREEN << "Char" << RESET << std::endl;
			literalType.convertChar();
			break ;
		case INT:
			std::cout << "Input: " << YELLOW << literal << RESET << " = ";
			std::cout << GREEN << "Int" << RESET << std::endl;
			literalType.convertInt();
			break ;
		case FLOAT:
			std::cout << "Input: " << YELLOW << literal << RESET << " = ";
			std::cout << GREEN << "Float" << RESET << std::endl;
			literalType.convertFloat();
			break ;
		case DOUBLE:
			std::cout << "Input: " << YELLOW << literal << RESET << " = ";
			std::cout << GREEN << "Double" << RESET << std::endl;
			literalType.convertDouble();
			break ;
		case INVALID:
			std::cout << "Input: " << YELLOW << literal << RESET << " = ";
			std::cout << RED << "Invalid input" << RESET << std::endl;
			break ;
	}
	return ;
}
