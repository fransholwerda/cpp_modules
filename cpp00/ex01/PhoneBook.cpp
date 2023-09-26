/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:56:41 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 12:29:26 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_index = 0;
	return ;
}

PhoneBook::~PhoneBook(){}

static size_t	contact_count(Contact *contacts)
{
	unsigned int	count = 0;

	for (size_t i = 0; i < 8; i++)
	{
		if (!contacts[i].is_empty())
			count++;
	}
	return (count);
}

// This function will print the contacts in a table format
static void	print_table(Contact *contacts)
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for(size_t i = 0; i < 8; i++)
	{
		if (!contacts[i].is_empty())
		{
			std::cout << "|" << std::setw(10) << i << "|";
			contacts[i].print_basic();
		}
	}
	return ;
}

void	PhoneBook::add_contact(void)
{
	this->contacts[this->contact_index].set_info();
	this->contact_index++;
	if (this->contact_index > 7)
		this->contact_index = 0;
	return ;
}

void	PhoneBook::search_contact(void)
{
	bool			valid = false;
	std::string		input;

	if (contact_count(this->contacts) == 0)
	{
		std::cout << "No contacts found." << std::endl;
		return ;
	}	
	print_table(this->contacts);
	while (!valid)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		else if (std::cin.good() && !input.empty())
		{
			if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
			{
				if (this->contacts[input[0] - '0'].is_empty())
					std::cout << "Contact not found." << std::endl;
				else
				{
					this->contacts[input[0] - '0'].print_all();
					valid = true;
				}
			}
			else
				std::cout << "Invalid input, please try again." << std::endl;
		}
		else
			std::cout << "Invalid input, please try again." << std::endl;
	}
}
