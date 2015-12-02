/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:42:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/02 10:17:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_x(int x)
{
	int			rx;

	rx = 480 / 4;
	return (rx + (x * 10));
}

static int		fdf_y(int y)
{
	int			ry;

	ry = 480 / 4;
	return (ry + (y * 10));
}

static int		fdf_c(int c)
{
	int			rc;

	rc = 0x0000ff;
	return (rc + (c * 0xff0));
}

static int		fdf_draw(void *ve)
{
	t_list		*cp;
	t_fdf_point	*pt;
	t_env		*e;

	e = (t_env *)ve;
	cp = e->lst;
	while (cp)
	{
		pt = (t_fdf_point *)cp->content;
		mlx_pixel_put(e->mlx, e->win, fdf_x(pt->x), fdf_y(pt->y), fdf_c(pt->z));
		cp = cp->next;
	}
	ft_lstdel(&e->lst, NULL);
	return (0);
}

static int		fdf_handle_key(int key, void *e)
{
	//ft_printf("key= [%d]\n", key);
	if (key == 53)
	{
		mlx_destroy_window(((t_env *)e)->mlx, ((t_env *)e)->win);
		exit(0);
	}
	return (0);
}

void			fdf_mlx(t_list *lst, char *title)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
	{
		ft_printf("fdf: {red}Error: mlx_init!\{eoc}n");
		return ;
	}
	if (!(e.win = mlx_new_window(e.mlx, 480, 480, title)))
	{
		ft_printf("%s: {red}Error: Can't create {eoc}\n", title);
		return ;
	}
	e.lst = lst;
	mlx_expose_hook(e.win, fdf_draw, &e);
	mlx_key_hook(e.win, fdf_handle_key, &e);
	mlx_loop(e.mlx);
}

