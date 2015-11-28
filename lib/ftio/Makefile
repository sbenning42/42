#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/11/15 20:51:54 by sbenning          #+#    #+#             *#
#*   Updated: 2015/11/19 18:00:01 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =		test_ftio
SRC =		srcs/ftio_term.c \
			main.c \
			srcs/ftio_read.c \
			srcs/ftio_error.c \
			srcs/ftio_env.c
#			srcs/ftio_signal.c \
			srcs/ftio_error.c \
			srcs/ftio_perform.c \
			srcs/ftio_env.c
LIB =		lib/libft.a
OBJ =		$(SRC:.c=.o)
HEADERS =	includes
CC =		gcc
T_FLAG =	-Wall
TV_FLAG =	$(T_FLAG) -Wextra
FLAG =		$(TV_FLAG) -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(T_FLAG) -o $(NAME) -I $(HEADERS) $(OBJ) $(LIB)

%.o:%.c
	$(CC) $(T_FLAG) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
