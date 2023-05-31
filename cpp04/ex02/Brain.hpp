/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 19:33:25 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/31 11:18:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);

		Brain		&operator=(const Brain &rhs);

		std::string	showIdeas(void) const;
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
	private:
		std::string	_ideas[100];
};

#endif
