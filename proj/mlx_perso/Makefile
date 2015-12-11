# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/11 01:36:11 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		gen

NAME_NUX =		gen_nux

SRC =		srcs/main.c
		#	lib/lexer/srcs/get_next_line.c\
			lib/lexer/srcs/lexer_ini.c\
			lib/lexer/srcs/lexer_token.c\
			lib/lexer/srcs/lexer_chr.c\
			lib/lexer/srcs/lexer.c\
			srcs/math_mat.c\
			srcs/gen_mlx.c\
			srcs/gen_parser.c

OBJ =		$(SRC:.c=.o)

FRAMEWORK =	-framework OpenGL -framework AppKit

LIB_FT =	libft.a

LIB_MLX	=	libmlx.a.old.a

LIB_MLX_NUX	=	libmlx.a

LIB_FT_DIR =	lib/ft

LIB_MLX_DIR = 	lib/mlx

LIB_MLX_NUX_DIR = 	lib/mlx_nux

LIB =		-lft\
			-lmlx

LIB_NUX =	-lmlx -lXext -lX11

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

nux : $(NAME_NUX)

$(NAME) : $(LIB_FT) $(LIB_MLX) $(OBJ)
	$(CC) -o $(NAME) -I $(HEADERS) $(OBJ) -L $(LIB_FT_DIR) -L $(LIB_MLX_DIR) $(LIB) $(FRAMEWORK)

$(NAME_NUX) : $(LIB_FT_NUX) $(LIB_MLX_NUX) $(OBJ)
	$(CC) -o $(NAME_NUX) -I $(HEADERS) $(OBJ) lib/ft/libft.a -L $(LIB_FT_DIR) -L $(LIB_MLX_NUX_DIR) $(LIB_NUX)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

$(LIB_FT_NUX) :
	make re -C $(LIB_FT_DIR)

$(LIB_MLX) :
	make -C $(LIB_MLX_DIR)

$(LIB_MLX_NUX) :
	make -C $(LIB_MLX_NUX_DIR)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -I $(HEADERS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)
	make clean -C $(LIB_MLX_DIR)

clean_nux:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)
	make clean -C $(LIB_MLX_NUX_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_FT_DIR)

fclean_nux : clean_nux
	rm -f $(NAME_NUX)
	make re -C $(LIB_FT_DIR)
re: fclean all

re_nux: fclean_nux nux
