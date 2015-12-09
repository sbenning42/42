/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:21:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 09:00:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_initmat(t_fdf_px *m, int size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
			m[i][j] = INT_MIN;
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
	map->mat[i][X_rel] = i % map->x - (map->x / 2);
	map->mat[i][Y_rel] = i / map->x - (map->y / 2);
	map->mat[i][Z_rel] = ft_atoi(t->value);
	map->mat[i][X_scr] = map->mat[i][X_rel] * map->x_gap + map->x_rts;
	map->mat[i][Y_scr] = map->mat[i][Y_rel] * map->y_gap + map->y_rts;
	map->mat[i][Color] = FDF_COLOR(map->mat[i][Z_rel], map->z_min, map->z_max);
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

static void		fdf_maj_z(t_fdf_map *map, int z)
{
	if (z >= map->z_max)
		map->z_max = z;
	if (z <= map->z_min)
		map->z_min = z;
	if (map->z_max == map->z_min)
	{
		map->z_max += 1;
		map->z_min += -1;
	}
	while (!map->z_max)
		map->z_max++;
	while (!map->z_min)
		map->z_min--;
}

static void		fdf_maj_xy(t_fdf_map *map, int *x)
{
	map->y += 1;
	if (*x > map->x)
		map->x = *x;
	*x = 0;
}

static int		fdf_synerror(t_env *env, t_lex_tk *t)
{
	char		synmsg[FDF_SNPRINTF_BS];

	ft_bzero((void *)synmsg, FDF_SNPRINTF_BS);
	printf("\n\n[%s]\n\n", t->value);
	ft_sprintf(synmsg, "%s: [{red}%.*1s{eoc}]", "Syntax error near token", t->size, t->value);
	ft_fprintf(2, ERRFMT, env->av, env->id, synmsg);
	return (0);
}

static int		fdf_map_attr(t_env *env, t_list *lst)
{
	t_lex_tk	*t;
	int			x;

	x = 0;
	while (lst)
	{
		t = (t_lex_tk *)lst->content;
		x += 1;
		if (t->type == Unknow)
			return (fdf_synerror(env, t));
		else if (t->type == Eol)
			fdf_maj_xy(env->map, &x);
		else
			fdf_maj_z(env->map, ft_atoi(t->value));
		lst = lst->next;
	}
	env->map->x_gap /= env->map->x;
	env->map->y_gap /= env->map->y;
	if (!(env->map->mat = fdf_newpxmat(env->map->x * env->map->y)))
		return (ft_err(env->av, env->id, "Memory allocation failed"));
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
	while (ft_strdel(&line) && (ret = get_next_line(fd, &line)) > 0)
	{
		if (!(el = fdf_lexer(env->av, env->id, line)))
			break ;
		else if (el->next)
			ft_lstadd_back(&lst, el);
		else
			ft_lstdelone(&el, NULL);
	}
	if (ret < 0)
		ft_err(env->av, env->id, "Can't read (gnl)");
	else if (!ret && fdf_map_attr(env, lst))
		fdf_map_constructor(env, lst);
	ft_lstdel(&lst, NULL);
	return ((ret > 0 ? !ft_strdel(&line) : 1));
}
