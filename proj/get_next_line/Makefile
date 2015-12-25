#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/20 02:27:34 by sbenning          #+#    #+#             *#
#*   Updated: 2015/12/20 14:56:53 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = gnl

SRC = main.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

LIBFT = libft.a

LIB = ft

LIBFT_DIR = ft/

FT_HEADER = includes

HEADER = .

DEP = get_next_line.h

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJ)
	gcc -Wextra -Wall -Werror -o $@ $^ -L $(LIBFT_DIR) -l$(LIB) 

%.o : %.c $(DEP)
	gcc -Wextra -Wall -Werror -I $(LIBFT_DIR)$(FT_HEADER) -I $(HEADER) -c -o $@ $<
