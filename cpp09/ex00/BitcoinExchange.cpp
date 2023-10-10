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
	std::string day;
	std::string month;
	std::string year;
	std::string temp;
	size_t pos = date.find('-');

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

BitCoinExchange::BitCoinExchange()
{
}

BitCoinExchange::BitCoinExchange(const std::string &db_filename)
{
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
		std::string value = line.substr(pos + 1);
		_btc[key] = std::stod(value);
	}
}
