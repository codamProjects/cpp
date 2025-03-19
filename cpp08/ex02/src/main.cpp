
#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>

int main(void) {
	{
		MutantStack<std::string> mstack;
		if (mstack.empty())
			std::cout << "stack<string> still empty" << std::endl;
		mstack.push("Hello");
		std::cout << "added: " << mstack.top() << std::endl;
		mstack.push("World");
		std::cout << "added: " << mstack.top() << std::endl;
		if (!mstack.empty())
			std::cout << "stack<string> now has size: " << mstack.size() << std::endl;
	}
	std::cout << "-------" << std::endl;
	{
		MutantStack<std::list<int>> lstack;
		std::list<int> d = {1, 2, 3, 4};
		std::list<int> e = {5, 6, 7, 8};
		lstack.push(d);
		lstack.push(e);
		auto i = lstack.begin();
		auto j = lstack.end();
		j--;
		std::list<int> p = *i;
		std::cout << "list " << std::distance(lstack.begin(), i)  << ", " << *p.begin() << " t/m " << p.back() << std::endl;
		std::list<int> q = *j;
		std::cout << "list " << std::distance(lstack.begin(), j)  << ", " << *q.begin() << " t/m " << q.back() << std::endl;
	}
	std::cout << "-------" << std::endl;
	{
		MutantStack<int, std::list<int>> iStack;
		std::list<int> iList;
		iStack.push(100);
		iList.push_back(100);
		iStack.push(200);
		iList.push_back(200);
		iStack.push(42);
		iList.push_back(42);
		iStack.push(300);
		iList.push_back(300);
		auto i = iList.begin();
		auto j = iList.cend();
		MutantStack<int, std::list<int>>::iterator k = iStack.begin();
		MutantStack<int, std::list<int>>::const_iterator l = iStack.cend();
		std::cout << "List:";
		for (; i != j; i++)
			std::cout << " " << *i;
		std::cout << "\nMutantStack:";
		for (; k != l; k++)
			std::cout << " " << *k;
		std::cout << std::endl;
	}
	std::cout << "-------" << std::endl;
	{
		MutantStack<std::string> newVar;
		newVar.push("something");
		std::stack<std::string> ogVar(newVar);
		std::cout << ogVar.top() << " vs " << newVar.top() << std::endl;
	}
	std::cout << "-------" << std::endl;
	{
		MutantStack<double> msArr;
		msArr.push(10.0);
		msArr.push(9.0);
		msArr.push(8.0);
		msArr.push(7.0);
		msArr.push(6.0);
		msArr.push(5.0);
		msArr.push(4.0);
		msArr.push(3.0);
		msArr.push(2.0);
		msArr.push(1.0);
		msArr.push(0.0);
		MutantStack<double>::reverse_iterator ri = msArr.rbegin();
		MutantStack<double>::const_reverse_iterator crj = msArr.crend();
		std::cout << "reversed iterator:";
		for (; ri != crj; ri++)
			std::cout << " " << *ri;
		std::cout << std::endl;
		MutantStack<double>::iterator k = msArr.begin();
		MutantStack<double>::const_iterator cl = msArr.cend();
		std::cout << "normal iterator:";
		for (; k != cl; k++)
			std::cout << " " << *k;
		std::cout << std::endl;
	}
	return (0);
}

// int main(void) {
	
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	--ite;
// 	while (ite != it)
// 	{
// 		std::cout << *ite << std::endl;
// 		--ite;
// 	}
// 	std::cout << *ite << std::endl;
// 	std::stack<int> s(mstack);
// 	return (0);
// }
