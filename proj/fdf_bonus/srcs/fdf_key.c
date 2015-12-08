/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:23:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 03:26:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		(*f)(t_env *)keyhandle(int key)
{
	if (key == 53)
		return (fdf_quit); // todo
	else if (key == 12)
		return (fdf_quit);
	return (fdf_nothing);  //todo
}

int				fdf_key(int key, void *p)
{
	t_env		*env;

	env = (t_env *)p;
	keyhandle(key)(env); //doto
	return (key);
}
