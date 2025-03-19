
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm::AForm("presidential pardon", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm::AForm(other), _target(other._target) { }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ppform) {
	if (this != &ppform)
		AForm::operator=(ppform);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

const std::string	PresidentialPardonForm::getTarget() const { return(this->_target); }

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	this->checkBeforeExec(executor);
	std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
}