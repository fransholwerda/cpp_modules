#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		std::string const	_input;
		int					_type;
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
		void	fromChar();
		void	fromInt();
		void	fromFloat();
		void	fromDouble();
		void	convert();

		class ImpossibleException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
