#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/11/29 00:07:46 by sbenning          #+#    #+#             *#
#*   Updated: 2015/11/29 12:04:56 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME =	lexer

SRC =	srcs/get_next_line.c\
		srcs/lexer_chr.c\
		srcs/lexer_token.c\
		srcs/lexer_ini.c\
		srcs/lexer.c\
		main.c
	

LIB =		lib/ft/libft.a

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -I $(HEADERS) -o $(NAME) $(SRC) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

