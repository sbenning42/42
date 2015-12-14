/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:34:32 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 09:42:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_getscr_attr(t_fdf_map *map, t_fdf_px px)
{
	px[X_iso] = TOXISO(sqrtf, px[X_rel], px[Y_rel]);
	px[Y_iso] = TOYISO(sqrtf, px[X_rel], px[Y_rel], px[Z_rel]);
	px[X_scr] = TOSCREEN(px[X_iso], map->gap);
	px[Y_scr] = TOSCREEN(px[Y_iso], map->gap);
	if (px[Z_rel] > 0.0)
		px[Color] = (float)TOCOLORUNK(((px[Z_rel] * BLUE) / map->z_max));
	else if (px[Z_rel] < 0.0)
		px[Color] = (float)TOCOLORUNK(px[Z_rel]);
	else
		px[Color] = (float)0xffffff;
}
