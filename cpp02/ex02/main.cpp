/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 18:43:14 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/23 16:01:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c = Fixed(23.4235f);
	Fixed d = Fixed(23.4280f);
	Fixed e = Fixed(23.4280f);
	Fixed f(10);
	Fixed g(5);
	std::cout << "\nc: " << c << "\nd: " << d << "\ne: " << e << "\nf: " << f << "\ng: " << g << "\n" << std::endl;
	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;
	std::cout << c << " > " << d << ": " << (c > d) << std::endl;
	std::cout << c << " < " << d << ": " << (c < d) << std::endl;
	std::cout << c << " >= " << d << ": " << (c >= d) << std::endl;
	std::cout << c << " <= " << d << ": " << (c <= d) << std::endl;
	std::cout << d << " >= " << e << ": " << (d >= e) << std::endl;
	std::cout << c << " == " << d << ": " << (c == d) << std::endl;
	std::cout << d << " == " << e << ": " << (d == e) << std::endl;
	std::cout << c << " != " << d << ": " << (c != d) << std::endl;
	std::cout << d << " != " << e << ": " << (d != e) << std::endl;
	std::cout << f << " + " << g << ": " << (f + g) << std::endl;
	std::cout << f << " - " << g << ": " << (f - g) << std::endl;
	std::cout << f << " * " << g << ": " << (f * g) << std::endl;
	std::cout << f << " / " << g << ": " << (f / g) << std::endl;

	try
	{
		std::cout << f << " / 0" << ": " << (f / Fixed(0)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "The program continues after the exception." << std::endl;
	return 0;
}