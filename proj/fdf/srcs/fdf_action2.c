/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_action2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:15:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 09:44:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_zoomi_action(t_fdf_map *map)
{
	map->gap += map->gap / 10.0;
}

void		fdf_zoomd_action(t_fdf_map *map)
{
	if ((map->gap - (map->gap / 10.0)) >= 2.0)
		map->gap -= map->gap / 10.0;
}

void		fdf_alti_action(t_fdf_map *map)
{
	if (map->z_max > 0 && map->z_max < 126)
		map->z_max++;
	if (map->z_min > -126 && map->z_min < 0)
		map->z_min--;
	fdf_maj_alt_map(map, 1.0);
}

void		fdf_altd_action(t_fdf_map *map)
{
	if (map->z_max > 1 && map->z_max < 126)
		map->z_max--;
	if (map->z_min > -126 && map->z_min < 0)
		map->z_min++;
	fdf_maj_alt_map(map, -1.0);
}
