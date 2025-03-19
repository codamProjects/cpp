
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../includes/Bureaucrat.hpp"
# include "../includes/Colours.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		AForm();

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& form);
		virtual ~AForm();
	
		class GradeTooHighException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception { 
			public:
				virtual const char* what() const noexcept;
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class FailedToOpenFileException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class RoboFailException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat const& bureaucrat);
		
		void				checkBeforeExec(Bureaucrat const& executor) const;
		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& outputStream, AForm const& form);

#endif