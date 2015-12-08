/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:27:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 20:14:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_bresenham(t_env *env, t_fdf_map *map, int clr)
{
	int			i;
	int			x;
	int			y;
	int			c;

	i = -1;
	while (++i < (map->x * map->y))
	{
		if ((x = map->mat[i][X_scr]) == INT_MIN)
			continue ;
		y = map->mat[i][Y_scr];
		c = map->mat[i][Color];
		c += (c > 0 ? 0x0 : 0xffffff);
		if (clr)
			c = 0;
		mlx_pixel_put(env->mlx, env->win, x, y, c);
	}
}

int				fdf_draw(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	fdf_bresenham(env, env->map, 0);
	return (0);
}
