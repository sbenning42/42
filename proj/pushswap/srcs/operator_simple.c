/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:57:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:21:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		op_sx(\
			t_dlist **astack, int *stroke)
{
	void	*tmp;

	if (!(*astack) || !(*astack)->n)
		return ;
	tmp = (*astack)->content;
	(*astack)->content = (*astack)->n->content;
	(*astack)->n->content = tmp;
	(*stroke)++;
}

void		op_rx(\
			t_dlist **astack, int *stroke)
{
	t_dlist	*tmp;

	if (!(*astack))
		return ;
	tmp = *astack;
	*astack = (*astack)->n;
	if (*astack)
		(*astack)->p = NULL;
	tmp->n = NULL;
	tmp->p = NULL;
	ft_dlstaddn(astack, tmp);
	(*stroke)++;
}

void		op_rrx(\
			t_dlist **astack, int *stroke)
{
	t_dlist	*tmp;

	tmp = *astack;
	while (tmp && tmp->n)
	{
		tmp = tmp->n;
	}
	tmp->p->n = NULL;
	tmp->p = NULL;
	ft_dlstaddp(astack, tmp);
	(*stroke)++;
}
