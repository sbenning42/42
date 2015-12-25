#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/25 09:56:20 by sbenning          #+#    #+#             *#
#*   Updated: 2015/12/25 13:05:00 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =		fillit

SRC =		main.c\
			fillit.c\
			parse.c

SRC_DIR =	srcs/

OBJ =		$(addprefix $(SRC_DIR), $(SRC:.c=.o))

LIBFT =		libft.a

LIB =		ft

LIB_DIR =	lib/

HEADER =	includes/

DEP =		$(HEADER)fillit.h

CC =		gcc

FLAG = -Wall -Wextra -Werror

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C $(LIB_DIR)$(LIB)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR)$(LIB) -l$(LIB)

%.o : %.c $(DEP)
	$(CC) $(FLAG) -o $@ $< -c -I $(HEADER) -I $(LIB_DIR)$(LIB)/$(HEADER)

clean :
	make fclean -C $(LIB_DIR)$(LIB)
	rm -rf srcs/*.o
	rm -rf $(NAME)

re : clean all

