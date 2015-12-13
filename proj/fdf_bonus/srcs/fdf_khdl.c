/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:15:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		khdl_none(void *p, int key)
{
	return (0);
	(void)p;
	(void)key;
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
