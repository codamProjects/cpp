
#include "Colours.hpp"
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>
#include <map>
#include <set>
#include <iostream>

static void found(int search, int first) {
	std::cout << GREEN << "int " << search << " found in container on index " << first << RESET << std::endl;
}

static void notFound(int search) {
	std::cout << RED << "int " << search << " not found in container" << RESET << std::endl;
}

int main(void) {
	{
		std::vector<int> const numVec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
		auto i = easyfind(numVec, 7);
		i == numVec.cend() ? notFound(7) : found(*i, std::distance(numVec.cbegin(), i));
		auto j = easyfind(numVec, 0);
		j == numVec.cend() ? notFound(0) : found(*j, std::distance(numVec.cbegin(), j));
		auto const k = easyfind(numVec, 10);
		k == numVec.cend() ? notFound(10) : found(*k, std::distance(numVec.cbegin(), k));
	}
	std::cout << "------------" << std::endl;
	{
		std::list<int> lst = {42};
		auto i = easyfind(lst, 43);
		i == lst.cend() ? notFound(43) : found(*i, std::distance(lst.cbegin(), i));
		auto j = easyfind(lst, 42);
		j == lst.cend() ? notFound(42) : found(*j, std::distance(lst.cbegin(), j));
	}
	std::cout << "------------" << std::endl;
	{
		std::deque<int> emptyDeque = {};
		auto i = easyfind(emptyDeque, 7);
		i == emptyDeque.cend() ? notFound(7) : found(*i, std::distance(emptyDeque.cbegin(), i));
	}
	std::cout << "------------" << std::endl;
	{
		std::string str = {'a', 'b', 'b', 'd'};
		auto i = easyfind(str, 'b');
		i == str.cend() ? notFound('b') : found(*i, std::distance(str.cbegin(), i));
	}
	std::cout << "------------" << std::endl;
	{
		std::forward_list<int> forwList = {-1, 100, -2, 0, 0};
		auto i = easyfind(forwList, 2);
		i == forwList.cend() ? notFound(2) : found(*i, std::distance(forwList.cbegin(), i));
		auto j = easyfind(forwList, 0);
		j == forwList.cend() ? notFound(0) : found(*j, std::distance(forwList.cbegin(), j));
	}
	std::cout << "------------" << std::endl;
	{
		std::array<int, 5> numArr = {-42, 42, -42, 42, -42};
		
		auto i = easyfind(numArr, 43);
		i == numArr.cend() ? notFound(43) : found(*i, std::distance(numArr.cbegin(), i));
		auto j = easyfind(numArr, 42);
		j == numArr.cend() ? notFound(42) : found(*j, std::distance(numArr.cbegin(), j));
	}
	std::cout << "------------" << std::endl;	
	{
		std::cout << "set and multiset will not give the correct index" << std::endl;
		std::set<int> numSet = {2, 1, 1, 1};
		auto i = easyfind(numSet, 1);
		i == numSet.cend() ? notFound(1) : found(*i, std::distance(numSet.cbegin(), i));
		std::multiset<int> numMSet = {2, 1, 1, 1};
		auto j = easyfind(numMSet, 1);
		j == numMSet.cend() ? notFound(1) : found(*j, std::distance(numMSet.cbegin(), j));
	}
	std::cout << "------------" << std::endl;
	{
		std::list<bool> boolSet = {false, false, false, false, true, true, false};
		auto i = easyfind(boolSet, true);
		i == boolSet.cend() ? notFound(1) : found(*i, std::distance(boolSet.cbegin(), i));
	}
	return (0);
}