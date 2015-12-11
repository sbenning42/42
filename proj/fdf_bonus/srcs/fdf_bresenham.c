#include "fdf.h"

void			bres_fill_info_o1o2(int dx, int dy, t_bres_info *info)
{
	info->diff = ft_math_abs(dx) > ft_math_abs(dy) ? ft_math_abs(dx) : ft_math_abs(dy);
	info->id = (dx >= dy ? X_scr : Y_scr);
	info->id_e = (dx >= dy ? Y_scr : X_scr);
	info->d1 = (dx >= dy ? dx : dy);
	info->d2 = (dx >= dy ? dy : dx);
	info->i0 = -1;
	info->i1 = 1;
	info->i2 = 1;
	info->c1 = 1;
	info->c2 = 0;
}

void			bres_fill_info_o3o4(int dx, int dy, t_bres_info *info)
{
	info->diff = ft_math_abs(dx) > ft_math_abs(dy) ? ft_math_abs(dx) : ft_math_abs(dy);
	info->id = (-dx >= dy ? X_scr : Y_scr);
	info->id_e = (-dx >= dy ? Y_scr : X_scr);
	info->d1 = (-dx >= dy ? dx : dy);
	info->d2 = (-dx >= dy ? dy : dx);
	info->i0 = 1;
	info->i1 = (-dx >= dy ? -1 : 1);
	info->i2 = (-dx >= dy ? 1 : -1);
	info->c1 = (-dx >= dy ? 0 : 1);
	info->c2 = 1;
}

void			bres_fill_info_o5o6(int dx, int dy, t_bres_info *info)
{
	info->diff = ft_math_abs(dx) > ft_math_abs(dy) ? ft_math_abs(dx) : ft_math_abs(dy);
	info->id = (dx <= dy ? X_scr : Y_scr);
	info->id_e = (dx <= dy ? Y_scr : X_scr);
	info->d1 = (dx <= dy ? dx : dy);
	info->d2 = (dx <= dy ? dy : dx);
	info->i0 = -1;
	info->i1 = -1;
	info->i2 = -1;
	info->c1 = 0;
	info->c2 = 1;
}

void			bres_fill_info_o7o8(int dx, int dy, t_bres_info *info)
{
	info->diff = ft_math_abs(dx) > ft_math_abs(dy) ? ft_math_abs(dx) : ft_math_abs(dy);
	info->id = (dx >= -dy ? X_scr : Y_scr);
	info->id_e = (dx >= -dy ? Y_scr : X_scr);
	info->d1 = (dx >= -dy ? dx : dy);
	info->d2 = (dx >= -dy ? dy : dx);
	info->i0 = 1;
	info->i1 = (dx >= -dy ? 1 : -1);
	info->i2 = (dx >= -dy ? -1 : 1);
	info->c1 = (dx >= -dy ? 1 : 0);
	info->c2 = 0;
}

void			bres_fill_info_verthor(int dx, int dy, t_bres_info *info)
{
	info->diff = ft_math_abs(dx) > ft_math_abs(dy) ? ft_math_abs(dx) : ft_math_abs(dy);
	info->id = (dx == 0 ? Y_scr : X_scr);
	info->id_e = -1;
	info->d1 = (dx == 0 ? dy : dx);
	info->d2 = (dx == 0 ? dx : dy);
	info->i0 = 0;
	info->i1 = (info->d1 > 0 ? 1 : -1);
	info->d1 = info->d2;
	info->i2 = 0;
	info->c1 = 0;
	info->c2 = 0;
}

void			bres_info(int dx, int dy, t_bres_info *info)
{
	if (dx > 0 && dy)
	{
		if (dy > 0)
			bres_fill_info_o1o2(dx, dy, info);
		else
			bres_fill_info_o7o8(dx, dy, info);
	}
	else if (dx < 0 && dy)
	{
		if (dy > 0)
			bres_fill_info_o3o4(dx, dy, info);
		else
			bres_fill_info_o5o6(dx, dy, info);
	}
	else if (dx == 0 || dy == 0)
		bres_fill_info_verthor(dx, dy, info);
}

void			bres_put(t_env *env, t_fdf_px p1, t_fdf_px p2, t_bres_info info, int clr)
{
	int			e;
	int			c1;
	int			c2;

	c1 = p1[Color];
	c2 = p2[Color];
	if (c1 != c2)
	{
		if (c1 == 0xffffff && c2 > 0xff00)
			c1 = c2 + 0x8800;
		else if (c2 == 0xffffff && c1 > 0xff00)
			c1 = c1 + 0x8800;
		else if (c1 == 0xffffff && c2 < 0xff00)
			c1 = c2 + 0x8800;
		else if (c2 == 0xffffff && c1 < 0xff00)
			c1 = c1 + 0x8800;
		else
			c1 = ((c1 + c2) / 2);
	}
	c1 = (clr ? 0 : c1);
	e = info.d1;
	info.d1 = e * 2;
	info.d2 *= 2;
	while (42)
	{
		mlx_pixel_put(env->mlx, env->win, p1[X_scr], p1[Y_scr], c1);
		p1[info.id] += info.i1;
		if (p1[info.id] == p2[info.id])
			break ;
		e += info.i0 * info.d2;
		if ((info.c1 && e < 0) || (!info.c1 && e > 0) || (info.c2 && e == 0))
		{
			p1[info.id_e] += info.i2;
			e += info.d1;
		}
	}
}

void			fdf_bresenham_draw(t_env *env, t_fdf_px p1, t_fdf_px p2, int clr)
{
	t_bres_info	info;
	t_fdf_px	cp1;
	t_fdf_px	cp2;
	int			i;

	i = -1;
	while (++i < 6)
	{
		cp1[i] = p1[i];
		cp2[i] = p2[i];
	}
	bres_info(cp2[X_scr] - cp1[X_scr], cp2[Y_scr] - cp1[Y_scr], &info);
	bres_put(env, cp1, cp2, info, clr);
}
	
