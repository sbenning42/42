/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:42:19 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:07:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	lenstack(\
			t_dlist *stack)
{
	int		i;

	i = 1;
	while (stack->n)
	{
		if (*(int *)stack->content < *(int *)stack->n->content)
			return (4);
		stack = stack->n;
		i++;
	}
	return (i);
}

int			reverse(\
			t_dlist **astack, int o)
{
	int		i;
	int		stroke;

	if ((i = lenstack(*astack)) > 3)
		return (0);
	stroke = 0;
	ft_printf("ra ");
	op_rx(astack, &stroke);
	ft_printf("sa\n");
	op_sx(astack, &stroke);
	if (IS(O_DEBUG, o) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR, o))
			ft_printf("{pink}Stroke{eoc}: %d\n", stroke);
		else
			ft_printf("Stroke: %d\n", stroke);
	}
	return (1);
}

static int	handelable(\
			t_dlist *stack)
{
	while (stack && stack->n)
	{
		if ((*(int *)stack->content > *(int *)stack->n->content) && stack->n->n)
			return (0);
		else if (*(int *)stack->content > *(int *)stack->n->content)
			return (1);
		stack = stack->n;
	}
	return (0);
}

int			reverse_swap(\
			t_dlist **astack, int o)
{
	int		stroke;

	stroke = 0;
	if (!handelable(*astack))
		return (0);
	ft_printf("ra ");
	op_rx(astack, &stroke);
	ft_printf("ra ");
	op_rx(astack, &stroke);
	ft_printf("sa ");
	op_sx(astack, &stroke);
	ft_printf("rra ");
	op_rrx(astack, &stroke);
	ft_printf("rra\n");
	op_rrx(astack, &stroke);
	if (IS(O_DEBUG, o) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR, o))
			ft_printf("{pink}Stroke{eoc}: %d\n", stroke);
		else
			ft_printf("Stroke: %d\n", stroke);
	}
	return (1);
}
