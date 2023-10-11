#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		BitCoinExchange btc("data.csv");
		btc.feedInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
