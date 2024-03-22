# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/23 18:54:37 by fholwerd      #+#    #+#                  #
#    Updated: 2024/03/12 15:08:18 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= PmergeMe
SRC		= $(ROOT)main.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= 
LINKS	= 
FLAGS	= -Wall -Wextra -Werror -g -fsanitize=address #-std=c++98
CC		= c++

all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "Compiling executable."
	@$(CC) $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean:
	@echo "Cleaning files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Cleaning executable."
	@rm -f $(NAME)

re: fclean all

.PHONY: all libs clean fclean re

