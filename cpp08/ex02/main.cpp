#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	std::cout << "Testing with MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nTesting with std::list:" << std::endl;
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);
	std::list<int>::iterator it2 = l.begin();
	std::list<int>::iterator ite2 = l.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(l);

	std::cout << "\nTesting with std::vector:" << std::endl;
	std::vector<int> v;
	v.push_back(5);
	v.push_back(17);
	std::cout << v.back() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	//[...]
	v.push_back(0);
	std::vector<int>::iterator it3 = v.begin();
	std::vector<int>::iterator ite3 = v.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::vector<int> s3(v);
	return (0);
}
