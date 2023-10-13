#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		RPN	rpn;
		rpn.calculate(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
