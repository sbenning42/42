# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#*   Updated: 2016/03/19 16:40:07 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =		libftcap.a

SRC =		ft_initcap.c\
			ft_cap.c

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

