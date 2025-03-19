
#include "Span.hpp"
#include "Colours.hpp"
#include <iostream>

#include <vector>
#include <list>
#include <map>
#include <string>
#include <deque>
#include <limits>
#include <algorithm>

static int otherMaxSpan(std::multiset<int> const& m) {
	auto min = std::min_element(m.begin(), m.end());
	auto max = std::max_element(m.begin(), m.end());
	//std::cout << BLUE << "smallest int in set: " << *min << ", largest int in set: " << *max << RESET << std::endl;
	return (*max - *min);
}

static int otherMinSpan(std::multiset<int> const& m) {
	//int min = *std::min_element(m.begin(), m.end());
	//int max = *std::max_element(m.begin(), m.end());
	int shortSpan = std::numeric_limits<int>::max();
	for (auto i = m.begin(); std::next(i) != m.end(); i++) {
		if (shortSpan > *std::next(i) - *i) {
			//min = *i;
			//max = *std::next(i);
			shortSpan = std::min(shortSpan, *std::next(i) - *i);
		}
	}
	//std::cout << BLUE << "int with smallest difference: " << min << " and " << max << RESET << std::endl;
	return (shortSpan);
}

int main(void) {
	try {
		std::cout << YELLOW << "subject test:" << RESET << std::endl;
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << "---------" << std::endl;
	try {
		unsigned int N = 100000;
		std::cout << YELLOW << "test N=" << N << " in range min/max int" << RESET << std::endl;
		Span span = Span(N);

		span.fillUp(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
		std::cout << "shortest span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		std::cout << "other shortest span " << otherMinSpan(span.getContainer()) << ", other longest span: " << otherMaxSpan(span.getContainer()) << std::endl;

	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << "---------" << std::endl;
	try {
		std::cout << YELLOW << "test set with all 10's" << RESET << std::endl;
		Span span = Span(10);
		std::multiset<int> multiset ={10, 10, 10, 10, 10, 10, 10, 10, 10};
		span.addContainer(multiset);
		std::cout << "shortest span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		std::cout << YELLOW << "test set with all min span 1000" << RESET << std::endl;
		Span span1 = Span(10);
		std::multiset<int> set ={100000, -1000, -2050, -6000, 7000, 20, -3050};
		span1.addContainer(set);
		std::cout << "shortest span: " << span1.shortestSpan() << ", longest span: " << span1.longestSpan() << std::endl;		
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << "---------" << std::endl;
	{
		std::cout << YELLOW << "test N=0 set" << RESET << std::endl;
		Span span = Span(0);
		std::cout << "try get shortest span: ";
		try { std::cout << span.shortestSpan() << std::endl; } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try get longest span: ";
		try { std::cout << span.shortestSpan() << std::endl; } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try add int: ";
		try { span.addNumber(10); } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try add range of iterators: ";
		std::multiset<int> newSet {1, -100, 124, 41611, 2525242, 0, -41452};
		try { span.addContainer(newSet); } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
	}
	std::cout << "---------" << std::endl;
	{
		std::cout << YELLOW << "test N=1 set" << RESET << std::endl;
		Span span = Span(1);
		std::cout << "try add range of iterators: ";
		std::multiset<int> newSet {1, -100, 124, 41611, 2525242, 0, -41452};
		try { span.addContainer(newSet); } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << YELLOW << "add int" << RESET << std::endl;;
		try { span.addNumber(10); } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try add extra int: ";
		try { span.addNumber(10); } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try get shortest span: ";
		try { std::cout << span.shortestSpan() << std::endl; } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
		std::cout << "try get longest span: ";
		try { std::cout << span.shortestSpan() << std::endl; } catch (const std::exception& e) { std::cout << RED << "Error: " << e.what() << RESET << std::endl; }
	}
	std::cout << "---------" << std::endl;
	try {
		std::cout << YELLOW << "test adding different containers: " << RESET << std::endl;
		Span span(10000);
		span.addNumber(-10000);
		span.addNumber(10000);
		std::cout << span << "shortes span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		std::vector<int> vec = {-20001, 20000};
		std::list<int> lst = {-100, 100, 0};
		std::deque<int> dq = {-100000, 0};
		std::set<int> s = {};
		span.addContainer(vec);
		std::cout << span << "shortes span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		span.addContainer(lst);
		std::cout << span << "shortes span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		span.addContainer(dq);
		std::cout << span << "shortes span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
		span.addContainer(s);
		std::cout << span << "shortes span: " << span.shortestSpan() << ", longest span: " << span.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << "---------" << std::endl;
	try {
		for (int j = 0; j < 20; j++) {
			unsigned int N = 100000;
			//std::cout << YELLOW << "test size " << N << " in range min/max int, compare output to other spancalculator" << RESET << std::endl;
			Span span = Span(N);

			span.fillUp(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
			if(span.shortestSpan() != otherMinSpan(span.getContainer()) || span.longestSpan() != otherMaxSpan(span.getContainer()))
			 	std::cout << RED << "output did not match" << RESET << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}
