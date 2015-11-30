/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:08:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/29 23:59:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void lexer_error(t_list **alst, char *s)
{
	t_list	*tmp;
	char	*cp;
	size_t	i;

	ft_printf("lexer: Unknow token: '{gr|ss}%c{eoc}'\n", *s);
	if (*alst)
	{
		while (*alst)
		{
			tmp = (*alst)->next;
			cp = ((t_lex_tk *)(*alst)->content)->value;
			i = ((t_lex_tk *)(*alst)->content)->size;
			ft_printf("{green}%.*s {eoc}", i, cp);
			ft_lstdelone(alst, NULL);
			*alst = tmp;
		}
	}
	ft_printf("{red}%s{eoc}\n", s);
	exit(0);
}

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

static void dontknow(char *cs, t_lex_tk **pattern, t_lex_tk_type type, t_lex_attr attr)
{
	while (*cs)
		*(*pattern)++ = lexer_to_tk(type, cs++, attr);
	if (type == Eol && !*cs)
		*(*pattern)++ = lexer_to_tk(type, cs++, attr);
}

static void		lexer_init(t_lex_rule rule, t_lex_tk *pattern)
{
	t_lex_attr	attr;

	attr.size = 1;
	attr.save = True;
	attr.esc = False;
	attr.rec = False;
	dontknow(LEX_TOKEN_EOL, &pattern, Eol, attr);
	attr.save = rule.save_blk == True ? True : False;
	dontknow(LEX_TOKEN_BLK, &pattern, Blank, attr);
	attr.save = True;
	dontknow(LEX_TOKEN_ESC, &pattern, Escape, attr);
	attr.rec = rule.rec == True ? True : False;
	dontknow(LEX_TOKEN_QUO, &pattern, Quote, attr);
	dontknow(LEX_TOKEN_SBRA, &pattern, Sbracket, attr);
	attr.rec = False;
	dontknow(LEX_TOKEN_EBRA, &pattern, Ebracket, attr);
}

static t_lex_tk	lexer_nonetk(char *s)
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

t_list			*ft_lexer(t_lex_rule rule, t_lex_tk *pattern, \
				size_t size, char *s)
{
	t_lex_tk	rule_pattern[LEX_NB_TOKEN];
	t_lex_tk	tmp;
	t_list		*lst;
	
	lst = NULL;
	lexer_init(rule, rule_pattern);
	while (tmp.type != Eol)
	{
		tmp = lexer_nonetk(s);
		lexer_tokenchr(s, rule_pattern, LEX_NB_TOKEN, &tmp);
		if (tmp.type == None)
		{
			lexer_tokenchr(s, pattern, size, &tmp);
			if (tmp.type == None)
			{
				lexer_constchr(s, &tmp);
				if (tmp.type == None && rule.error == True)
					lexer_error(&lst, s);
			}
		}
		lexer_tokenadd(&lst, &tmp, rule);
		s += tmp.size;
	}
	return (lst);
}
