/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neig.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:25:06 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 17:15:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		set_neig(t_graph *paths, int id1, int id2)
{
	int			*tmp;

	tmp = paths->node[id1].neig;
	paths->node[id1].neig = (int *)ft_memalloc(sizeof(int) *\
			(paths->node[id1].neig_size + 1));
	if (paths->node[id1].neig_size)
		ft_memcpy(paths->node[id1].neig, tmp, sizeof(int) *\
				paths->node[id1].neig_size);
	free(tmp);
	paths->node[id1].neig[paths->node[id1].neig_size] = id2;
	paths->node[id1].neig_size += 1;
	tmp = paths->node[id2].neig;
	paths->node[id2].neig = (int *)ft_memalloc(sizeof(int) *\
			(paths->node[id2].neig_size + 1));
	if (paths->node[id2].neig_size)
		ft_memcpy(paths->node[id2].neig, tmp, sizeof(int) *\
				paths->node[id2].neig_size);
	free(tmp);
	paths->node[id2].neig[paths->node[id2].neig_size] = id1;
	paths->node[id2].neig_size += 1;
}

void			fill_neig(t_graph *paths, int id)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (++i < (int)(ACCESS_PATH_META(paths, id)->size - 1))
	{
		j = -1;
		while (++j < id)
		{
			if (is_in_neig(paths, id, j))
				continue ;
			k = 0;
			while (++k < (int)(ACCESS_PATH_META(paths, j)->size - 1))
			{
				if (ACCESS_PATH_META(paths, id)->step[i]\
						== ACCESS_PATH_META(paths, j)->step[k])
				{
					set_neig(paths, id, j);
					break ;
				}
			}
		}
	}
}
