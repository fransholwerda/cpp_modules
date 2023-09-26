#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Bureaucrat	bob("Bob", 1);
		Intern	someRandomIntern;
		AForm	*rrf;

		std::cout << "Trying to make a non-existing form:" << std::endl;
		try
		{
			rrf = someRandomIntern.makeForm("No Form", "Bender");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Trying to make a Robotomy Creation form:" << std::endl;
		try
		{
			rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete (rrf);
	}
	return (0);
}
