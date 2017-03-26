/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 15:06:00 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/14 15:08:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void		ft_dlstaddn(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*cp;

	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	cp = *alst;
	while (cp->n)
		cp = cp->n;
	cp->n = elem;
	elem->p = cp;
}
