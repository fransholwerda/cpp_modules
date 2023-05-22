/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:27:28 by fholwerd      #+#    #+#                 */
/*   Updated: 2023/05/22 13:18:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	replace_string_in_file(const std::string &filename,
								const std::string &find,
								const std::string &replace)
{
	std::ifstream	ifs(filename);
	if (!ifs)
	{
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}
	std::ofstream	ofs(filename + ".replace");
	if (!ofs)
	{
		std::cout << "Error: could not create file" << std::endl;
		return ;
	}

	std::string	line;
	while (std::getline(ifs, line))
	{
		std::string	newline;
		size_t	pos = 0;
		while (pos < line.length())
		{
			size_t	next = line.find(find, pos);
			if (next == std::string::npos)
			{
				newline += line.substr(pos);
				break ;
			}
			newline += line.substr(pos, next - pos);
			newline += replace;
			pos = next + find.length();
		}
		ofs << newline << std::endl;
	}
	ifs.close();
	ofs.close();
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	find = argv[2];
	std::string	replace = argv[3];
	replace_string_in_file(filename, find, replace);
	return (0);
}
