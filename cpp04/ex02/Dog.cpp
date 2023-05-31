/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:16:43 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 12:24:14 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return ;
}

Dog		&Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
	return ;
}
