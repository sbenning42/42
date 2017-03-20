/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:14:50 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 17:07:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				save_path(t_graph *path, t_btrack *backtrack)
{
	size_t		size;
	int			*step;
	t_node		*tmp;
	static int	id;

	size = lst_size(backtrack->path);
	step = (int *)ft_memalloc(sizeof(int) * size);
	fill_step(step, backtrack->path);
	tmp = path->node;
	path->mem_size += 1;
	path->node = (t_node *)ft_memalloc(sizeof(t_node) * path->mem_size);
	if (path->size)
		ft_memcpy(path->node, tmp, sizeof(t_node) * path->size);
	path->node[id].id = id;
	path->node[id].meta = (t_path *)ft_memalloc(sizeof(t_path));
	ACCESS_PATH_META(path, id)->step = step;
	ACCESS_PATH_META(path, id)->size = size;
	path->size += 1;
	fill_neig(path, id);
	id += 1;
	return (0);
}
