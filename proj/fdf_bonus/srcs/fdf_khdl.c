/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 03:17:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_majmat(t_env *env)
{
	t_fdf_px	*m;
	int	i;

	i = -1;
	m = env->map->mat;
	while (++i < (env->map->x * env->map->y))
	{
		if (m[i][X_rel] == INT_MIN)
			continue ;
		m[i][X_scr] = m[i][X_rel] * env->map->x_gap + env->map->x_rts;
		m[i][Y_scr] = m[i][Y_rel] * env->map->y_gap + env->map->y_rts;
		m[i][Color] = FDF_COLOR(m[i][Z_rel], env->map->z_min, env->map->z_max);
	}
}

int		khdl_none(void *p, int key)
{
	t_env	*env;
	int		fd;

	env = (t_env *)p;
	if ((fd = open("fdf.deb.out", O_WRONLY)) > 0)
	{
		ft_fprintf(fd, "%s: %s: [%d]\n", env->av, env->id, key);
		close(fd);
	}
	return (0);
}

int		khdl_quit(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	mlx_destroy_window(env->mlx, env->win);
	close(env->fd);
	exit(EXIT_SUCCESS);
	return (0);
}

int		khdl_default(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	fdf_bresenham(env, env->map, 1);
	env->map->x_gap = (X_SCR / 1.5) / env->map->x;
	env->map->y_gap = (Y_SCR / 1.5) / env->map->y;
	fdf_majmat(env);
	fdf_bresenham(env, env->map, 0);
	return (0);
}

int		khdl_zoom_inc(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	fdf_bresenham(env, env->map, 1);
	env->map->x_gap *= 2;
	env->map->y_gap *= 2;
	fdf_majmat(env);
	fdf_bresenham(env, env->map, 0);
	return (0);
}

int		khdl_zoom_dec(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	fdf_bresenham(env, env->map, 1);
	env->map->x_gap /= (env->map->x_gap == 1 ? 1 : 2);
	env->map->y_gap /= (env->map->y_gap == 1 ? 1 : 2);
	fdf_majmat(env);
	fdf_bresenham(env, env->map, 0);
	return (0);
}
