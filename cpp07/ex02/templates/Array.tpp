
#include "Array.hpp"
#include <iostream>
#include "Colours.hpp"

template <typename T>
Array<T>::Array() : _size(0), _elements(new T[this->_size]()) { 
	//std::cout << BLUE << "Constructed an Array with length: " << this->_size << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _elements(new T[this->_size]()) { 
	//std::cout << BLUE << "Constructed an Array with length: " << this->_size << RESET<< std::endl;
}

template <typename T>
Array<T>::Array(Array const& other) {
	this->_size = other._size;
	this->_elements = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_elements[i] = other._elements[i];
	//std::cout << BLUE << "Copy constructed an Array with length: " << this->_size << RESET << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other) {
	if (this != &other) {
		delete[] (this->_elements);
		this->_size = other._size;
		this->_elements = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_elements[i] = other._elements[i];
	}
	//std::cout << BLUE << "Copy assigned an Array with length: " << this->_size << RESET << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array() { 
	delete[] (this->_elements);
	//std::cout << BLUE << "Deleted and destructed an Array" << RESET << std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= this->_size)
		throw OOBException();
	return (this->_elements[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= this->_size)
		throw OOBException();
	return (this->_elements[i]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template <typename T>
const char* Array<T>::OOBException::what() const noexcept { return ("index is out of bounds"); }
