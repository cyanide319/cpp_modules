# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tristan <tristan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:29:44 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/05/18 14:58:12 by tristan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRCS = main.cpp \
		Form.cpp \
		Bureaucrat.cpp \

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