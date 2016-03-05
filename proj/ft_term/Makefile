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

NAME =			readline

SRC =			ft_exit.c\
				main.c\
				ft_term.c\
				global.c\
				rl_echo.c\
				rl_expand.c\
				rl_flush.c\
				rl_handle.c\
				rl_handle_suite.c\
				rl_history_handle.c\
				rl_init.c\
				rl_maj.c\
				rl_pop.c\
				rl_push.c\
				rl_readline.c\
				get_next_line.c\
				rl_history_getrl.c\
				rl_history.c\
				ft_readline.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIB =		libft.a

LIB =			ft

TERM =			termcap

LIB_DIR =		lib/

HEADER =		includes

DEPEND =		$(HEADER)/ft_term.h\
				$(HEADER)/ft_readline.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(OBJ_LIB) $(NAME)

$(OBJ_LIB) :
	make -C $(LIB_DIR)$(LIB)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ -L $(LIB_DIR)$(LIB) -l$(LIB) -l$(TERM)
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
