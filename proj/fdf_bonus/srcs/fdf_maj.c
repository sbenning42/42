/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:12:53 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:13:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_majmat(t_env *e)
{
	t_fdf_px	*m;
	int			size;
	int			i;

	i = -1;
	size = e->map->x * e->map->y;
	m = e->map->m;
	while (++i < size)
	{
		if (m[i][Fix])
			continue ;
		else
			fdf_getscr_attr(e->map, m[i]);
	}
}

void			fdf_maj_alt_map(t_fdf_map *map, float inc)
{
	int			i;
	int			size;

	i = -1;
	size = map->x * map->y;
	while (++i < size)
	{
		if (map->m[i][Fix] || !map->m[i][Z_rel])
			continue ;
		if (inc > 0)
		{
			if (map->m[i][Z_rel] > 0.0)
				map->m[i][Z_rel]++;
			else
				map->m[i][Z_rel]--;
		}
		else
		{
			if (map->m[i][Z_rel] > 1.0)
				map->m[i][Z_rel]--;
			else if (map->m[i][Z_rel] < -1.0)
				map->m[i][Z_rel]++;
		}
	}
}
