/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 10:57:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/19 11:24:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_id_by_name(t_graph *rooms, char *name)
{
	int		id;

	id = 0;
	while (id < rooms->size)
	{
		if (!ft_strcmp(ACCESS_ROOM_META(rooms, id)->name, name))
			return (id);
		id++;
	}
	return (-1);
}

int			is_in_neig(t_graph *rooms, int id1, int id2)
{
	int		i;

	i = 0;
	while (i < rooms->node[id1].neig_size)
	{
		if (rooms->node[id1].neig[i] == id2)
			return (1);
		i++;
	}
	return (0);
}
