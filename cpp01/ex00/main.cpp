/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:31:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/22 14:15:00 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

void	leaks(void)
{
	system("leaks -q Brainz");
}

int	main(void)
{
	Zombie	*zombie;

	atexit(&leaks);
	std::cout << "Creating a zombie on the stack." << std::endl;
	Zombie stackZombie("Stack Zombie");
	stackZombie.announce();
	std::cout << std::endl;

	std::cout << "Creating a zombie on the heap." << std::endl;
	zombie = newZombie("Heap Zombie");
	zombie->announce();
	std::cout << "Destroying the heap zombie." << std::endl;
	delete zombie;
	std::cout << std::endl;

	std::cout << "Creating a random zombie on the stack, this one is immediately destroyed." << std::endl;
	randomChump("Random Stack Zombie");
	std::cout << std::endl;

	std::cout << "Exiting the program, it automatically destroys the Stack Zombie." << std::endl;
	return (0);
}
