/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:34:32 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 18:48:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_getscr_attr(t_fdf_map *map, t_fdf_px px)
{
	px[X_iso] = TOXISO(sqrtf, px[X_rel], px[Y_rel]);
	px[Y_iso] = TOYISO(sqrtf, px[X_rel], px[Y_rel], px[Z_rel]);

	px[X_scr] = TOSCREEN(px[X_iso], map->gap);
	px[Y_scr] = TOSCREEN(px[Y_iso], map->gap);
	if (px[Z_rel] > 0.0)
		px[Color] = (float)TOCOLORUNK(((px[Z_rel] * BLUE) / map->z_max));
	else if (px[Z_rel] < 0.0)
		px[Color] = (float)TOCOLORUNK(px[Z_rel]);
	else
		px[Color] = (float)0xffffff;
}

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
		if (map->m[i][Fix])
			continue ;
		else if (map->m[i][Z_rel] == 1.0)
			map->m[i][Z_rel] += (inc * 2.0);
		else if (map->m[i][Z_rel] == -1.0)
			map->m[i][Z_rel] += (inc * 2.0);
		else if (map->m[i][Z_rel])
			map->m[i][Z_rel] += inc;
	}
}
