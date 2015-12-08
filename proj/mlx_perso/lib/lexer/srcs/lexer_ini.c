/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:04:47 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 23:31:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_lex_tk	lexer_to_tk(t_lex_tk_type type, char *value, t_lex_attr attr)
{
	t_lex_tk	token;

	token.type = type;
	token.value = value;
	token.size = attr.size;
	token.save = attr.save;
	token.esc = attr.esc;
	token.rec = attr.rec;
	return (token);
}

static void		lexer_init_block(char *cs, t_lex_tk **pattern, \
				t_lex_tk_type type, t_lex_attr attr)
{
	while (*cs)
		*(*pattern)++ = lexer_to_tk(type, cs++, attr);
	if (type == Eol && !*cs)
		*(*pattern)++ = lexer_to_tk(type, cs++, attr);
}

void			lexer_init(t_lex_rule rule, t_lex_tk *pattern)
{
	t_lex_attr	attr;

	attr.size = 1;
	attr.save = rule.save_blk == True ? True : False;
	attr.esc = False;
	attr.rec = False;
	lexer_init_block(LEX_TOKEN_EOL, &pattern, Eol, attr);
	attr.save = rule.save_blk == True ? True : False;
	lexer_init_block(LEX_TOKEN_BLK, &pattern, Blank, attr);
	attr.save = True;
	lexer_init_block(LEX_TOKEN_ESC, &pattern, Escape, attr);
	attr.rec = rule.rec == True ? True : False;
	lexer_init_block(LEX_TOKEN_QUO, &pattern, Quote, attr);
	lexer_init_block(LEX_TOKEN_SBRA, &pattern, Sbracket, attr);
	attr.rec = False;
	lexer_init_block(LEX_TOKEN_EBRA, &pattern, Ebracket, attr);
}

t_lex_tk		lexer_get_nonetk(char *s)
{
	t_lex_tk	token;

	token.type = None;
	token.value = s;
	token.size = 1;
	token.save = True;
	token.esc = False;
	token.rec = False;
	return (token);
}
