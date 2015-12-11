/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/10 23:39:20 by sbenning         ###   ########.fr       */
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
//		m[i][X_scr] = m[i][X_rel] * env->map->x_gap + env->map->x_rts;
//		m[i][Y_scr] = m[i][Y_rel] * env->map->y_gap + env->map->y_rts;
//		m[i][Color] = FDF_COLOR(m[i][Z_rel], env->map->z_min, env->map->z_max);
		m[i][X_scr] = (m[i][X_rel] - m[i][Y_rel]) * env->map->x_gap;
		m[i][Y_scr] = (m[i][Y_rel] + m[i][X_rel] - (m[i][Z_rel] / 2)) * env->map->y_gap;
		m[i][X_scr] += env->map->x_rts;
		m[i][Y_scr] += env->map->y_rts;
		if (m[i][Z_rel] > 0)
			m[i][Color] = 0xff0000 + (0xff00 - (m[i][Z_rel] * env->map->c_ppad));
		else if (m[i][Z_rel] < 0)
			m[i][Color] = 0xff + (0xff00 - (ft_math_abs(m[i][Z_rel]) * env->map->c_npad));
		else
			m[i][Color] = 0xffffff;
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
	free(env->map->mat);
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
	fdf_draw_mat(env, env->map, 1);
	env->map->x_gap = X_SCR / 3;
	env->map->y_gap = Y_SCR / 3;
	env->map->x_gap /= env->map->x;
	env->map->y_gap /= (env->map->y + env->map->z_max);
	if (env->map->x_gap > env->map->y_gap)
		env->map->x_gap = env->map->y_gap;
	else
		env->map->y_gap = env->map->x_gap;
	fdf_majmat(env);
	fdf_draw_mat(env, env->map, 0);
	return (0);
}

int		khdl_zoom_inc(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	fdf_draw_mat(env, env->map, 1);
	env->map->x_gap *= 2;
	env->map->y_gap *= 2;
	fdf_majmat(env);
	fdf_draw_mat(env, env->map, 0);
	return (0);
}

int		khdl_zoom_dec(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	fdf_draw_mat(env, env->map, 1);
	env->map->x_gap /= (env->map->x_gap <= 1 ? 1 : 2);
	env->map->y_gap /= (env->map->y_gap <= 1 ? 1 : 2);
	fdf_majmat(env);
	fdf_draw_mat(env, env->map, 0);
	return (0);
}
