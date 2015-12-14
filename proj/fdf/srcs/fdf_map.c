/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:00:34 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:10:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_initmat(t_fdf_px *m, int size)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		ft_bzero((void *)m[i], sizeof(t_fdf_px));
		m[i][Fix] = 1.0;
	}
}

static t_fdf_px	*fdf_newpxmat(int size)
{
	t_fdf_px	*m;

	if (!(m = (t_fdf_px *)ft_memalloc(sizeof(t_fdf_px) * size)))
		return (NULL);
	fdf_initmat(m, size);
	return (m);
}

static void		fdf_maj_xy(t_fdf_map *map, int *x)
{
	map->y += 1;
	if (*x > map->x)
		map->x = *x;
	*x = -1;
}

int				fdf_map_attr(t_env *e, t_list *lst)
{
	t_lex_tk	*t;
	int			x;
	int			max;

	if (!lst)
		return (ft_verbose(e->av, e->id, "File seems to be empty..."));
	x = 0;
	while (lst)
	{
		t = (t_lex_tk *)lst->content;
		if (t->type == Unknow)
			return (fdf_synerror(e, t, e->map->y + 1));
		else if (t->type == Eol)
			fdf_maj_xy(e->map, &x);
		lst = lst->next;
		x++;
	}
	max = (e->map->x > e->map->y ? e->map->x : e->map->y);
	e->map->gap = (FDF_SCREEN / 3.0) / max;
	if (!(e->map->m = fdf_newpxmat(e->map->x * e->map->y)))
		return (ft_err(e->av, e->id, "Memory allocation failed"));
	return (1);
}
