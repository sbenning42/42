/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regexp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:14:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 16:19:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEXP_H
# define FT_REGEXP_H

/*
***	###################	BNF Grammar description	################################
***
***	<regexp> ::= <regexp_term> | <regexp_term><regexp> ;
***	<regexp_term> ::= <regexp_descriptor> | <regexp_descriptor><regexp_status> ;
***	<regexp_decriptor> ::= litteral | '['<regexp_range>']' ;
***	<regexp_range> ::= letter-letter | ~letter-letter;
***	<regexp_status> ::= + | * | ?;
***
*/

# define REGEXP_FORBBIDEN_CHARS				"~?*+[]"

# define OFFSET(X)							(g_regexp_parser + X)

# define REGEXP_ALL							OFFSET(0)
# define REGEXP_EXTEND						OFFSET(1)
# define REGEXP_TERME						OFFSET(2)
# define REGEXP_TERM_STATUED				OFFSET(3)
# define REGEXP_DESCRIPTOR					OFFSET(4)
# define REGEXP_BRACKET						OFFSET(5)
# define REGEXP_CLOSE_BRACKET				OFFSET(6)
# define REGEXP_SIGNED_RANGE				OFFSET(7)
# define REGEXP_NORANGE						OFFSET(8)
# define REGEXP_RANGE						OFFSET(9)
# define REGEXP_OPEN_RANGE					OFFSET(10)
# define REGEXP_STATUS						OFFSET(11)
# define REGEXP_QUANTIFIER_STATUS			OFFSET(12)
# define REGEXP_TERMINAL_TILD				OFFSET(13)
# define REGEXP_TERMINAL_INTER				OFFSET(14)
# define REGEXP_TERMINAL_STAR				OFFSET(15)
# define REGEXP_TERMINAL_PLUS				OFFSET(16)
# define REGEXP_TERMINAL_MINUS				OFFSET(17)
# define REGEXP_TERMINAL_OPEN_BRACKET		OFFSET(18)
# define REGEXP_TERMINAL_CLOSE_BRACKET		OFFSET(19)
# define REGEXP_TERMINAL_LETTER				OFFSET(20)
# define REGEXP_TERMINAL_LITTERAL			OFFSET(21)

# include									"libft.h"
# include									"ft_parser.h"

typedef struct s_regex_lexem				t_regex_lexem;

struct										s_regex_lexem
{
	char									*parser_key;
	int										id;
	char									*value;
	char									*start;
	t_regex_lexem							*next;
};

int				reg_match(t_regex_lexem *lst, char *scan);

int				reg_lexer(t_parser *self, char **scan, char *start_match, void *data);
int				reg_pop(t_parser *self, char **scan, char *start_match, void *data);

int				match_tild(t_parser *self, char **scan, void *data);
int				match_inter(t_parser *self, char **scan, void *data);
int				match_star(t_parser *self, char **scan, void *data);
int				match_plus(t_parser *self, char **scan, void *data);
int				match_minus(t_parser *self, char **scan, void *data);
int				match_open_bracket(t_parser *self, char **scan, void *data);
int				match_close_bracket(t_parser *self, char **scan, void *data);

int				match_letter(t_parser *self, char **scan, void *data);
int				match_litteral(t_parser *self, char **scan, void *data);

extern t_parser	g_regexp_parser[];

#endif
