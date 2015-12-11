/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:15:21 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 18:52:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_default_action(t_env *e)
{
	free(e->map->m);
	*e->map = *fdf_save_map(NULL);
	fdf_save_map(e);
}

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
	if (map->z_max < 126)
		map->z_max++;
	if (map->z_min > -126)
		map->z_min--;
	fdf_maj_alt_map(map, 1.0);
}

void		fdf_altd_action(t_fdf_map *map)
{
	if (map->z_max > 1)
		map->z_max--;
	if (map->z_min < -1)
		map->z_min++;
	fdf_maj_alt_map(map, -1.0);
}


void		fdf_quit_action(t_env *e)
{
	free(e->map->m);
	mlx_destroy_window(e->mlx, e->win);
	close(e->fd);
	exit(EXIT_SUCCESS);
}
