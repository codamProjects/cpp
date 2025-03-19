
#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout <<"Adresses:\n\t";
	std::cout << "string: " << &str << "\n\t";
	std::cout << "stringPTR: " << stringPTR << "\n\t";
	std::cout << "stringREF: " << &stringREF << "\n";
	std::cout << "Values:\n\t";
	std::cout << "string: " << str << "\n\t";
	std::cout << "stringPTR: " << *stringPTR << "\n\t";
	std::cout << "stringREF: " << stringREF << "\n";
	str = "HELLO";
	std::cout <<"Adresses:\n\t";
	std::cout << "string: " << &str << "\n\t";
	std::cout << "stringPTR: " << stringPTR << "\n\t";
	std::cout << "stringREF: " << &stringREF << "\n";
	std::cout << "Values:\n\t";
	std::cout << "string: " << str << "\n\t";
	std::cout << "stringPTR: " << *stringPTR << "\n\t";
	std::cout << "stringREF: " << stringREF << "\n";
	return (0);
}
