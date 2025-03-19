
#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Dwight"), _grade(75) { }

Bureaucrat::Bureaucrat(int grade) : _name("Dwight") {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this != &bureaucrat) 
		this->_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

const std::string	Bureaucrat::getName() const { return (this->_name); }
int					Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::incrementGrade(int value) { 
	if (this->_grade - value < 1)
		throw GradeTooHighException();
	if (this->_grade - value > 150)
		throw GradeTooLowException();
	this->_grade -= value; 
}

void	Bureaucrat::decrementGrade(int value) {
	if (this->_grade + value < 1)
		throw GradeTooHighException();
	if (this->_grade + value > 150)
		throw GradeTooLowException(); 
	this->_grade += value; 
}

void	Bureaucrat::incrementGrade() { 
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	if (this->_grade - 1 > 150)
		throw GradeTooLowException();
	this->_grade -= 1; 
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade + 1 < 1)
		throw GradeTooHighException();
	if (this->_grade + 1 > 150)
		throw GradeTooLowException(); 
	this->_grade += 1; 
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << YELLOW << this->getName() << GREEN << " signed " << YELLOW << form.getName() << RESET << std::endl;
	}
	catch (const std::exception& exception) {
		std::cout << YELLOW << this->getName() << RED << " couldn't sign " << YELLOW << form.getName() << RED << " because " << exception.what() << "." << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << YELLOW << this->getName() << GREEN << " executed " << YELLOW << form.getName() << RESET << std::endl; 
	}
	catch (const std::exception& exception) {
		std::cout << YELLOW << this->getName() << RED << " couldn't execute " << YELLOW << form.getName() << RED << " because " << exception.what() << "." << RESET << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept { return ("Bureaucrats grade is to high"); }
const char*	Bureaucrat::GradeTooLowException::what() const noexcept { return ("Bureaucrats grade is to low"); }

std::ostream& operator<<(std::ostream& outputStream, Bureaucrat const& bureaucrat) {
	outputStream << YELLOW << bureaucrat.getName() << RESET << ", bureaucrat grade " << GREEN << bureaucrat.getGrade() << "." << RESET;
	return (outputStream);
}