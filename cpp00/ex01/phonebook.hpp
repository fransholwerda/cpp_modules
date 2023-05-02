/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:58:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/02 15:38:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	size_t	contact_index;
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact();
	void	search_contact();
};

#endif
