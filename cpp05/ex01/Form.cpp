#include "Form.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form::~Form()
{
}

Form	&Form::operator=(Form const &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (this->_name);
}

bool				Form::isSigned() const
{
	return (this->_signed);
}

int					Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << " form, signed: " << form.isSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return (out);
}
