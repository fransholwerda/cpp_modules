#include <iostream>
#include <limits>
#include <vector>
#include "Span.hpp"

int main()
{
	std::srand(time(NULL));

	std::cout << "Test from the subject" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nTest with int32_min and int32_max" << std::endl;
	Span sp2 = Span(2);
	sp2.addNumber(INT32_MIN);
	sp2.addNumber(INT32_MAX);
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "\nTest with 10,000 random numbers" << std::endl;
	Span sp3 = Span(10000);
	for (int i = 0; i < 10000; i++)
		sp3.addNumber(rand());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << "\nTest with 100,000 random numbers" << std::endl;
	Span sp4 = Span(100000);
	for (int i = 0; i < 100000; i++)
		sp4.addNumber(rand());
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;

	std::cout << "\nTest with empty span" << std::endl;
	Span sp5 = Span(0);
	try
	{
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest with span with one element" << std::endl;
	Span sp6 = Span(1);
	sp6.addNumber(42);
	try
	{
		std::cout << sp6.shortestSpan() << std::endl;
		std::cout << sp6.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest with span that could hold two, but has none" << std::endl;
	Span sp7 = Span(2);
	try
	{
		std::cout << sp7.shortestSpan() << std::endl;
		std::cout << sp7.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest that attempts to add a number to a span that is full" << std::endl;
	Span sp8 = Span(2);
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest that adds numbers to a span using a range of iterators" << std::endl;
	Span sp9 = Span(1000);
	std::vector<int> v(1000);
	std::generate(v.begin(), v.end(), std::rand);
	sp9.addNumber(v.begin(), v.end());
	std::cout << sp9.shortestSpan() << std::endl;
	std::cout << sp9.longestSpan() << std::endl;
	return (0);
}
