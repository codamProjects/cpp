
#include "Colours.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>

template<typename T> void printArray(Array<T>& arr) {
	std::cout << "Array has size: " << arr.size() << ", its values are: [";
	for (unsigned i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
		if (i + 1 < arr.size())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main(void) {
	try {
		Array<std::string> emptyArr;
		::printArray(emptyArr);
		Array<std::string> strArray(20);
		for (unsigned int i = 0; i < strArray.size(); i++)
			strArray[i] = "\'value: " + std::to_string(i) + "\'";
		::printArray(strArray);
		emptyArr = strArray;
		strArray[0] = "other value: 0";
		std::cout << strArray[0] << std::endl;
		std::cout << emptyArr[0] << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try {
		Array<void *> voidArr(10);
		::printArray(voidArr);
		std::cout << voidArr[11];
	}
	catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try {
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i * 42;
		::printArray(arr);
		Array<int> newArr(arr);
		arr[0] = -42;
		std::cout << arr[0] << std::endl;
		std::cout << newArr[0] << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
}


// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }