# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 13:50:09 by sbenning          #+#    #+#              #
#    Updated: 2015/06/10 00:32:59 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME =		Client

SRC =		error.c\
			comm.c\
			cmd.c\
			client.c\
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

