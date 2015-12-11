/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:27:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/10 20:11:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_bresenham_line(t_env *env, int x, int y, int clr)
{
	if (y + 1 < env->map->y && (env->map->mat[(y + 1) * env->map->x + x][Y_rel] != INT_MIN)&& (env->map->mat[y * env->map->x + x][Y_rel] != INT_MIN))
	{
		fdf_bresenham_draw(env, env->map->mat[y * env->map->x + x], env->map->mat[(y + 1) * env->map->x + x], clr);
	}
	if (x + 1 < env->map->x && (env->map->mat[y * env->map->x + x + 1][X_rel] != INT_MIN)&& (env->map->mat[y * env->map->x + x][X_rel] != INT_MIN))
	{
		fdf_bresenham_draw(env, env->map->mat[y * env->map->x + x], env->map->mat[y * env->map->x + (x + 1)], clr);
		fdf_bresenham_line(env, x + 1, y, clr);
	}
}

void			fdf_bresenham(t_env *env, int clr)
{
	int			y;

	y = -1;
	while (++y < env->map->y)
		fdf_bresenham_line(env, 0, y, clr);
}

void			fdf_draw_mat(t_env *env, t_fdf_map *map, int clr)
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
		mlx_pixel_put(env->mlx, env->win, x, y, (clr ? 0 : c));
	}
	fdf_bresenham(env, clr);
}

int				fdf_draw(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	fdf_draw_mat(env, env->map, 0);
	return (0);
}
