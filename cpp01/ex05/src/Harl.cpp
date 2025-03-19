
#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Unknown comment level" << std::endl;
	return ;
}

void	Harl::_debug(void)
{
	std::cout << "Debug message\n";
	return ;
}

void	Harl::_info(void)
{
	std::cout << "Info message\n";
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "Warning message\n";
	return ;
}

void	Harl::_error(void)
{
	std::cout << "Error message\n";
	return ;
}
