NAME =		lem

SRC =		lib/get_next_line.c\
		srcs/get.c\
		srcs/data.c\
		srcs/path.c\
		srcs/fill.c\
		srcs/exec.c\
		srcs/lem.c\
		main.c
	
LIB =		lib/ft/libft.a

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra

all : $(NAME)

$(NAME) :
	$(CC) -o $(NAME) -I $(HEADERS) $(SRC) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

