/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 16:07:05 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 17:00:20 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of strPTR: " << strPTR << std::endl;
	std::cout << "Address of strREF: " << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of strPTR: " << *strPTR << std::endl;
	std::cout << "Value of strREF: " << strREF << std::endl;
	return (0);
}
