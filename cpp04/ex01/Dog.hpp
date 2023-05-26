/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:14:59 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 19:17:22 by fholwerd      ########   odam.nl         */
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
		virtual ~Dog(void);

		Dog				&operator=(const Dog &rhs);

		virtual void	makeSound(void) const;
};

#endif
