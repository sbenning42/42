# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:58:48 by sbenning          #+#    #+#              #
#*   Updated: 2015/12/13 20:18:19 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =			ft_ls

NAME_NUX =		ft_ls_nux

SRC =			srcs/main.c\
				srcs/ls_avsort.c\
				srcs/ls_avprint.c\
				srcs/ft_ls.c\
				srcs/get_opt.c\
				srcs/tree.c\
				srcs/ls_msg.c\
				srcs/verbose.c\
				srcs/name.c

DEPEND =		includes/ft_ls.h

OBJ =			$(SRC:.c=.o)

LIB_FT =		libft.a

LIB_FT_DIR =	lib/ft

LIB =			-lft

HEADERS =		includes

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

all : $(LIB_FT) $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ -I $(HEADERS) $^ -L $(LIB_FT_DIR) $(LIB)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAGS) -o $@ -I $(HEADERS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_FT_DIR)

re: fclean all
