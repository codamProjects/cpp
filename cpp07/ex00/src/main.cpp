
#include "whatever.hpp"
#include <iostream>
#include <string>

# define RESET "\033[0m"
# define YEL "\033[33m"

// struct myType {
// 	int value;
// };

// class myClass {
// 	public:
// 		int data;
// 		myClass(int val) : data(val) {}
// };

int main(void) {
	std::cout << YEL << "test from subject:" << RESET<< std::endl;
	{
		int a = 2;
		int b = 3;
		
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
	
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	std::cout << YEL << "\nFloats:" << RESET << std::endl;
	{
		float a = 2.4f;
		float b = 2.6f;
		
		std::cout << "before swap -> a = " << a << ", b = " << b << std::endl; 
		::swap(a, b);
		std::cout << "after swap -> a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	std::cout << YEL << "\nVoid*:" << RESET << std::endl;
	{
		int buf;
		void* a = nullptr;
		void* b = &buf;
		
		std::cout << "before swap -> a = " << a << ", b = " << b << std::endl; 
		::swap(a, b);
		std::cout << "after swap -> a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	// {
	// 	myType a{10};
	// 	myType b{5};
 
	// 	::swap(a, b);
	// 	::max(a, b);
	// 	::min(a, b);
	// }
	// {
	// 	myClass a(10);
	// 	int b = 5;
 
	// 	::swap(a, b);
	// 	::max(a, b);
	// 	::min(a, b);
	// }
}