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
				srcs/get_opt.c\
				srcs/tree.c\
				srcs/select.c\
				srcs/argv.c\
				srcs/dir.c\
				srcs/ls_avsort.c\
				srcs/ls_sort.c\
				srcs/ls_print.c\
				srcs/name.c\
				srcs/ft_err.c\
				srcs/format_mode.c\
				srcs/format_name.c\
				srcs/format_time.c\
				srcs/ft_intlen.c

OBJ =			$(SRC:.c=.o)

LIB_FT =		libft.a

LIB_FT_DIR =	lib/ft

LIB =			-lft

HEADERS =		includes

DEPEND =		$(HEADERS)/ft_ls.h

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
