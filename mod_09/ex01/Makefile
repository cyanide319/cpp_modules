# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:29:44 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/08/18 15:04:22 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS = main.cpp \
		RPN.cpp \

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



leak: re
		leaks --atExit -- ./$(NAME) "1 1 + 2 - 4 + 2 * 5 *"
		leaks --atExit -- ./$(NAME) "1 1 + 2 - 4 + 2 * 5"
		leaks --atExit -- ./$(NAME) "1 1 + 2 - 4343243243242 + 2 * 5 *"
		leaks --atExit -- ./$(NAME) "1 a + 2 - 4 + 2 * 5 *"