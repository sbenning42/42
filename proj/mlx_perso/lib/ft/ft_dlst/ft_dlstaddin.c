/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 14:49:47 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/14 22:06:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void		ft_dlstaddin(t_dlist **alst, t_dlist *elem, t_uint i)
{
	t_dlist	*cp;
	t_dlist	*tmp;

	cp = *alst;
	while (i-- && cp)
		cp = cp->n;
	if (!cp)
		*alst = elem;
	else
	{
		tmp = cp->n;
		cp->n = elem;
		elem->p = cp;
		elem->n = tmp;
		if (tmp)
			tmp->p = elem;
	}
}
