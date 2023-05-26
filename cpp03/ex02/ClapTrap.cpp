/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 16:18:08 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/24 16:30:51 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = "ClapTrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
	return ;
}
