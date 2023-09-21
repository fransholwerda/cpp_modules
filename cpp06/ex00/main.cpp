#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <input>" << std::endl;
		return (1);
	}

	ScalarConverter	scalarConverter(argv[1]);

	try
	{
		scalarConverter.printChar();
	}
	catch (std::exception &e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}
	try
	{
		scalarConverter.printInt();
	}
	catch (std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}
	try
	{
		scalarConverter.printFloat();
	}
	catch (std::exception &e)
	{
		std::cout << "float: " << e.what() << std::endl;
	}
	try
	{
		scalarConverter.printDouble();
	}
	catch (std::exception &e)
	{
		std::cout << "double: " << e.what() << std::endl;
	}
	return (0);
}
