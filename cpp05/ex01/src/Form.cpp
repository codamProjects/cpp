
#include "../includes/Form.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) { }

Form&	Form::operator=(const Form& form) {
	if (this != &form)
		this->_isSigned = form._isSigned;
	return (*this);
}

Form::~Form() { }

const std::string	Form::getName() const {return (this->_name); }
bool				Form::getIsSigned() const {return (this->_isSigned); }
int					Form::getSignGrade() const {return (this->_signGrade); }
int					Form::getExecGrade() const {return (this->_execGrade); } 

void				Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const noexcept { return ("Forms grade is to high"); }
const char*	Form::GradeTooLowException::what() const noexcept { return ("Forms grade is to low"); }

std::ostream& operator<<(std::ostream& outputStream, Form const& form) {
	outputStream << "Form " << YELLOW << form.getName() << RESET << " with sign grade '" << GREEN << form.getSignGrade() << RESET << "' and execute grade '" << GREEN << form.getExecGrade() << RESET << "', is ";
	if (!form.getIsSigned())
		outputStream << RED << "not ";
	else
		outputStream << GREEN;
	outputStream << "signed" << RESET;
	return (outputStream);
}