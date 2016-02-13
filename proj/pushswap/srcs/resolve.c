/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:59:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/13 13:56:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	handle_stack_b\
				(t_dlist **astack, int *stroke, int size)
{
	int		mem;
	char	flag;

	mem = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		if ((*astack)\
				&& (*astack)->n\
				&& ((*astack)->content > (*astack)->n->content)\
				&& size--)
		{
			flag = 1;
			mem++;
			op_sx(astack, stroke);
			ft_printf("sb ");
			op_rx(astack, stroke);
			ft_printf("rb ");
		}
		else
		{
			while (mem--)
			{
				op_rrx(astack, stroke);
				ft_printf("rrb ");
			}
		}
	}
}

void		ps_resolve\
				(t_dlist **astack_a, t_dlist **astack_b, size_t size, int o)
{
	t_dlist	*tmp;
	int		stroke;
	int		bsize;
	
	stroke = 0;
	tmp = *astack_a;
	(void)size;
	bsize = 0;
	while (42)
	{
		if (!*astack_a)
			break ;
		op_px(astack_a, astack_b, &stroke);
		ft_printf("pb ");
		handle_stack_b(astack_b, &stroke, bsize);
		bsize++;
	}
	ft_printf("\n");
	if (IS(O_DEBUG, o))
	{
		debug(*astack_a, "A");
		debug(*astack_b, "B");
	}
}
