
#include "PmergeMe.hpp"

#include <iostream>
#include <exception>

static void	printResult(PmergeMe<std::vector> const& vec, PmergeMe<std::list> const& lst) {
	std::cout << "Before:";
	for (int token : vec.getOriginal())
		std::cout << " " << token;
	std::cout << "\nAfter: ";
	for (int token : lst.getSorted())
		std::cout << " " << token;
	std::cout << "\n";
	std::cout << "Time to process a range of " << vec.getOriginal().size();
	std::cout << " elements with std::<vector> : " << vec.getDuration() << " us\n";
	std::cout << "Time to process a range of " << lst.getOriginal().size();
	std::cout << " elements with std::<list> : " << lst.getDuration() << " us" << std::endl;
}

int main(int argc, char *argv[]) {
	try {
		if (argc < 2)
			throw (std::runtime_error("no arguments passed"));
		PmergeMe<std::vector> vec;
		vec.sortC(argc, argv);
		PmergeMe<std::list> lst;
		lst.sortC(argc, argv);
		printResult(vec, lst);		
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}