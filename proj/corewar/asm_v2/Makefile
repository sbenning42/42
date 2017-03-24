#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2017/03/09 15:07:24 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			myasm

SRC =			main.c\
				proginfo.c\
				ft_getopt.c\
				cursor_singleton.c\
				asm_gramm.c\
				asm_logic.c\
				asm_match.c\
				asm_parser.c\
				get_next_line.c\
				op.c
#lexer_dump.c
#token.c

SRC_DIR =		srcs/
OBJ_DIR =		obj/

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

DEPEND =		asm.h\
				op.h

ABS_DEPEND =	$(addprefix $(HEADER)/, $(DEPEND))

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIBFT_DIR =		libft

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) : $(ABS_OBJ)
	$(CC) $(FLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT)

$(COR_OBJ) : $(COR_SRC) $(ABS_DEPEND)
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
