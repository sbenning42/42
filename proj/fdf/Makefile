# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/25 11:26:54 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		fdf

NAME_NUX =		fdf_nux

SRC =		lib/gnl/get_next_line.c\
			srcs/fdf_action.c\
			srcs/fdf_action2.c\
			srcs/fdf_get.c\
			srcs/fdf_save.c\
			srcs/fdf_free.c\
			srcs/fdf_khdl.c\
			srcs/fdf_khdl2.c\
			srcs/fdf_key.c\
			srcs/fdf_info.c\
			srcs/fdf_bresenham.c\
			srcs/fdf_constructor.c\
			srcs/fdf_maj.c\
			srcs/fdf_map.c\
			srcs/fdf_draw.c\
			srcs/fdf_msg.c\
			srcs/fdf_mlx.c\
			srcs/fdf_lexer.c\
			srcs/fdf_parser.c\
			srcs/main.c

DEPEND =	includes/fdf.h

OBJ =		$(SRC:.c=.o)

FRAMEWORK =	-framework OpenGL -framework AppKit

LIB_FT =	libft.a

#LIB_MLX	=	libmlx.a.old.a

LIB_MLX_NUX	=	libmlx.a

LIB_FT_DIR =	lib/ft

LIB_MLX_DIR = 	lib/mlx

LIB_MLX_NUX_DIR = 	lib/mlx_nux

LIB =		-lft\
			-lmlx

LIB_NUX =	-lmlx -lXext -lX11

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all : $(LIB_FT) $(LIB_MLX) $(NAME)

nux : $(LIB_FT_NUX) $(LIB_MLX) $(NAME_NUX)

$(NAME) : $(OBJ)
	$(CC) -o $@ -I $(HEADERS) $^ -L $(LIB_FT_DIR) -L $(LIB_MLX_DIR) $(LIB) $(FRAMEWORK)

$(NAME_NUX) : $(OBJ) $(DEPEND)
	$(CC) -o $(NAME_NUX) -I $(HEADERS) $(OBJ) lib/ft/libft.a -L $(LIB_FT_DIR) -L $(LIB_MLX_NUX_DIR) $(LIB_NUX)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

$(LIB_FT_NUX) :
	make re -C $(LIB_FT_DIR)

$(LIB_MLX) :
	make -C $(LIB_MLX_DIR)

$(LIB_MLX_NUX) :
	make -C $(LIB_MLX_NUX_DIR)

%.o : %.c $(DEPEND)
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
