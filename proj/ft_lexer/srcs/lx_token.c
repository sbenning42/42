/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 22:02:24 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 22:09:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void		lx_del(t_lxem **alst)
{
	t_lxem	*cp;
	t_lxem	*tmp;

	cp = *alst;
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
