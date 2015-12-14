/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:15:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:15:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
