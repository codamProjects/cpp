
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/AForm.hpp"
# include <cstdlib>
# include <ctime>
# include "../includes/Colours.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string	_target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& rrform);
		virtual ~RobotomyRequestForm();

		const std::string	getTarget() const;

		void	execute(Bureaucrat const& executor) const override;
};

#endif