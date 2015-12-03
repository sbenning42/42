/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:04:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/03 15:26:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*fdf_fd(int fd, char *path, t_lex_rule rule)
{
	t_list		*lst;
	char		*line;
	int			ret;
	int			y;

	y = 0;
	ret = 1;
	lst = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			ft_printf("fdf: {red|ss}%s{eoc}: {red}Gnl error{eoc}\n", path);
			return (NULL);
		}
		else if (!fdf_lexing(&lst, line, y++, rule))
		{
			ft_printf("On file %s\n", path);
			return (NULL);
		}
	}
	return (lst);
}

static int		fdf_open(char *path)
{
	int			fd;

	fd = open(path, O_RDONLY);
	if (errno)
	{
		ft_printf("fdf: {red|ss}%s{eoc}: %s\n", path, strerror(errno));
		return (-1);
	}
	return (fd);
}

t_list			*fdf(char *path)
{
	int			fd;
	t_lex_rule	rule;
	t_list		*lst;

	rule.save_blk = False;
	rule.error = False;
	rule.esc = False;
	rule.rec = False;
	if (path)
	{
		fd = fdf_open(path);
		if (fd < 0)
			return (NULL);
	}
	else
	{
		fd = 0;
		path = "Standart Input";
	}
	lst = fdf_fd(fd, path, rule);
	close(fd);
	return (lst);
}
