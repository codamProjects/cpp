
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm::AForm("robotomy request", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm::AForm(other), _target(other._target) { }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rrform) {
	if (this != &rrform)
		AForm::operator=(rrform);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string	RobotomyRequestForm::getTarget() const { return(this->_target); }

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	this->checkBeforeExec(executor);
	std::cout << BLUE << "DDDRRRRRRRRRR\n" << RESET;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << GREEN << this->_target << " has been robotomized!" << RESET << std::endl;
	else
		throw RoboFailException();

}