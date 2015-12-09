/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:47:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 02:50:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_loop(t_env *env)
{
	char		*id;

	if (!(env->mlx = mlx_init()))
		ft_err(env->av, env->id, "Can't init mlx");
	else if (!(env->win = mlx_new_window\
						(env->mlx, X_SCR, Y_SCR, NAM(env->id, id))))
		ft_err(env->av, env->id, "Can't create mlx window");
	else
	{
		mlx_key_hook(env->win, fdf_key, env);
		mlx_expose_hook(env->win, fdf_draw, env);
		mlx_loop(env->mlx);
	}
}

static void		fdf_init_khdl(t_env *env)
{
	env->khdl[0].key = FDF_DEF_K;
	env->khdl[0].handle = khdl_default;
	env->khdl[1].key = FDF_ZOOI_K;
	env->khdl[1].handle = khdl_zoom_inc;
	env->khdl[2].key = FDF_ZOOD_K;
	env->khdl[2].handle = khdl_zoom_dec;
	env->khdl[3].key = FDF_QUIT_K;
	env->khdl[3].handle = khdl_quit;
}

void			fdf_mlx(char *av, char *id, int fd)
{
	t_env		env;
	t_fdf_map	map;

	ft_bzero((void *)&map, sizeof(t_fdf_map));
	ft_bzero((void *)&env, sizeof(t_env));
	map.x_rts = X_SCR / 2;
	map.y_rts = Y_SCR / 2;
	map.x_gap = X_SCR / 1.5;
	map.y_gap = Y_SCR / 1.5;
	map.z_max = INT_MIN;
	map.z_min = INT_MAX;
	fdf_init_khdl(&env);
	env.map = &map;
	env.av = av;
	env.id = id;
	env.fd = fd;
	if (fdf_parser(&env, fd) && map.mat)
		fdf_loop(&env);
	close(fd);
	exit(EXIT_SUCCESS);
}
