
#include "iter.hpp"
#include "Colours.hpp"
#include <iostream>

struct dataSet {
	std::string title;
	int isbn;
};

static void mississippi(const int& i) {
	std::cout << YELLOW << i << RESET << " mississippi ";
}

static void	multiply42(int& i) {
	i *= 42;
}

static void addPlusPlus(std::string& str) {
	str += "++";
}

static void	printStruct(const dataSet& data) {
	std::cout << "book: " << GREEN << data.title << RESET;
	std::cout << " with isbn: " << GREEN << data.isbn << RESET << std::endl;
}

template<typename T> void printValue(T value) {
	std::cout << value << " ";
}

int main(void) {
	{
		std::cout << BLUE << "start counting:\n" << RESET;
		int intArray[] = {1, 2, 3, 4, 5};
		::iter(intArray, 5, mississippi);
		std::cout << std::endl;
	}
	std::cout << "-----" << std::endl;
	{
		std::cout << BLUE << "print words with template:\n" << RESET;
		std::string words[] = {"aap", "noot", "mies", "wim"};
		size_t length = 4;
		::iter(words, length, ::printValue<std::string>);
		std::cout << std::endl;
		std::cout << BLUE << "print words with lambda function:\n" << RESET;
		::iter(words, length, [](const std::string& str) {std::cout << str << " ";});
		std::cout << std::endl;
	}
	std::cout << "-----" << std::endl;
	{
		int intArray[] = {0, 2, 4, 8, 16};
		std::cout << "before: ";
		::iter(intArray, 5, ::printValue<int>);
		std::cout << std::endl;
		::iter(intArray, 5, multiply42);
		std::cout << BLUE << "multiply by 42\n" << RESET  "after: ";
		::iter(intArray, 5, ::printValue<int>);
		std::cout << std::endl;
	}
	std::cout << "-----" << std::endl;
	{
		std::string words[] = {"a", "b", "c"};
		std::cout << "before: ";
		::iter(words, 3, ::printValue<std::string>);
		std::cout << std::endl;
		::iter(words, 3, addPlusPlus);
		std::cout << BLUE << "add ++\n" << RESET "after: ";
		::iter(words, 3, ::printValue<std::string>);
		std::cout << std::endl;
	}
	std::cout << "-----" << std::endl;
	{
		dataSet setArray[] = {{"book1", 123}, {"book2", 456}, {"book3", 789}};
		std::cout << "print dataSet:\n";
		::iter(setArray, 3, printStruct);
	}
}

