
#ifndef TYPES_HPP
# define TYPES_HPP

# include "Colours.hpp"
# include <string>
# include <iostream>
# include <stdexcept>
# include <sstream>
# include <limits>
# include <iomanip>
# include <cmath>

enum type {CHAR, INT, FLOAT, DOUBLE, INVALID};

class Types {
	private:
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		size_t		_afterDecPoint = 1;
		size_t		_beforeDecPoint = 1;
		std::string	_literal;
		std::string	_trimmedLit;

		Types() = delete;
		Types(Types const& other) = delete;
		Types& operator=(Types const& types) = delete;

	public:
		Types(std::string const& literal);
		~Types();

		void	convertChar();
		void	convertInt();
		void	convertFloat();
		void	convertDouble();
		
		type	getType();
		void	checkSpecial();
		void	checkInt();
		void	checkFloat();
		void	checkDouble();

		void	basicChecks();

		class	ParseException : public std::exception {
			private:
				std::string _message;
			public:
				explicit 	ParseException(const std::string& message);
				const char* what() const noexcept override;
		};
};

#endif