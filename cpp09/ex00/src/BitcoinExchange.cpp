
#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() { 
	this->_today = getTodaysDate();
	this->_dataBase = parseDataBase(DATABASE, this->_today);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::outputCalculations(std::string const& d, std::string const& v) {
	try {
		if (v.empty() && d.empty())
			throw std::invalid_argument("bad input => empty line");
		if (v.empty())	
			throw std::invalid_argument("bad input => " + d);
		Date date = parseDate(d);
		float value = parseFloat(v);
		if (value < 0)
			throw std::invalid_argument("not a positive number");
		if (value > 1000)
			throw std::invalid_argument("too large a number");
		auto i = this->_dataBase.lower_bound(date);
		if (i == this->_dataBase.begin() && date < i->first)
			throw std::invalid_argument("date");
		if (i == this->_dataBase.end() || date < i->first)
			i--;
		float newValue = i->second * value;
		std::cout << d << " => " << v << " = " << newValue << std::endl;
	} catch(const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
