# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/05 15:47:37 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		fdf

NAME_NUX =		fdf_nux

SRC =		lib/lexer/srcs/get_next_line.c\
			srcs/fdf_khdl.c\
			srcs/fdf_key.c\
			srcs/fdf_draw.c\
			srcs/fdf_mlx.c\
			srcs/fdf_lexer.c\
			srcs/fdf_parser.c\
			srcs/main.c
#			srcs/fdf_handle.c\
			srcs/fdf_mlx.c\
			srcs/fdf_exec.c\
			srcs/fdf.c\

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
