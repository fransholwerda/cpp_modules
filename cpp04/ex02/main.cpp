/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 18:41:57 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 13:04:29 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void	leaks(void)
// {
// 	system("leaks -q Brain");
// 	return ;
// }

int main()
{
	// atexit(leaks);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	int		number_of_animals = 4;
	Animal	*animals[number_of_animals];

	for (int i = 0; i < number_of_animals; i++)
	{
		if (i < number_of_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}
	for (int i = 0; i < number_of_animals; i++)
		delete animals[i];

	std::cout << std::endl;
	Dog	*dog = new Dog();
	dog->getBrain()->setIdea(0, "Idea 1");
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	Dog *dog2 = new Dog(*dog);
	dog->getBrain()->setIdea(0, "Idea 2");
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog;
	delete dog2;

	return 0;
}
