/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:47:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 19:23:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_loop(t_env *env)
{
	char		*id;

	if ((env->mlx = mlx_init()) == NULL)
		ft_err(env->av, env->id, "Can't init mlx");
	else if (!(env->win = mlx_new_window(env->mlx, X_SCR, Y_SCR, NAM(env->id))))
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
	env->khdl[0].key = 0;
	env->khdl[0].f = khdl_default;
	env->khdl[1].key = 0;
	env->khdl[1].f = khdl_zoom_inc;
	env->khdl[2].key = 0;
	env->khdl[2].f = khdl_zoom_dec;
	env->khdl[3].key = 53;
	env->khdl[3].f = khdl_quit;
	env->khdl[4].key = 0;
	env->khdl[4].f = khdl_none;
}

void			fdf_mlx(char *av, char *id, int fd)
{
	t_env		env;
	t_fdf_map	map;

	ft_bzero((void *)&map, sizeof(t_fdf_map));
	ft_bzero((void *)&env, sizeof(t_env));
	map.z_max = INT_MIN;
	map.z_min = INT_MAX;
	env.map = &map;
	env.av = av;
	env.id = id;
	fdf_init_khdl(&env);
	fdf_parser(&env, fd);
	close(fd);
	if (map.mat == NULL)
		return ;
	fdf_loop(&env);
}
