#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		AForm();
	public:
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		virtual ~AForm();

		AForm	&operator=(AForm const &other);

		std::string const	&getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &aForm);

#endif
