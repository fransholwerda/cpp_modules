/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:22:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 13:40:28 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	one("Clap");
	ScavTrap	two("Scav");

	std::cout << "\nClap attacks Scav" << std::endl << "----------------" << std::endl;
	one.attack("Scav");
	std::cout << "\nScav takes 5 damage" << std::endl << "----------------" << std::endl;
	two.takeDamage(5);
	std::cout << "\nScav repairs 3 hit points" << std::endl << "----------------" << std::endl;
	two.beRepaired(3);
	std::cout << "\nScav takes 50 damage" << std::endl << "----------------" << std::endl;
	two.takeDamage(50);
	std::cout << "\nScav attempts to repair 5 hit points" << std::endl << "----------------" << std::endl;
	two.beRepaired(5);
	std::cout << "\nScav attempts to attack Clap" << std::endl << "----------------" << std::endl;
	two.attack("Clap");
	std::cout << "\nScav goes into Gate keeper mode" << std::endl << "----------------" << std::endl;
	two.guardGate();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
