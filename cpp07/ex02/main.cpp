#include <iostream>
#include "Array.hpp"

int main(void)
{
	{
		Array<int> a(5);
		Array<std::string> b(5);
		Array<int> c;

		std::cout << "a.size() = " << a.size() << std::endl;
		std::cout << "b.size() = " << b.size() << std::endl;
		std::cout << "c.size() = " << c.size() << std::endl;

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = std::to_string(i);
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		try
		{
			std::cout << "a[5] = " << a[5] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "b[5] = " << b[5] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "c[0] = " << c[0] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		// PUT MORE TESTS HERE
	}
	return (0);
}
