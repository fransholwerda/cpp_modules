# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/23 18:54:37 by fholwerd      #+#    #+#                  #
#    Updated: 2023/09/26 14:37:49 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= execute
SRC		= $(ROOT)main.cpp \
		  $(ROOT)AForm.cpp \
		  $(ROOT)Bureaucrat.cpp \
		  $(ROOT)ShrubberyCreationForm.cpp \
		  $(ROOT)RobotomyRequestForm.cpp \
		  $(ROOT)PresidentialPardonForm.cpp
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

