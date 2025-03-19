
#include "../includes/AForm.hpp"

AForm::AForm(const std::string name, const int signGrade, const int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) { }

AForm&	AForm::operator=(const AForm& form) {
	if (this != &form)
		this->_isSigned = form._isSigned;
	return (*this);
}

AForm::~AForm() { }

const std::string	AForm::getName() const {return (this->_name); }
bool				AForm::getIsSigned() const {return (this->_isSigned); }
int					AForm::getSignGrade() const {return (this->_signGrade); }
int					AForm::getExecGrade() const {return (this->_execGrade); } 

void				AForm::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void				AForm::checkBeforeExec(Bureaucrat const& executor) const{
	if (!this->_isSigned)
		throw NotSignedException();
	if (this->_execGrade < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const noexcept { return ("Forms grade is to high"); }
const char*	AForm::GradeTooLowException::what() const noexcept { return ("Forms grade is to low"); }
const char* AForm::NotSignedException::what() const noexcept { return ("Form is not signed"); }
const char* AForm::FailedToOpenFileException::what() const noexcept { return ("Failed to create file"); }
const char*	AForm::RoboFailException::what() const noexcept { return ("robotomizing has failed"); }

std::ostream& operator<<(std::ostream& outputStream, AForm const& form) {
	outputStream << "Form " << YELLOW << form.getName() << RESET << " with sign grade '" << GREEN << form.getSignGrade() << RESET << "' and execute grade '" << GREEN << form.getExecGrade() << RESET << "', is ";
	if (!form.getIsSigned())
		outputStream << RED << "not ";
	else
		outputStream << GREEN;
	outputStream << "signed" << RESET;
	return (outputStream);
}