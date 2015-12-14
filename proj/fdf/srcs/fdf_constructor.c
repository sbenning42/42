/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:09:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 09:43:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_fill_px(t_fdf_map *map, int i, t_lex_tk *t)
{
	float		z;

	z = ((float)ft_atoi(t->value) / 2.0);
	z = (z > 127.0 ? 127.0 : z);
	z = (z < -127.0 ? -127.0 : z);
	map->m[i][Z_rel] = z;
	map->z_max = (map->z_max < (int)z ? (int)z : map->z_max);
	map->z_min = (map->z_min > (int)z ? (int)z : map->z_min);
	z = ABSF(z);
	map->m[i][Fix] = 0.0;
	map->m[i][X_rel] = (float)(i % map->x) - (map->x / 2);
	map->m[i][Y_rel] = (float)(i / map->x) - (map->y / 2);
	fdf_getscr_attr(map, map->m[i]);
}

void			fdf_map_constructor(t_env *env, t_list *lst)
{
	t_lex_tk	*t;
	int			i;

	i = 0;
	while (lst)
	{
		t = (t_lex_tk *)lst->content;
		if (t->type == Eol)
		{
			while (i % env->map->x)
				i++;
		}
		else
			fdf_fill_px(env->map, i++, t);
		lst = lst->next;
	}
}
