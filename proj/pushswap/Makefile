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

NAME =			push_swap

SRC =			srcs/main.c\
				srcs/pushswap.c\
				srcs/reverse.c\
				srcs/nosort.c\
				srcs/sort.c\
				srcs/roll.c\
				srcs/getopt.c\
				srcs/operator_simple.c\
				srcs/operator_multiple.c\
				srcs/debug.c\
				srcs/error.c

OBJ =			$(SRC:.c=.o)

LIB_FT =		libft.a

LIB_FT_DIR =	lib/ft

LIB =			-lft

HEADERS =		includes

DEPEND =		$(HEADERS)/pushswap.h

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

all : $(LIB_FT) $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ -L $(LIB_FT_DIR) $(LIB)

$(LIB_FT) :
	make -C $(LIB_FT_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAGS) -o $@ -I $(LIB_FT_DIR)/$(HEADERS) -I $(HEADERS) -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_FT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_FT_DIR)/$(LIB_FT)

re: fclean all
