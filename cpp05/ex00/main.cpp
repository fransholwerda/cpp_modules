#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	alpha("Alpha", 1);
	std::cout << alpha << std::endl;

	try
	{
		alpha.decrementGrade();
		std::cout << alpha << std::endl;
		alpha.incrementGrade();
		std::cout << alpha << std::endl;
		std::cout << "Trying to increment grade above 1 (would be 0)" << std::endl;
		alpha.incrementGrade();
		std::cout << alpha << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Alpha's exception: " << e.what() << "\n" << std::endl;
	}

	Bureaucrat	bravo("Bravo", 150);
	std::cout << bravo << std::endl;

	try
	{
		bravo.incrementGrade();
		std::cout << bravo << std::endl;
		bravo.decrementGrade();
		std::cout << bravo << std::endl;
		std::cout << "Trying to decrement grade below 150 (would be 151)" << std::endl;
		bravo.decrementGrade();
		std::cout << bravo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bravo's exception: " << e.what() << "\n" << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Bureaucrat with grade 0" << std::endl;
		Bureaucrat	charlie("Charlie", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Charlie's exception: " << e.what() << "\n" << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Bureaucrat with grade 151" << std::endl;
		Bureaucrat	delta("Delta", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Delta's exception: " << e.what() << "\n" << std::endl;
	}

	return (0);
}
