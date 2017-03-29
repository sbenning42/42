/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:48:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 17:39:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_OPT_CHARSET	"vc"
# define ASM_VERBOSE_OPT	0x1
# define ASM_COLOR_OPT		0x2

# define SEP0LINE			"--------------------------------"
# define SEPLINE			SEP0LINE SEP0LINE

# define ASM_ERROR_CFMT		"{gr}%s:{eoc} {gr|yellow}%s:{eoc} {gr|red}%s{eoc}\n"
# define ASM_ERROR_FMT		"%s: %s: %s\n"

# define ASM_SUCCESS_CFMT	"{gr}%s:{eoc} {gr|cyan}%s:{eoc} {gr|green}%s{eoc}\n"
# define ASM_SUCCESS_FMT	"%s: %s: %s\n"

# define ASM_HEADER_CFMT	"\t{gr|blue}%s{eoc}: {pink|gr}%s{eoc}\n"
# define ASM_HEADER_FMT		"\t%s: %s\n"

# define ASM_PAYLOAD_CFMT	"[{red|gr|ss}!TODO!{eoc}]\n"
# define ASM_PAYLOAD_FMT	"[!TODO!]\n"

# define ASM_TOKEN_P0		"({gr|yellow}%03d{eoc}, {gr|cyan}%03d{eoc})"
# define ASM_TOKEN_P1		" {gr|green}%20s{eoc}"
# define ASM_TOKEN_P2		" ---->\t\t| {gr}%s{eoc} |\n"
# define ASM_TOKEN_CFMT		ASM_TOKEN_P0 ASM_TOKEN_P1 ASM_TOKEN_P2
# define ASM_TOKEN_FMT		"(%03d, %03d) %20s ---->\t\t| %s |\n"

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

# include					"ft_parser.h"
# include					"proginfo.h"
# include					"get_next_line.h"
# include					"libft.h"
# include					"op.h"
# include					<errno.h>

typedef struct s_op			t_op;
typedef struct s_payload	t_payload;
typedef struct s_label		t_label;
typedef struct s_instruction	t_instruction;

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

struct						s_payload
{
	unsigned char			*payload;
	t_label					*labels;
	size_t					size;
	size_t					offset;
	t_intruction			*instructions;
};

struct						s_label
{
	char					*id;
	size_t					offset;
	t_label					*next;
};

struct						s_instruction
{
};

extern t_parser				g_asm_grammar[];
extern t_op					g_op[];

char						*error_fmt(void);
char						*success_fmt(void);
char						*token_fmt(void);
char						*header_fmt(void);

void						open_error(char *file);
void						read_error(char *file);
void						compile_error(int fd, char *file);

void						asm_dump_token_lst(t_token *lst);
void						asm_dump_header(header_t h);
void						asm_dump_payload(t_payload *payload);


t_label						*new_label(char *id, unsigned char offset);
void						add_label(t_label **label_lst, t_label *label);
void						del_label(t_label **label);
t_label						*get_label(t_label *label, char *id);

int							asm_header(header_t *h, t_token **lst);
int							asm_payload(t_payload *payload, t_token **lst);

int							asm_compile(int fd, char *file);







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
