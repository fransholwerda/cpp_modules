#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return (EXIT_FAILURE);
	}
	(void)argv;

	try
	{
		BitCoinExchange btc("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "Hello World!" << std::endl;
	return (EXIT_SUCCESS);
}
