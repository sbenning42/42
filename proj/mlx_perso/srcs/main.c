/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 01:53:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 11:51:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"

int				gen_color(int z)
{
	int			c;

	if (z == 0)
		return (WHITE);
	else if (z > 0)
		c = (RED + GREEN) - ((GREEN / BLUE) * z);
	else
		c = (BLUE + GREEN) - (((GREEN / BLUE)) * -z);
	return (c);
}

void			gen_mlx_putmat(t_env *e, t_fdf_px *m, int clr)
{
	int			i;
	int			c;

	i = -1;
	while (++i < (e->map->x * e->map->y))
	{
		if (m[i][Fix])
			continue ;
		c = (clr ? 0 : (int)m[i][Color]);
		mlx_pixel_put(e->mlx, e->win, (int)m[i][X_scr], (int)m[i][Y_scr], c);
	}
}

void			gen_getscreen(t_gen_map *map, t_fdf_px *m)
{
	int			i;

	i = -1;
	while (++i < (map->x * map->y))
	{
		if (m[i][Fix])
			continue ;
		m[i][X_scr] = m[i][X_iso] * map->gap + (SCREEN / 2.0);
		m[i][Y_scr] = m[i][Y_iso] * map->gap + (SCREEN / 2.0);
		m[i][Color] = (float)gen_color(m[i][Z_rel]);
	}
}

int				gen_draw(void *p)
{
	t_env		*e;

	e = (t_env *)p;
	gen_getscreen(e->map, e->map->m);
	gen_mlx_putmat(e, e->map->m, 0);
	return (0);

}
int				gen_key(int key, void *p)
{
	t_env		*e;

	e = (t_env *)p;
	if (key == 65451 || key == 69)
	{
		gen_mlx_putmat(e, e->map->m, 1);
		e->map->gap += (e->map->gap / 10.0);
		gen_getscreen(e->map, e->map->m);
		gen_mlx_putmat(e, e->map->m, 0);
		return (0);
	}
	else if (key == 65453 || key == 78)
	{
		gen_mlx_putmat(e, e->map->m, 1);
		if ((e->map->gap - (e->map->gap / 10.0)) >= 1.0)
			e->map->gap -= (e->map->gap / 10.0);
		gen_getscreen(e->map, e->map->m);
		gen_mlx_putmat(e, e->map->m, 0);
		return (0);
	}
	else if (key == 65437 || key == 87)
	{
		gen_mlx_putmat(e, e->map->m, 1);
		e->map->gap = ((SCREEN / 3.0) / (e->map->x > e->map->y ? e->map->x : e->map->y));
		gen_getscreen(e->map, e->map->m);
		gen_mlx_putmat(e, e->map->m, 0);
		return (0);
	}
	else if (!(key == 53 || key == 12 || key == 65307))
		return (ft_printf("(%d)\n", key));
	mlx_destroy_window(e->mlx, e->win);
	ft_memdel((void **)&e->map->m);
	exit(EXIT_SUCCESS);
	return (0);
}

static void		gen_mlx(char *av, t_fdf_px *m, int x, int y)
{
	t_env		e;
	t_gen_map	map;

	map.m = m;
	map.x = x;
	map.y = y;
	map.gap = ((SCREEN / 3.0) / (x > y ? x : y));
	e.map = &map;
	e.av = av;
	if (!(e.mlx = mlx_init()))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", "mlx init");
		ft_memdel((void **)&m);
		return ;
	}
	if (!(e.win = mlx_new_window(e.mlx, 680, 420, av)))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", "mlx create window");
		ft_memdel((void **)&m);
		return ;
	}
	mlx_key_hook(e.win, gen_key, &e);
	mlx_expose_hook(e.win, gen_draw, &e);
	mlx_loop(e.mlx);
}

static int		gen_putusage(char *av, int returnval)
{
	ft_printf("%s: %s: %s\n", av, "Usage", "gen [x] [y]");
	return (returnval);
}

static void		gen_fillmat(t_fdf_px *m, int x, int y)
{
	int			i;
	int			c;

	i = -1;
	while (++i < (x * y))
	{
		if (i < 50)
			c = 0;
		else if (i < 100)
			c = 10;
		else if (i < 150)
			c = 0;
		else if (i < 200)
			c = -10;
		else
			c = 0;
		m[i][Fix] = 0.0;
		m[i][X_rel] = (float)(i % x)/* - ((float)x / 2.0)*/;
		m[i][Y_rel] = (float)(i / x)/* - ((float)y / 2.0)*/;
		m[i][Z_rel] = c;
		m[i][X_iso] = (sqrtf(2.0) / 2.0) * (m[i][X_rel] - m[i][Y_rel]);
		m[i][Y_iso] = (sqrtf(2.0 / 3.0) * -m[i][Z_rel]) - (1.0 / sqrt(6.0)) * (m[i][X_rel] + m[i][Y_rel]);
		m[i][Color] = 0xffffff;
	}
}

static int		gen(char *av, int x, int y)
{
	t_fdf_px	*m;
	int			pid;

	if (!(m = (t_fdf_px *)ft_memalloc(sizeof(t_fdf_px) * (x * y))))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", \
				av, "Error", "Memory allocation failed");
		return (1);
	}
	gen_fillmat(m, x, y);
	if (!(pid = fork()))
		gen_mlx(av, m, (float)x, (float)y);
	else if (pid < 0 || errno)
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", strerror(errno));
		errno = 0;
		free(m);
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	int			x;
	int			y;

	if (ac != 3)
		return (gen_putusage(av[0], 0));
	x = ft_atoi(av[1]);
	y = ft_atoi(av[2]);
	if (!(x >= 0 && y >= 0))
		return (gen_putusage(av[0], 0));
	if (gen(av[0], x, y))
		return (1);
	return (0);
}
