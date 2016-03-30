#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/03/30 09:48:01 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			cursor

SRC =			main.c\
				term.c\
				mput.c\
				cur_init.c\
				cur_set.c\
				cur_signal.c\
				cur_scrinfo.c\
				cur_lico.c\
				cur_info.c\
				cur_limotion.c\
				cur_comotion.c\
				cur_xlicomotion.c\
				cur_clear.c\
				cur_mode.c\
				cur_read.c\
				cur_roll.c\
				cur_motion.c

SRC_DIR =		srcs/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(SRC_DIR), $(SRC:.c=.o))

COBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_LIBFT =		libft.a

LIBFT =			ft

TERM =			termcap

LIB_DIR =		lib/

HEADER =		includes

LIB =			-L $(LIB_DIR)$(LIBFT) -l$(LIBFT) -l$(TERM)

LIBHEADER =		-I $(LIB_DIR)$(LIBFT)/$(HEADER)

DEPEND =		$(HEADER)/cursor.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(OBJ_LIBFT) $(NAME)

$(OBJ_LIBFT) :
	make -C $(LIB_DIR)$(LIBFT)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(LIB) 
	mv $^ $(OBJ_DIR)

%.o : %.c $(DEPEND)
	$(CC) $(FLAG) -I $(HEADER) $(LIBHEADER) -o $@ -c $<

clean :
	rm -rf $(COBJ)
	make clean -C $(LIB_DIR)$(LIBFT)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB_DIR)$(LIBFT)/$(OBJ_LIBFT)

re : fclean all
