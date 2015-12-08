/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:12:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/03 11:53:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SCREEN 796
/*
static void		fdf_iso_coo(t_list *lst)
{
	t_fdf_point	*pt;

	while (lst)
	{
		pt = (t_fdf_point *)lst->content;
		pt->x = ;
		pt->y = ;
		lst = lst->next;
	}
}
*/
static void		fdf_relativ_coo(t_list *lst, int x, int y, int gap)
{
	t_fdf_point	*pt;
	int			tx;
	int			tmpx;
	int			tmpy;

	x /= 2;
	y /= 2;
	while (lst)
	{
		pt = (t_fdf_point *)lst->content;
/*		if (!pt->x)
		{
			y++;
			tx = x;
		}
		pt->x = FDF_MIDDLE + (tx++ * gap);
		pt->y = FDF_MIDDLE + (y * gap);
*/		tmpx = pt->x;
		tmpy = pt->y - (pt->z / (gap / 4));
		pt->x = ((tmpx - tmpy) * (gap / 2)) + (FDF_MIDDLE - gap * y);
		pt->y = ((tmpy + tmpx) * (gap / 4)) + (FDF_MIDDLE - gap * y);
//		pt->x = (SCREEN / (gap / 2) + SCREEN / (gap / 4)) / 2;
//		pt->y = (SCREEN / (gap / 4) - (SCREEN / (gap / 2))) / 2;
//		tmp = pt->x;
		//pt->x = ((pt->x > FDF_MIDDLE) ? (pt->x - gap) : (pt->x + gap));
		//pt->y = ((pt->y > FDF_MIDDLE) ? (pt->y - gap) : (pt->y + gap));
		lst = lst->next;
	}
}

static void		fdf_handle_rank(t_list *lst, int *x, int *y)
{
	t_fdf_point	*pt;

	*x = 0;
	*y = 0;
	while (lst)
	{
		pt = (t_fdf_point *)lst->content;
		if (*x < pt->x)
			*x = pt->x;
		if (*y < pt->y)
			*y = pt->y;
		lst = lst->next;
	}
}

void			fdf_handle_point(t_env *e)
{
	int			max;
	int			x;
	int			y;

	fdf_handle_rank(lst, &x, &y);
	max = x > y ? x : y;
	fdf_relativ_coo(lst, x, y, (FDF_MIDDLE / max));
//	fdf_iso_coo(lst);
}
