/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 13:34:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:24:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		reverse_roll(\
		t_dlist **astack, int min, int o)
{
	int	stroke;

	stroke = 0;
	while (*(int *)(*astack)->content != min)
	{
		ft_printf("rra ");
		op_rrx(astack, &stroke);
	}
	(void)o;
	return (stroke);
}

int		roll(\
		t_dlist **astack, int min, int o)
{
	int	stroke;

	stroke = 0;
	while (*(int *)(*astack)->content != min)
	{
		ft_printf("ra ");
		op_rx(astack, &stroke);
	}
	(void)o;
	return (stroke);
}
