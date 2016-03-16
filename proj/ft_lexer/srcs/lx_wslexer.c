/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_wslexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:17:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 11:50:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void				lx_del(t_lxem **alst)
{
	t_lxem			*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		dyn_strdel(&(*alst)->value);
		ft_memdel((void **)alst);
		*alst = tmp;
	}
}

t_lxem				*lx_newtoken(t_lxtype type)
{
	t_lxem			*token;

	if (!(token = (t_lxem *)ft_memalloc(sizeof(t_lxem))))
		return (NULL);
	if (dyn_strnew(&token->value, 32) < 0)
	{
		ft_memdel((void **)&token);
		return (NULL);
	}
	token->type = type;
	return (token);
}

void				lx_addtoken(t_lxem **alst, t_lxem *token)
{
	t_lxem			*cp;

	if (!(cp = *alst))
	{
		*alst = token;
		return ;
	}
	while (cp->next)
		cp = cp->next;
	cp->next = token;
	token->previous = cp;
}

t_lxem				*lx_wslexer(char *line)
{
	t_lxem			*lxlist;
	t_lxem			*token;

	lxlist = NULL;
	while (*line)
	{
		g_plvskip = 0;
		if (!(token = lx_wslexem(line)))
		{
			lx_del(&lxlist);
			return (NULL);
		}
		line += token->len;
		line += g_plvskip;
		lx_addtoken(&lxlist, token);
	}
	return (lxlist);
}
