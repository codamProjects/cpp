
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
	int	index = 5;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case 0:
		{
			(this->*functions[0])();
			[[fallthrough]];
		}
		case 1:
		{
			(this->*functions[1])();
			[[fallthrough]];
		}
		case 2:
		{
			(this->*functions[2])();
			[[fallthrough]];
		}
		case 3:
		{
			(this->*functions[3])();
			break ;
		}
		default:
			std::cout << "Unknown comment level" << std::endl;
	}
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
