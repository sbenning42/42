/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:40:08 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 14:02:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex		*lx_newtoken(t_lextype type, int protect, size_t len, int pound)
{
	t_lex	*t;

	if ((t = (t_lex *)ft_memalloc(sizeof(t_lex))))
	{
		t->type = type;
		t->protect = protect;
		t->len = len;
		t->pound = pound;
	}
	return (t);
}

void		lx_tokenlist(t_lex **alst, t_lex *token)
{
	t_lex	*cp;

	if (!*alst)
	{
		*alst = token;
		return ;
	}
	cp = *alst;
	while (cp->next)
		cp = cp->next;
	cp->next = token;
	token->previous = cp;
}
