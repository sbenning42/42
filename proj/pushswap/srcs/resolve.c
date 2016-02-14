/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:59:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/14 12:44:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	finish\
				(t_dlist **astack_a, t_dlist **astack_b, int o, int stroke)
{
	while (*astack_b)
	{
		ft_printf("pa ");
		op_px(astack_b, astack_a, &stroke);
	}
	ft_printf("\n");
	debug_split();
	if (IS(O_DEBUG) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR))
			ft_printf("\n{pink}Stroke{eoc} = %d\n", stroke);
		else
			ft_printf("\nStroke = %d\n", stroke);
	}
}

void	 	select_sort\
				 (t_dlist **astack_a, t_dlist **astack_b, size_t size, int o)
{
	t_dlist	*tmp;
	int		stroke;
	int		min;
	int		flag;
	
	(void)o;
	stroke = 0;
	while (*astack_a)
	{
		min = INT_MAX;
		flag = 1;
		tmp = *astack_a;
		while (tmp)
		{
			if (*(int *)tmp->content == stackenv()->min && flag && !(flag = 0))
			{
				ft_printf("pb ");
				op_px(astack_a, astack_b, &stroke);
			}
			else if (min > *(int *)tmp->content)
				min = *(int *)tmp->content;
			tmp = tmp->n;
		}
		stackenv()->min = min;
	}
	finish(astack_a, astack_b, o, stroke);
}
