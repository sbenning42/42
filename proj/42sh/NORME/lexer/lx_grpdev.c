/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_grpdev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 20:40:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:17:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int					lx_grpdev(t_lxem *list)
{
	int				i;

	while (list)
	{
		i = -1;
		while (++i < LX_GROUP_SIZE)
		{
			if (!list->plv && !ft_strcmp(list->value.str, g_lxgrp[i].lxem.str))
				g_lxgrp[i].f(list);
		}
		list = list->next;
	}
	return (0);
}
