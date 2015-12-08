/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 01:53:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/07 13:18:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen.h"
/*
int				gen_key(int key, void *p)
{
	t_env		*e;

	e = (t_env *)p;
	if (GEN_QUIT(key))
	{
		ft_printf("%s: {cyan}%s{eoc}: %s\n", e->av, "gen control", "Good bye!");
		mlx_destroy_window(e->mlx, e->win);
		ft_memdel((void **)&e->map->mat);
		exit(EXIT_SUCCESS);
	}
	return (key);
}
*/

void			gen_mlx_putclear(t_env *e, t_cart_pt *mat, int x, int y)
{
	t_cart_pt	p;
	int			i;
	int			j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			p.p[Cart_x] = (mat[i * x + j].p[Cart_x] - (e->map->x / 2)) * e->map->gapx + (680 / 2);
			p.p[Cart_y] = (mat[i * x + j].p[Cart_y] - (e->map->y / 2)) * e->map->gapy + (420 / 2);
			p.p[Color] = RGB_BLACK;
			mlx_pixel_put(e->mlx, e->win, p.p[Cart_x], p.p[Cart_y], p.p[Color]);
		}
	}
}

void			gen_mlx_putmat(t_env *e, t_cart_pt *mat, int x, int y)
{
	t_cart_pt	p;
	int			i;
	int			j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			p.p[Cart_x] = (mat[i * x + j].p[Cart_x] - (e->map->x / 2)) * e->map->gapx + (680 / 2);
			p.p[Cart_y] = (mat[i * x + j].p[Cart_y] - (e->map->y / 2)) * e->map->gapy + (420 / 2);
			p.p[Color] = mat[i * x + j].p[Color];
			mlx_pixel_put(e->mlx, e->win, p.p[Cart_x], p.p[Cart_y], p.p[Color]);
		}
	}
}

int				gen_draw(void *p)
{
	t_env		*e;

	e = (t_env *)p;
	gen_mlx_putmat(e, e->map->mat, e->map->x, e->map->y);
	return (0);

}
int				gen_key(int key, void *p)
{
	t_env		*e;

	e = (t_env *)p;
	if (key == 65451)
	{
		gen_mlx_putclear(e, e->map->mat, e->map->x, e->map->y);
		e->map->gapx++;
		e->map->gapy++;
		gen_draw(p);
		return (0);
	}
	if (key == 65453)
	{
		gen_mlx_putclear(e, e->map->mat, e->map->x, e->map->y);
		e->map->gapx--;
		e->map->gapy--;
		gen_draw(p);
		return (0);
	}
	if (!(key == 53 || key == 12 || key == 65307))
		return (ft_printf("(%d)\n", key));
	mlx_destroy_window(e->mlx, e->win);
	ft_memdel((void **)&e->map->mat);
	exit(EXIT_SUCCESS);
	return (0);
}

static void		gen_mlx(char *av, t_cart_pt **amat, int x, int y)
{
	t_env		e;
	t_gen_map	map;

	map.mat = *amat;
	map.x = x;
	map.y = y;
	map.gapx = ((680 / 1.5) / x);
	map.gapy = ((420 / 1.5) / y);
	e.map = &map;
	e.av = av;
	if (!(e.mlx = mlx_init()))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", "mlx init");
		ft_memdel((void **)amat);
		return ;
	}
	if (!(e.win = mlx_new_window(e.mlx, 680, 420, av)))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", "mlx create window");
		ft_memdel((void **)amat);
		return ;
	}
	mlx_key_hook(e.win, gen_key, &e);
	mlx_expose_hook(e.win, gen_draw, &e);
	mlx_loop(e.mlx);
}

static void		gen_putcontrol(char *av)
{
	ft_printf("%s: {ss}%s{eoc}:\n\n", av, "Window Control");
	ft_printf("\t{green}<%s>{eoc}\t[%s]\n", "escape", "Quit");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "5", "Center MAP");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "8", "X Rotation +");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "2", "X Rotation -");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "4", "Y Rotation +");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "6", "Y rotation -");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "7", "Z-Rotation +");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "9", "Z-Rotation -");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "+", "Zoom +");
	ft_printf("\t{green}<%s>{eoc}\t\t[%s]\n", "-", "Zoom -");
#ifdef TROLL
	ft_printf("\n%s: {cyan|gr}%s{eoc}: {pink}%s{eoc}\n", \
			av, "Troll", "Enjoy it!");
#endif /* TROLL */
}

static int		gen_puterror(char *av, char *type, char *msg, int returnval)
{
	ft_printf("%s: %s: %s\n", av, type, msg);
	return (returnval);
}

static int		gen_putusage(char *av, int returnval)
{
	ft_printf("%s: %s: %s\n", av, "Usage", "gen [x] [y]");
	return (returnval);
}

static void		gen_fillmat(t_cart_pt *mat, int x, int y)
{
	int			i;
	int			j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			mat[i * x + j].p[Cart_x] = j;
			mat[i * x + j].p[Cart_y] = i;
			mat[i * x + j].p[Cart_z] = 0;
			mat[i * x + j].p[Color] = RGB_WHITE - (i * j + y * x) * 0xff;
		}
	}
}

static int		gen(char *av, int x, int y)
{
	t_cart_pt	*mat;
	int			pid;

	if (!(mat = (t_cart_pt *)ft_memalloc(sizeof(t_cart_pt) * (x * y))))
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", \
				av, "Error", "Memory allocation failed");
		return (1);
	}
	gen_fillmat(mat, x, y);
	if (!(pid = fork()))
		gen_mlx(av, &mat, x, y);
	else if (pid < 0 || errno)
	{
		ft_printf("%s: {red}%s{eoc}: %s\n", av, "Error", strerror(errno));
		errno = 0;
		free(mat);
		return (1);
	}
	gen_putcontrol(av);
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
