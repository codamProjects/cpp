
#include "BitcoinExchange.hpp"
#include <fstream>
#include <ctime>
#include <algorithm>

static void checkDate(Date const& date) {
	if (date.year < 1970)
		throw std::exception();
	if (date.month <= 0 || date.month > 12)
		throw std::exception();
	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = daysInMonth[date.month - 1];
	if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0))
		days = 29;
	if (date.day <= 0 || date.day > days)
		throw std::exception();
}

static std::string trimWhitespaces(std::string const& str) {
	std::string trimmed = str;
	  trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), trimmed.end());
	return(trimmed);
}

Date	parseDate(std::string const& key) {
	Date date;
	try {
		size_t i, j, k;
		std::string trimmedKey = trimWhitespaces(key);
		date.year = std::stoi(trimmedKey, &i);
		i < trimmedKey.size() && trimmedKey[i] == '-' ? i++ : throw std::exception();
		date.month = std::stoi(trimmedKey.substr(i), &j);
		i + j < trimmedKey.size() && trimmedKey[i + j] == '-' ? j++ : throw std::exception();
		date.day = std::stoi(trimmedKey.substr(i + j), &k);
		i + j + k == trimmedKey.size() && trimmedKey[i + j + k] == '\0' ? checkDate(date) : throw std::exception();
	} catch (const std::exception& e) {
		throw std::invalid_argument("bad date input => " + key);
	}
	return (date);
}

float	parseFloat(std::string const& value) {
	float f;
	try {
		size_t i;
		std::string trimmedValue = trimWhitespaces(value);
		if (trimmedValue.back() == 'f' || trimmedValue.back() == 'F')
			trimmedValue.pop_back();
		f = std::stof(trimmedValue, &i);
		if (i < trimmedValue.size())
			throw std::exception();
	} catch(const std::exception& e) {
		throw std::invalid_argument("bad value input => " + value);
	}
	return (f);
}

std::map<Date, float> const parseDataBase(std::string const& file_name, Date const& today) {
	std::map<Date, float> dataBase;
	std::string delimitter = ",";
	std::ifstream file(file_name);
	std::string line;
	
	if (!file.is_open())
		throw std::runtime_error("failed to open: " + file_name);
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::invalid_argument("database has invalid line format");
	while (std::getline(file, line)) {
		size_t pos = line.find(delimitter);
		if (!line.empty()) {
			std::string strKey = pos != std::string::npos ? line.substr(0, pos) : line;
			pos = pos != std::string::npos ? pos + delimitter.size() : line.size();
			std::string strValue = pos < line.size() ? line.substr(pos) : "";
			if (strValue.empty())
				throw std::invalid_argument("");
			Date key = parseDate(strKey);
			if (today < key)
				throw std::invalid_argument("invalid date in database");
			float value = parseFloat(strValue);
			dataBase[key] = value;
		}
	}
	return (dataBase);	
}

Date getTodaysDate() {
	Date today;
	std::time_t t = std::time(nullptr);
	std::tm* localTime = std::localtime(&t);
	today.year = localTime->tm_year + 1900;
	today.month = localTime->tm_mon + 1;
	today.day = localTime->tm_mday;
	return (today);
}

void	readInput(std::string const& input_file) {
	std::ifstream file(input_file);
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("failed to open: " + input_file);
	if (!std::getline(file, line))
		throw std::invalid_argument("empty file");
	if (line != "date | value")
		throw std::invalid_argument("input has invalid line format");

	std::string delimitter = " | ";
	BitcoinExchange btc;
	while (std::getline(file, line)) {
		size_t pos = line.find(delimitter);
		std::string date = pos != std::string::npos ? line.substr(0, pos) : line;
		pos = pos != std::string::npos ? pos + delimitter.size() : line.size();
		std::string value = pos < line.size() ? line.substr(pos) : "";
		btc.outputCalculations(date, value);
	}	
}
