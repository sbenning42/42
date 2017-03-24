/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:31:00 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 15:28:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_OPT_CHARSET		"cv"
# define ASM_OPT_COLOR			1
# define ASM_OPT_VERBOSE		2

# define ASM_SRC_EXT			".s"
# define ASM_BIN_EXT			".cor"

# define ASM_LEXICAL_ERROR_FMT	"%s: Lexical error at [%d][%d] - `%c`\n"
# define ASM_OPEN_ERROR_FMT		"%s: Open error on file: '%s'\n"
# define ASM_TOKEN_DUMP_FMT		"TOKEN %03d: (%03d,%03d) -> [%s]-[%s]-[%zu]\n"

# define G_ASM_GRAMM			g_asm_gramm
# define ASM_PARSE(X)			(G_ASM_GRAMM + X)

# include						"op.h"
# include						"asm_gramm.h"
# include						"libft.h"
# include						"get_next_line.h"
# include						"proginfo.h"
# include						<fcntl.h>

typedef struct s_op				t_op;
typedef struct s_token			t_token;
typedef struct s_lexem			t_lexem;
typedef struct s_position		t_position;
typedef enum e_gramm_type		t_gramm_type;
typedef struct s_gramm_rule		t_gramm_rule;
typedef int						(*t_logic)\
									(t_gramm_rule *,\
									 t_gramm_rule *,\
									 char **, t_lexem *);
typedef int						(*t_match)(char **, t_lexem *);

enum							e_gramm_type
{
	gt_logic,
	gt_match
};

struct							s_gramm_rule
{
	t_gramm_type				type;
	t_match						match;
	t_logic						logic;
	t_gramm_rule				*left;
	t_gramm_rule				*right;
	int							skip_whitespace;
};

struct							s_op
{
	char						*id;
	unsigned int				opcode;
	unsigned int				nb_arg;
	int							args_type[MAX_ARGS_NUMBER];
	char						*desc;
	unsigned int				cycle;
	unsigned int				carry;
	unsigned int				ocp;
	unsigned int				label_size;
};

struct							s_token
{
	int							id;
	int							type;
	char						*value;
	size_t						size;
	int							line;
	int							column;
};

struct							s_lexem
{
	t_list						*lst;
	t_token						token;
};

struct							s_position
{
	int							li;
	int							co;
};

extern t_gramm_rule				G_ASM_GRAMM[];

t_position						*s_cursor_position(void);
void							cursor_position_reset(void);
void							cursor_position_inc_li(int offset);
void							cursor_position_inc_co(int offset);

void							token_reset(t_lexem *lexem);
void							token_delete(t_lexem *lexem);
int								token_push(t_lexem *lexem, char c);
int								token_save(t_lexem *lexem);

int								logic_and\
								(t_gramm_rule *left_rule,\
								 t_gramm_rule *right_rule,\
								 char **scan, t_lexem *lexer);
int								logic_or\
								(t_gramm_rule *left_rule,\
								 t_gramm_rule *right_rule,\
								 char **scan, t_lexem *lexer);
int								logic_xor\
								(t_gramm_rule *left_rule,\
								 t_gramm_rule *right_rule,\
								 char **scan, t_lexem *lexer);
int								logic_or_and\
								(t_gramm_rule *left_rule,\
								 t_gramm_rule *right_rule,\
								 char **scan, t_lexem *lexer);
int								logic_and_or\
								(t_gramm_rule *left_rule,\
								 t_gramm_rule *right_rule,\
								 char **scan, t_lexem *lexer);

int								match_c(char **scan, t_lexem *lexer, char c);
int								match_charset(char **scan, t_lexem *lexer, char *charset);

int								match_c_minus(char **scan, t_lexem *lexer);
int								match_c_comment(char **scan, t_lexem *lexer);
int								match_c_command(char **scan, t_lexem *lexer);
int								match_c_label(char **scan, t_lexem *lexer);
int								match_c_separator(char **scan, t_lexem *lexer);
int								match_c_direct(char **scan, t_lexem *lexer);
int								match_c_registre(char **scan, t_lexem *lexer);
int								match_c_literal(char **scan, t_lexem *lexer);
int								match_c_end_line(char **scan, t_lexem *lexer);
int								match_identifier(char **scan, t_lexem *lexer);
int								match_uinteger(char **scan, t_lexem *lexer);
int								match_end_literal(char **scan, t_lexem *lexer);

int								asm_parse\
								(char **scan, t_lexem *lexer,\
								 t_gramm_rule *rule);

//void							asm_lexer_dump(t_lexem lexer);

#endif
