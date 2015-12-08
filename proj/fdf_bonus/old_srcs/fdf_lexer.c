/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/05 18:02:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_synerror(t_list *lst, char *av, char *name)
{
	while (lst)
	{
		if (((t_lex_tk *)lst->content)->type != Const_nu)
		{
			ft_printf("%s: {red}%s{eoc}: %s'%.*s'\n", \
					av, name, "Parse error near token: ", \
					((t_lex_tk *)lst->content)->size, \
					((t_lex_tk *)lst->content)->value);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int		fdf_memfail(char *av, char *name, t_list **alst)
{
	ft_printf("%s: {red}%s{eoc}: %s\n", \
			av, "Memory allocation failed", name);
	if (alst)
		ft_lstdel(alst, NULL);
	return (0);
}

static void		fdf_majdept(t_fdf_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

static int		fdf_lex_line\
				(char *line, t_fdf_map *map, t_lex_rule rule, char *av)
{
	t_list		*lst;
	t_list		*cp;
	t_list		*elem;
	t_fdf_point	pt;

	if (!(lst = ft_lexer(rule, NULL, 0, line)))
		return (1);
	else if (fdf_synerror(lst, av, map->name))
		return (0);
	pt.y = map->y++;
	pt.x = 0;
	cp = lst;
	while (cp)
	{
		pt.z = ft_atoi(((t_lex_tk *)cp->content)->value);
		fdf_majdept(map, pt.z);
		if (!(elem = ft_lstnew((void *)&pt, sizeof(t_fdf_point))))
			return (fdf_memfail(av, map->name, &lst));
		ft_lstadd_back(&map->lst, elem);
		cp = cp->next;
		pt.x++;
	}
	ft_lstdel(&lst, NULL);
	map->x = ((pt.x - 1 > map->x) ? pt.x - 1 : map->x);
	return (1);
}

static int			fdf_parse_fd(int fd, char **av, int i, t_fdf_map *map)
{
	t_lex_rule		rules;
	char			*line;
	int				ret;

	ft_bzero((void *)&rules, sizeof(t_lex_rule));
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!fdf_lex_line(line, map, rules, av[0]))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	map->y--;
	if (ret < 0)
		ft_printf("%s:{red}%s{eoc}%s\n", \
				av[0], " Error: read or Memory allocation failed: ", av[i]);
	return (((ret == -1 || ret == 1) ? 0 : 1));
}

int				fdf_parse_file(char **av, int i, t_fdf_map *map)
{
	int			fd;

	map->name = av[i];
	if (!ft_strcmp(av[i], FDF_FAKE_AV))
		fd = 0;
	else
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0 || errno)
		{
			ft_printf("%s: {red|ss}%s{eoc}: %s\n",\
					av[0], av[i], strerror(errno));
			errno = 0;
			return (0);
		}
	}
	if (!fdf_parse_fd(fd, av, i, map) && map->lst)
	{
		ft_lstdel(&map->lst, NULL);
		return (0);
	}
	return (1);
}
