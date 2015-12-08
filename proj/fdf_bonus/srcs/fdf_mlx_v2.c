/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:47:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 04:25:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_loop(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		ft_err(env->av, env->id, "Can't init mlx");
	else if ((env->win = mlx_create_windox(env->mlx, X_SCR, Y_SCR)) == NULL)
		ft_err(env->av, env->id, "Can't create mlx window");
	else
	{
		mlx_key_hook(env->win, fdf_key, env);	//todo
		mlx_expose_hook(env->win, fdf_draw, env);	//todo
		mlx_loop(env->mlx);
	}
}

static void		fdf_init_khdl(t_env *env)
{
	env->khdl[0] = khdl_default;
	env->khdl[1] = khdl_zoom_inc;
	env->khdl[2] = khdl_zoom_dec;
	env->khdl[3] = khdl_quit;
	env->khdl[4] = khdl_none;
}

void			fdf_mlx(char *av, char *id, int fd)
{
	t_env		env;
	t_fdf_map	map;

	ft_bzero((void *)&map, sizeof(t_fdf_map));
	ft_bzero((void *)&env, sizeof(t_env));
	env.map = &map;
	env.av = av;
	env.id = id;
	fdf_init_khdl(&env);
	fdf_parse(&env, fd);
	close(fd);
	if (map.mat == NULL)
		return ;
	fdf_loop(&env);
}
