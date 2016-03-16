/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:39:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:35:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void		lx_killblank(t_lxem **alst)
{
	t_lxem	*tmp;
	t_lxem	*cp;

	cp = *alst;
	while (cp)
	{
		tmp = cp->next;
		if ((!cp->plv && !ft_strcmp(" ", cp->value.str)) || !cp->len)
		{
			if (cp == *alst)
				*alst = tmp;
			if (cp->previous)
				cp->previous->next = tmp;
			if (tmp)
				tmp->previous = cp->previous;
			cp->next = NULL;
			lx_del(&cp);
		}
		cp = tmp;
	}
}

t_lxem		*ft_lexer(char *line)
{
	t_lxem	*wslxlist;

	if (!(wslxlist = lx_wslexer(line)))
		return (NULL);
	if (lx_tilddev(wslxlist) < 0)
	{
		lx_del(&wslxlist);
		return (NULL);
	}
	if (lx_reserveddev(wslxlist) < 0)
	{
		lx_del(&wslxlist);
		return (NULL);
	}
	lx_killblank(&wslxlist);
	lx_print(wslxlist);
	return (wslxlist);
}
