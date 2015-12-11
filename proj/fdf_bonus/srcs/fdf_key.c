/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:23:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/10 12:27:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		(*choose_khdl(t_env *env, int key))(void *, int)
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
	choose_khdl(env, key)(env, key);
	return (key);
}
