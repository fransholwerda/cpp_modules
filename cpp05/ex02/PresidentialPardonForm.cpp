#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
