#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/03/30 15:42:52 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			minishell

SRC =			main.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIBFT =		libft.a

OBJ_LIBRL =		libftreadline.a

LIBFT =			ft

LIBRL =			ftreadline

TERM =			termcap

LIB_DIR =		lib/

HEADER =		includes

LIB =			-L $(LIB_DIR)$(LIBRL) -l$(LIBRL) -L $(LIB_DIR)$(LIBFT) -l$(LIBFT) -l$(TERM)

LIBHEADER =		-I $(LIB_DIR)$(LIBFT)/$(HEADER) -I $(LIB_DIR)$(LIBRL)/$(HEADER)

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(OBJ_LIBFT) $(OBJ_LIBRL) $(NAME)

$(OBJ_LIBFT) :
	make -C $(LIB_DIR)$(LIBFT)

$(OBJ_LIBRL) :
	make -C $(LIB_DIR)$(LIBRL)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(LIB) 
	mv $^ $(OBJ_DIR)

%.o : %.c
	$(CC) $(FLAG) -I $(HEADER) $(LIBHEADER) -o $@ -c $<

clean :
	rm -rf $(COBJ)
	make clean -C $(LIB_DIR)$(LIBFT)
	make clean -C $(LIB_DIR)$(LIBRL)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)$(LIBFT)/$(OBJ_LIBFT)
	rm -rf $(LIB_DIR)$(LIBFTRL)/$(OBJ_LIBRL)

re : fclean all
