/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_reserveddev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:30:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:02:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void		lx_reserveddevlexem(t_lxem *list)
{
	int		i;

	i = -1;
	while (++i < LX_RESERVED_SIZE)
	{
		if (!ft_strcmp(list->value.str, g_lxreserved[i].str))
		{
			list->type = g_lxreserved[i].type;
			break ;
		}
	}
}

int			lx_reserveddev(t_lxem *list)
{
	while (list)
	{
		if (!list->plv)
			lx_reserveddevlexem(list);
		list = list->next;
	}
	return (0);
}
