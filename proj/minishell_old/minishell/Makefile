#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/03/19 17:20:49 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			minishell

SRC =			main.c\
				minishell.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIBFT =		libft.a

OBJ_LIBCAP =	libftcap.a

OBJ_LIBRL =		libftreadline.a

LIBFT =			ft

LIBFTCAP =		ftcap

LIBRL =			ftreadline

TERM =			termcap

LIB_DIR =		lib/

HEADER =		includes

LIB =			-L $(LIB_DIR)$(LIBRL) -l$(LIBRL) -L $(LIB_DIR)$(LIBFTCAP) -l$(LIBFTCAP) -L $(LIB_DIR)$(LIBFT) -l$(LIBFT) -l$(TERM)

LIBHEADER =		-I $(LIB_DIR)$(LIBFT)/$(HEADER) -I $(LIB_DIR)$(LIBFTCAP)/$(HEADER) -I $(LIB_DIR)$(LIBRL)/$(HEADER)

DEPEND =		$(HEADER)/minishell.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(OBJ_LIBFT) $(OBJ_LIBCAP) $(OBJ_LIBRL) $(NAME)

$(OBJ_LIBFT) :
	make -C $(LIB_DIR)$(LIBFT)

$(OBJ_LIBCAP) :
	make -C $(LIB_DIR)$(LIBFTCAP)

$(OBJ_LIBRL) :
	make -C $(LIB_DIR)$(LIBRL)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(LIB) 
	mv $^ $(OBJ_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAG) -I $(HEADER) $(LIBHEADER) -o $@ -c $<

clean :
	rm -rf $(COBJ)
	make clean -C $(LIB_DIR)$(LIBFT)
	make clean -C $(LIB_DIR)$(LIBFTCAP)
	make clean -C $(LIB_DIR)$(LIBRL)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)$(LIBFT)/$(OBJ_LIBFT)
	rm -rf $(LIB_DIR)$(LIBFTCAP)/$(OBJ_LIBCAP)
	rm -rf $(LIB_DIR)$(LIBFTRL)/$(OBJ_LIBRL)

re : fclean all
