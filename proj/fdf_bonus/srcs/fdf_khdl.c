/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 18:51:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		khdl_none(void *p, int key)
{
	t_env	*e;
	int		fd;

	e = (t_env *)p;
	if ((fd = open("fdf.deb.out", O_WRONLY|O_APPEND)) > 0)
	{
		ft_fprintf(fd, "%s: %s: [%d]\n", e->av, e->id, key);
		close(fd);
	}
	return (0);
}

int		khdl_quit(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_quit_action(e);
	return (0);
	(void)key;
}

int		khdl_default(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, CLEAR);
	fdf_default_action(e);
	fdf_majmat(e);
	fdf_draw_m(e, e->map, 0);
	return (0);
	(void)key;
}

int		khdl_zoom_inc(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, CLEAR);
	fdf_zoomi_action(e->map);
	fdf_majmat(e);
	fdf_draw_m(e, e->map, 0);
	return (0);
	(void)key;
}

int		khdl_zoom_dec(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, CLEAR);
	fdf_zoomd_action(e->map);
	fdf_majmat(e);
	fdf_draw_m(e, e->map, 0);
	return (0);
	(void)key;
}

int		khdl_alt_inc(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, CLEAR);
	fdf_alti_action(e->map);
	fdf_majmat(e);
	fdf_draw_m(e, e->map, 0);
	return (0);
	(void)key;
}

int		khdl_alt_dec(void *p, int key)
{
	t_env	*e;

	e = (t_env *)p;
	fdf_draw_m(e, e->map, CLEAR);
	fdf_altd_action(e->map);
	fdf_majmat(e);
	fdf_draw_m(e, e->map, 0);
	return (0);
	(void)key;
}
