/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:04:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 18:37:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_exec(t_list *lst)
{
	t_fdf_point	*p;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (lst)
	{
		p = (t_fdf_point *)lst->content;
		if (i++)
			ft_printf("%c", y == p->y ? ' ' : '\n');
		ft_printf("%d-%d-%d", p->x, p->y, p->z);
		y = p->y;
		lst = lst->next;
	}
}

static void		fdf_fd(int fd, char *path, t_lex_rule rule)
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
		ft_putnbr(ret);
		if (ret < 0)
		{
			ft_printf("fdf: {red|ss}%s{eoc}: {red}Gnl error{eoc}\n", path);
			return ;
		}
		else if (fdf_lexing(&lst, line, y++, rule) == 0)
			return ;
	}
	fdf_exec(lst);
	ft_lstdel(&lst, NULL);
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

void			fdf(char *path)
{
	int			fd;
	t_lex_rule	rule;

	rule.save_blk = False;
	rule.error = True;
	rule.esc = False;
	rule.rec = False;
	if (path)
	{
		fd = fdf_open(path);
		if (fd < 0)
			return ;
	}
	else
	{
		fd = 0;
		path = "Standart Input";
	}
	fdf_fd(fd, path, rule);
	close(fd);
}
