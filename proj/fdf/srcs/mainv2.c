/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/04 14:15:47 by sbenning         ###   ########.fr       */
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
				mlx_pixel_put(e->mlx, e->win, FDF_GAP_W(x, e->map.x), \
						FDF_GAP_H(y, e->map.y), \
						0xff0000 - (e->map.mat[y][x]->z * 0xff));
			x++;
		}
		y++;
	}
	return (0);
}

int				fdf_key(int key, void *p)
{
	t_env		*e;

	if (key == 53 || key == 12 || key == 65307)
	{
		e = (t_env *)p;
		mlx_destroy_window(e->mlx, e->win);
		//fdf_destroy_mat(&e->map.mat, e->map.x);
		exit(EXIT_SUCCESS);
	}
/*	else
		ft_fprintf(2, "[{green}%d{eoc}][{cyan}%c{eoc}]\n", key, (char)key);
*/	return (0);
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
		map.mat[pt->y][pt->x] = pt;
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
					e->map.name);
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
						e->map.name);
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

static void		fdf_mlx(t_fdf_map map, char *av)
{
	t_env		e;

	e.map = map;
	e.mlx = mlx_init();
	if (!e.mlx)
	{
		ft_printf("fdf: {red}Error: Can't load mlx: %s{eoc}\n", map.name);
		return ; //FREE(map.lst || e.map.lst)!!!!
	}
	e.win = mlx_new_window(e.mlx, FDF_WIDTH, FDF_HEIGHT, justname(map.name));
	if (!e.win)
	{
		ft_printf("%s: {red}%s%s{eoc}\n", \
				av, "Error: Can't create window: ", map.name);
		return ; //FREE(map.lst || e.map.lst)!!!!
	}
	if (fdf_handle_env(&e))
	{
		mlx_destroy_window(e.mlx, e.win);
		ft_printf("%s: {red}%s%s{eoc}\n", av, "Error: Can't handle env :( : ", map.name);
		return ; //FREE(map.lst || e.map.lst)!!!!
	}
	mlx_expose_hook(e.win, fdf_draw, (void *)&e);
	mlx_key_hook(e.win, fdf_key, (void *)&e);
	mlx_loop(e.mlx);
}

static char		**fdf_handle_av(int *ac, char **fake, char **real)
{
	char		**av;

	fake[0] = real[0];
	fake[1] = FDF_FAKE_AV;
	av = (*ac == 1 ? fake : real);
	*ac += (*ac == 1 ? 1 : 0);
	return (av);
}
/*
static int		fdf_fail(char *name)
{
	ft_printf("%s:{ss}%s{eoc}", name, " There is no valid map\n");
	return (0);
}
*/
static int		fdf_success(char *name)
{
	ft_printf("%s:{ss}%s{eoc}\n\n{green}%s{eoc}%s{green}%s{eoc}%s",\
			name, " This is the rules when focus on window:",\
			"<escape>", " : Close the window\n",\
			"<up-down>", " : Change color\n\n");
	return (0);
}

int				main(int ac, char **av)
{
	char		**fdf_av;
	char		*fake_av[2];
	t_fdf_map	map;
	int			pid;
	int			i;

	fdf_av = fdf_handle_av(&ac, fake_av, av);
	fdf_success(av[0]);
	i = 1;
	while (i < ac)
	{
		ft_bzero((void *)&map, sizeof(t_fdf_map));
		if (fdf_parse_file(fdf_av, i++, &map))
		{
			if (!(pid = fork()))
				fdf_mlx(map, av[0]);
			else if (pid < 0)
				ft_printf("%s:{red}%s{eoc}%s\n", \
						av[0], " Error: Can't fork to handle ", fdf_av[i - 1]);
		}
	}
	return (0);
}
