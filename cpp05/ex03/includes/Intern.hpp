
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/Colours.hpp"

using Form = AForm;

class Intern {
	public:
		Intern();
		Intern(Intern const& intern);
		Intern& operator=(Intern const& intern);
		~Intern();

		Form*	makeForm(std::string const& form, std::string const& target);

		class NotFoundException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};
};

#endif