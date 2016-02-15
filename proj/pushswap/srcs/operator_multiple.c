/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_multiple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:57:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:21:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		op_ss(\
			t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_sx(astack_a, stroke);
	op_sx(astack_b, stroke);
}

void		op_rs(\
			t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_rx(astack_a, stroke);
	op_rx(astack_b, stroke);
}

void		op_rrs(\
			t_dlist **astack_a, t_dlist **astack_b, int *stroke)
{
	op_rrx(astack_a, stroke);
	op_rrx(astack_b, stroke);
}

void		op_px(\
			t_dlist **astack_pop, t_dlist **astack_push, int *stroke)
{
	t_dlist	*tmp;

	if (!(*astack_pop))
		return ;
	tmp = *astack_pop;
	*astack_pop = (*astack_pop)->n;
	if (*astack_pop)
		(*astack_pop)->p = NULL;
	tmp->n = NULL;
	tmp->p = NULL;
	ft_dlstaddp(astack_push, tmp);
	(*stroke)++;
}
