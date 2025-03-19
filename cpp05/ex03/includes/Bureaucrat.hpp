
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/AForm.hpp"
# include "../includes/Colours.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat();

		class GradeTooHighException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade(int value);
		void				decrementGrade(int value);
		void				incrementGrade();
		void				decrementGrade();
	
		void				signForm(AForm& form);
		void				executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& outputStream, Bureaucrat const& bureaucrat);

#endif