# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#    Updated: 2014/12/09 12:43:13 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRC =		ft_bzero.c\
			ft_memalloc.c\
			ft_memchr.c\
			ft_memdel.c\
			ft_memset.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strexp.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strncpy.c\
			ft_strnew.c\

SRC_PATH =	./srcs/

OBJ =		$(SRC:.c=.o)

HEADERS =	./includes

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) : $(addprefix $(SRC_PATH), $(SRC))
	$(CC) $(FLAGS) -c $(addprefix $(SRC_PATH), $(SRC)) -I $(HEADERS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

