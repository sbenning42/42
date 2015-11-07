# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 13:50:09 by sbenning          #+#    #+#              #
#    Updated: 2015/06/11 03:04:49 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME =		server

SRC =		error.c\
			comm.c\
			server.c\
			main.c

LIB =		libft.a

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

OBJ =	$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -I $(HEADERS) -o $(NAME) $(LIB) $^

%.o: $(addprefix srcs/, %.c)
	$(CC) $(FLAGS) -c $^ -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

