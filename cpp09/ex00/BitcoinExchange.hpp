#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitCoinExchange
{
	private:
		std::map<std::string, double>	_btc;
		std::string 					_earliestDate;
		void	readData(const std::string &db_filename);
		BitCoinExchange();
	public:
		BitCoinExchange(const std::string &db_filename);
		BitCoinExchange(const BitCoinExchange &other);
		~BitCoinExchange();
		BitCoinExchange &operator=(const BitCoinExchange &other);

		double	getExchangeRate(const std::string &date);
		void	feedInput(const std::string &filename);

		class DatabaseException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Database exception");
				}
		};
		class FileException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("File exception");
				}
		};
		class DateException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Date exception");
				}
		};
};

#endif
