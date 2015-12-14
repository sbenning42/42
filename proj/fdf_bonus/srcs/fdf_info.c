/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:35:13 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 10:37:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bres_fill_info_o1o2(int dx, int dy, t_bres_info *info)
{
	info->diff = ABSI(dx) > ABSI(dy) ? ABSI(dx) : ABSI(dy);
	info->id = (dx >= dy ? X_scr : Y_scr);
	info->id_e = (dx >= dy ? Y_scr : X_scr);
	info->d1 = (dx >= dy ? dx : dy);
	info->d2 = (dx >= dy ? dy : dx);
	info->i0 = -1;
	info->i1 = 1;
	info->i2 = 1;
	info->c1 = 1;
	info->c2 = 0;
}

void		bres_fill_info_o3o4(int dx, int dy, t_bres_info *info)
{
	info->diff = ABSI(dx) > ABSI(dy) ? ABSI(dx) : ABSI(dy);
	info->id = (-dx >= dy ? X_scr : Y_scr);
	info->id_e = (-dx >= dy ? Y_scr : X_scr);
	info->d1 = (-dx >= dy ? dx : dy);
	info->d2 = (-dx >= dy ? dy : dx);
	info->i0 = 1;
	info->i1 = (-dx >= dy ? -1 : 1);
	info->i2 = (-dx >= dy ? 1 : -1);
	info->c1 = (-dx >= dy ? 0 : 1);
	info->c2 = 1;
}

void		bres_fill_info_o5o6(int dx, int dy, t_bres_info *info)
{
	info->diff = ABSI(dx) > ABSI(dy) ? ABSI(dx) : ABSI(dy);
	info->id = (dx <= dy ? X_scr : Y_scr);
	info->id_e = (dx <= dy ? Y_scr : X_scr);
	info->d1 = (dx <= dy ? dx : dy);
	info->d2 = (dx <= dy ? dy : dx);
	info->i0 = -1;
	info->i1 = -1;
	info->i2 = -1;
	info->c1 = 0;
	info->c2 = 1;
}

void		bres_fill_info_o7o8(int dx, int dy, t_bres_info *info)
{
	info->diff = ABSI(dx) > ABSI(dy) ? ABSI(dx) : ABSI(dy);
	info->id = (dx >= -dy ? X_scr : Y_scr);
	info->id_e = (dx >= -dy ? Y_scr : X_scr);
	info->d1 = (dx >= -dy ? dx : dy);
	info->d2 = (dx >= -dy ? dy : dx);
	info->i0 = 1;
	info->i1 = (dx >= -dy ? 1 : -1);
	info->i2 = (dx >= -dy ? -1 : 1);
	info->c1 = (dx >= -dy ? 1 : 0);
	info->c2 = 0;
}

void		bres_fill_info_verthor(int dx, int dy, t_bres_info *info)
{
	info->diff = ABSI(dx) > ABSI(dy) ? ABSI(dx) : ABSI(dy);
	info->id = (dx == 0 ? Y_scr : X_scr);
	info->id_e = -1;
	info->d1 = (dx == 0 ? dy : dx);
	info->d2 = (dx == 0 ? dx : dy);
	info->i0 = 0;
	info->i1 = (info->d1 > 0 ? 1 : -1);
	info->d1 = info->d2;
	info->i2 = 0;
	info->c1 = 0;
	info->c2 = 0;
}
