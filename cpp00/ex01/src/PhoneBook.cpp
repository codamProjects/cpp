
#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::addContact(const Contact& newContact)
{
	contacts[index] = newContact;
	index = (index + 1) % MAX;
	return;	
}

void	PhoneBook::showContacts(void) const
{
	const std::string line = "---------------------------------------------\n";
	int	size = -1;
	std::string input;

	if (contacts[0].firstname().empty())
	{
		std::cout << "Your phonebook is empty, use 'ADD' to add a contact." << std::endl;
		return;
	}
	std::cout << line << "|     Index|First name| Last name|  Nickname|\n" << line;
	for (int i = 0; i < (int)MAX; i++)
	{
		if (contacts[i].firstname().empty())
			break ;
		std::cout << "|" << std::string(9, ' ') << i << "|";
		ft_tableInput(contacts[i].firstname());
		ft_tableInput(contacts[i].lastname());
		ft_tableInput(contacts[i].nickname());
		std::cout << "\n" << line;
		size += 1;
	}
	std::cout << "To get more information of one of your contacts ";
	std::string output = "please type the corresponding index number in the range of 0:" + std::to_string(size) + ": ";
	input = ft_getInput(output);
	if (input.length() == 1 && ((int)(input[0] - '0') <= size && (int)(input[0] - '0') >= 0))
		contacts[(int)(input[0] - '0')].showContact();
	else
		std::cout << "This is not a valid index number." << std::endl;
	return;
 }
