/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:34:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:49:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		debug_dl(t_dlist *l, size_t size, char *name)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	tmp = l;
	ft_printf("LIST %s:\n", name);
	while (tmp)
	{
		ft_printf("Elelm %d/%zu: [%d]\n", i++, size - 1, *(int *)tmp->content);
		tmp = tmp->n;
	}
	ft_printf("\n");
}
