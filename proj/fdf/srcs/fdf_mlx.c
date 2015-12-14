/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 00:47:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 09:40:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*fdf_getname(char *s)
{
	char		*name;

	name = ft_strrchr(s, '/');
	return ((name ? name + 1 : s));
}

static void		fdf_loop(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_err(e->av, e->id, "Can't init mlx");
	else if (!(e->win = mlx_new_window(e->mlx, FDF_SCREEN, FDF_SCREEN, \
										fdf_getname(e->id))))
		ft_err(e->av, e->id, "Can't create mlx window");
	else
	{
		mlx_key_hook(e->win, fdf_key, (void *)e);
		mlx_expose_hook(e->win, fdf_draw, (void *)e);
		mlx_loop(e->mlx);
	}
}

static void		fdf_init_khdl(t_env *e)
{
	e->khdl[DEF_K_ID].key = FDF_DEF_K;
	e->khdl[DEF_K_ID].hdl = khdl_default;
	e->khdl[ZOOI_K_ID].key = FDF_ZOOI_K;
	e->khdl[ZOOI_K_ID].hdl = khdl_zoom_inc;
	e->khdl[ZOOD_K_ID].key = FDF_ZOOD_K;
	e->khdl[ZOOD_K_ID].hdl = khdl_zoom_dec;
	e->khdl[QUIT_K_ID].key = FDF_QUIT_K;
	e->khdl[QUIT_K_ID].hdl = khdl_quit;
	e->khdl[ALTI_K_ID].key = FDF_ALTI_K;
	e->khdl[ALTI_K_ID].hdl = khdl_alt_inc;
	e->khdl[ALTD_K_ID].key = FDF_ALTD_K;
	e->khdl[ALTD_K_ID].hdl = khdl_alt_dec;
}

void			fdf_mlx(char *av, char *id, int fd)
{
	t_env		e;
	t_fdf_map	map;

	ft_bzero((void *)&map, sizeof(t_fdf_map));
	ft_bzero((void *)&e, sizeof(t_env));
	fdf_init_khdl(&e);
	map.z_max = INT_MIN;
	map.z_min = INT_MAX;
	e.map = &map;
	e.av = av;
	e.id = id;
	e.fd = fd;
	if (fdf_parser(&e, fd) && map.m)
	{
		fdf_save_map(&e);
		fdf_loop(&e);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
