/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:24:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 13:47:58 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode." << std::endl;
	return ;
}
