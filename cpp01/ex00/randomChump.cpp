/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:48:33 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 12:49:11 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
