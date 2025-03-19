
#include "../includes/Intern.hpp"

Intern::Intern() { }
Intern::Intern(Intern const& other) { (void)other; }
Intern&	Intern::operator=(Intern const& intern) { (void)intern; return (*this); }
Intern::~Intern() { }

Form*	Intern::makeForm(std::string const& form, std::string const& target) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	int 	index = 0;
	for (int i = 0; i < 3; i++) {
		if (forms[i] == form) {
			index = i + 1;
			break ;
		}
	}
	switch (index) {
		case 1: {
			std::cout << "Intern creates " << YELLOW << form << RESET << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 2: {
			std::cout << "Intern creates " << YELLOW << form << RESET << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 3: {
			std::cout << "Intern creates " << YELLOW << form << RESET << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default:
			throw NotFoundException();
	}
}

const char*	Intern::NotFoundException::what() const noexcept { return ("Intern couldn't find the form"); }