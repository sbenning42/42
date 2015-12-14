/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:23:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 15:02:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		(*choose_khdl(t_env *e, int key))(void *, int)
{
	int			i;

	i = -1;
	while (++i < NB_KHDL)
	{
		if (key == e->khdl[i].key)
			return (e->khdl[i].hdl);
	}
	return (khdl_none);
}

int				fdf_key(int key, void *p)
{
	t_env		*e;

	e = (t_env *)p;
	choose_khdl(e, key)(e, key);
	return (key);
}
