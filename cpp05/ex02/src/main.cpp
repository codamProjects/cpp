
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int	main(void) {
	try {
		Bureaucrat dwight(75);
		std::cout << dwight << std::endl;
		ShrubberyCreationForm scForm("sc_home");
		std::cout << scForm << std::endl;
		dwight.executeForm(scForm);
		dwight.signForm(scForm);
		std::cout << scForm << std::endl;
		dwight.executeForm(scForm);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	};
	std::cout << "\n------------\n\n";
	try {
		Bureaucrat dwight(46, "mr robo");
		std::cout << dwight << std::endl;
		RobotomyRequestForm rrForm("rr_home");
		std::cout << rrForm << std::endl;
		dwight.signForm(rrForm);
		dwight.executeForm(rrForm);
		std::cout << "increment bureaucrat by 1\n";
		dwight.incrementGrade();
		std::cout << dwight << std::endl;
		dwight.executeForm(rrForm);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	};
	std::cout << "\n------------\n\n";
	try {
		Bureaucrat dwight;
		std::cout << dwight << std::endl;
		PresidentialPardonForm ppForm("pp_home");
		std::cout << ppForm << std::endl;
		dwight.signForm(ppForm);
		std::cout << "increment bureaucrat by 51\n";
		dwight.incrementGrade(51);
		std::cout << dwight << std::endl;
		dwight.signForm(ppForm);
		std::cout << ppForm << std::endl;
		dwight.executeForm(ppForm);
		std::cout << "increment bureaucrat by 20\n";
		dwight.incrementGrade(20);
		std::cout << dwight << std::endl;
		dwight.executeForm(ppForm);
		std::cout << "decrement bureaucrat by 147\n";
		dwight.decrementGrade(147);
		std::cout << dwight << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	};
	return (0);
}
