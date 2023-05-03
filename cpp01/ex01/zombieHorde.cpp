/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 14:19:34 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 15:55:32 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	std::string	zombie_name;

	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombie_name = name + std::to_string(i);
		zombies[i].setName(zombie_name);
	}
	return (zombies);
}
