/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 01:40:02 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/05 11:34:38 by sbenning         ###   ########.fr       */
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
			if (e->map.mat[y][x][Coo_x] >= 0)
				mlx_pixel_put(e->mlx, e->win, x * FDF_GAP_W(e->map.x), \
						y * FDF_GAP_H(e->map.y), \
						0xff0000 - (e->map.mat[y][x][Coo_z] * 0xff));
			x++;
		}
		y++;
	}
	return (0);
}

static int		fdf_destroy_mat(int ****mat, int y, int x)
{
	int			i;
	int			j;

	i = -1;
	if (!*mat)
		return (0);
	while (++i <= y && (*mat)[i])
	{
		j = -1;
		while (++j <= x && (*mat)[i][j])
			ft_memdel((void **)&((*mat)[i][j]));
		ft_memdel((void **)&((*mat)[i]));
	}
	ft_memdel((void **)mat);
	return (0);
}


int				fdf_key(int key, void *p)
{
	t_env		*e;

	if (key == 53 || key == 12 || key == 65307)
	{
		e = (t_env *)p;
		mlx_destroy_window(e->mlx, e->win);
		fdf_destroy_mat(&e->map.mat, e->map.y, e->map.x);
		exit(EXIT_SUCCESS);
	}
/*	else
		ft_fprintf(2, "[{green}%d{eoc}][{cyan}%c{eoc}]\n", key, (char)key);
*/	return (0);
}

static void		fdf_fill_mat(t_env *e)
{
	t_list		*cp;
	t_fdf_point	*pt;

	cp = e->map.lst;
	while (cp)
	{
		pt = (t_fdf_point *)cp->content;
		e->map.mat[pt->y][pt->x][0] = pt->x;
		e->map.mat[pt->y][pt->x][1] = pt->y;
		e->map.mat[pt->y][pt->x][2] = pt->z;
		cp = cp->next;
	}
	ft_lstdel(&e->map.lst, NULL);
}

static void		fdf_init_point(int *point)
{
	point[0] = -1;
	point[1] = -1;
	point[2] = -1;
}

static int		fdf_handle_env(t_env *e)
{
	int			***mat;
	int			i;
	int			j;
	int			k;


	

	mat = (int ***)ft_memalloc(sizeof(int **) * e->map.y + 1);
	if (mat == NULL)
		return (0);
	i = 0;
	while (i <= e->map.y)
	{
		mat[i] = (int **)ft_memalloc(sizeof(int *) * e->map.x + 1);
		if (mat[i] == NULL)
			return (fdf_destroy_mat(&mat, i, 0));
		j = 0;
		while (j <= e->map.x)
		{
			mat[i][j] = (int *)ft_memalloc(sizeof(int) * 3);
			if (mat[i][j] == NULL)
				return (fdf_destroy_mat(&mat, i, e->map.x));
			k = 0;
			while (k <= 2)
			{
				mat[i][j][k] = -1;
				k++;
			}
			j++;
		}
		i++;
	}
	e->map.mat = mat;
	fdf_fill_mat(e);
	return (1);
}

static char		*name(char *path)
{
	char		*f;

	f = ft_strrchr(path, '/');
	return (f ? ++f : path);
}

void			fdf_mlx(t_fdf_map map, char *av)
{
	t_env		e;

	e.map = map;
	if (!(e.mlx = mlx_init()))
	{
		ft_lstdel(&map.lst, NULL);
		ft_printf("%s: {red}%s%s{eoc}\n", av, ERRMSG_MLX, map.name);
		return ;
	}
	if (!(e.win = mlx_new_window(e.mlx, FDF_WIDTH, FDF_HEIGHT, name(map.name))))
	{
		ft_lstdel(&map.lst, NULL);
		ft_printf("%s: {red}%s%s{eoc}\n", av, ERRMSG_WIN, map.name);
		return ;
	}
	if (!fdf_handle_env(&e))
	{
		ft_printf("%s:{red}%s{eoc}%s // %d\n", av, ERRMSG_MALLOC, map.name, 1);
		mlx_destroy_window(e.mlx, e.win);
		ft_lstdel(&map.lst, NULL);
		return ;
	}
	mlx_expose_hook(e.win, fdf_draw, (void *)&e);
	mlx_key_hook(e.win, fdf_key, (void *)&e);
	mlx_loop(e.mlx);
}

