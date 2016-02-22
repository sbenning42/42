#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/02/14 23:27:05 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			42sh

SRC =			main.c\
				hook_init.c\
				hook_input.c\
				hook_read.c\
				hook_buffer.c\
				hook_handle.c\
				hook_control.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIB =		libft.a

LIB =			ft

LIB_DIR =		lib/

HEADER =		includes

DEPEND =		$(HEADER)/hook.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(OBJ_LIB) $(NAME)

$(OBJ_LIB) :
	make -C $(LIB_DIR)$(LIB)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR)$(LIB) -l$(LIB)
	mv $^ $(OBJ_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAG) -I $(HEADER) -I $(LIB_DIR)$(LIB)/$(HEADER) -o $@ -c $<

clean :
	rm -rf $(COBJ)
	make clean -C $(LIB_DIR)$(LIB)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)$(LIB)/$(OBJ_LIB)

re : fclean all
