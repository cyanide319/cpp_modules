# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:29:44 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/04/20 18:10:26 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

SRCS = main.cpp \
		Cat.cpp \
		Dog.cpp \
		Animal.cpp \
		Brain.cpp \
		# WrongAnimal.cpp \


# CFLAGS = -Wall -Wextra -Werror -std=c++98
# CC = c++ -g

CC ?=	gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I$I
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	+= -I$I
DEBUG	= -g
SFLAGS	= -fsanitize=address

OBJS = $(SRCS:%cpp=%o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

execute: re
		./$(NAME)

leak: re
		leaks --atExit -- ./$(NAME)