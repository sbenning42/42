/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:24:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 23:31:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char				*tobool(t_bool boo)
{
	if (boo == True)
		return ("{green}True{eoc}");
	return ("{red}False{eoc}");
}

char				*totype(t_lex_tk_type type)
{
	if (type == None)
		return ("None");
	if (type == Eol)
		return ("Eol");
	if (type == Error)
		return ("Error");
	if (type == Line)
		return ("Line");
	if (type == Blank)
		return ("Blank");
	if (type == Escape)
		return ("Escape");
	if (type == Quote)
		return ("Quote");
	if (type == Sbracket)
		return ("Sbracket");
	if (type == Ebracket)
		return ("Ebracket");
	if (type == Const_alpha)
		return ("Const_alpha");
	if (type == Const_nu)
		return ("Const_nu");
	return (NULL);
}

void				lexer_tokenadd(t_list **alst, t_lex_tk *content, \
					t_lex_rule rule)
{
	static t_bool	escape = False;
	t_list			*elem;

	if (rule.esc == True && content->type == Escape && escape == False)
		escape = True;
	else if (rule.esc == True && escape == True)
	{
		content->rec = False;
		content->esc = True;
		escape = False;
	}
	else if ((rule.rec == True && content->rec == True) || \
			content->save == False)
		return ;
	if (!(elem = ft_lstnew((void *)content, sizeof(t_lex_tk))))
	{
		ft_lstdel(alst, NULL);
		ft_printf("{ss|red}MALLOC ERROR!!!{eoc}\n");
		exit(1);
	}
	ft_lstadd_back(alst, elem);
}
