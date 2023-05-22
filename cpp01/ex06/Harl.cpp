/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 13:26:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/22 14:08:31 by fholwerd      ########   odam.nl         */
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

static int	find_case(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	int	case_num = find_case(level);

	switch (case_num)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
