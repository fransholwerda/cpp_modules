#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <string.h>
#include <limits>
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

std::string trimTrailingZeros(const std::string& input) {
	size_t dotPosition = input.find_last_of('.');
	size_t endPosition = input.find_last_not_of('0');

	if (endPosition == std::string::npos || (dotPosition != std::string::npos && endPosition < dotPosition)) {
		return input;
	}

	return input.substr(0, endPosition + 1);
}


bool	typeIsChar(std::string input)
{
	if (input.empty())
		return (false);
	if (input.length() == 1)
	{
		char c = input.c_str()[0];
		if (c >= 0 && c <= 127)
			return (true);
	}
	return (false);
}

bool	typeIsInt(std::string input)
{
	if (input.empty() || (input[0] == '-' && input.size() == 1))
		return (false);
	if (!((input.size() >= 2 && input[0] == '-' && all_digits(input.substr(1))) || all_digits(input)))
		return (false);

	try {
		int number = std::stoi(input);
		number = 0;
	} catch (const std::invalid_argument& e) {
		return (false);
	} catch (const std::out_of_range& e) {
		return (false);
	}
	return (true);
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

void	fromChar(const std::string& input)
{
	char c = input[0];
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	try	{
		int toInt = static_cast<int>(c);
		std::cout << "int: " << toInt << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	try {
		float toFloat = static_cast<float>(c);
		std::cout << "float: " << toFloat << ".0f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	try {
		double toDouble = static_cast<double>(c);
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	fromInt(const std::string& input)
{
	int toInt = std::stoi(input);
	try	{
		char c = static_cast<char>(toInt);
		if (toInt > 127)
			std::cout << "char: overflow" << std::endl;
		else if (toInt < 0)
			std::cout << "char: underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	std::cout << "int: " << toInt << std::endl;

	try {
		float toFloat = static_cast<float>(toInt);
		std::cout << "float: " << toFloat << ".0f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	try {
		double toDouble = static_cast<double>(toInt);
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	fromFloat(const std::string& input)
{
	float toFloat = std::stof(input);
	try	{
		char c = static_cast<char>(toFloat);
		if (toFloat > 127)
			std::cout << "char: overflow" << std::endl;
		else if (toFloat < 0)
			std::cout << "char: underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		int toInt = static_cast<int>(toFloat);
		if (toFloat > static_cast<float>(INT32_MAX) || (toInt < 0 && toFloat > 0.0f))
			std::cout << "int: overflow" << std::endl;
		else if (toFloat < static_cast<float>(INT32_MIN) || (toInt > 0 && toFloat < 0.0f))
			std::cout << "int: underflow" << std::endl;
		else
			std::cout << "int: " << toInt << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	std::string floatString = trimTrailingZeros(std::to_string(toFloat));
	if (floatString.back() == '.')
		std::cout << "float: " << floatString << "0f" << std::endl;
	else
		std::cout << "float: " << floatString << "f" << std::endl;

	try {
		double toDouble = static_cast<double>(toFloat);
		std::string doubleString = trimTrailingZeros(std::to_string(toDouble));
		if (doubleString.back() == '.')
			std::cout << "double: " << doubleString << "0" << std::endl;
		else
			std::cout << "double: " << doubleString << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void fromDouble(const std::string& input)
{
	double toDouble = std::stof(input);
	try	{
		char c = static_cast<char>(toDouble);
		if (toDouble > 127)
			std::cout << "char: overflow" << std::endl;
		else if (toDouble < 0)
			std::cout << "char: underflow" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		int toInt = static_cast<int>(toDouble);
		if (toDouble > static_cast<double>(INT32_MAX) || (toInt < 0 && toDouble > 0.0))
			std::cout << "int: overflow" << std::endl;
		else if (toDouble < static_cast<double>(INT32_MIN) || (toInt > 0 && toDouble < 0.0))
			std::cout << "int: underflow" << std::endl;
		else
			std::cout << "int: " << toInt << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	try {
		float toFloat = static_cast<float>(toDouble);
		std::string floatString = trimTrailingZeros(std::to_string(toFloat));
		if (floatString.back() == '.')
			std::cout << "float: " << floatString << "0f" << std::endl;
		else
			std::cout << "float: " << floatString << "f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	std::string doubleString = trimTrailingZeros(std::to_string(toDouble));
	if (doubleString.back() == '.')
		std::cout << "double: " << doubleString << "0" << std::endl;
	else
		std::cout << "double: " << doubleString << std::endl;
}


static int detect_type(const std::string& input)
{
	if (typeIsInt(input))
		return (INT);
	else if (typeIsChar(input))
		return (CHAR);
	else if (typeIsFloat(input))
		return (FLOAT);
	else if (typeIsDouble(input))
		return (DOUBLE);
	return (-1);
}

void ScalarConverter::convert(const std::string& input)
{
	int type = detect_type(input);
	switch (type)
	{
	case -1:
		std::cout << "Impossible" << std::endl;
		break;
	case CHAR:
		fromChar(input);
		break;
	case INT:
		fromInt(input);
		break;
	case FLOAT:
		fromFloat(input);
		break;
	case DOUBLE:
		fromDouble(input);
		break;
	default:
		break;
	}
}
