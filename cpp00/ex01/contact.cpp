/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:13:41 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 12:29:45 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "Contact.hpp"

/* This is the constructor */
Contact::Contact(){}

/* This is the destructor */
Contact::~Contact(){}

/* This function will ask for user input, validate it and return it*/
std::string	user_input(std::string prompt)
{
	std::string	input;
	bool		valid = false;

	while (!valid)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		else if (std::cin.good() && !input.empty())
			valid = true;
		else
			std::cout << "Invalid input, please try again." << std::endl;
	}
	return (input);
}

bool	Contact::is_empty(void)
{
	if (this->first_name.empty())
		return (true);
	return (false);
}

/* This function will set the info of the contact */
void	Contact::set_info(void)
{
	this->first_name = user_input("First name: ");
	this->last_name = user_input("Last name: ");
	this->nickname = user_input("Nickname: ");
	this->phone_number = user_input("Phone number: ");
	this->darkest_secret = user_input("Darkest secret: ");
	std::cout << "Contact added!" << std::endl;
	return ;
}

void	Contact::print_basic(void)
{
	if (this->first_name.empty())
		return ;
	if (this->first_name.length() > 10)
		std::cout << this->first_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->first_name << "|";
	if (this->last_name.length() > 10)
		std::cout << this->last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->last_name << "|";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->nickname << "|";
	std::cout << std::endl;
	return ;
}

void	Contact::print_all(void)
{
	if (this->first_name.empty())
		return ;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
	return ;
}
