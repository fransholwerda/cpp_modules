#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

bool isYearValid(const std::string &year)
{
	if (year.size() != 4)
		return (false);
	for (size_t i = 0; i < year.size(); i++)
	{
		if (!std::isdigit(year[i]))
			return (false);
	}
	return (true);
}

bool isMonthValid(const std::string &month)
{
	if (month.size() != 2)
		return (false);
	if (month[0] != '0' && month[0] != '1')
		return (false);
	if (month[0] == '0' && month[1] == '0')
		return (false);
	if (month[0] == '1' && month[1] != '0' && month[1] != '1' && month[1] != '2')
		return (false);
	return (true);
}

bool isDayValid(const std::string &year, const std::string &month, const std::string &day)
{
	int y = std::stoi(year);
	int m = std::stoi(month);
	int d = std::stoi(day);

	if (d < 1 || d > 31)
		return (false);
	if (m == 2)
	{
		if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
		{
			if (d > 29)
				return (false);
		}
		else
		{
			if (d > 28)
				return (false);
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 30)
			return (false);
	}
	return (true);
}

bool isDateValid(const std::string &date)
{
	std::string	day;
	std::string	month;
	std::string	year;
	std::string	temp;
	size_t		pos = date.find('-');

	if (pos == std::string::npos)
		return (false);
	year = date.substr(0, pos);
	temp = date.substr(pos + 1);
	pos = temp.find('-');
	if (pos == std::string::npos)
		return (false);
	month = temp.substr(0, pos);
	day = temp.substr(pos + 1);
	if (isYearValid(year) && isMonthValid(month) && isDayValid(year, month, day))
		return (true);
	return (false);
}

std::string decreaseDate(const std::string &date)
{
	int			day;
	int			month;
	int			year;
	std::string	temp;
	size_t		pos = date.find('-');

	year = atoi(date.substr(0, pos).c_str());
	temp = date.substr(pos + 1);
	pos = temp.find('-');
	month = atoi(temp.substr(0, pos).c_str());
	day = atoi(temp.substr(pos + 1).c_str());
	if (day > 1)
		day--;
	else if (month > 1)
	{
		month--;
		day = 31;
	}
	else
	{
		year--;
		month = 12;
		day = 31;
	}
	std::string new_date = std::to_string(year) + "-";
	if (month < 10)
		new_date += "0";
	new_date += std::to_string(month) + "-";
	if (day < 10)
		new_date += "0";
	new_date += std::to_string(day);
	return (new_date);
}

BitCoinExchange::BitCoinExchange()
{
}

BitCoinExchange::BitCoinExchange(const std::string &db_filename)
{
	_earliestDate = "9999-99-99";
	readData(db_filename);
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &other)
{
	*this = other;
}

BitCoinExchange::~BitCoinExchange()
{
}

BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other)
{
	if (this != &other)
	{
		_btc = other._btc;
	}
	return (*this);
}

void	BitCoinExchange::readData(const std::string &db_filename)
{
	if (db_filename.empty())
		throw DatabaseException();
	
	std::ifstream db(db_filename);
	if (!db.is_open())
		throw FileException();

	std::string line;
	std::getline(db, line); // Skip the first line
	while (std::getline(db, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw DatabaseException();
		std::string key = line.substr(0, pos);
		if (!isDateValid(key))
			throw DateException();
		if (key < _earliestDate)
			_earliestDate = key;
		std::string value = line.substr(pos + 1);
		_btc[key] = std::stod(value);
	}
}

double	BitCoinExchange::getExchangeRate(const std::string &date)
{
	if (!isDateValid(date))
	{
		std::cout << "Invalid date, date must be in the format YYYY-MM-DD" << std::endl;
		throw DateException();
	}
	if (date < _earliestDate)
	{
		std::cout << "Date is earlier than the earliest date in the database" << std::endl;
		throw DateException();
	}
	if (_btc.find(date) != _btc.end())
		return (_btc[date]);
	std::string temp = date;
	while (temp != _earliestDate)
	{
		temp = decreaseDate(temp);
		if (_btc.find(temp) != _btc.end())
			return (_btc[temp]);
	}
	throw DateException();
}

void	BitCoinExchange::feedInput(const std::string &filename)
{
	if (filename.empty())
		throw FileException();

	std::ifstream input(filename);
	if (!input.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		throw FileException();
	}

	std::string line;
	std::getline(input, line); // Skip the first line
	while (std::getline(input, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pos - 1);
		if (!isDateValid(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		else if (date < _earliestDate)
		{
			std::cout << "Error: date is earlier than the earliest date in the database." << std::endl;
			continue ;
		}
		std::string value = line.substr(pos + 1);
		double btc = std::stod(value);
		if (btc < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (btc > INT32_MAX || btc > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		try
		{
			double exchange_rate = getExchangeRate(date);
			std::cout << date << " => " << btc << " = " << btc * exchange_rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
