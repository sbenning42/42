#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/02/24 22:59:49 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			42sh

SRC =			main.c\
				hook_handler_arrow.c\
				hook_handler_conf.c\
				hook_input.c\
				hook_output.c\
				hook_manage.c\
				hook_buffer.c\
				hook_stack.c\
				hook_init.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIB =		libft.a

LIB =			ft

TERM =			termcap

LIB_DIR =		lib/

HEADER =		includes

DEPEND =		$(HEADER)/hook.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

DEF =			-D "INIT_SP {[0 ... 2047] == ' '}" -D "INIT_CL {[0 ... 2047] == '\b'}"

all : $(OBJ_LIB) $(NAME)

$(OBJ_LIB) :
	make -C $(LIB_DIR)$(LIB)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR)$(LIB) -l$(LIB) -l$(TERM)
	mv $^ $(OBJ_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAG) -I $(HEADER) -I $(LIB_DIR)$(LIB)/$(HEADER) -o $@ -c $< $(DEF)

clean :
	rm -rf $(COBJ)
	make clean -C $(LIB_DIR)$(LIB)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)$(LIB)/$(OBJ_LIB)

re : fclean all
