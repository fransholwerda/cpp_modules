/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:31:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 13:38:37 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// First, implement a Zombie class. It has a string private attribute name.
// Add a member function void announce( void ); to the Zombie class. Zombies
// announce themselves as follows:
// <name>: BraiiiiiiinnnzzzZ...
// Don’t print the angle brackets (< and >). For a zombie named Foo, the message
// would be:
// Foo: BraiiiiiiinnnzzzZ...
// Then, implement the two following functions:
// • Zombie* newZombie( std::string name );
// It creates a zombie, name it, and return it so you can use it outside of the function
// scope.
// • void randomChump( std::string name );
// It creates a zombie, name it, and the zombie announces itself.
// Now, what is the actual point of the exercise? You have to determine in what case
// it’s better to allocate the zombies on the stack or heap.
// Zombies must be destroyed when you don’t need them anymore. The destructor must
// print a message with the name of the zombie for debugging purposes.

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

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
