#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2016/04/29 17:07:33 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			minishell

MAIN_SRC =		main.c
CURSOR_SRC =	cur_ask.c\
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
				cur_xmotion.c
READLINE_SRC =	ft_readline.c\
				rl_id.c\
				rl_read.c\
				rl_maj.c\
				rl_code.c\
				rl_dump.c\
				rl_display.c\
				rl_global.c\
				rl_code_quit.c\
				rl_code_arrow.c\
				rl_code_moves.c\
				rl_code_word_moves.c\
				rl_code_other_moves.c\
				rl_code_select.c\
				rl_cpy.c\
				rl_cut.c\
				rl_prompt.c
HISTORY_SRC =	hist_dump.c\
				hist_load.c\
				hist_save.c\
				hist_copy.c
LEXER_SRC =		ft_lexer.c\
				lx_global.c\
				lx_plv.c\
				lx_print.c\
				lx_grpdev.c\
				lx_fgrp.c\
				lx_tilddev.c\
				lx_wsfstate.c\
				lx_wslexem.c\
				lx_wslexer.c
PARSER_SRC =	ft_parser.c\
				cmd.c
EXEC_SRC =		ft_exec.c\
				exec.c
BUILTIN_SRC =	built_exit.c\
				built_prompt.c
LOOP_SRC =
TOOL_SRC =		get_next_line.c\
				libdic.c\
				dyn_strpush.c\
				ft_getopt.c

SRC_DIR =		srcs/
OBJ_DIR =		obj/
MAIN_DIR =		main/
CURSOR_DIR =	cursor/
READLINE_DIR =	readline/
HISTORY_DIR =	history/
LEXER_DIR =		lexer/
PARSER_DIR =	parser/
EXEC_DIR =		exec/
BUILTIN_DIR =	builtin/
LOOP_DIR =		loop/
TOOL_DIR =		tool/

MAIN =			$(addprefix $(MAIN_DIR), $(MAIN_SRC))
CURSOR =		$(addprefix $(CURSOR_DIR), $(CURSOR_SRC))
READLINE =		$(addprefix $(READLINE_DIR), $(READLINE_SRC))
HISTORY =		$(addprefix $(HISTORY_DIR), $(HISTORY_SRC))
LEXER =			$(addprefix $(LEXER_DIR), $(LEXER_SRC))
PARSER =		$(addprefix $(PARSER_DIR), $(PARSER_SRC))
EXEC =			$(addprefix $(EXEC_DIR), $(EXEC_SRC))
BUILTIN =		$(addprefix $(BUILTIN_DIR), $(BUILTIN_SRC))
LOOP =			$(addprefix $(LOOP_DIR), $(LOOP_SRC))
TOOL =			$(addprefix $(TOOL_DIR), $(TOOL_SRC))

SRC =			$(TOOL)\
				$(CURSOR)\
				$(READLINE)\
				$(HISTORY)\
				$(LEXER)\
				$(PARSER)\
				$(EXEC)\
				$(BUILTIN)\
				$(MAIN)\
				$(LOOP)

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

LIBTERMCAP =	termcap

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIB_DIR =		lib/

LIBFT_DIR =		$(addprefix $(LIB_DIR), $(LIBFT))

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			clang

FLAG =			-Wall -Wextra -Wpedantic -Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) : $(ABS_OBJ)
	$(CC) $(FLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT) -l$(LIBTERMCAP)

$(COR_OBJ) : $(COR_SRC)
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
	mkdir -p $(addprefix $(OBJ_DIR), $(MAIN_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(CURSOR_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(READLINE_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(HISTORY_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(LEXER_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(PARSER_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(EXEC_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(BUILTIN_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(LOOP_DIR))
	mkdir -p $(addprefix $(OBJ_DIR), $(TOOL_DIR))
