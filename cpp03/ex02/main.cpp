/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:22:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 13:56:45 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	one("Clap");
	ScavTrap	two("Scav");
	FragTrap	three("Frag");

	std::cout << "\nFrag attacks Clap" << std::endl << "----------------" << std::endl;
	three.attack("Clap");
	std::cout << "\nClap takes 5 damage" << std::endl << "----------------" << std::endl;
	one.takeDamage(5);
	std::cout << "\nClap repairs 3 hit points" << std::endl << "----------------" << std::endl;
	one.beRepaired(3);
	std::cout << "\nClap takes 50 damage" << std::endl << "----------------" << std::endl;
	one.takeDamage(50);
	std::cout << "\nClap attempts to repair 5 hit points" << std::endl << "----------------" << std::endl;
	one.beRepaired(5);
	std::cout << "\nClap attempts to attack Frag" << std::endl << "----------------" << std::endl;
	one.attack("Frag");

	std::cout << "\nClap attacks Frag" << std::endl << "----------------" << std::endl;
	one.attack("Frag");
	std::cout << "\nFrag takes 5 damage" << std::endl << "----------------" << std::endl;
	three.takeDamage(5);
	std::cout << "\nFrag repairs 3 hit points" << std::endl << "----------------" << std::endl;
	three.beRepaired(3);
	std::cout << "\nFrag takes 500 damage" << std::endl << "----------------" << std::endl;
	three.takeDamage(500);
	std::cout << "\nFrag attempts to repair 5 hit points" << std::endl << "----------------" << std::endl;
	three.beRepaired(5);
	std::cout << "\nFrag attempts to attack Clap" << std::endl << "----------------" << std::endl;
	three.attack("Clap");

	std::cout << "\nFrag request a high five" << std::endl << "----------------" << std::endl;
	three.highFivesGuys();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
