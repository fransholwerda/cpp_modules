/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:20:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 19:21:43 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string		WrongAnimal::getType(void) const
{
	return (this->_type);
}

void			WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound" << std::endl;
	return ;
}
