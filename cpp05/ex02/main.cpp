#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	jim("Jim", 150);
		ShrubberyCreationForm	shrubbery("home");
		RobotomyRequestForm		robotomy("home");
		PresidentialPardonForm	presidential("home");

		std::cout << bob << std::endl;
		std::cout << jim << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << presidential << std::endl;
		std::cout << std::endl;

		std::cout << "Trying to sign forms with Jim who has too low grades:" << std::endl;
		try
		{
			jim.signForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			jim.signForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			jim.signForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Trying to execute forms with Jim who couldn't sign the forms because of too low grades:" << std::endl;
		try
		{
			jim.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			jim.executeForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			jim.executeForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Trying to sign forms with Bob who has high enough grades:" << std::endl;
		try
		{
			bob.signForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bob.signForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bob.signForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Trying to execute forms with Bob who has signed forms with high enough grades:" << std::endl;
		try
		{
			bob.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bob.executeForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bob.executeForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}
