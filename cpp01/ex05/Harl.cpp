/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 13:26:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/22 14:10:58 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "Vacuum tube serial number 4302613 contains a beetle." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "Vacuum tube serial number 4302613 contains a beetle." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "A vacuum tube seems to have a problem, I'm turning on the exterminating feature." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "The exterminating feature has malfunctioned, I'm turning on the self-destruct feature." << std::endl;
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "[ I don't know what you're talking about. ]" << std::endl;
}
