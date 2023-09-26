#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();
		Intern	&operator=(Intern const &other);

		AForm	*makeForm(std::string const &name, std::string const &target) const;

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif
