#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/05/30 15:42:02 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			ftcd

MAIN_SRC =		main.c\
				get_opt.c

OBJ_DIR =		obj/
SRC_DIR =		srcs/
MAIN_DIR =		main/

MAIN =			$(addprefix $(MAIN_DIR), $(MAIN_SRC))

SRC =			$(MAIN)

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIB_DIR =		lib/

LIBFT_DIR =		$(addprefix $(LIB_DIR), $(LIBFT))

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			clang

FLAG =			-Wall -Wextra -Wpedantic -Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) : $(ABS_OBJ)
	$(CC) $(FLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT)

$(COR_OBJ) : $(COR_SRC)
	$(CC) $(FLAG) -o $@ -c $< -I$(HEADER) -I$(LIBFT_HEADER)

$(ABS_OBJ_LIBFT) :
	make -C $(LIBFT_DIR)

lclean :
	make clean -C $(LIBFT_DIR)

lfclean :
	make fclean -C $(LIBFT_DIR)

lre : 
	make re -C $(LIBFT_DIR)

clean :
	rm -f $(ABS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

config :
	mkdir -p $(addprefix $(OBJ_DIR), $(MAIN_DIR))
