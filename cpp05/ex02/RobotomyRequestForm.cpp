#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
	AForm(other),
	_target(other._target)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->_target = other._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
