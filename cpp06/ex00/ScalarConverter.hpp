#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

class ScalarConverter
{
	private:
		std::string const	_input;
		ScalarConverter();
	public:
		ScalarConverter(std::string const &input);
		ScalarConverter(ScalarConverter const &other);
		virtual ~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &other);

		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

		class ImpossibleException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return("impossible");
				}
		};
		class NonDisplayableException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return("Non displayable");
				}
		};
};

#endif