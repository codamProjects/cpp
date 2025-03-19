
#include <iostream>
#include <string>
#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::addContact(void)
{
	std::string firstBuf, lastBuf, nickBuf, phoneBuf, secretBuf;

	firstBuf = ft_getInput("Enter your first name: ");
	lastBuf = ft_getInput("Enter your last name: ");
	nickBuf = ft_getInput("Enter your nickname: ");
	phoneBuf = ft_getInput("Enter your phonenumber: ");
	secretBuf = ft_getInput("Enter your deepest secret: ");
	if (firstBuf.empty() || lastBuf.empty() || nickBuf.empty() 
			|| phoneBuf.empty() || secretBuf.empty())
	{
		std::cout << "Adding contact failed (one or more empty fields)" << std::endl;
		return (0);
	}
	firstName = firstBuf;
	lastName = lastBuf;
	nickName = nickBuf;
	phoneNumber = phoneBuf;
	secret = secretBuf;
	std::cout << "Your contact has been added" << std::endl;
	return (1);
}

void	Contact::showContact(void) const
{
	std::cout << "First name: " << firstName << "\n";
	std::cout << "Last name: " << lastName << "\n";
	std::cout << "Nick name: " << nickName << "\n";
	std::cout << "Phonenumber: " << phoneNumber << "\n";
	std::cout << "Secret: " << secret << std::endl;
	return;
}

std::string Contact::firstname(void) const
{
	return (firstName);
}

std::string Contact::lastname(void) const
{
	return (lastName);
}

std::string Contact::nickname(void) const
{
	return (nickName);
}

std::string Contact::phonenumber(void) const
{
	return (phoneNumber);
}

std::string Contact::darksecret(void) const
{
	return (secret);
}
