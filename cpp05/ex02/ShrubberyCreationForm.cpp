#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target),
	_tree("       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
	AForm(other),
	_target(other._target),
	_tree(other._tree)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->_target = other._target;
	this->_tree = other._tree;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream	ofs((this->_target + "_shrubbery").c_str());

	if (!ofs.is_open())
		throw ShrubberyCreationForm::FileNotOpenedException();
	ofs << this->_tree;
	ofs.close();
}

const char	*ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return ("File couldn't be opened");
}
