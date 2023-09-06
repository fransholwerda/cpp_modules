#include "AForm.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(AForm const &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(AForm const &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::string const	&AForm::getName() const
{
	return (this->_name);
}

bool				AForm::isSigned() const
{
	return (this->_signed);
}

int					AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char			*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char			*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &out, AForm const &aForm)
{
	out << aForm.getName() << " form, signed: " << aForm.isSigned() << ", grade to sign: " << aForm.getGradeToSign() << ", grade to execute: " << aForm.getGradeToExecute();
	return (out);
}
