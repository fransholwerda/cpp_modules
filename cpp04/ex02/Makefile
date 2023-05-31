# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/23 18:54:37 by fholwerd      #+#    #+#                  #
#    Updated: 2023/05/31 13:03:12 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= Abstract
SRC		= $(ROOT)main.cpp \
			$(ROOT)Animal.cpp \
			$(ROOT)Brain.cpp \
			$(ROOT)Dog.cpp \
			$(ROOT)Cat.cpp \
			$(ROOT)WrongAnimal.cpp \
			$(ROOT)WrongCat.cpp
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

