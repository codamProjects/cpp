
#include <iostream>
#include <string>
#include "utils.hpp"

void	ft_tableInput(const std::string rowData)
{
	const size_t len = rowData.length();

	if (len == 10)
		std::cout << rowData << "|";
	else if (len > 10)
		std::cout << rowData.substr(0, 9) << ".|";
	else
		std::cout << std::string(10 - len, ' ') << rowData << "|";
	return;
}


std::string ft_trim(const std::string &input)
{
	size_t start = input.find_first_not_of(" \t\n\r");
	size_t end = input.find_last_not_of(" \t\n\r");

	if (start == std::string::npos && end == std::string::npos)
		return "";
	return input.substr(start, (end - start + 1));
}

std::string ft_getInput(const std::string output)
{
	std::string str;

	std::cout << output;
	std::getline(std::cin, str);
	str = ft_trim(str);
	return str;
}