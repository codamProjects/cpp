
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int	main(void) {
	Intern	intern;
	Form	*robo = nullptr;
	Form	*president = nullptr;
	Form	*shrub = nullptr;
	Form	*other = nullptr;

	try {
		robo = intern.makeForm("robotomy request", "hello");
		std::cout << *robo << std::endl;
		president = intern.makeForm("presidential pardon", "bonjour");
		std::cout << *president << std::endl;
		shrub = intern.makeForm("shrubbery creation", "olla");
		std::cout << *shrub << std::endl;
		Bureaucrat dwight(shrub->getExecGrade());
		std::cout << dwight << std::endl;
		dwight.signForm(*shrub);
		dwight.executeForm(*shrub);
		other = intern.makeForm("other", "somewhere else");
		std::cout << *other << std::endl;

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete robo;
	delete president;
	delete shrub;
	delete other;
}
