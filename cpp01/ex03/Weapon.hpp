/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 17:26:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/04 12:24:59 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(std::string type);
	Weapon();
	~Weapon();
	const std::string&	getType() const;
	void				setType(std::string type);
};

#endif
