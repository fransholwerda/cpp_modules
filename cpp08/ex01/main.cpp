#include <iostream>
#include "Span.hpp"

int main()
{
	srand(time(NULL));
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(2);
	sp2.addNumber(1);
	sp2.addNumber(1);
	std::cout << sp2.longestSpan() << std::endl;

	//Test with more than 10000 random numbers
	Span sp3 = Span(10000);
	for (int i = 0; i < 10000; i++)
		sp3.addNumber(rand());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return (0);
}

class Classname
{
	private:
		int _int;
	public:
		Classname();
		Classname(int wow);
		~Classname();

		void		set_int(int i);
		const int	get_int();
};
