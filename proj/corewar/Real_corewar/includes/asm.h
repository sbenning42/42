/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:48:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/28 18:22:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_OPT_CHARSET	"v"
# define ASM_VERBOSE_OPT	0x1

# define ASM_OPEN_ERROR_FMT	"%s: Can't open file: `%s`\n"

# define N_DUMB				0
# define N_LINE				1
# define N_CONTENT			2
# define N_SIGNICOM			3
# define N_COMMENT			4
# define N_SIGNIFICATIF		5
# define N_COMMAND			6
# define N_ID_COMMAND		7
# define N_LITERAL			8
# define N_EXPRESSION		9
# define N_LABINSTR			10
# define N_LABEL			11
# define N_INSTRUCTION		12
# define N_SUITE_ARG		13
# define N_SEP_ARG			14
# define N_ARGUMENT			15
# define N_DIRECT			16
# define N_DIR_ARG			17
# define N_DIR_LAB			18

# define T_EMPTY			19
# define T_COMMENT			20
# define T_SKIP_EMPTY		21
# define T_COMMAND			22
# define T_ID				23
# define T_LITERAL			24
# define T_SKIP_LITERAL		25
# define T_LABEL			26
# define T_SEPARATOR		27
# define T_REGISTRE			28
# define T_INDIRECT			29
# define T_DIRECT			30
# define T_DIR_LAB			31

# include		"ft_parser.h"
# include		"proginfo.h"
# include		"get_next_line.h"
# include		"libft.h"
# include		"op.h"

typedef struct s_op	t_op;

struct				s_op
{
	char			*id;
	unsigned int	opcode;
	unsigned int	nb_arg;
	int				args_type[MAX_ARGS_NUMBER];
	char			*desc;
	unsigned int	cycle;
	unsigned int	carry;
	unsigned int	ocp;
	unsigned int	label_size;
};

extern t_parser		g_asm_grammar[];
/*
int					match_t_comment(t_parser *self, char **scan, void *data);
int					match_t_command(t_parser *self, char **scan, void *data);
int					match_t_litteral(t_parser *self, char **scan, void *data);
int					match_t_separator(t_parser *self, char **scan, void *data);
int					match_t_direct(t_parser *self, char **scan, void *data);
int					match_t_label(t_parser *self, char **scan, void *data);
int					match_t_registre(t_parser *self, char **scan, void *data);
int					match_t_indirect(t_parser *self, char **scan, void *data);
int					match_t_identifier(t_parser *self, char **scan, void *data);
int					match_t_skip_litteral(t_parser *self, char **scan, void *data);
int					match_t_skip_all(t_parser *self, char **scan, void *data);
int					match_t_end_line(t_parser *self, char **scan, void *data);
*/
#endif
