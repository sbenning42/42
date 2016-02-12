/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:57:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:48:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		op_sx(t_dlist **ah_dl)
{
	void	*tmp;

	if (!(*ah_dl) || !(*ah_dl)->n)
		return ;
	tmp = (*ah_dl)->content;
	(*ah_dl)->content = (*ah_dl)->n->content;
	(*ah_dl)->n->content = tmp;
}

void		op_rx(t_dlist **ah_dl)
{
	t_dlist	*tmp;

	if (!(*ah_dl))
		return ;
	tmp = *ah_dl;
	*ah_dl = (*ah_dl)->n;
	if (*ah_dl)
		(*ah_dl)->p = NULL;
	tmp->n = NULL;
	tmp->p = NULL;
	ft_dlstaddn(ah_dl, tmp);
}

void		op_rrx(t_dlist **ah_dl)
{
	t_dlist	*tmp;

	tmp = *ah_dl;
	while (tmp && tmp->n)
	{
		tmp = tmp->n;
	}
	tmp->p->n = NULL;
	tmp->p = NULL;
	ft_dlstaddp(ah_dl, tmp);
}
