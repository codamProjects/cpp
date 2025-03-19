
#include "Base.hpp"

Base::~Base() {}

Base*	generate(void) {
	srand(time(0));
	int random = rand() % 4;
	std::cout << "generated an instance of: ";
	if (random == 0) {
		std::cout << YELLOW << "\"A\"" << RESET << std::endl;
		return (new A);
	}
	else if (random == 1) {
		std::cout << YELLOW << "\"B\"" << RESET << std::endl;
		return (new B);
	}
	else {
		std::cout << YELLOW << "\"C\"" << RESET << std::endl;
		return (new C);
	}
}

void	identify(Base* p) {
	std::cout << "indentified pointer as instance of: ";
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "\"A\"" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "\"B\"" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "\"C\"" << RESET << std::endl;
	else
		std::cout << RED << "Unknow type" << RESET << std::endl;
}

void	identify(Base& p) {
	std::cout << "indentified reference as instance of: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE << "\"A\"" << RESET << std::endl;
		return ;
	} catch (const std::bad_cast&) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BLUE << "\"B\"" << RESET << std::endl;
		return ;
	} catch (const std::bad_cast&) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BLUE << "\"C\"" << RESET << std::endl;
		return ;
	} catch (const std::bad_cast&) { }
	std::cout << RED << "Unknow type" << RESET << std::endl;	
}