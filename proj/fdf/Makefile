# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#    Updated: 2015/12/01 12:20:12 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRC =		lib/lexer/srcs/get_next_line.c\
			lib/lexer/srcs/lexer_ini.c\
			lib/lexer/srcs/lexer_token.c\
			lib/lexer/srcs/lexer_chr.c\
			lib/lexer/srcs/lexer.c\
			srcs/fdf.c\
			srcs/fdf_lexer.c\
			srcs/main.c

OBJ =		$(SRC:.c=.o)

LIB =		-lft\
			-lmlx

FRAMEWORK =	-framework OpenGL -framework AppKit

LIB_DIR =	lib/ft
			
HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) -o $(NAME) -I $(HEADERS) $(OBJ) -L $(LIB_DIR) $(LIB) $(FRAMEWORK)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -I $(HEADERS) -c $<

$(LIB) :
	make -C $(LIB_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

