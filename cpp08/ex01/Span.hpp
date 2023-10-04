#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		std::vector<int>	_vec;
		unsigned int		_size;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span	&operator=(const Span &copy);

		void		addNumber(int n);
		void		addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		long int	shortestSpan();
		long int	longestSpan();

		class FullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
