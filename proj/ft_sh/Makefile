#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2015/12/19 00:09:57 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			ft_sh

SRC =			ft_sh.c\
				main.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

OBJ_LIB =		libft.a

LIB =			ft

LIB_DIR =		lib/

HEADER =		includes

CC =			gcc

FLAG =			-Wall -Wextra #-Werror

all : $(OBJ_LIB) $(OBJ) $(NAME)

$(OBJ_LIB) :
	make -C $(LIB_DIR)$(LIB)

$(NAME) : $(OBJ)
		$(CC) $(FLAG) -L $(LIB_DIR)$(LIB) -l$(LIB) -o $@ $^

%.o : %.c
	$(CC) $(FLAG) -I $(HEADER) -I $(LIB_DIR)$(LIB)/$(HEADER) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	make clean -C $(LIB_DIR)$(LIB)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)$(LIB)

re : fclean all
