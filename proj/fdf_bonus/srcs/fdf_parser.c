/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:21:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 19:23:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_initmat(t_fdf_map *map)
{
	int			i;
	int			j;
	int			x;
	int			y;

	x = map->x;
	y = map->y;
	i = -1;
	while (++i < (x * y))
	{
		j = -1;
		while (++j < 6)
			map->mat[i][j] = INT_MIN;
	}
}

static int		fdf_map_newmat(t_env *env)
{
	env->map->mat = (t_fdf_px *)ft_memalloc(sizeof(t_fdf_px) * \
										(env->map->x * env->map->y));
	if (env->map->mat == NULL)
	{
		ft_err(env->av, env->id, "Memory allocation failed");
		return (0);
	}
	fdf_initmat(env->map);
	return (1);
}

static t_list	*fdf_squeeze(t_list *cp, int *i, int x)
{
	while (*i % x && cp)
		(*i)++;
	return (cp->next);
}

static void		fdf_fill_px(t_fdf_map *map, int i, t_lex_tk *t)
{
	map->mat[i][X_rel] = i % map->x - (map->x / 2);
	map->mat[i][Y_rel] = i / map->x - (map->y / 2);
	map->mat[i][Z_rel] = ft_atoi(t->value);
	map->mat[i][X_scr] = map->mat[i][X_rel] * map->x_gap + map->x_rts;
	map->mat[i][Y_scr] = map->mat[i][Y_rel] * map->y_gap + map->y_rts;
	map->mat[i][Color] = map->mat[i][Z_rel] * map->c_gap;
}

static void		fdf_map_constructor(t_env *env, t_list **alst)
{
	t_lex_tk	*t;
	t_list		*cp;
	int			i;
	
	cp = *alst;
	env->map->x_rts = X_SCR / 2;
	env->map->y_rts = Y_SCR / 2;
	env->map->x_gap = (X_SCR / 1.5) / env->map->x;
	env->map->y_gap = (Y_SCR / 1.5) / env->map->y;
	env->map->c_gap = 0xff0000 / ((i = (env->map->z_max - env->map->z_min)) == 0 ? 1 : i);
	i = 0;
	while (cp)
	{
		t = (t_lex_tk *)cp->content;
		if (t->type == Eol)
		{
			cp = fdf_squeeze(cp, &i, env->map->x);
			continue ;
		}
		else
		{
			fdf_fill_px(env->map, i, t);
			cp = cp->next;
		}
		i++;
	}
}

static int		fdf_synerror_action(t_env *env, t_lex_tk *t, int ret)
{
	char		synmsg[64];

	ft_sprintf(synmsg, "%s: '{red}%*s{eoc}'",\
		   	"Syntax error near token", t->size, *t->value);
	ft_fprintf(2, ERRFMT, env->av, env->id, synmsg);
	return (ret);
}

static void		fdf_maj_z(t_fdf_map *map, t_lex_tk *t)
{
	int			r;

	r = ft_atoi(t->value);
	if (r >= map->z_max)
		map->z_max = r;
	if (r <= map->z_min)
		map->z_min = r;
}

static int		fdf_synerror(t_env *env, t_list **alst)
{
	t_list		*cp;
	t_lex_tk	*t;
	int			x;

	cp = *alst;
	x = -1;
	if (*alst == NULL)
		return (1);
	while (cp && (++x + 1))
	{
		t = (t_lex_tk *)cp->content;
		if (t->type == Unknow)
			return (fdf_synerror_action(env, t, 1));
		else if (t->type == Eol)
		{
			env->map->y++;
			env->map->x = (env->map->x < x ? x : env->map->x);
			x = 0;
		}
		else
			fdf_maj_z(env->map, t);
		cp = cp->next;
	}
	return (0);
}

void			fdf_parser(t_env *env, int fd)
{
	t_list		*lst;
	t_list		*el;
	char		*line;
	int			ret;

	lst = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((el = fdf_lexer(env->av, env->id, line)) == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd_back(&lst, el);
	}
	if (ret < 0)
	{
		ft_err(env->av, env->id, "Can't read (gnl)");
		ft_lstdel(&lst, NULL);
	}
	if (!fdf_synerror(env, &lst) && fdf_map_newmat(env))
	{
		fdf_map_constructor(env, &lst);
	}
	else
		ft_lstdel(&lst, NULL);
}
