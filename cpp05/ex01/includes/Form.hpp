
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/Bureaucrat.hpp"
# include "../includes/Colours.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		Form();

	public:
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& other);
		Form&	operator=(const Form& form);
		~Form();

		class GradeTooHighException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat const& bureaucrat);
};

std::ostream& operator<<(std::ostream& outputStream, Form const& form);

#endif