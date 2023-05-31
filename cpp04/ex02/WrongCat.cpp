/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:24:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 19:26:51 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat		&WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void			WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
	return ;
}
