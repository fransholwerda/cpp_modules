#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	jim("Jim", 150);
	ShrubberyCreationForm	shrubberyCreationForm("home");

	std::cout << bob << std::endl;
	std::cout << jim << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << std::endl;

	try
	{
		bob.signForm(shrubberyCreationForm);
		std::cout << shrubberyCreationForm << std::endl;
		bob.executeForm(shrubberyCreationForm);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		jim.executeForm(shrubberyCreationForm);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
