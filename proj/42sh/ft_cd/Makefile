NAME =			ft_cd

SRC_DIR =		sh/
OBJ_DIR =		obj/
HEADER_DIR =	includes/
LIB_DIR =		lib/ft/

SRC = 			clean.c\
				oldpwd.c\
				cdlst.c\
				cd_currentrep.c\
				getopt.c\
				main.c

OBJ =			$(SRC:.c=.o)

LIB =			ft

LIBFT =			libft.a

HEADER =		ft_cd.h

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(addprefix $(LIB_DIR), $(LIBFT)) $(NAME)

$(NAME) : $(addprefix $(OBJ_DIR), $(OBJ))
	$(CC) $(FLAG) -L $(LIB_DIR) -l$(LIB) -o $@ $^

$(addprefix $(OBJ_DIR), %.o) : $(addprefix $(SRC_DIR), %.c) $(addprefix $(HEADER_DIR), $(HEADER))
	$(CC) $(FLAG) -I $(HEADER_DIR) -I $(addprefix $(LIB_DIR), $(HEADER_DIR)) -o $@ -c $<

clean :
	rm -f $(addprefix $(OBJ_DIR), $(OBJ))

fclean : clean
	rm -f $(NAME)

re : fclean all

relib :
	make re -C $(LIB_DIR)

