/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:35:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 13:28:58 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
