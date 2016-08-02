# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#*   Updated: 2016/04/28 19:03:06 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		libftreadline.a

SRC =		main/ft_readline.c\
			rl/rl_id.c\
			tool/get_next_line.c\
			rl/rl_read.c\
			rl/rl_maj.c\
			rl/rl_code.c\
			rl/rl_dump.c\
			rl/rl_display.c\
			tool/dyn_strpush.c\
			rl/rl_global.c\
			rl/rl_code_quit.c\
			rl/rl_code_arrow.c\
			rl/rl_code_moves.c\
			rl/rl_code_word_moves.c\
			rl/rl_code_other_moves.c\
			rl/rl_code_select.c\
			rl/rl_cpy.c\
			rl/rl_cut.c\
			cursor/cur_ask.c\
			cursor/cur_capability.c\
			cursor/cur_clear.c\
			cursor/cur_fmotion.c\
			cursor/cur_get.c\
			cursor/cur_global.c\
			cursor/cur_goto.c\
			cursor/cur_init.c\
			cursor/cur_maj.c\
			cursor/cur_mode.c\
			cursor/cur_motion.c\
			cursor/cur_put.c\
			cursor/cur_write.c\
			cursor/cur_scroll.c\
			cursor/cur_set.c\
			cursor/cur_signal.c\
			cursor/cur_term.c\
			cursor/cur_xmotion.c\
			history/hist_dump.c\
			history/hist_load.c\
			history/hist_save.c\
			history/hist_copy.c

OBJ =		$(SRC:.c=.o)

HEADERS =	includes

CC =		clang

FLAGS =		-Wall -Wextra -Wpedantic -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c $(HEADERS)/ft_readline.h
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADERS) -I ../ft/includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

