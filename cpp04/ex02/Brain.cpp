/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 11:05:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 11:08:05 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
	return ;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copied" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
	return ;
}

Brain		&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			setIdea(i, rhs.getIdea(i));
	}
	return (*this);
}

std::string	Brain::showIdeas(void) const
{
	std::string	ideas;

	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i] != "")
		{
			ideas += this->_ideas[i];
			ideas += "\n";
		}
	}
	return (ideas);
}

void		Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
	return ;
}

std::string	Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}
