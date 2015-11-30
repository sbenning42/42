/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:08:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 23:31:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void		lexer_error(t_list **alst, char *s)
{
	t_list		*tmp;
	char		*cp;
	size_t		i;

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

t_list			*ft_lexer(t_lex_rule rule, t_lex_tk *pattern, \
				size_t size, char *s)
{
	t_lex_tk	rule_pattern[LEX_NB_TOKEN];
	t_lex_tk	tmp;
	t_list		*lst;

	lst = NULL;
	lexer_init(rule, rule_pattern);
	tmp = lexer_get_nonetk(s);
	while (tmp.type != Eol)
	{
		tmp = lexer_get_nonetk(s);
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
