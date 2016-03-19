# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#*   Updated: 2016/03/19 13:32:47 by sbenning         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC =	ft_mem/ft_memset.c\
		ft_mem/ft_bzero.c\
		ft_mem/ft_memalloc.c\
		ft_mem/ft_memccpy.c\
		ft_mem/ft_memchr.c\
		ft_mem/ft_memcmp.c\
		ft_mem/ft_memcpy.c\
		ft_mem/ft_memdel.c\
		ft_mem/ft_membzdel.c\
		ft_mem/ft_memmove.c\
		ft_char/ft_isalnum.c\
		ft_char/ft_isalpha.c\
		ft_char/ft_isascii.c\
		ft_char/ft_isdigit.c\
		ft_char/ft_isprint.c\
		ft_char/ft_tolower.c\
		ft_char/ft_toupper.c\
		ft_str/ft_atoi.c\
		ft_str/ft_itoa.c\
		ft_str/ft_strcat.c\
		ft_str/ft_strchr.c\
		ft_str/ft_strclr.c\
		ft_str/ft_strcmp.c\
		ft_str/ft_strcpy.c\
		ft_str/ft_strdel.c\
		ft_str/ft_strdup.c\
		ft_str/ft_strequ.c\
		ft_str/ft_strexp.c\
		ft_str/ft_striter.c\
		ft_str/ft_striteri.c\
		ft_str/ft_strjoin.c\
		ft_str/ft_strlcat.c\
		ft_str/ft_strlen.c\
		ft_str/ft_strmap.c\
		ft_str/ft_strmapi.c\
		ft_str/ft_strncat.c\
		ft_str/ft_strncmp.c\
		ft_str/ft_strncpy.c\
		ft_str/ft_strnequ.c\
		ft_str/ft_strnew.c\
		ft_str/ft_strnstr.c\
		ft_str/ft_strrchr.c\
		ft_str/ft_strsplit.c\
		ft_str/ft_strstr.c\
		ft_str/ft_strsub.c\
		ft_str/ft_strtrim.c\
		ft_str/ft_strupper.c\
		ft_str/ft_strlower.c\
		ft_wchar/ft_wclen.c\
		ft_wchar/ft_wctoa.c\
		ft_put/ft_putchar.c\
		ft_put/ft_putchar_fd.c\
		ft_put/ft_putendl.c\
		ft_put/ft_putendl_err.c\
		ft_put/ft_putstr_err.c\
		ft_put/ft_putchar_err.c\
		ft_put/ft_putnbr_err.c\
		ft_put/ft_putendl_fd.c\
		ft_put/ft_putnbr.c\
		ft_put/ft_putnbr_fd.c\
		ft_put/ft_putstr.c\
		ft_put/ft_putstr_fd.c\
		ft_buff/ft_buffnew.c\
		ft_buff/ft_buffexp.c\
		ft_buff/ft_buffdel.c\
		ft_lst/ft_lstnew.c\
		ft_lst/ft_lstdelone.c\
		ft_lst/ft_lstdel.c\
		ft_lst/ft_lstadd.c\
		ft_lst/ft_lstiter.c\
		ft_lst/ft_lstadd_back.c\
		ft_lst/ft_lstmap.c\
		ft_dlst/ft_dlstnew.c\
		ft_dlst/ft_dlstdelone.c\
		ft_dlst/ft_dlstdel.c\
		ft_dlst/ft_dlstaddp.c\
		ft_dlst/ft_dlstaddn.c\
		ft_dlst/ft_dlstaddip.c\
		ft_dlst/ft_dlstaddin.c\
		ft_dlst/ft_dlstmap.c\
		ft_dar/ft_darnew.c\
		ft_dar/ft_daradd.c\
		ft_dar/ft_dardel.c\
		ft_dar/ft_dardumpi.c\
		ft_dar/ft_dardump.c\
		ft_dar2/ft_dar2new.c\
		ft_dar2/ft_dar2add.c\
		ft_dar2/ft_dar2del.c\
		ft_dar2/ft_dar2dump.c\
		ft_err/ft_err.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_printf_color.c\
		ft_printf/ft_printf_diouxpcs_val.c\
		ft_printf/ft_printf_family.c\
		ft_printf/ft_printf_finaly.c\
		ft_printf/ft_printf_flush.c\
		ft_printf/ft_printf_getarg.c\
		ft_printf/ft_printf_getindex.c\
		ft_printf/ft_printf_ini.c\
		ft_printf/ft_printf_save.c\
		ft_printf/ft_printf_set.c\
		ft_printf/ft_printf_set_p1.c\
		ft_printf/ft_printf_set_p2.c\
		ft_printf/ft_printf_set_p3.c\
		ft_printf/ft_printf_spec_char.c\
		ft_printf/ft_printf_spec_number_p1.c\
		ft_printf/ft_printf_spec_number_p2.c\
		ft_printf/ft_printf_static.c\
		ft_printf/ft_printf_tools.c\
		ft_printf/ft_printf_vfamily.c\
		ft_env/ft_env.c\
		ft_exit/ft_exit.c\
		ft_global/ft_global.c

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

