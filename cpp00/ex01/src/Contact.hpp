
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	int			addContact(void);
	void		showContact(void) const;
	std::string firstname(void) const;
	std::string lastname(void) const;
	std::string nickname(void) const;
	std::string phonenumber(void) const;
	std::string darksecret(void) const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;
};

#endif
