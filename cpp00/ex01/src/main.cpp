
#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "Your phonebook is empty.\n";
	while (true)
	{
		input = ft_getInput("Please choose one of the following actions: ADD, SEARCH or EXIT: ");
		if (input == "ADD")
		{
			Contact newContact;
			if (newContact.addContact())
				phoneBook.addContact(newContact);
		}
		else if (input == "SEARCH")
			phoneBook.showContacts();	
		else if (input == "EXIT")
			break ;
		else if (input.empty())
			std::cout << "Sorry, an empty field or the use of only whitespaces is not allowed." << std::endl;
		else
			std::cout << "Sorry '" << input << "' is not one of the options" << std::endl;
	}
	return (0);
}
