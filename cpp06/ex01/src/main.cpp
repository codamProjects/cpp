
#include "Serializer.hpp"
#include <iostream>
#include "Colours.hpp"

int main() {
	{
		Data	data;
		Data*	orgData = &data;

		std::cout << "orgData: " << YELLOW << orgData << RESET << std::endl;
		std::cout << "orgData->content: " << BLUE << orgData->content << RESET << std::endl;
		const uintptr_t raw = Serializer::serialize(orgData);
		std::cout << "uintptr_t: " << YELLOW << raw << RESET << std::endl;
		Data* newData = Serializer::deserialize(raw);
		std::cout << "newData: " << YELLOW << newData << RESET << std::endl;
		std::cout << "newData->content: " << BLUE << newData->content << RESET << std::endl;
	}
	std::cout << std::endl;
	{
		Data* orgData = new Data;

		orgData->content = "hello world";
		std::cout << "orgData: " << YELLOW << orgData << RESET << std::endl;
		std::cout << "orgData->content: " << BLUE << orgData->content << RESET << std::endl;
		uintptr_t raw = Serializer::serialize(orgData);
		std::cout << "uintptr_t: " << YELLOW << raw << RESET << std::endl;
		Data* otherData = Serializer::deserialize(raw);
		std::cout << "otherData: " << YELLOW << otherData << RESET << std::endl;
		std::cout << "otherData->content: " << BLUE << otherData->content << RESET << std::endl;
		otherData->content = "hello moon";
		std::cout << "changed otherData->content: " << BLUE << otherData->content << RESET << std::endl;
		raw = Serializer::serialize(otherData);
		std::cout << "uintptr_t: " << YELLOW << raw << RESET << std::endl;	
		orgData = Serializer::deserialize(raw);
		std::cout << "orgData: " << YELLOW << orgData << RESET << std::endl;
		std::cout << "orgData->content: " << BLUE << orgData->content << RESET << std::endl;
		delete (orgData);
	}
}