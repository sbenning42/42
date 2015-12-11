/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:27:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 15:08:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_bresenham_line(t_env *e, int x, int y, int clr)
{
	int			i;
	int			j;

	i = y * e->map->x + x;
	j = (y + 1) * e->map->x + x;
	if (y + 1 < e->map->y && !e->map->m[j][Fix])
		fdf_bresenham_px(e, e->map->m[i], e->map->m[j], clr);
	j = y * e->map->x + x + 1;
	if (x + 1 < e->map->x && !e->map->m[j][Fix])
	{
		fdf_bresenham_px(e, e->map->m[i], e->map->m[j], clr);
		fdf_bresenham_line(e, x + 1, y, clr);
	}
}

void			fdf_draw_line(t_env *e, t_fdf_map *map, int clr)
{
	int			y;

	y = -1;
	while (++y < map->y)
		fdf_bresenham_line(e, 0, y, clr);
}

void			fdf_draw_m(t_env *e, t_fdf_map *map, int clr)
{
	t_fdf_px	*m;
	int			color;
	int			size;
	int			i;

	size = map->x * map->y;
	m = map->m;
	i = -1;
	while (++i < size)
	{
		if (m[i][Fix])
			continue ;
		color = (clr ? 0x0 : m[i][Color]);
		mlx_pixel_put(e->mlx, e->win, m[i][X_scr], m[i][Y_scr], color);
	}
	fdf_draw_line(e, map, clr);
}

int				fdf_draw(void *p)
{
	t_env		*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, 0);
	return (0);
}
