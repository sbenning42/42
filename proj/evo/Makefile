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

NAME =		evo

NAME_NUX =	evo_nux

SRC =		srcs/main.c\
			srcs/evo.c\
			srcs/msg.c\
			srcs/random.c

DEPEND =	includes/evo.h

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

FLAGS =		-Wall -Wextra -Werror

all : $(LIB_FT) $(LIB_MLX) $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ -I $(HEADERS) $^ -L $(LIB_FT_DIR) -L $(LIB_MLX_DIR) $(LIB) $(FRAMEWORK)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

$(LIB_MLX) :
	make -C $(LIB_MLX_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAGS) -o $@ -I $(HEADERS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)
	make clean -C $(LIB_MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_FT_DIR)

re: fclean all
