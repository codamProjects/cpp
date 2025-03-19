
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "Types.hpp"
# include "Colours.hpp"

class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter const& other) = delete;
		ScalarConverter& operator=(ScalarConverter const& scalarConverter) = delete;
		~ScalarConverter() = delete;
	
	public:
		static void	convert(std::string const& literal);
};

#endif