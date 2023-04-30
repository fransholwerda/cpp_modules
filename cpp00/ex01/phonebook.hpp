/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:58:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/04/28 14:42:10 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	size_t	amount;
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact();
	void	search_contact();
};

#endif
