
#include "Span.hpp"
#include "Colours.hpp"
#include <vector>
#include <cmath>
#include <limits>
#include <random>
#include <algorithm>

Span::Span(unsigned int const N) : _N(N) {}

Span::Span(Span const& other) : _N(other._N), _container(other._container) {}

Span& Span::operator=(Span const& other) {
	if (this != &other) {
		this->_N = other._N;
		this->_container = other._container;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int const num) {
	if (this->_container.size() >= this->_N)
		throw fullException();
	this->_container.insert(num);
}

void	Span::fillUp(int min, int max) {
	if (this->_container.size() >= this->_N)
		throw fullException();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	while (this->_container.size() < this->_N)
		this->_container.insert(dist(gen));
}

int Span::shortestSpan() const {
	if (this->_container.size() <= 1)
		throw noSpanException();
	std::vector<int> dif(this->_container.size());
	std::adjacent_difference(this->_container.begin(), this->_container.end(), dif.begin(),
							[](int a, int b) { return (std::abs(a - b)); });
	return (*std::min_element(dif.begin() + 1, dif.end()));
}

int Span::longestSpan() const {
	if (this->_container.size() <= 1)
		throw noSpanException();
	return (*std::prev(this->_container.end()) - *this->_container.begin());
}

std::multiset<int> const& Span::getContainer() const { return (this->_container); }

const char*	Span::fullException::what() const noexcept { return ("list is already full"); }
const char* Span::noSpanException::what() const noexcept { return ("not enough data to create a span"); }
const char* Span::addRequestToLargeException::what() const noexcept { return ("range of iterators to big too add"); }

std::ostream& operator<<(std::ostream& os, Span const& container) {
	std::multiset<int> pC = container.getContainer();
	std::cout << "Container content: " << GREEN << "[";
	for (std::multiset<int>::iterator iC = pC.begin(); iC != pC.end(); iC++) {
		if (iC != pC.begin())
			std::cout << ", ";
		std::cout << *iC;
	}
	std::cout << "]" << RESET << std::endl;
	return (os);
}