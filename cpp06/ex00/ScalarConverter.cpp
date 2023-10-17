#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include "ScalarConverter.hpp"

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

	if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
		return (true);

	bool dot = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input[i] == '-' || input[i] == '+')) && input.length() > 1)
			continue ;
		else if (input[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(input[i]))
		{
			if (input[i] == 'f' && i == input.length() - 1)
				return (true);
			return (false);
		}
	}
	return (false);
}

bool	typeIsDouble(std::string input)
{
	if (input.empty())
		return (false);

	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf")
		return (true);

	bool dot = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input[i] == '-' || input[i] == '+')) && input.length() > 1)
			continue ;
		else if (input[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

ScalarConverter::ScalarConverter(std::string const &input) : _input(input)
{
	if (typeIsInt(input))
		this->_type = INT;
	else if (typeIsChar(input))
		this->_type = CHAR;
	else if (typeIsFloat(input))
		this->_type = FLOAT;
	else if (typeIsDouble(input))
		this->_type = DOUBLE;
	else
		throw ImpossibleException();
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) : _input(other._input)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
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

void	ScalarConverter::fromChar()
{
	std::cout << "char: '" << this->_input[0] << "'" << std::endl;
	try	{
		printInt();
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}
	try {
		printFloat();
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
	try {
		printDouble();
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	ScalarConverter::fromInt()
{
	try {
		printChar();
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	std::cout << "int: " << this->_input << std::endl;
	try {
		printFloat();
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
	try {
		printDouble();
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	ScalarConverter::fromFloat()
{
	try {
		printChar();
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	try {
		printInt();
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}
	try {
		printFloat();
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
	try {
		printDouble();
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	ScalarConverter::fromDouble()
{
	try {
		printChar();
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	try {
		printInt();
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}
	try {
		printFloat();
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
	std::cout << "double: " << this->_input << std::endl;
}

void	ScalarConverter::convert()
{
	switch (this->_type)
	{
		case CHAR:
			std::cout << "CHAR!" << std::endl;
			fromChar();
			break ;
		case INT:
			std::cout << "INT!" << std::endl;
			fromInt();
			break ;
		case FLOAT:
			std::cout << "FLOAT!" << std::endl;
			fromFloat();
			break ;
		case DOUBLE:
			std::cout << "DOUBLE!" << std::endl;
			fromDouble();
			break ;
		default:
			std::cout << "DEFAULT!" << std::endl;
			throw ImpossibleException();
			break ;
	}
}

std::ostream	&operator<<(std::ostream &out, ScalarConverter const &scalarConverter)
{
	(void)scalarConverter;
	return (out);
}

const char			*ScalarConverter::ImpossibleException::what() const throw()
{
	return("impossible");
}

const char			*ScalarConverter::NonDisplayableException::what() const throw()
{
	return("Non displayable");
}

