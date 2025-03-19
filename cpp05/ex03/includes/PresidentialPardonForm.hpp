
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/AForm.hpp"
# include "../includes/Colours.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string	_target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ppform);
		virtual ~PresidentialPardonForm();

		const std::string	getTarget() const;

		void	execute(Bureaucrat const& executor) const override;
};

#endif