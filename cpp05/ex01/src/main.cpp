
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void) {
	try {
		Bureaucrat	dwight(51);
		Form		form1("'Form1'", 50, 75);
		Form		form2("'Form2'", 1, 75);
		std::cout << dwight << std::endl;
		std::cout << form1 << std::endl;
		dwight.signForm(form1);
		std::cout << "increment Dwight's grade by 1" << std::endl;
		dwight.incrementGrade();
		std::cout << dwight << std::endl;
		dwight.signForm(form1);
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		dwight.signForm(form2);
		form2.beSigned(dwight);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
