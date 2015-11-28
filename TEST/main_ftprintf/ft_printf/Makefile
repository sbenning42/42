NAME =		libftprintf.a

SRC = 	srcs/ft_printf_color.c\
		srcs/ft_printf_static.c\
		srcs/ft_printf_finaly.c\
		srcs/ft_printf_flush.c\
		srcs/ft_printf.c\
		srcs/ft_printf_diouxpcs_val.c\
		srcs/ft_printf_family.c\
		srcs/ft_printf_tools.c\
		srcs/ft_printf_vfamily.c\
		srcs/ft_printf_getarg.c\
		srcs/ft_printf_getindex.c\
		srcs/ft_printf_ini.c\
		srcs/ft_printf_save.c\
		srcs/ft_printf_set.c\
		srcs/ft_printf_set_p1.c\
		srcs/ft_printf_set_p2.c\
		srcs/ft_printf_set_p3.c\
		srcs/ft_printf_spec_char.c\
		srcs/ft_printf_spec_number_p1.c\
		srcs/ft_printf_spec_number_p2.c

SRC_LIBFT =	libft/ft_mem/ft_memset.c\
		libft/ft_mem/ft_bzero.c\
		libft/ft_mem/ft_memalloc.c\
		libft/ft_mem/ft_memccpy.c\
		libft/ft_mem/ft_memchr.c\
		libft/ft_mem/ft_memcmp.c\
		libft/ft_mem/ft_memcpy.c\
		libft/ft_mem/ft_memdel.c\
		libft/ft_mem/ft_membzdel.c\
		libft/ft_mem/ft_memmove.c\
		libft/ft_char/ft_isalnum.c\
		libft/ft_char/ft_isalpha.c\
		libft/ft_char/ft_isascii.c\
		libft/ft_char/ft_isdigit.c\
		libft/ft_char/ft_isprint.c\
		libft/ft_char/ft_tolower.c\
		libft/ft_char/ft_toupper.c\
		libft/ft_str/ft_atoi.c\
		libft/ft_str/ft_itoa.c\
		libft/ft_str/ft_strcat.c\
		libft/ft_str/ft_strchr.c\
		libft/ft_str/ft_strclr.c\
		libft/ft_str/ft_strcmp.c\
		libft/ft_str/ft_strcpy.c\
		libft/ft_str/ft_strdel.c\
		libft/ft_str/ft_strdup.c\
		libft/ft_str/ft_strequ.c\
		libft/ft_str/ft_strexp.c\
		libft/ft_str/ft_striter.c\
		libft/ft_str/ft_striteri.c\
		libft/ft_str/ft_strjoin.c\
		libft/ft_str/ft_strlcat.c\
		libft/ft_str/ft_strlen.c\
		libft/ft_str/ft_strmap.c\
		libft/ft_str/ft_strmapi.c\
		libft/ft_str/ft_strncat.c\
		libft/ft_str/ft_strncmp.c\
		libft/ft_str/ft_strncpy.c\
		libft/ft_str/ft_strnequ.c\
		libft/ft_str/ft_strnew.c\
		libft/ft_str/ft_strnstr.c\
		libft/ft_str/ft_strrchr.c\
		libft/ft_str/ft_strsplit.c\
		libft/ft_str/ft_strstr.c\
		libft/ft_str/ft_strsub.c\
		libft/ft_str/ft_strtrim.c\
		libft/ft_str/ft_strupper.c\
		libft/ft_str/ft_strlower.c\
		libft/ft_wchar/ft_wclen.c\
		libft/ft_wchar/ft_wctoa.c\
		libft/ft_put/ft_putchar.c\
		libft/ft_put/ft_putchar_fd.c\
		libft/ft_put/ft_putendl.c\
		libft/ft_put/ft_putendl_err.c\
		libft/ft_put/ft_putstr_err.c\
		libft/ft_put/ft_putchar_err.c\
		libft/ft_put/ft_putnbr_err.c\
		libft/ft_put/ft_putendl_fd.c\
		libft/ft_put/ft_putnbr.c\
		libft/ft_put/ft_putnbr_fd.c\
		libft/ft_put/ft_putstr.c\
		libft/ft_put/ft_putstr_fd.c\
		libft/ft_buff/ft_buffnew.c\
		libft/ft_buff/ft_buffexp.c\
		libft/ft_buff/ft_buffdel.c\
		libft/ft_lst/ft_lstnew.c\
		libft/ft_lst/ft_lstdelone.c\
		libft/ft_lst/ft_lstdel.c\
		libft/ft_lst/ft_lstadd.c\
		libft/ft_lst/ft_lstiter.c\
		libft/ft_lst/ft_lstadd_back.c\
		libft/ft_lst/ft_lstmap.c\
		libft/ft_dar/ft_darnew.c\
		libft/ft_dar/ft_daradd.c\
		libft/ft_dar/ft_dardel.c\
		libft/ft_dar2/ft_dar2new.c\
		libft/ft_dar2/ft_dar2add.c\
		libft/ft_dar2/ft_dar2del.c

OBJ =		$(SRC:.c=.o)

OBJ_LIBFT =	$(SRC_LIBFT:.c=.o)

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra #-Werror 

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_LIBFT)
	ar cr $(NAME) $(OBJ) $(OBJ_LIBFT)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all



