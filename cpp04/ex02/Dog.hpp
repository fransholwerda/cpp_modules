/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:14:59 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 12:24:09 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &src);
		virtual	~Dog(void);

		Dog		&operator=(const Dog &rhs);

		Brain	*getBrain(void) const;
		void	makeSound(void) const;
	private:
		Brain	*_brain;
};

#endif
