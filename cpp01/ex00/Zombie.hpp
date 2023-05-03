/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 12:33:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/03 13:19:57 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>

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
