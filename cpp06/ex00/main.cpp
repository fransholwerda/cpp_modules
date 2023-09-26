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

	scalarConverter.convert();
	return (0);
}
