/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:04:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/01 14:03:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_ptr(int keycode, void *ptr)
{
	t_param		param;

	param = *((t_param *)ptr);
	ft_printf("Keycode = %d\n", keycode);
//	ft_lstdel(&param.lst, NULL);
//	mlx_destroy_window(param.mlx, param.win);
	return (0);
}

static void		fdf_exec(t_list *lst, char *path)
{
/*	t_list		*cp;
	t_fdf_point	*p;
	int			y;
	int			i;

	y = 0;
	i = 0;
	cp = lst;
	while (cp)
	{
		p = (t_fdf_point *)cp->content;
		if (i++)
			ft_printf("%c", y == p->y ? '-' : '\n');
		ft_printf("({cyan}%d{eoc},{green}%d{eoc},{yellow}%d{eoc})", \
					p->x, p->y, p->z);
		y = p->y;
		cp = cp->next;
	}
*/
	void		*mlx;
	void		*win;
	char		buf[FDF_BS];
	t_param		param;

	if (!(mlx = mlx_init()))
	{
		ft_printf("fdf: Error: {red}Can't init mlx{eoc}\n");
		return ;
	}
	ft_sprintf(buf, "Fdf: %s", path);
	win = mlx_new_window(mlx, 2500, 2500, buf);
	if (!win)
	{
		ft_printf("fdf: Error: {red}Can't create window{eoc}\n");
		return ;
	}
	param.lst = lst;
	param.mlx = mlx;
	param.win = win;
	mlx_loop(mlx);
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
		if (ret < 0)
		{
			ft_printf("fdf: {red|ss}%s{eoc}: {red}Gnl error{eoc}\n", path);
			return ;
		}
		else if (fdf_lexing(&lst, line, y++, rule) == 0)
			return ;
	}
	fdf_exec(lst, path);
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
