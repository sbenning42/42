# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#    Updated: 2015/11/30 17:49:07 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRC =		srcs/fdf.c\
			srcs/fdf_lexer.c\
			srcs/main.c
	
LIB =		lib/ft/libft.a\
			lib/lexer/srcs/get_next_line.c\
			lib/lexer/srcs/lexer_ini.c\
			lib/lexer/srcs/lexer_token.c\
			lib/lexer/srcs/lexer_chr.c\
			lib/lexer/srcs/lexer.c

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

$(NAME) :
	$(CC) -o $(NAME) -I $(HEADERS) $(SRC) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

