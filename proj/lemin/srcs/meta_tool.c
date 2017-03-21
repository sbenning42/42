/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:07:05 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 11:07:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_id_by_name(t_graph *rooms, char *name)
{
	int		id;

	id = 0;
	while (id < (int)rooms->size)
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
	while (i < (int)rooms->node[id1].neig_size)
	{
		if (rooms->node[id1].neig[i] == id2)
			return (1);
		i++;
	}
	return (0);
}
