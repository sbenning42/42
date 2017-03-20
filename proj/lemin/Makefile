#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2017/03/09 15:07:24 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			lemin

MAIN_SRC =		main.c\
				parsing.c\
				resolve.c\
				play.c\
				lemin.c
PARSER_SRC =	parse_tag.c\
				parse_pop.c\
				parse_room.c\
				parse_hall.c
META_SRC =		tool.c
GLOBAL_SRC =	global.c
TOOL_SRC =		get_next_line.c\
				ft_getopt.c\
				proginfo.c\
				delete_tab.c
DUMP_SRC =		dump_graph.c\
				dump_solution.c
BACKT_SRC =		get_paths.c\
				save_path.c\
				neig.c\
				get_solutions.c\
				tools.c
LEM_SRC =		get_lem.c

SRC_DIR =		srcs/
OBJ_DIR =		obj/
MAIN_DIR =		main/
PARSER_DIR =	parser/
META_DIR =		meta/
GLOBAL_DIR =	global/
TOOL_DIR =		tool/
DUMP_DIR =		dump/
BACKT_DIR =		backtrack/
LEM_DIR =		lem/

MAIN =			$(addprefix $(MAIN_DIR), $(MAIN_SRC))
PARSER =		$(addprefix $(PARSER_DIR), $(PARSER_SRC))
META =			$(addprefix $(META_DIR), $(META_SRC))
GLOBAL =		$(addprefix $(GLOBAL_DIR), $(GLOBAL_SRC))
TOOL =			$(addprefix $(TOOL_DIR), $(TOOL_SRC))
DUMP =			$(addprefix $(DUMP_DIR), $(DUMP_SRC))
BACKT =			$(addprefix $(BACKT_DIR), $(BACKT_SRC))
LEM =			$(addprefix $(LEM_DIR), $(LEM_SRC))

SRC =			$(TOOL)\
				$(PARSER)\
				$(META)\
				$(GLOBAL)\
				$(DUMP)\
				$(BACKT)\
				$(LEM)\
				$(MAIN)

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

DEPEND =		lemin.h

ABS_DEPEND =	$(addprefix $(HEADER)/, $(DEPEND))

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIB_DIR =		lib/

LIBFT_DIR =		$(addprefix $(LIB_DIR), $(LIBFT))

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			gcc

FLAG =			-Wall -Wextra #-Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) : $(ABS_OBJ)
	$(CC) $(FLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT)

$(COR_OBJ) : $(COR_SRC) $(ABS_DEPEND)
	$(CC) $(FLAG) -o $@ -c $< -I$(HEADER) -I$(LIBFT_HEADER)

$(ABS_OBJ_LIBFT) :
	make -C $(LIBFT_DIR)

lclean :
	make clean -C $(LIBFT_DIR)

lfclean :
	make fclean -C $(LIBFT_DIR)

lre : 
	make re -C $(LIBFT_DIR)

clean :
	rm -f $(ABS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

config :
	@mkdir -p $(addprefix $(OBJ_DIR), $(MAIN_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(PARSER_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(META_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(GLOBAL_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(TOOL_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(DUMP_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(BACKT_DIR))
	@mkdir -p $(addprefix $(OBJ_DIR), $(LEM_DIR))
