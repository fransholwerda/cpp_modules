#include <iostream>
#include <vector>
#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_vec = copy._vec;
		_size = copy._size;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_vec.size() == _size)
		throw FullException();
	_vec.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + std::distance(begin, end) > _size)
		throw FullException();
	_vec.insert(_vec.end(), begin, end);
}

long int	Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::sort(_vec.begin(), _vec.end());
	long int min = static_cast<long int>(_vec[1]) - static_cast<long int>(_vec[0]);
	for (unsigned int i = 2; i < _vec.size(); i++)
	{
		if (static_cast<long int>(_vec[i]) - static_cast<long int>(_vec[i - 1]) < min)
			min = static_cast<long int>(_vec[i]) - static_cast<long int>(_vec[i - 1]);
	}
	return (min);
}

long int	Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::sort(_vec.begin(), _vec.end());
	return (static_cast<long int>(_vec[_vec.size() - 1]) - static_cast<long int>(_vec[0]));
}

const char* Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Span is empty or contains only one element");
}
