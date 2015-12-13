/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:11:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:12:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_map				*fdf_save_map(t_env *e)
{
	static char			call;
	static t_fdf_map	map;
	t_fdf_px			*m;
	int					size;
	int					i;

	if (call)
	{
		call = 0;
		return (&map);
	}
	map = *(e->map);
	size = map.x * map.y;
	if (!(m = (t_fdf_px *)ft_memalloc(sizeof(t_fdf_px) * size)))
	{
		ft_fprintf(2, "%s: {res}%s{eoc}: Memory allocation failed!\n", \
				e->av, e->id);
		fdf_quit_action(e);
	}
	i = -1;
	while (++i < size)
		ft_memcpy(m[i], e->map->m[i], sizeof(t_fdf_px));
	map.m = m;
	call = 1;
	return (&map);
}
