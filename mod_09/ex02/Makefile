# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:29:44 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/08/25 15:47:15 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS = main.cpp \
		PmergeMe.cpp \

CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

OBJS = $(SRCS:%cpp=%o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o: $(SRCS) $(OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

exec: re
		./$(NAME)

100:
		@./$(NAME) `jot -r 100 1 100000 | tr '\n' ' '`

1000: 
		@./$(NAME) `jot -r 1000 1 100000 | tr '\n' ' '`

10000:
		@./$(NAME) `jot -r 10000 1 100000 | tr '\n' ' '`

leak: re
		leaks --atExit -- ./$(NAME)