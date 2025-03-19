
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/AForm.hpp"
# include <fstream>
# include "../includes/Colours.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scform);
		virtual ~ShrubberyCreationForm();

		const std::string	getTarget() const;

		void	execute(Bureaucrat const& executor) const override;
};

#endif