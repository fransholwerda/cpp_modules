/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:33:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 15:26:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
