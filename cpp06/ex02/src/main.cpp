
#include "Base.hpp"

int main() {
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	delete (obj);
	// {
	// 	std::cout << "Testing with base class" << std::endl;
	// 	Base base;
	// 	identify(&base);
	// 	identify(base);
	// }
}
