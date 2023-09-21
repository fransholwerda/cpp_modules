#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const &input) : _input(input)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) : _input(other._input)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

bool	all_digits(std::string input)
{
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

bool	typeIsChar(std::string input)
{
	if (input.length() == 1)
		return (true);
	return (false);
}

bool	typeIsInt(std::string input)
{
	if (input.empty())
		return (false);
	else if (all_digits(input))
		return (true);
	return (false);
}

bool	typeIsFloat(std::string input)
{
	if (input.empty())
		return (false);
	
	bool dot = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
	}

bool	typeIsDouble(std::string input)
{
	
}

void	ScalarConverter::printChar()
{
	// Check if string input is a single character
	if (this->_input.length() == 1 && !std::isdigit(this->_input[0]))
	{
		char	c = this->_input[0];
		if (c < 32 || c > 126)
			throw NonDisplayableException();
		std::cout << "char: '" << c << "'" << std::endl;
	} // Check if string input is a number
	else if (all_digits(this->_input))
	{
		char	c = std::stoi(this->_input);
		if (c < 32 || c > 126)
			throw NonDisplayableException();
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
		throw ImpossibleException();
}

void	ScalarConverter::printInt()
{
	if (this->_input.length() == 1 && !std::isdigit(this->_input[0]))
		std::cout << "int: " << static_cast<int>(this->_input[0]) << std::endl;
	else if (all_digits(this->_input))
		std::cout << "int: " << std::stoi(this->_input) << std::endl;
	else
		throw ImpossibleException();
}

void	ScalarConverter::printFloat()
{
	try
	{
		float	f = std::stof(this->_input);
		if (f - std::floor(f) < 0.000001 || f - std::floor(f) > 0.999999)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		throw ImpossibleException();
	}
}

void	ScalarConverter::printDouble()
{
	try
	{
		double	d = std::stod(this->_input);
		if (d - std::floor(d) < 0.000001 || d - std::floor(d) > 0.999999)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch (std::exception &e)
	{
		throw ImpossibleException();
	}
}

std::ostream	&operator<<(std::ostream &out, ScalarConverter const &scalarConverter)
{
	(void)scalarConverter;
	return (out);
}
