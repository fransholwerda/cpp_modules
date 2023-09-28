#include <iostream>
#include "iter.hpp"

void	print_int(int const &i)
{
	std::cout << i << " ";
}

void	print_string(std::string const &s)
{
	std::cout << s << " ";
}

int main(void)
{
	int int_array[] = { 1, 2, 3, 4, 5 };
	std::string string_array[] = { "Hello", "World", "!" };

	std::cout << "int_array: ";
	::iter(int_array, 5, print_int);
	std::cout << std::endl;

	std::cout << "string_array: ";
	::iter(string_array, 3, print_string);
	std::cout << std::endl;

	return (0);
}
