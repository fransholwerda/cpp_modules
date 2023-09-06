#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form		form1("Form1", 1, 1);
	std::cout << form1 << std::endl;

	Form		form150("Form150", 150, 150);
	std::cout << form150 << std::endl;

	try
	{
		std::cout << "Trying to create a Form with gradeToSign 0" << std::endl;
		Form	form0("Form0", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Form0's exception: " << e.what() << "\n" << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with gradeToExecute 0" << std::endl;
		Form	form0("Form0", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Form0's exception: " << e.what() << "\n" << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with gradeToSign 151" << std::endl;
		Form	form151("Form151", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Form151's exception: " << e.what() << "\n" << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with gradeToExecute 151" << std::endl;
		Form	form151("Form151", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Form151's exception: " << e.what() << "\n" << std::endl;
	}

	Form		form2("Form2", 2, 2);
	std::cout << form2 << std::endl;
	Bureaucrat	epsilon("Epsilon", 2);
	std::cout << epsilon << std::endl;
	epsilon.signForm(form2);
	std::cout << form2 << std::endl;


	Form		form50("Form50", 50, 50);
	std::cout << form50 << std::endl;
	Bureaucrat	zeta("Zeta", 60);
	std::cout << zeta << std::endl;
	zeta.signForm(form50);
	std::cout << form50 << std::endl;
	std::cout << "\nTrying to sign form50 again but with grade 40" << std::endl;
	Bureaucrat	eta("Eta", 40);
	std::cout << eta << std::endl;
	eta.signForm(form50);
	std::cout << form50 << std::endl;

	return (0);
}
