/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 13:20:37 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:20:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nosort(\
	t_dlist *stack, int o, int finish)
{
	while (stack && stack->n)
	{
		if (*(int *)stack->content > *(int *)stack->n->content)
			return (1);
		stack = stack->n;
	}
	if (!finish)
		return (0);
	if (IS(O_DEBUG, o) || IS(O_STROKE, o))
	{
		if (IS(O_COLOR, o))
			ft_printf("{pink}Stroke{eoc}: 0\n");
		else
			ft_printf("Stroke: 0\n");
	}
	return (0);
}
