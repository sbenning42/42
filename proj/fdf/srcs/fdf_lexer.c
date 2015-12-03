/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/03 17:56:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_synerror(t_list *lst, char *path)
{
	while (lst)
	{
		if (((t_lex_tk *)lst->content)->type != Const_nu)
		{
			ft_printf("fdf: {red}Syntax error: %.*s{eoc} : %s\n", \
					((t_lex_tk *)lst->content)->size, \
					((t_lex_tk *)lst->content)->value, path);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
/*
static int		fdf_handle_lexed(t_list **lst, t_list *lex_lst, \
				t_fdf_point point)
{
	t_list		*elem;
	char		*s;

	s = ((t_lex_tk *)lex_lst->content)->value;
	point.z = ft_atoi(s);
	if (!(elem = ft_lstnew(&point, sizeof(t_fdf_point))))
	{
		ft_lstdel(lst, NULL);
		ft_printf("fdf: {red}Memorry allocation error{eoc}\n");
		return (0);
	}
	ft_lstadd_back(lst, elem);
	return (1);
}

int				fdf_lexing(t_list **lst, char *s, int y, t_lex_rule rule)
{
	t_fdf_point	point;
	t_list		*lex_lst;
	t_list		*tmp;
	int			x;

	lex_lst = ft_lexer(rule, NULL, 0, s);
	if (fdf_synerror(lex_lst))
		return (0);
	point.y = y;
	x = 0;
	tmp = lex_lst;
	while (lex_lst)
	{
		point.x = x++;
		if (!fdf_handle_lexed(lst, lex_lst, point))
		{
			ft_lstdel(&tmp, NULL);
			free(s);
			return (0);
		}
		lex_lst = lex_lst->next;
	}
	ft_lstdel(&tmp, NULL);
	free(s);
	return (1);
}
*/
static int		fdf_memfailed(t_list **alst, char *path, int msg)
{
	if (msg)
		ft_printf("fdf: {red}Memory allocation failed{eoc}: %s\n", path);
	ft_lstdel(alst, NULL);
	return (0);
}

static int		fdf_lex_line(char *line, t_fdf_map *map, t_lex_rule rule)
{
	static int	x = 0;
	t_list		*lst;
	t_list		*cp;
	t_list		*elem;
	t_fdf_point	pt;

	map->x = 0;
	lst = ft_lexer(rule, NULL, 0, line);
	if (!lst || fdf_synerror(lst, map->path))
		return (fdf_memfailed(&lst, map->path, lst ? 0 : 1));
	pt.y = map->y;
	cp = lst;
	while (cp)
	{
		pt.x = map->x++;
		pt.z = ft_atoi(((t_lex_tk *)cp->content)->value);
		if (!(elem = ft_lstnew((void *)&pt, sizeof(t_fdf_point))))
			return (fdf_memfailed(&lst, map->path, 1));
		ft_lstadd_back(&map->lst, elem);
		cp = cp->next;
	}
	ft_lstdel(&lst, NULL);
	x = (x > (map->x - 1) ? x : map->x - 1);
	map->x = x;
	return (1);
}

static t_fdf_map	fdf_lex(int fd, char *path, t_lex_rule rule)
{
	t_fdf_map		map;
	char			*line;
	int				ret;

	map.lst = NULL;
	ft_bzero((void *)&map, sizeof(t_fdf_map) - sizeof(char *));
	ft_strncpy(map.path, path, ((ret = (int)ft_strlen(path)) > 64 ? 64 : ret));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!fdf_lex_line(line, &map, rule))
		{
			ft_lstdel(&map.lst, NULL);
			free(line);
			return (map);
		}
		map.y++;
		free(line);
	}
	if (ret < 0)
	{
		ft_printf("fdf: {red|ss}%s{eoc}: {red}Gnl error{eoc}\n", map.path);
		ft_lstdel(&map.lst, NULL);
	}
	return (map);
}

t_fdf_map		fdf_parse_map(char *path, t_lex_rule rule)
{
	t_fdf_map	map;
	int			fd;

	map.lst = NULL;
	if (!ft_strcmp(path, "Standard Input"))
		fd = 0;
	else
	{
		fd = open(path, O_RDONLY);
		if (fd < 0 || errno)
		{
			ft_printf("fdf: {red|ss}%s{eoc}: %s\n", path, strerror(errno));
			return (map);
		}
	}
	return (fdf_lex(fd, path, rule));
}
