/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 20:22:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_majmat(t_env *env)
{
	int	i;

	i = -1;
	while (++i < (env->map->x * env->map->y))
	{
		if (env->map->mat[i][X_rel] == INT_MIN)
			continue ;
		env->map->mat[i][X_scr] = env->map->mat[i][X_rel] * env->map->x_gap + env->map->x_rts;
		env->map->mat[i][Y_scr] = env->map->mat[i][Y_rel] * env->map->y_gap + env->map->y_rts;
		env->map->mat[i][Color] = env->map->mat[i][Z_rel] * env->map->c_gap;
	}
}

int		khdl_none(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	ft_printf("%s: %s: [%d]\n", env->av, env->id, key);
	return (0);
}

int		khdl_quit(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	mlx_destroy_window(env->mlx, env->win);
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
