/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:39:12 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 12:39:41 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}
