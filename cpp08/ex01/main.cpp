#include <iostream>
#include <limits>
#include "Span.hpp"

int main()
{
	srand(time(NULL));

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
	return (0);
}
