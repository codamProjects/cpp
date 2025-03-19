
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(const Contact& newContact);
	void	showContacts(void) const;

private:
	static const size_t		MAX = 8;
	Contact					contacts[MAX];
	size_t					index;
};

#endif
