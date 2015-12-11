/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:21:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 17:23:54 by sbenning         ###   ########.fr       */
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

static void		fdf_map_constructor(t_env *env, t_list *lst)
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

static void		fdf_maj_xy(t_fdf_map *map, int *x)
{
	map->y += 1;
	if (*x > map->x)
		map->x = *x;
	*x = -1;
}

static int		fdf_synerror(t_env *env, t_lex_tk *t)
{
	char		synmsg[FDF_SNPRINTF_BS];

	ft_bzero((void *)synmsg, FDF_SNPRINTF_BS);
	ft_sprintf(synmsg, "%s: [{red}%.*1s{eoc}]", "Syntax error near token", t->size, t->value);
	ft_fprintf(2, ERRFMT, env->av, env->id, synmsg);
	return (0);
}

static int		fdf_map_attr(t_env *e, t_list *lst)
{
	t_lex_tk	*t;
	int			x;
	int			max;

	x = 0;
	while (lst)
	{
		t = (t_lex_tk *)lst->content;
		if (t->type == Unknow)
			return (fdf_synerror(e, t));
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

int				fdf_parser(t_env *env, int fd)
{
	t_list		*lst;
	t_list		*el;
	char		*line;
	int			ret;

	lst = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(el = fdf_lexer(env->av, env->id, line)))
			break ;
		else if (el->next)
			ft_lstadd_back(&lst, el);
		else
			ft_lstdelone(&el, fdf_free_line);
	}
	if (ret < 0)
		ft_err(env->av, env->id, "Can't read (gnl)");
	else if (!ret && fdf_map_attr(env, lst))
		fdf_map_constructor(env, lst);
	ft_lstdel(&lst, fdf_free_line);
	return ((ret > 0 ? 0 : 1));
}
