/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:23:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 03:11:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		(*keyhandle(t_env *env, int key))(void *, int)
{
	int			i;

	i = -1;
	while (++i < NB_KHDL)
	{
		if (key == env->khdl[i].key)
			return (env->khdl[i].handle);
	}
	return (khdl_none);
}

int				fdf_key(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	keyhandle(env, key)(env, key);
	return (key);
}
