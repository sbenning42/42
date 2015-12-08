/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:27:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 03:27:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_draw(void *p)
{
	t_env		*env;

	env = (t_env *)p;
	fdf_bresenham(env, env->map, env->map->mat[0]); //todo
	return (0);
}
