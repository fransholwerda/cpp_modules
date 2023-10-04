#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "----------------------------------------" << std::endl;
	{
		std::cout << "Deque tests" << std::endl;
		std::cout << "Test 1: Create a deque of int" << std::endl;
		std::deque<int> intDeque;
		for (int i = 0; i < 10; i++)
			intDeque.push_back(i);
		std::cout << "intDeque: ";
		for (std::deque<int>::iterator it = intDeque.begin(); it != intDeque.end(); it++) // Expected output: 0 1 2 3 4 5 6 7 8 9
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "\nTest 2: Find 3 in the intDeque" << std::endl;
		try
		{
			std::deque<int>::iterator it = easyfind(intDeque, 3); // Expected output: 3
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}

		std::cout << "\nTest 3: Find 42 in the intDeque" << std::endl;
		try
		{
			std::deque<int>::iterator it = easyfind(intDeque, 42); // Expected output: Not found
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}
	}

	std::cout << "----------------------------------------" << std::endl;
	{
		std::cout << "List tests" << std::endl;
		std::cout << "Test 1: Create a list of int" << std::endl;
		std::list<int> intList;
		for (int i = 0; i < 10; i++)
			intList.push_back(i);
		std::cout << "intList: ";
		for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) // Expected output: 0 1 2 3 4 5 6 7 8 9
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "\nTest 2: Find 3 in the intList" << std::endl;
		try
		{
			std::list<int>::iterator it = easyfind(intList, 3); // Expected output: 3
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}

		std::cout << "\nTest 3: Find 42 in the intList" << std::endl;
		try
		{
			std::list<int>::iterator it = easyfind(intList, 42); // Expected output: Not found
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}
	}

	std::cout << "----------------------------------------" << std::endl;
	{
		std::cout << "Vector tests" << std::endl;
		std::cout << "Test 1: Create a vector of int" << std::endl;
		std::vector<int> intVector;
		for (int i = 0; i < 10; i++)
			intVector.push_back(i);
		std::cout << "intVector: ";
		for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++) // Expected output: 0 1 2 3 4 5 6 7 8 9
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "\nTest 2: Find 3 in the intVector" << std::endl;
		try
		{
			std::vector<int>::iterator it = easyfind(intVector, 3); // Expected output: 3
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}

		std::cout << "\nTest 3: Find 42 in the intVector" << std::endl;
		try
		{
			std::vector<int>::iterator it = easyfind(intVector, 42); // Expected output: Not found
			std::cout << "Found " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}
	}
}
