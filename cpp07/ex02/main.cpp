#include <iostream>
#include "Array.hpp"

int main(void)
{
	{
		Array<int> a(5);
		Array<std::string> b(5);
		Array<int> c;

		std::cout << "Basic tests" << std::endl;

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

		try
		{
			std::cout << "\nTest 1: Create an empty Array of int" << std::endl;
			Array<int> intArray;
			std::cout << "intArray size: " << intArray.size() << std::endl; // Expected output: 0

			std::cout << "\nTest 2: Create an Array of double with a size of 5" << std::endl;
			Array<double> doubleArray(5);
			std::cout << "doubleArray size: " << doubleArray.size() << std::endl; // Expected output: 5

			std::cout << "\nTest 3: Access elements in the doubleArray" << std::endl;
			doubleArray[0] = 3.14;
			doubleArray[1] = 2.71;
			std::cout << "doubleArray[0]: " << doubleArray[0] << std::endl; // Expected output: 3.14
			std::cout << "doubleArray[1]: " << doubleArray[1] << std::endl; // Expected output: 2.71

			std::cout << "\nTest 4: Assign one Array to another" << std::endl;
			Array<double> anotherDoubleArray(3);
			anotherDoubleArray = doubleArray;
			std::cout << "anotherDoubleArray[0]: " << anotherDoubleArray[0] << std::endl; // Expected output: 3.14

			std::cout << "\nTest 5: Modify an element through the copy" << std::endl;
			anotherDoubleArray[0] = 42;
			std::cout << "anotherDoubleArray[0]: " << anotherDoubleArray[0] << std::endl; // Expected output: 42
			std::cout << "doubleArray[0]: " << doubleArray[0] << std::endl; // Expected output: 3.14

			std::cout << "\nTest 6: Access out-of-bounds element (should throw an exception)" << std::endl;
			std::cout << "Accessing out-of-bounds element: ";
			std::cout << doubleArray[10] << std::endl; // This should throw an exception

		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	return (0);
}
