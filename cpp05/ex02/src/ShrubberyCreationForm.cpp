
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm::AForm("shrubbery creation", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm::AForm(other), _target(other._target) { }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scform) {
	if (this != &scform)
		AForm::operator=(scform);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string	ShrubberyCreationForm::getTarget() const { return(this->_target); }

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	std::string filename = this->_target + "_shrubbery";
	std::string tree = "   *      *      *   \n";
	tree += "  ***    ***    ***  \n";
	tree += " *****  *****  ***** \n";
	tree += "*********************\n";
	tree += "  |||    |||    |||  \n";
	
	this->checkBeforeExec(executor);
	
	std::ofstream file(filename);
	if (!file.is_open())
		throw FailedToOpenFileException();
	
	file << tree << std::endl;
	file.close();
}