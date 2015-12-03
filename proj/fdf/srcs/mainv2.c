/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/03 18:27:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_draw(void *p)
{
	t_env		*e;
	int			x;
	int			y;

	e = (t_env *)p;
	y = 0;
	while (y <= e->map.y)
	{
		x = 0;
		while (x <= e->map.x)
		{
			if (e->map.mat[y][x] != INT_MIN)
				mlx_pixel_put(e->mlx, e->win, x * FDF_GAP, y * FDF_GAP, \
								e->map.mat[y][x] * 0xff);
			x++;
		}
		y++;
	}
	return (0);
}

int				fdf_key(int key, void *p)
{
	t_env		*e;

	if (key == 53 || key == 12)
	{
		e = (t_env *)p;
		mlx_destroy_window(e->mlx, e->win);
		//fdf_destroy_mat(&e->map.mat, e->map.x);
		exit(EXIT_SUCCESS);
	}
	else
		ft_fprintf(2, "[{green}%d{eoc}][{cyan}%c{eoc}]\n", key, (char)key);
	return (0);
}

static void		fdf_fill_mat(t_fdf_map map)
{
	t_list		*cp;
	t_fdf_point	*pt;

	//ft_printf("{cyan}PASS HERE\n{eoc}\n");
	cp = map.lst;
	while (cp)
	{
		pt = (t_fdf_point *)cp->content;
		map.mat[pt->y][pt->x] = pt->z;
		cp = cp->next;
	}
	ft_lstdel(&map.lst, NULL);
}

static void		ft_intset(int *t, int v, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
		t[i++] = v;
}

static int		fdf_handle_env(t_env *e)
{
	int			i;

	if (!(e->map.mat = (int **)ft_memalloc(sizeof(int *) * e->map.y)))
	{
		ft_printf("fdf: {red}Error: Memory allocation failed!{eoc} : %s\n", \
					e->map.path);
		ft_lstdel(&e->map.lst, NULL);
		return (1);
	}
	i = -1;
	while (++i <= e->map.y)
	{
		if (!(e->map.mat[i] = (int *)ft_memalloc(sizeof(int) * e->map.x)))
		{
			//fdf_destroy_mat(&e->map.mat, i);
			ft_printf("fdf: {red}Error: Memory allocation failed!{eoc} : %s\n",\
						e->map.path);
			ft_lstdel(&e->map.lst, NULL);
			return (1);
		}
		ft_intset(e->map.mat[i], INT_MIN, (size_t)e->map.x);
	}
	fdf_fill_mat(e->map);
	return (0);
}

static char		*justname(char *path)
{
	return (ft_strrchr(path, '/') + 1);
}

static void		fdf_mlx(t_fdf_map map)
{
	t_env		e;

	e.map = map;
	e.mlx = mlx_init();
	if (!e.mlx)
	{
		ft_printf("fdf: {red}Error: Can't load mlx: %s{eoc}\n", map.path);
		return ;
	}
	e.win = mlx_new_window(e.mlx, FDF_WIDTH, FDF_HEIGHT, justname(map.path));
	if (!e.win)
	{
		ft_printf("fdf: {red}Error: Can't create window: %s{eoc}\n", map.path);
		return ;
	}
	if (fdf_handle_env(&e))
	{
		mlx_destroy_window(e.mlx, e.win);
		ft_printf("fdf: {red}Error: Can't handle env :( : %s{eoc}\n", map.path);
		return ;
	}
	mlx_expose_hook(e.win, fdf_draw, (void *)&e);
	mlx_key_hook(e.win, fdf_key, (void *)&e);
	mlx_loop(e.mlx);
}

void			fdf(t_fdf_map map)
{
	int			pid;

	pid = fork();
	if (!pid)
		fdf_mlx(map);
	else if (pid < 0)
		ft_printf("fdf: {red}Error: Can't fork to handle{eoc} %s\n", map.path);
}

int				main(int ac, char **av)
{
	t_lex_rule	rule;
	t_fdf_map	map;
	char		fake_av[64];
	int			i;

	ft_bzero((void *)&rule, sizeof(t_lex_rule));
	ft_bzero((void *)fake_av, sizeof(char) * 64);
	i = 0;
	while (++i < ac)
	{
		map = fdf_parse_map(av[i], rule);
		if (map.lst)
			fdf(map);
	}
	if (ac == 1)
	{
		ft_strcpy(fake_av, "Standard Input");
		map = fdf_parse_map(fake_av, rule);
		fdf(map);
	}
	if (map.lst)
		ft_printf("fdf: {ss}This is the rules when focus on window:{eoc}\n\n\
{green}<escape>{eoc} : Close the window\n\
{green}<up-down>{eoc} : Change color\n\n");
	return (0);
}
