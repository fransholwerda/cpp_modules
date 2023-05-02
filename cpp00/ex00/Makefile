# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/23 18:54:37 by fholwerd      #+#    #+#                  #
#    Updated: 2023/05/02 18:34:48 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= megaphone
SRC		= $(ROOT)megaphone.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= 
LINKS	= 
FLAGS	= -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
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

