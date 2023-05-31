/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 18:58:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 12:24:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return ;
}

Cat		&Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
	return ;
}
