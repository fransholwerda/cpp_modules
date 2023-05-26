/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 18:42:19 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/26 18:42:52 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &src);
		virtual ~Animal(void);

		Animal			&operator=(const Animal &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string		_type;
};

#endif
