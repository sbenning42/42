# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 13:50:09 by sbenning          #+#    #+#              #
#    Updated: 2015/05/27 13:50:14 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME =		Computerv1

SRC =		ft_isdigit.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memalloc.c\
			ft_memchr.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_strncpy.c\
			dyntab.c\
			libft_ext.c\
			math.c\
			err.c\
			lexer.c\
			parser.c\
			resolve.c\
			resolve_square.c\
			discriminent.c\
			handle.c\
			main.c


HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

OBJ =	$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -I $(HEADERS) -o $(NAME)

%.o: $(addprefix srcs/, %.c)
	$(CC) $(FLAGS) -c $^ -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

