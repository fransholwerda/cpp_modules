/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 17:31:28 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/23 18:51:21 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	one("Clap");
	ClapTrap	two("Trap");

	std::cout << "\nClap attacks Trap" << std::endl << "----------------" << std::endl;
	one.attack("Trap");
	std::cout << "\nTrap takes 5 damage" << std::endl << "----------------" << std::endl;
	two.takeDamage(5);
	std::cout << "\nTrap repairs 3 hit points" << std::endl << "----------------" << std::endl;
	two.beRepaired(3);
	std::cout << "\nTrap takes 50 damage" << std::endl << "----------------" << std::endl;
	two.takeDamage(50);
	std::cout << "\nTrap attempts to repair 5 hit points" << std::endl << "----------------" << std::endl;
	two.beRepaired(5);
	std::cout << "\nTrap attempts to attack Clap" << std::endl << "----------------" << std::endl;
	two.attack("Clap");
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
