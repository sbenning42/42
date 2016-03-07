/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 22:02:24 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 11:56:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void		lx_del(t_lxem **alst)
{
	t_lxem	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		dyn_strdel(&(*alst)->value);
		ft_memdel((void **)alst);
		*alst = tmp;
	}
}

void		lx_addtoken(t_lxem **alst, t_lxem *token)
{
	t_lxem	*cp;

	if (!(cp = *alst))
		*alst = token;
	else
	{
		while (cp->next)
			cp = cp->next;
		cp->next = token;
	}
}

t_lxem		*lx_newtoken(t_lxtype type, int plv)
{
	t_lxem	*token;

	if (!(token = (t_lxem *)ft_memalloc(sizeof(t_lxem))))
		return (NULL);
	if (dyn_strnew(&token->value, 64) < 0)
	{
		ft_memdel((void **)&token);
		return (NULL);
	}
	token->type = type;
	token->plv = plv;
	return (token);
}
//t_lxem		*tx_duptoken(t_lxem token);
