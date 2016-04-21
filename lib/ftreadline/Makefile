# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#*   Updated: 2016/04/21 11:46:12 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		libftreadline.a

SRC =		ft_readline.c\
			rl_id.c\
			rl_history.c\
			get_next_line.c\
			rl_read.c\
			rl_maj.c\
			rl_code.c\
			dyn_strpush.c\
			rl_global.c\
			rl_code_p1.c\
			rl_code_p2.c\
			rl_code_p3.c\
			rl_code_p4.c\
			rl_code_p5.c\
			rl_code_p6.c\
			rl_cpy.c\
			rl_cut.c\
			cur_ask.c\
			cur_capability.c\
			cur_clear.c\
			cur_fmotion.c\
			cur_get.c\
			cur_global.c\
			cur_goto.c\
			cur_init.c\
			cur_maj.c\
			cur_mode.c\
			cur_motion.c\
			cur_put.c\
			cur_write.c\
			cur_scroll.c\
			cur_set.c\
			cur_signal.c\
			cur_term.c\
			cur_xmotion.c\
			hist_load.c\
			hist_save.c

OBJ =		$(SRC:.c=.o)

HEADERS =	includes

CC =		clang

FLAGS =		-Wall -Wextra -Wpedantic

all : $(NAME)

$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c $(HEADERS)/ft_readline.h
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

