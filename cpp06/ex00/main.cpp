#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <input>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	// try
	// {
	// 	ScalarConverter	scalarConverter(argv[1]);
	// 	scalarConverter.convert();
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	return (0);
}
