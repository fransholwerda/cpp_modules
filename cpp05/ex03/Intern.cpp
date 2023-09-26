#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

int	findForm(std::string const &name)
{
	std::string	forms[] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};
	for (int i = 0; i < static_cast<int>(forms->length()); i++)
	{
		if (name == forms[i])
			return (i);
	}
	return (-1);
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	AForm	*form;

	switch (findForm(name))
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::UnknownFormException();
	}
	std::cout << "Intern creates " << *form << std::endl;
	return (form);
}

const char	*Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form");
}
