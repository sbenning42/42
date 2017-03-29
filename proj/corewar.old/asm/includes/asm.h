/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:31:00 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 14:32:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define O_CHARSET "c"
# define O_COLOR 1

# define ASM_SRC_EXT		".s"
# define ASM_BIN_EXT		".cor"

# define ASM_BUFFER_SIZE	512

# define ST_DEFAULT			0
# define ST_WORD			1
# define ST_LABEL			2
# define ST_CMD				3
# define ST_COMMENT			4
# define ST_LITERAL			5
# define ST_ARGS			6
# define ST_REG_ARG			7
# define ST_DIR_ARG			8
# define ST_IND_ARG			9
# define ST_LABEL_ARG		10
# define ST_FLUSH			11
# define ST_SEPARATOR		12

# define LEXICAL_ERR_FMT "Lexical error at [%d][%d] - `%c`\n"

# include					"op.h"
# include					"libft.h"
# include					"proginfo.h"
# include					<fcntl.h>

typedef struct s_op			t_op;
typedef struct s_token		t_token;
typedef struct s_lexem		t_lexem;

struct						s_op
{
	char					*id;
	unsigned int			opcode;
	unsigned int			nb_arg;
	int						args_type[MAX_ARGS_NUMBER];
	char					*desc;
	unsigned int			cycle;
	unsigned int			carry;
	unsigned int			ocp;
	unsigned int			label_size;
};

struct						s_token
{
	int						type;
	char					*value;
	size_t					size;
	int						line;
	int						column;
};

struct						s_lexem
{
	t_list					*lst;
	t_token					token;
};


void						token_reset(t_lexem *lexem);
void						token_delete(t_lexem *lexem);
int							token_push(t_lexem *lexem, char c);
int							token_save(t_lexem *lexem);

int							flush_state(t_lexem *lexem, char c);
int							args_state(t_lexem *lexem, char c);
int							lab_arg_state(t_lexem *lexem, char c);
int							ind_arg_state(t_lexem *lexem, char c);
int							dir_arg_state(t_lexem *lexem, char c);
int							reg_arg_state(t_lexem *lexem, char c);
int							label_state(t_lexem *lexem, char c);
int							word_state(t_lexem *lexem, char c);
int							comment_state(t_lexem *lexem, char c);
int							literal_state(t_lexem *lexem, char c);
int							command_state(t_lexem *lexem, char c);
int							default_state(t_lexem *lexem, char c);

int							check_logical_integrity(t_lexem *lexem);

void						compile(int fd);

void						dump_lexem(t_list *tmp);
#endif
