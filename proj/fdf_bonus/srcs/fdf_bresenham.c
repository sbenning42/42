/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:35:32 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 10:37:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		bres_info(int dx, int dy, t_bres_info *info)
{
	if (dx > 0 && dy)
	{
		if (dy > 0)
			bres_fill_info_o1o2(dx, dy, info);
		else
			bres_fill_info_o7o8(dx, dy, info);
	}
	else if (dx < 0 && dy)
	{
		if (dy > 0)
			bres_fill_info_o3o4(dx, dy, info);
		else
			bres_fill_info_o5o6(dx, dy, info);
	}
	else if (dx == 0 || dy == 0)
		bres_fill_info_verthor(dx, dy, info);
}

static int		bres_color(int c1, int c2)
{
	int			c;

	if (c1 != c2)
	{
		if (c1 == WHITE && c2 > GREEN)
			c = c2 + 0x8800;
		else if (c2 == WHITE && c1 > GREEN)
			c = c1 + 0x8800;
		else if (c1 == WHITE && c2 < GREEN)
			c = c2 + 0x8800;
		else if (c2 == WHITE && c1 < GREEN)
			c = c1 + 0x8800;
		else
			c = ((c1 + c2) / 2);
	}
	else
		c = c1;
	return (c);
}

static void		bres_put(t_env *env, t_fdf_pxi p1, t_fdf_pxi p2, \
				t_bres_info info)
{
	int			e;
	int			c;

	c = (info.clr ? 0 : bres_color(p1[Color], p2[Color]));
	e = info.d1;
	info.d1 = e * 2;
	info.d2 *= 2;
	while (42)
	{
		mlx_pixel_put(env->mlx, env->win, p1[X_scr], p1[Y_scr], c);
		p1[info.id] += info.i1;
		if (p1[info.id] == p2[info.id])
			break ;
		e += info.i0 * info.d2;
		if ((info.c1 && e < 0) || (!info.c1 && e > 0) || (info.c2 && e == 0))
		{
			p1[info.id_e] += info.i2;
			e += info.d1;
		}
	}
}

void			fdf_bresenham_px(t_env *e, t_fdf_px p1, t_fdf_px p2, int clr)
{
	t_bres_info	info;
	t_fdf_pxi	cp1;
	t_fdf_pxi	cp2;
	int			i;

	i = -1;
	while (++i < 9)
	{
		cp1[i] = (int)p1[i];
		cp2[i] = (int)p2[i];
	}
	bres_info(cp2[X_scr] - cp1[X_scr], cp2[Y_scr] - cp1[Y_scr], &info);
	info.clr = clr;
	bres_put(e, cp1, cp2, info);
}
