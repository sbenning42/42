# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#*   Updated: 2016/03/19 19:10:18 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		libftreadline.a

SRC =		ft_readline.c\
			rl_id.c\
			rl_term.c\
			rl_history.c\
			get_next_line.c\
			rl_read.c\
			rl_maj.c\
			rl_code.c\
			rl_echo.c\
			dyn_strpush.c\
			rl_global.c\
			rl_code_p1.c\
			rl_code_p2.c\
			rl_code_p3.c\
			rl_code_p4.c

OBJ =		$(SRC:.c=.o)

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

