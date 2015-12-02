# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/01 19:56:54 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRC =		lib/lexer/srcs/get_next_line.c\
			lib/lexer/srcs/lexer_ini.c\
			lib/lexer/srcs/lexer_token.c\
			lib/lexer/srcs/lexer_chr.c\
			lib/lexer/srcs/lexer.c\
			srcs/fdf_handle.c\
			srcs/fdf_mlx.c\
			srcs/fdf_exec.c\
			srcs/fdf_lexer.c\
			srcs/fdf.c\
			srcs/main.c

OBJ =		$(SRC:.c=.o)

FRAMEWORK =	-framework OpenGL -framework AppKit

LIB_FT =	libft.a

LIB_MLX	=	libmlx.a

LIB_FT_DIR =	lib/ft

LIB_MLX_DIR = 	lib/mlx

LIB =		-lft\
			-lmlx

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

$(NAME) : $(LIB_FT) $(LIB_MLX) $(OBJ)
	$(CC) -o $(NAME) -I $(HEADERS) $(OBJ) -L $(LIB_FT_DIR) -L $(LIB_MLX_DIR) $(LIB) $(FRAMEWORK)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

$(LIB_MLX) :
	make -C $(LIB_MLX_DIR)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -I $(HEADERS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)
	make clean -C $(LIB_MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_FT_DIR)

re: fclean all

