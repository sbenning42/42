/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:08:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/02 00:20:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "get_next_line.h"

# define LEX_NB_TOKEN 16
# define LEX_TOKEN_EOL "\0"
# define LEX_TOKEN_BLK " \n\t\b\r"
# define LEX_TOKEN_ESC "\\"
# define LEX_TOKEN_QUO "'\"`"
# define LEX_TOKEN_SBRA "([{"
# define LEX_TOKEN_EBRA ")]}"
# define LEX_TOKEN_NU "-0123456789abcdefxABCDEF"

typedef enum		e_bool
{
	False = 0,
	True = 1
}					t_bool;

typedef enum		e_lex_tk_type
{
	None,
	Eol,
	Error,
	Line,
	Blank,
	Escape,
	Quote,
	Sbracket,
	Ebracket,
	Const_alpha,
	Const_nu
}					t_lex_tk_type;

typedef struct		s_lex_attr
{
	size_t			size;
	t_bool			save;
	t_bool			esc;
	t_bool			rec;
}					t_lex_attr;

typedef struct		s_lex_rule
{
	t_bool			esc;
	t_bool			rec;
	t_bool			save_blk;
	t_bool			error;
}					t_lex_rule;

typedef struct		s_lex_tk
{
	t_lex_tk_type	type;
	char			*value;
	size_t			size;
	t_bool			save;
	t_bool			esc;
	t_bool			rec;
}					t_lex_tk;

char				*tobool(t_bool boo);
char				*totype(t_lex_tk_type type);

t_lex_tk			lexer_get_nonetk(char *s);
void				lexer_tokenadd(t_list **alst, t_lex_tk *content, \
					t_lex_rule rule);
void				lexer_tokenchr(char *s, t_lex_tk *pattern, size_t size, \
					t_lex_tk *token);
void				lexer_constchr(char *s, t_lex_tk *token);
void				lexer_init(t_lex_rule rule, t_lex_tk *pattern);

t_list				*ft_lexer(t_lex_rule rule, t_lex_tk *pattern, \
					size_t size, char *s);

#endif
